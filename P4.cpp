//
// Created by rudri on 6/19/2020.
//
#include "P4.h"
#include <iostream>
#include <vector>
#include <list>
using namespace std;

void p4() {
	auto l1 = list<int>{ 1, 3, 4, 4 };
	auto v = vector<int>{ 3, 1, 4, 3 };
	cout << boolalpha << contain_same_value(l1, v) << endl;
	cout << boolalpha << contain_same_value(list<int>{ 1, 3, 4, 3 }, vector<int>{ 3, 1, 4, 3 }) << endl;
}
