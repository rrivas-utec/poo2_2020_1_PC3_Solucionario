//
// Created by rudri on 6/19/2020.
//

#include "P2.h"

#include <iostream>

void p2() {
	nearest_spheres_t ne = {
		{2, 3},
        {1, 8},
        {9, 2},
		{5, 3}};

	auto [status, spheres] = ne(8);
	cout << "average: " << ne.average() << endl;
	for (auto s: spheres)
		cout << "distance: " << s.delta
		        << " radius: " << s.radius
		        << " sw: " << s.specific_weight
		        << " weight: " << s.weight()
		        << " volume: " << s.volume() << endl;
}
