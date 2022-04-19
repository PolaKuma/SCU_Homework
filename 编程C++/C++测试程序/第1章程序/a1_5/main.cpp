// 文件路径名:a1_5\main.cpp
#include <iostream>					// 编译预处理命令
#include <cstring>					// “cstring”和“string.h”为C头文件，包含字符串相关函数的声明
using namespace std;				// 使用命名空间std

char *CStrCopy(char *target, const char *source)
// 操作结果：C风格将串source复制到串target
{
	char *tar = target;												// 暂存target
	while((*tar++ = *source++) != '\0');							// 逐个字符进行复制，直到'\0'为止
	return target;													// 返回target
}

char *CStrCopy(char *target, const char *source, int n)
// 操作结果：C风格将串source复制n个字符到串target 
{
	int len = (int)strlen(source) < n ? (int)strlen(source) : n;	// 目标串长
	for (int pos = 0; pos < len; pos++) target[pos] = source[pos];	// 逐个字符进行复制
	target[len] = '\0';												// 串结束符
	return target;													// 返回target
}

char* CStrConcat(char *target, const char *source)
// 操作结果：C风格将串source连接到串target的后面
{
	char *tar = target + strlen(target);							// tar指向target的结尾处
	while((*tar++ = *source++) != '\0');							// 逐个字符连接到target的后面，直到'\0'为止
	return target;													// 返回target
}

int main()
{
	char dest[100] = "destination", src[100] = "source";			// 定义变量
	CStrCopy(dest, src);											// 调用CStrCopy()函数
	cout << "CStrCopy(dest, src):" << " dest:" << dest << endl;		// 显示相关信息
	CStrCopy(dest, src, 4);											// 调用CStrCopy()函数
//	dest[4] = '\0';													// 手动加上终止符, 可省略
	cout << "CStrCopy(dest, src, 4):" << " dest:" << dest << endl;	// 显示相关信息
	CStrCopy(dest, "Hello ");										// 复制串"Hello "
	CStrCopy(src, "world");											// 复制串"world"
	CStrConcat(dest, src);											// 调用CStrConcat()函数
	cout << "CStrConcat(dest, src):" << " dest:" << dest << endl;	// 显示相关信息

	return 0;														// 返回值0, 返回操作系统
}