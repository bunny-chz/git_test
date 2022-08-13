#include "MyString.h"

//左移运算符
ostream& operator<< (ostream & cout, MyString& str)
{
	cout << str.pString;
	return cout;
}
//右移运算符
istream& operator>>(istream& cin, MyString& str)
{
	//先将原有的数据释放
	if (str.pString != NULL)
	{
		delete[] str.pString;
		str.pString = NULL;
	}
	char buf[1024]; //开辟临时的字符数组，保存用户输入内容
	cin >> buf;

	str.pString = new char[strlen(buf) + 1];
	strcpy(str.pString, buf);
	str.m_Size = strlen(buf);

	return cin;
}

//构造函数
MyString::MyString(const char * str)
{
	this->pString = new char[strlen(str) + 1];
	strcpy(this->pString, str);
	this->m_Size = strlen(str);
}

//拷贝构造
MyString::MyString(const MyString& str)
{
	this->pString = new char[strlen(str.pString) + 1];
	strcpy(this->pString, str.pString);
	this->m_Size = str.m_Size;
}
//析构函数
MyString::~MyString()
{
	if (this->pString!=NULL)
	{
		delete[]this->pString;
		this->pString = NULL;
	}
}

char& MyString::operator[](int index)
{
	return this->pString[index];
}

MyString& MyString::operator=(const char * str)
{
	if (this->pString != NULL){
		delete[] this->pString;
		this->pString = NULL;
	}
	this->pString = new char[strlen(str) + 1];
	strcpy(this->pString, str);
	this->m_Size = strlen(str);
	return *this;
}

MyString& MyString::operator=(const MyString& str)
{
	if (this->pString != NULL){
		delete[] this->pString;
		this->pString = NULL;
	}
	this->pString = new char[strlen(str.pString) + 1];
	strcpy(this->pString, str.pString);
	this->m_Size = str.m_Size;
	return *this;
}


MyString MyString::operator+(const char * str)
{
	int newsize = this->m_Size + strlen(str) + 1;
	char *temp = new char[newsize];
	memset(temp, 0, newsize);
	strcat(temp, this->pString);
	strcat(temp, str);

	MyString newstring(temp);
	delete[] temp;

	return newstring;
}

MyString MyString::operator+(const MyString& str)
{
	int newsize = this->m_Size + str.m_Size + 1;
	char *temp = new char[newsize];
	memset(temp, 0, newsize);
	strcat(temp, this->pString);
	strcat(temp, str.pString);

	MyString newstring(temp);
	delete[] temp;
	return newstring;
}

bool MyString::operator==(const char * str)
{
	if (strcmp(this->pString, str) == 0 && strlen(str) == this->m_Size){
		return true;
	}

	return false;
}

bool MyString::operator==(const MyString& str)
{
	if (strcmp(this->pString, str.pString) == 0 && str.m_Size == this->m_Size){
		return true;
	}

	return false;
}
