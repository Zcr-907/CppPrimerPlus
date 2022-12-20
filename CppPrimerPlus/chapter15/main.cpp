#include "friendclass.h"
#include <iostream>
#include <typeinfo>

using namespace std;

int main() {
    Tv tv("Lewis");
    Remote rt;
    rt.getTvName(tv);
    cout << "------- RTTI -------" << endl;
    Grand *pg = new Grand();
    Grand *pmj = new Major();
    Grand *pmi = new Minor();

    Major *castPmj;
    cout << "------- dynamic_cast -------" << endl;
    if (castPmj = dynamic_cast<Major *>(pg)) {
        castPmj->speak();
        castPmj->say();
    }
    if (castPmj = dynamic_cast<Major *>(pmj)) {
        castPmj->speak();
        castPmj->say();
    }
    if (castPmj = dynamic_cast<Major *>(pmi)) {
        castPmj->speak();
        castPmj->say();
    }
    cout << "------- dynamic_cast -------" << endl;
    cout << "------- typeid -------" << endl;
    bool bmj = typeid(Major) == typeid(*pmj);
    bool bg = typeid(Major) == typeid(*pg);
    cout << "bmj:" << bmj << endl;
    cout << "bg:" << bg << endl;

    cout << "------- typeid -------" << endl;
    cout << "------- RTTI -------" << endl;
}

