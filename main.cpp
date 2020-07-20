#include <iostream>
#include "P1.h"
#include "P2.h"
#include "P3.h"
#include "P4.h"

using namespace std;

int main() {
    try {
        p1();
        cout << "P1 passed" << endl;
        p2();
        cout << "P2 passed" << endl;
        p3();
        cout << "P3 passed" << endl;
        p4();
        cout << "P4 passed" << endl;

    }
    catch (const runtime_error& error) {
        cout << "ERROR: " << error.what();
    }
    return 0;
}
