#include "SharedPtr.h"
#include "person.h"
#include<iostream>

using std::endl;
using std::cout;

void test_bool()
{
	cout<< "--- test bool ---" << endl;
	
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
	cout<< "-- test person --" << endl;
	SharedPtr<Person> p(new Person("Yael", 7, 5));
	p->print();
	
	SharedPtr<Person> p1(new Person("Tali", 4, 1));
	p1->print();
	
	SharedPtr<Person> p2(new Person("Rut", 8, 6));
	p2->print();
	
	SharedPtr<Person> p3(new Person("Dan", 9, 2));
	p3->print();
}


void test_ops()
{
	std::cout<< "-- test * --" << std::endl;	
	SharedPtr<int> SPtr(new int(5));		
	std::cout<< "*UPtr:  " << *SPtr <<std::endl;	
}


int main()
{
	test_bool();
	test_person();
	test_ops();
	return 0;
}