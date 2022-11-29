#include <iostream>
#include "mytime0.h"

int main() {
    Time playing;
    Time coding(6);
    Time fixing(12, 30);

    using std::cout;
    using std::endl;

    cout << "playing time = ";
    playing.show();
    cout << endl;

    cout << "coding time = ";
    coding.show();
    cout << endl;

    cout << "fixing time = ";
    fixing.show();
    cout << endl;

    Time sum = coding.sum(fixing);
    cout << "coding.sum(fixing) = ";
    sum.show();
    cout << endl;

    Time sum_op = coding + fixing;
    cout << "coding + fixing = ";
    sum_op.show();
    cout << endl;
}

