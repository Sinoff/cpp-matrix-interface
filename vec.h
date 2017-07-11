#ifndef _VEC_H_
#define _VEC_H_

#include <list>
#include <exception>
#include <iostream>

using namespace std;

class ExceptionWrongDimensions: public exception
{
public:
	const char* what() const throw();
};

class ExceptionEmptyOperand: public exception
{
public:
	const char* what() const throw();
};

class ExceptionIndexExceed: public exception
{
public:
	const char* what() const throw();
};

template <class T>
class Vec {
public:
	typename list<T>::const_iterator begin() const {
		return vals_.begin();
	}
	typename list<T>::const_iterator end() const {
		return vals_.end();
	}
	Vec() {};

	Vec(const T& el);
	void push_back(T el);
	unsigned int size() const;
	Vec operator+(const Vec& rhs) const;
	Vec operator*(const T& rhs) const;
	T& operator[](unsigned int ind);
	const T& operator[](unsigned int ind) const;
	Vec operator,(const Vec& rhs) const;
	Vec operator[](const Vec<unsigned int>& ind) const;

	template <class Compare>
	void sort(Compare comp) {
		vals_.sort(comp);
	}

protected:
	list<T> vals_; 
};

template <class T>
Vec<T> operator*(const T& lhs, const Vec<T>& rhs);

template <class T>
ostream& operator<<(ostream& ro, const Vec<T>& v);

template <class T>
Vec<T> range(T start, unsigned int size);

#include "vec_impl.h"

#endif // _VEC_H_