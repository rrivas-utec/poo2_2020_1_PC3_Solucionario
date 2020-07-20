#ifndef HEAP_H
#define HEAP_H

#include <vector>
using namespace std;

template<typename T, typename Compare = greater<T>>
class heap_t {
	// attributes
	vector<T> data_;
	Compare comparer_;

	// heapify
	void heapify()
	{
		if (size(data_) == 0) return;
		auto index = parent(std::size(data_) - 1);
		while (true) {
			percolate_down(index);
			if (index-- == 0) break;
		}
	}

	// percolate_down
	void percolate_down(size_t index)
	{
		auto next = next_child(index);
		while (next < std::size(data_)) {
			if (comparer_(data_[next], data_[index]))
				swap(data_[next], data_[index]);
			index = next;
			next = next_child(index);
		}
	}

	// percolate_up
	void percolate_up(size_t index)
	{
		auto next = parent(index);
		while (next != index) {
			if (comparer_(data_[index], data_[next]))
				swap(data_[index], data_[next]);
			index = next;
			next = parent(index);
		}
	}

	static size_t right_child(const size_t index) { return 2 * index + 2; }
	static size_t left_child(const size_t index) { return 2 * index + 1; }
	static size_t parent(const size_t index) { return index > 0 ? (index - 1) / 2 : 0; }

	size_t next_child(const size_t index)
	{
		if (right_child(index) >= std::size(data_)) return left_child(index);
		return comparer_(data_[left_child(index)], data_[right_child(index)]) ?
			left_child(index) : right_child(index);
	}

public:
	// Constructor
	heap_t() = default;
	explicit heap_t(Compare comparer) : comparer_{ comparer } {}
	explicit heap_t(const heap_t& another)
	{
		data_ = another.data_;
		comparer_ = another.comparer_;
	}
	heap_t& operator=(const heap_t& another)
	{
		data_ = another.data_;
		comparer_ = another.comparer_;
		return *this;
	}
	heap_t(const heap_t&& another) noexcept
	{
		data_ = another.data_;
		comparer_ = another.comparer_;
	}
	heap_t& operator=(heap_t&& another) noexcept
	{
		data_ = another.data_;
		comparer_ = another.comparer_;
		return *this;
	}

	~heap_t() = default;

	// Add a value
	void push(T value)
	{
		data_.push_back(value);
		percolate_up(std::size(data_) - 1);
	}
	// Top value
	T top() { return data_.front(); }
	// Remove value
	void pop()
	{
		iter_swap(begin(data_), rbegin(data_));
		data_.pop_back();
		percolate_down(0);
	}
	// Empty
	bool empty() { return data_.empty(); }
	// Size
	size_t size() { return data_.size(); }
};

#endif