#include <iostream>
/*
	��Ŀ����ʵ��һ�����������ַ����е�ÿ���ո��滻��"%20"���������롰We arehappy.�����������We%20are%20happy.����
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
		��˼����������
		1. �������룺�ַ�����NULLָ�룬�ַ���Ϊ���ַ������ַ�����һ���ո��ַ���ֻ�ж���ո�
		2.�����ո��ַ������ո�λ���ַ�������ǰ�棬�ո�λ���ַ���������棬�ո�λ���ַ������м䣬�ַ���������������ո񣩡��������ո��ַ���
		
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
	�����Ŀӣ� �����鴢�������������������sizeof��strArr[i]��Ϊָ��ĳ��� 4������ԭ�ַ����ĳ��ȣ��ʳ���
*/