#ifndef __UNIQUEPTR_H__
#include <cstdlib>

template<typename T>
class UniquePtr
{
public:
    explicit UniquePtr(T* ptr);
    ~UniquePtr();

    T* operator->() const;
    T& operator*()  const;
    operator bool() const;

    T* get() const;

private:
    // Prevent coping 
    UniquePtr(UniquePtr const&);
    UniquePtr& operator=(UniquePtr const&);

    T*   m_ptr;
};

/* --------------------------------------------------- */

template<typename T>
UniquePtr<T>::UniquePtr(T* ptr):m_ptr(ptr)
{}


template<typename T>
UniquePtr<T>::~UniquePtr()
{
	if(m_ptr != NULL)
		delete m_ptr;
}


template<typename T>
T* UniquePtr<T>::operator->() const
{
	return m_ptr;
}


template<typename T>
T& UniquePtr<T>::operator*() const
{
	return *m_ptr;
}


template<typename T>
UniquePtr<T>::operator bool() const
{
	return m_ptr;
}


template<typename T>
T* UniquePtr<T>::get() const
{
	return m_ptr;
}
#endif
