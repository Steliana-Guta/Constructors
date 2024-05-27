// Constructors.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
class Book
{
private:
	
	int* pages;

public:
	
	Book() { pages = new int(500); } //no argument constructor
	Book(int num) { pages = new int; *pages = num; } //overload constructor
	Book(Book& obj) { pages = new int; *pages = obj.getPages(); } //copy constructor
	~Book() { std::cout << "Deleting object\n"; } //destructor
	void setPages(int num) { *pages = num; } //set 
	int getPages() { return *pages; } //get
};


int main()
{
	//dynamic memory allocation
	Book* b1 = new Book(); //using the no argument constructor
	std::cout << b1->getPages() << " - This is the amount of pages on b1.\n";
	
	
	//static memory allocation
	Book b2(300); //using the overload constructor
	std::cout << b2.getPages() << " - This is the amount of pages on b2.\n";
	
	//dynamic memory allocation
	Book b3 (*b1); //using the copy constructor //deep copy 
	b3.setPages(200);
	std::cout << b3.getPages() << " - This is the amount of pages on b3.\n";
	
	/*
	//static memory allocation
	Book b4= b2; //using the copy constructor //shallow copy  ??
	b4.setPages(700); 
	std::cout << b4.getPages() << " - This is the amount of pages on b4.\n\n";
	*/

	//print out all amounts
	std::cout << "The amount of pages for book 1 to book 4 are as follows: " << b1->getPages() << ", " << b2.getPages()  << ", " << b3.getPages() <<  ".\n";

	system("PAUSE");
	delete b1;
	return 0;
	
}
