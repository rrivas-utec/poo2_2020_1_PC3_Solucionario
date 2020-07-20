//
// Created by rudri on 6/19/2020.
//
#include <iostream>
#include "P1.h"
#include <list>
#include <deque>
using namespace std;

void p1() {
    for (const auto& item : sort_numbers<vector, greater<>>(2, 1, 3, 4, 7, 5))
        cout << item << " ";
    cout << endl;
    for (const auto& item : sort_numbers<list, less<>>(5, 7, 4, 3, 1, 2))
        cout << item << " ";
    cout << endl;
    for (const auto& item : sort_numbers<deque, less<>>(5, 7, 4, 3, 1, 2))
        cout << item << " ";
    cout << endl;
    for (const auto& item : sort_numbers<deque, less<>>(5))
        cout << item << " ";
    cout << endl;
}
