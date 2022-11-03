#include <iostream>

void char_dev() {
    using namespace std;
    cout << "-------> char_dev <-------" << endl;
    char ch1 = 'a';
    wchar_t wch1 = L'a';    // 扩展行字符串,具体长度由硬件决定
    char16_t ch16 = u'a';   // 16位无符号char
    char32_t ch32 = U'a';   // 32位无符号char
    cout << "show ch1 : " << ch1 << "\tsizeof : " << sizeof(ch1) << endl;
    cout << "show wch1 : " << wch1 << "\tsizeof : " << sizeof(wch1) << endl;
    cout << "show ch16: " << ch16 << "\tsizeof : " << sizeof(ch16) << endl;
    cout << "show ch32: " << ch32 << "\tsizeof : " << sizeof(ch32) << endl;


    cout << "-------> char_dev <-------" << endl;
}


