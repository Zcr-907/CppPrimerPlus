#include <iostream>
#include <fstream>

void fileIO_func() {
    std::cout << "-------> fileIO_func <-------" << std::endl;

    // 打开文件
    // 除非使用绝对路径,否则查询或者创建文件的路径是在构建目录下,而不是源代码目录下
    // 使用open()可以打开文件或者创建一个新的文件
    // 新创建处的ofstream对象可以像使用cout一样去使用
    char file_name[50];
    std::cout << "请输入要打开的文件名: ";
    std::cin.getline(file_name, 50);
    std::ofstream file_output;
    file_output.open(file_name);

    // 写入文件
    std::cout.setf(std::ios_base::boolalpha);
    std::cout << file_name << "是否打开: " << file_output.is_open() << std::endl;
    char input_data[50];
    std::cout << "请输入要写入文件" << file_name << "的数据: ";
    std::cin.getline(input_data, 50);
    file_output << "input_data" << std::endl;
    file_output.close();
    std::cout << "-------> fileIO_func <-------" << std::endl;

}
