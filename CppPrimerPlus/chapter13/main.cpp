#include <iostream>
#include "tabtenn0.h"

using namespace std;

int main() {
    TableTennisPlayer p1("Lewis", "Lei", true);
    p1.name();
    if (p1.hasTable()) {
        cout << " has a table;" << endl;
    }
    p1.resetTable(false);
    cout << "After rest Table= " << p1.hasTable() << endl;

    cout << "------- 创建子类 -------" << endl;
    RatePlayer r1{10, "Jiao", "BaCao", true};
    r1.name();
    cout << " rating: " << r1.rating() << endl;
    RatePlayer r2(20, p1);
    r2.name();
    cout << " rating: " << r2.rating() << endl;
}
