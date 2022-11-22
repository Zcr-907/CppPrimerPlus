#include "header_test.h"

void plus_HeaderStruct_h2_to_h1(HeaderStruct &h1, HeaderStruct h2) {
    h1.a = h1.a + h2.a;
    h1.b = h1.b + h2.b;
}
