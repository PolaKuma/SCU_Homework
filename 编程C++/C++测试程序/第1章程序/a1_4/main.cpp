// 文件路径名:a1_4\main.cpp
#include <iostream>					// 编译预处理命令
#include <cstring>					// “cstring”和“string.h”为C头文件，包含字符串相关函数的声明
using namespace std;				// 使用命名空间std

int main()
{
	char dest[100] = "destination", src[100] = "source";	// 定义变量
	strcpy_s(dest, strlen(src) + 1, src);					// 调用strcpy_s()函数
	cout << "strcpy_s(dest, strlen(src) + 1, src):" << " dest:" << dest << endl;				// 显示相关信息
	strncpy_s(dest, strlen(src) + 1, src, 4);				// 调用strncpy_s()函数
	dest[4] = '\0';					// 手动加上终止符
	cout << "strncpy_s(dest, strlen(src) + 1, src, 4):" << " dest:" << dest << endl;			// 显示相关信息
	strcpy_s(dest, strlen("Hello ") + 1, "Hello ");			// 复制串"Hello "
	strcpy_s(src, strlen("world") + 1, "world");			// 复制串"world"
	strcat_s(dest, strlen(dest) + strlen(src) + 1, src);	// 调用strcat_s()函数
	cout << "strcat_s(dest, strlen(dest) + strlen(src) + 1, src):" << " dest:" << dest << endl;	// 显示相关信息

	return 0;						// 返回值0, 返回操作系统
}
