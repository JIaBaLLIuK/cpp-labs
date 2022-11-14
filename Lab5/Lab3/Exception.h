#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <iostream>
#include <exception>

template <class Type>
class Exception : public std::exception
{
public:
	Exception(const char*, Type, int);
	~Exception() = default;
	Type GetWrongData() const;
	int GetErrorCode() const;


private:
	Type _wrongData;
	int _errorCode;
};

template<class Type>
Exception<Type>::Exception(const char* errorMessage, Type wrongData, int errorCode) : std::exception(errorMessage), _wrongData(wrongData), _errorCode(errorCode)
{ }

template<class Type>
Type Exception<Type>::GetWrongData() const
{
	return _wrongData;
}

template<class Type>
int Exception<Type>::GetErrorCode() const
{
	return _errorCode;
}

template <class Type>
class ArgumentException : public Exception<Type>
{
public:
	ArgumentException(const char*, Type, int);
	~ArgumentException() = default;
};

template<class Type>
ArgumentException<Type>::ArgumentException(const char* errorMessage, Type wrongData, int errorCode) : Exception<Type>(errorMessage, wrongData, errorCode)
{ }

template <class Type>
class ArgumentOutOfRangeException : public Exception<Type>
{
public:
	ArgumentOutOfRangeException(const char*, Type, int);
	~ArgumentOutOfRangeException() = default;
};

template<class Type>
ArgumentOutOfRangeException<Type>::ArgumentOutOfRangeException(const char* errorMessage, Type wrongData, int errorCode) : Exception<Type>(errorMessage, wrongData, errorCode)
{ }

#endif
