#include<iostream>
using namespace std;
class MyString
{
public:
	MyString();
	~MyString();
	MyString(const MyString& );
	const char* GetBuffer();
	int GetLength(){	return length;	}
	void SetString(const char* ); //重新设置字符串
	void SetString(const MyString& );
	void Append(const char* ); //追加字符
	void Append(const MyString& );
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
const char* MyString::GetBuffer()
{
	return mystring;
		
}
void MyString::SetString(const char* setstring)
{	
	length = strlen(setstring);
	mystring = new char[length+1];
	strcpy(mystring,setstring);
}
void MyString::SetString(const MyString& s)
{
	length = s.length;
	mystring = new char[length+1];
	strcpy(mystring,s.mystring);
}
void MyString::Append(const char* apd)
{
	length = length + strlen(apd);
	char* temp = mystring;  
	//因为要重新分配更大的空间
	mystring = new char[length+1];
	strcpy(mystring,temp);
	strcat(mystring,apd);
}
void MyString::Append(const MyString& a)
{
	length = length + a.length;
	char* temp = mystring;
	mystring = new char[length+1];
	strcpy(mystring,temp);
	strcat(mystring,a.mystring);
}
int main()
{
	MyString A;
	A.SetString("abc");
	printf("调用SetString(const char* ):\n");
	printf("%s\n",A.GetBuffer());
	MyString B;
	B.SetString(A);
	printf("调用SetString(const MyString& ):\n");
	printf("%s\n",B.GetBuffer());
	B.Append("123");
	printf("调用Append(const char* ):\n");
	printf("%s\n",B.GetBuffer());
	B.Append(A);
	printf("调用Append(const MyString& ):\n");
	printf("%s\n",B.GetBuffer());
	printf("调用拷贝构造函数:\n");
	MyString C(B);
	printf("%s\n",C.GetBuffer());
	return 0;
}