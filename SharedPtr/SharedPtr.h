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
	
	void release();

	SharedPtr& operator= (const SharedPtr&);
	SharedPtr& operator= (T* ptr);
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
SharedPtr<T>::SharedPtr(T* ptr)try 
		:m_ptr(ptr)
		, m_refCount(new size_t(1))
{
}
catch(std::bad_alloc& e)
{
	delete ptr;
	throw;
}


template<typename T>
SharedPtr<T>::~SharedPtr()
{
	std::cout << "Dtor m_refCount:  "<<*(m_refCount) << std::endl;
	release();
}


template<typename T>
void SharedPtr<T>::release()
{
	--*(m_refCount);
	if (*m_refCount == 0)
	{
		delete m_ptr;
		delete m_refCount;
	}
}


template<typename T>
SharedPtr<T>::SharedPtr(const SharedPtr& other)
	:m_ptr(other.m_ptr),
	m_refCount(other.m_refCount)
{
	++(*m_refCount);
	std::cout << "CopyCtor m_refCount:  "<<*(m_refCount) << std::endl;
}


template<typename T>
SharedPtr<T>& SharedPtr<T>::operator= (const SharedPtr<T>& ptr)
{	
	if (m_ptr != ptr.m_ptr)
	{
		release();
		m_ptr = ptr.m_ptr;
		m_refCount = ptr.m_refCount;
		++(*m_refCount);
	}
	return *this;
}


template<typename T>
SharedPtr<T>& SharedPtr<T>::operator= (T* ptr)
{
	release();
	try
	{
		m_ptr = ptr;
		m_refCount = new size_t(1);
	}
	catch(std::bad_alloc)
	{
		delete ptr;
	}
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
