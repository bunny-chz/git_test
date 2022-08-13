#include "MyString.h"

void test01()
{
	MyString str("hello World");

	cout << str << endl;

	//cout << "请输入MyString类型字符串：" << endl;
	//cin >> str;

	//cout << "字符串为： " << str << endl;

	//测试[]
	cout << "MyString的第一个字符为：" << str[0] << endl;

	//测试 =
	MyString str2 = "^_^";
	MyString str3 = "";
	str3 = "aaaa";
	str3 = str2;
	cout << "str2 = " << str2 << endl;
	cout << "str3 = " << str3 << endl;

	//测试 +
	MyString str4 = "我爱";
	MyString str5 = "北京";
	MyString str6 = str4 + str5;
	MyString str7 = str6 + "天安门";

	cout << str7 << endl;

	//测试 == 
	if (str6 == str7)
	{
		cout << "s6 与 s7相等" << endl;
	}
	else
	{
		cout << "s6 与 s7不相等" << endl;
	}
}
int main()
{
    
    system("pause");
    return EXIT_SUCCESS;
}
