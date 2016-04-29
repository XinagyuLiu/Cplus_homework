// LastHomework.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<fstream>
using namespace std;

int main(int argc, char* argv[])
{
	ofstream fout("1.txt");
	if(! fout)
	{
		cout << "文件不能打开" <<endl;
	}
	else 
	{
		fout << "Learning C++ is very useful."<< endl; 
		//cout << "Learning C++ is very useful."<< endl; 
	}
	fout.close(); 
	
	ifstream fin("1.txt");
	if ( ! fin)
	{
		cout << "文件不能打开" <<endl;
	}
	else
	{
		char buff[80];
		fin >> buff;
		fin.close();
		cout << buff << endl;
	}
	return 0;
}

