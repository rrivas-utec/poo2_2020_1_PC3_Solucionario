//
// PREGUNTA #2
//

#ifndef P2_H
#define P2_H

#include <cmath>
#include <numeric>
#include <functional>
#include "heap.h"

using namespace std;


using length_t = double;
using specific_weight_t = double;
using weight_t = double;
using volume_t = double;
inline double pi() { return std::acos(-1); }

struct sphere_t
{
	length_t radius = 0;
	specific_weight_t specific_weight = 0;
	weight_t delta = 0;

	volume_t volume() const { return 4.0 / 3.0 * pi() * radius * radius * radius; }
	weight_t weight() const { return volume() * specific_weight; }
	void update_delta(const weight_t another) { delta = abs(weight() - another); }
};

template <template <typename ...> class ContainerT = vector>
class nearest_spheres_t
{
    // compare function
	static auto comparer (sphere_t& s1, sphere_t& s2) { return s1.delta < s2.delta; }
	heap_t<sphere_t, function<bool(sphere_t&, sphere_t&)>> heap_{comparer};
	weight_t average_ = 0;

    // calculate average
    weight_t calculate_average(initializer_list<sphere_t> spheres) {
        return accumulate(begin(spheres), end(spheres),
            weight_t{}, [](const weight_t w, const sphere_t s)
                            {
                                return w + s.weight();
                            }) / size(spheres);
	}

public:
	nearest_spheres_t(initializer_list<sphere_t> spheres)
	{
        // calculate average
        average_ = calculate_average(spheres);
        // add spheres
		for (auto sphere : spheres)
		{
			sphere.update_delta(average_);
			heap_.push(sphere);
		}
	}

	weight_t average() {return average_;}

	pair<bool, ContainerT<sphere_t>> operator()(size_t n) {

        // check if heap is empty
        if (heap_.empty()) return { false, ContainerT<sphere_t>{} };

        // traverse heap until reach n values or heap became empty
        ContainerT<sphere_t > result;
		auto heap{ heap_ };
		while (n-- && !heap.empty())
		{
            result.emplace_back(heap.top());
			heap.pop();
		}
		// return result
		return { true, result };
	}
};

void p2();

#endif //P2_H
