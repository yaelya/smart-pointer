#include "SharedPtr.h"
#include "person.h"
#include<iostream>

using std::endl;
using std::cout;

void test_bool()
{
	cout<< "\n--- test bool ---" << endl;
	
	SharedPtr<int> SPtr(new int(5));
	if(SPtr)
		cout<< "SPtr -->True" << endl;
		
	SharedPtr<int> SPtr2(NULL);	
	if(!SPtr2)
		cout<< "SPtr2 -->False" << endl;
		
	cout<< "OK" << endl;
}


void test_person()
{
	cout<< "\n-- test person --" << endl;
	SharedPtr<Person> p(new Person("Yael", 7, 5));
	p->print();
	
	
	SharedPtr<Person> p1(new Person("Tali", 4, 1));
	p1->print();
	
	SharedPtr<Person> p2(new Person("Rut", 8, 6));
	p2->print();
	
	SharedPtr<Person> p3;
	p3 = p;
	p3->print();
	
	SharedPtr<Person> p4;
	p4 = p;
	p4->print();
	
}


void test_ops()
{
	std::cout<< "\n-- test * --" << std::endl;	
	SharedPtr<int> SPtr(new int(5));		
	std::cout<< "*SPtr:  " << *SPtr <<std::endl;	
}


void test_equal()
{
	std::cout<< "\n-- test == --" << std::endl;	
	SharedPtr<int> SPtr(new int(5));
	SharedPtr<int> SPtr1;
	SPtr1 = SPtr;
	
	if (SPtr1 == SPtr)	
		std::cout<< "SPtr == SPtr1 --> " << *SPtr <<std::endl;	
	else
		std::cout<< "SPtr != SPtr1 -- > " << *SPtr << *SPtr1 <<std::endl;
		
	std::cout<< "OK" << std::endl;
}


void test_different()
{
	std::cout<< "\n-- test != --" << std::endl;	
	SharedPtr<int> SPtr(new int(5));
	SharedPtr<int> SPtr1(new int(6));
	
	if (SPtr1 == SPtr)	
		std::cout<< "SPtr == SPtr1 --> " << *SPtr <<std::endl;	
	else
		std::cout<< "SPtr != SPtr1 -- > " << *SPtr << " != " << *SPtr1 <<std::endl;
		
	std::cout<< "OK" << std::endl;
}


int main()
{
	test_bool();
	test_person();
	test_ops();
	test_equal();
	test_different();
	return 0;
}

