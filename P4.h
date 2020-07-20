//
// PREGUNTA #4
//

#ifndef P4_H
#define P4_H

#include <unordered_map>
#include <numeric>
#include <vector>
using namespace std;

void p4();

template<typename T, template <typename...> typename ContainerT, template <typename...> typename ContainerU>
bool contain_same_value(ContainerT<T> cnt1, ContainerU<T> cnt2)
{
	// check if both containers have same size
	if (size(cnt1) != size(cnt2))
		return false;

	// creating hash table
	unordered_map<T, size_t> hash;
	for (auto item : cnt1)
		++hash[item];

	// Check
	for (auto item : cnt2)
        if (hash[item] > 0)
            --hash[item];

	auto total = accumulate(begin(hash), end(hash), size_t{},
	        [](size_t result, auto item) { return result + item.second; });
	
 	return total == 0;
}
#endif //P4_H
