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
