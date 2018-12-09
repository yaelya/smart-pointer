#include "person.h"
#include <iostream>
#include <cstring>
Person::Person()
{
	std::cout<< "Person Ctor" <<std::endl;
}


Person::Person(const char* name, unsigned int id, unsigned char age):m_id(id), m_age(age)
{
	std::strcpy(m_name, name);
	std::cout<< "Person Ctor" <<std::endl;
}


void Person::set(const char* name, unsigned int id, unsigned char age)
{
	m_id = id;
	m_age = age;
	std::strcpy(m_name, name);
}


Person::~Person()
{
	std::cout<< "Person Dtor" <<std::endl;
}


void Person::print()
{
	std::cout<< "name: "<< m_name << std::endl;
	std::cout<< "id: "<< m_id << std::endl;
	std::cout<< "age: "<< int(m_age) << std::endl;
}


