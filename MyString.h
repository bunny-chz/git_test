#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
using namespace std;

class MyString
{
	friend ostream& operator<< (ostream  & cout, MyString& str);
	friend istream& operator>>(istream& cin, MyString& str);

public:
	MyString(const char *);
	MyString(const MyString&);
	~MyString();

	char& operator[](int index); //[]重载

	//=号重载
	MyString& operator=(const char * str);
	MyString& operator=(const MyString& str); 

	//字符串拼接 重载+号
	MyString operator+(const char * str );
	MyString operator+(const MyString& str);

	//字符串比较
	bool operator== (const char * str);
	bool operator== (const MyString& str);
private:
	char * pString; //指向堆区空间
	int m_Size; //字符串长度 不算'\0'
};
