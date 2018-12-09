#ifndef __PERSON_H__
class Person{
public:
	Person();
	Person(const char* name, unsigned int id, unsigned char age);
	~Person();
	
	void set(const char* name, unsigned int id, unsigned char age);
	
	void print();

private:
	char m_name[32];
	unsigned int m_id;
	unsigned char m_age;
	
};
#endif
















