#include <iostream>
/*
	题目：请实现一个函数，把字符串中的每个空格替换成"%20"。例如输入“We arehappy.”，则输出“We%20are%20happy.”。
*/

void ReplceBlank(char string[], int length)
{
	if (string == NULL || length == 0) 
	{
		return;
	}

	int originalLength = 0;
	int numberOfBlank = 0;
	int newLength = 0;
	int i = 0;

	while (string[i]!='\0')
	{
		++originalLength;
		if (string[i] == ' ') {
			numberOfBlank++;
		}
		++i;
	}

	newLength = originalLength + 2 * numberOfBlank;
	if (length < newLength)
	{
		return;
	}

	int indexOfNew = newLength;
	int indexOfOriginal = originalLength;

	while (indexOfOriginal >= 0 && indexOfNew > indexOfOriginal)
	{
		if (string[indexOfOriginal] == ' ') {
			string[indexOfNew--] = '0';
			string[indexOfNew--] = '2';
			string[indexOfNew--] = '%';
		}
		else
		{
			string[indexOfNew--] = string[indexOfOriginal];
		}
		indexOfOriginal--;
	}

 }

int main() 
{
	/*
		构思测试用例：
		1. 特殊输入：字符串是NULL指针，字符串为空字符串、字符串有一个空格、字符串只有多个空格
		2.包含空格字符串（空格位于字符串的最前面，空格位于字符串的最后面，空格位于字符串的中间，字符串中有连续多个空格）、不包含空格字符串
		
	*/
	using namespace std;

	char str2[50] = "";
	char str3[50] = "       ";
	char str4[50] = { "Hello World!!" };
	char str5[50] = {" HelloWorld!!"};
	char str6[50] = "HelloWorld!! ";
	char str7[50] = "Hello    World!!";
	char str8[] = "  Hello  World!! ";
	char str9[50] = "HelloWorld!!";

	ReplceBlank(NULL, 0);
	ReplceBlank(str2, sizeof(str2));
	ReplceBlank(str3, sizeof(str3));
	ReplceBlank(str4, sizeof(str4));
	ReplceBlank(str5, sizeof(str5));
	ReplceBlank(str6, sizeof(str6));
	ReplceBlank(str7, sizeof(str7));
	ReplceBlank(str8, sizeof(str8));
	ReplceBlank(str9, sizeof(str9));

	cout << str2 << endl;
	cout << str3 << endl;
	cout << str4 << endl;
	cout << str5 << endl;
	cout << str6 << endl;
	cout << str7 << endl;
	cout << str8 << endl;
	cout << str9 << endl;
	system("pause");
	return 0; 
}
/*
	遇到的坑： 用数组储存起来测试用例，结果sizeof（strArr[i]）为指针的长度 4，而非原字符串的长度，故出错。
*/