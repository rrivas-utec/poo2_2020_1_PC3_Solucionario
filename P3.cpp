//
// Created by rudri on 6/19/2020.
//
#include "P3.h"
#include <iostream>
using namespace std;
using namespace std::string_literals;

void p3() {
    const auto result = remove_characters("Universidad de Ingenieria y Tecnologia"s, "de "s, "ia"s);
    cout << result << endl;

    const auto result2 = remove_characters("Ciencias de la computacion"s, "zkl"s, "lu"s);
    cout << result2 << endl;
}
