#include<iostream>
#include<string>
using namespace std;
class Cat{
	private:
		string name;
		static int numOfCats;
	public:
		Cat(string name);
		void mew();
		static int getNumofCats();

};

int Cat::numOfCats = 0;

Cat::Cat(string name1)
{
	name = name1;
	++numOfCats;
}

int Cat::getNumofCats()
{
	cout<<"numOfCats: "<<numOfCats<<endl;
	return numOfCats;
}

void Cat::mew()
{
	cout<<"miao miao "<<endl;
}

int main()
{
	Cat cat1("fistCat");
	cat1.mew();
	Cat::getNumofCats();
	Cat cat2("seconfCat");
	cat2.mew();
	Cat::getNumofCats();
	return 0;
}