//
// PREGUNTA #1
//

#ifndef P1_H
#define P1_H

#include "heap.h"

using namespace std;

void p1();

template<template <typename ...> class ContainerT, typename Compare = std::less<>, typename ...Args>
auto sort_numbers(Args... values) {
    // define a type alias
	using common_t = typename common_type<Args...>::type;

    // create heap and result container
	heap_t<common_t, Compare> h;
    ContainerT<common_t> result(sizeof...(Args)); // To avoid doing a lot of push_backs

    // add values
	(h.push(values), ...);  // Explore the possibility
	                        // to use std::initializer_list instead,
	                        // to avoid doing pushes

    // add all values to result container
	auto it = begin(result);
	while (!h.empty()) {
		*(it++) = h.top();
		h.pop();
	}
	return result;
}

#endif //P1_H
