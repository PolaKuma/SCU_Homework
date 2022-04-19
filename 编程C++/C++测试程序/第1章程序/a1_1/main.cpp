// 文件路径名:a1_1\main.cpp
#include <iostream>					// 编译预处理命令
#include <cstring>					// “cstring”和“string.h”为C头文件，包含字符串相关函数的声明
using namespace std;				// 使用命名空间std 

int main()
{
	char dest[100] = "destination", src[100] = "source";	// 定义变量
	strcpy(dest, src);				// 调用strcpy()函数
	cout << "strcpy(dest, src):" << " dest:" << dest << endl;	// 显示相关信息
	strncpy(dest, src, 4);			// 调用strncpy()函数
	dest[4] = '\0';					// 手动加上终止符
	cout << "strncpy(dest, src, 4):" << " dest:" << dest << endl;// 显示相关信息
	strcpy(dest, "Hello ");			// 复制串"Hello "
	strcpy(src, "world");			// 复制串"world"
	strcat(dest, src);				// 调用strcat()函数
	cout << "strcat(dest, src):" << " dest:" << dest << endl;	// 显示相关信息

	return 0;						// 返回值0, 返回操作系统
}
