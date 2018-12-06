#include "UniquePtr.h"
#include "person.h"
#include<iostream>

void test_bool()
{
	std::cout<< "-- test bool --" << std::endl;
	UniquePtr<int> UPtr(new int(5));
	if(UPtr)
		std::cout<< "UPtr -->True" << std::endl;
		
	UniquePtr<int> UPtr2(NULL);	
	if(!UPtr2)
		std::cout<< "UPtr2 -->False" << std::endl;
		
	std::cout<< "OK" << std::endl;
}


void test_person()
{
	std::cout<< "-- test person --" << std::endl;
	UniquePtr<Person> p(new Person("Yael", 7, 5));
	p->print();
}


void test_opc()
{
	std::cout<< "-- test * --" << std::endl;	
	UniquePtr<int> UPtr(new int(5));		
	std::cout<< "*UPtr:  " << *UPtr <<std::endl;	
}


int main()
{
	test_bool();
	test_opc();
	test_person();
	return 0;
}
