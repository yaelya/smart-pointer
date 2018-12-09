#ifndef __SHAREDPTR_H__
#include <cstdlib>
#include <iostream>
template<typename T>
class SharedPtr
{
public:
	explicit SharedPtr(T* ptr = NULL);
	SharedPtr(const SharedPtr& other);
	~SharedPtr();

	SharedPtr& operator= (const SharedPtr&);
	T* operator->() const; 
	T& operator*()  const;
	bool operator!=(const SharedPtr&) const;
	bool operator==(const SharedPtr&) const;

	T* get() const;
	operator bool() const;
		
private:
	T*   m_ptr;
	size_t* m_refCount;
};

/* -------------------------------------- */
template<typename T>
SharedPtr<T>::SharedPtr(T* ptr):m_ptr(ptr)
{
	m_refCount = new size_t;
	*m_refCount = 1;
}


template<typename T>
SharedPtr<T>::~SharedPtr()
{
	if (*m_refCount == 1)
		delete m_ptr;
	else
		m_refCount--;
	
}


template<typename T>
SharedPtr<T>::SharedPtr(const SharedPtr& other)
{
	m_ptr = other.m_ptr;
	++(*m_refCount);
}


template<typename T>
SharedPtr<T>& SharedPtr<T>::operator= (const SharedPtr<T>& ptr)
{	
	if (m_ptr == &ptr)
		return *m_ptr;
	
	delete []m_ptr;

	m_ptr = ptr.m_ptr;
	++(*m_refCount);
	return *this;
}


template<typename T>
T* SharedPtr<T>::operator->() const
{
	return m_ptr;
}


template<typename T>
T& SharedPtr<T>::operator*() const
{
	return *m_ptr;
}


template<typename T>
bool SharedPtr<T>::operator!=(const SharedPtr& ptr) const
{
	return m_ptr != ptr.m_ptr;
}


template<typename T>
bool SharedPtr<T>::operator==(const SharedPtr& ptr) const
{
	return m_ptr == ptr.m_ptr;
}


template<typename T>
T* SharedPtr<T>::get() const
{
	return m_ptr;
}


template<typename T>
SharedPtr<T>::operator bool() const
{
	return m_ptr;
}

#endif
