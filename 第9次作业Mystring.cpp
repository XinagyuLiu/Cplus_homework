#include<iostream>
using namespace std;
class MyString
{
public:
	MyString();
	~MyString();
	MyString(const MyString& mys);
	const char* GetBuffer(){ return mystring; }
	int GetLength(){ return length;	}
	MyString(const char* setstring);
	//运算符重载
	MyString operator= (const MyString s2);
	MyString operator+ (const MyString s2);
	friend MyString operator+= (MyString& s1,const MyString& s2);
//	MyString operator+= (const MyString s2);
private:
	int length;
	char* mystring;
};
MyString::MyString()
{
	mystring = new char[1];
	mystring[0] = '\0';
	length = 0;
	cout<<"constructing.."<<endl;
}
MyString::~MyString()
{
	delete []mystring;
	length = 0;
	cout<<"destructing.."<<endl;
}

MyString::MyString(const MyString& mys)
{
	mystring = new char[mys.length+1];
	length = mys.length;
	strcpy(mystring,mys.mystring);
	cout<<"copy constructing..."<<endl;
}

MyString::MyString(const char* setstring)
{
	length = strlen(setstring);
	mystring = new char[length+1];
	strcpy(mystring,setstring);
}

MyString MyString::operator= (const MyString s2)
{//重载运算符"=" ,用一个对象赋值给另外一个对象
	length = strlen(s2.mystring);
	mystring = new char[length+1];
	strcpy(mystring,s2.mystring);
	cout<<"重载了运算符="<<endl;
	return *this;
}
MyString MyString::operator+ (const MyString s2)
{
	MyString s3;
	s3.length = this->length + s2.length;
	char* temp =this->mystring;
	s3.mystring = new char[s3.length+1];
	strcpy(s3.mystring,temp);
	strcat(s3.mystring,s2.mystring);
	cout<<"重载了运算符+"<<endl;
	return s3;
}
MyString operator+= (MyString& s1,const MyString& s2)
{	//需要引用才能传值出去
	MyString s3;
	//定义s3是为了返回MyString类型的值
	s3.length = s1.length + s2.length; 
	char* temp =s1.mystring;
	s3.mystring = new char[s3.length+1];
	strcpy(s3.mystring,temp);
	strcat(s3.mystring,s2.mystring); 
	cout<<"重载了运算符+="<<endl;
	//把s3的值传到s1来
	s1.length = s3.length;
	s1.mystring = new char[s3.length+1];
	strcpy(s1.mystring,s3.mystring);
	return s3;
}
/* 
对比：重载为MyString的成员函数
MyString MyString::operator+= (const MyString s2)
{ //不需要引用就能传值出去
	MyString s3;
	//定义s3是为了返回MyString类型的值
	s3.length = length + s2.length; 
	char* temp =mystring;
	s3.mystring = new char[s3.length+1];
	strcpy(s3.mystring,temp);
	strcat(s3.mystring,s2.mystring); 
	cout<<"重载了运算符+="<<endl;
	length = s3.length;
	mystring = new char[s3.length+1];
	strcpy(mystring,s3.mystring);
	return s3;
}*/
int main()
{
	MyString str1 = "abc"; 
	printf("%s\n",str1.GetBuffer());
	MyString str2;
	str2 = str1;
	printf("%s\n",str2.GetBuffer());
	str1 = "xyz";
	MyString str3 = str1 + str2;
	printf("%s\n",str3.GetBuffer());
	cout<<"----------------------"<<endl;
	str2 = str1 = "xyz"; 
	printf("%s\n",str2.GetBuffer());

	str1 = "abc"; 
	str2 = "def";
	str1 += str2;
	printf("%s\n",str1.GetBuffer());
	return 0;
}