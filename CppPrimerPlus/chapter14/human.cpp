#include <iostream>
#include "human.h"

using namespace std;

void Human::show() const {
    cout << "Human::show" << endl;
}

void Man::subShow() const {
    Human::show();
    cout << "Man::subShow" << endl;
}

void Man1::miShow() {
    cout << "Man1::miShow" << endl;
}

void Man2::miShow() {
    cout << "Man2::miShow" << endl;
}
