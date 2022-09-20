#pragma once

#include <memory>

template<class T>
class Singleton
{
public:

    static T& Instance();

protected:

    Singleton() {}

private:

    static T* _instance;

    static T* Create();
    static T& GetReference(const std::unique_ptr<T>& ptr);

private:

    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    Singleton(Singleton&&) = delete;
    Singleton& operator=(Singleton&&) = delete;

};

template<class T>
inline T& Singleton<T>::Instance()
{
    static typename std::unique_ptr<T> singleton(T::Create());

    return GetReference(singleton);
}

template<class T>
inline T* Singleton<T>::Create()
{
    return new T();
}

template<class T>
inline T& Singleton<T>::GetReference(const std::unique_ptr<T>& ptr)
{
    return *ptr;
}
