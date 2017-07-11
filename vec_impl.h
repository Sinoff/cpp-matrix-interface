#ifndef _VEC_H_IMPL
#define _VEC_H_IMPL

#include "vec.h"

/*

Function: what (For ExceptionWrongDimensions class)

Abstract:

Throwing message explaining what the problem was (trying to do some operation with wrong dimension vectors).

Parameters:
N/A

Returns: the message explaining what happend  (trying to do some operation with wrong dimension vectors).
*/
const char* ExceptionWrongDimensions :: what() const throw()
{
		return "operand dimensions must agree";

}

/*

Function: what (For ExceptionEmptyOperand class)

Abstract:

Throwing message explaining what the problem was (for trying to operate on an empty input).

Parameters:
N/A

Returns: the message explaining what happend  (for trying to operate on an empty input).
*/
const char* ExceptionEmptyOperand :: what() const throw()
{
		return "empty operand";
}

/*

Function: what (For ExceptionIndexExceed class)

Abstract:

Throwing message explaining what the problem was (for trying to reach a non existing index in the vector).

Parameters:
N/A

Returns: the message explaining what happend  (for trying to reach a non existing index in the vector).
*/
const char* ExceptionIndexExceed :: what() const throw()
{
		return "index exeeds operand dimensions";
}

	/*

	Function: Vec (Constructor)

	Abstract:

	Creating a new object of class Vec.

	Parameters:

	el - element of type T class
	Returns: N/A
	*/

template <class T>
Vec<T>::Vec (const T& el)
	{
		T t = const_cast<T&>(el);
		this->push_back(t);
	}

/*

Function: push_back

Abstract:

Adding a new elemnt to the vector

Parameters:

el - element of type T class
Returns: N/A
*/
template <class T>
void Vec<T>::push_back(T el)
	{
		vals_.push_back(el);
	}

/*

Function: size

Abstract:

Returning how many elements there are in a vector.
Parameters:

N/A
Returns: how many elemnts there are in a vector.
*/
template <class T>
unsigned int Vec<T>::size() const
	{
		return vals_.size();
	}


/*

Function: operator+

Abstract:

Adding two vectors.

Parameters:

rhs - a reference to a vector
Returns: A vector containing the sum of the two vectors.
*/
template <class T>
Vec<T> Vec<T>::operator+(const Vec& rhs) const
	{

		unsigned int vec_size = this->size();
		if (rhs.size() != vec_size) throw ExceptionWrongDimensions(); //Dimensions don't fit

		if (rhs.size() == 0) throw ExceptionEmptyOperand(); // rhs is empty.
		
		Vec vec;
		for (unsigned int i = 0; i < vec_size; i++)
		{
			vec.push_back((*this)[i] + rhs[i]);
		}
		return vec;
	}

/*

Function: operator*

Abstract:

Multiplying a vector by a scalar (vector from left, i.e: Vec * Scalar).

Parameters:

rhs - a reference to a T element (the scalar)
Returns: A vector containing the sum of the multiplication.
*/
template <class T>
Vec<T> Vec<T>::operator*(const T& rhs) const
	{
		unsigned int vec_size = size();
		Vec vec;
		for (unsigned int i = 0; i < vec_size; i++)
		{
			vec.push_back((*this)[i] * rhs);
		}
		return vec;
	}

/*

Function: operator[]

Abstract:

Reaching a specific elemnt in a vector.

Parameters:

ind - the index number
Returns: The elemnt in the required index of the vector.
*/
template <class T>
T& Vec<T>::operator[](unsigned int ind)
	{
		unsigned int vec_size = size();
		if (ind >= vec_size) throw ExceptionIndexExceed(); //trying to reach an index which doesn't exist in vector.
		typename list<T>::iterator it = vals_.begin();
		std::advance(it, ind);
		return *it;
	}

/*

Function: operator[]

Abstract:

Reaching a specific elemnt in a vector.

Parameters:

ind - the index number
Returns: The elemnt in the required index of the vector, as const.
*/

template <class T>
const T& Vec<T>::operator[](unsigned int ind) const
	{
		unsigned int vec_size = size();
		if (ind >= vec_size) throw ExceptionIndexExceed(); //trying to reach an index which doesn't exist in vector
		typename list<T>::const_iterator it = vals_.begin();
		std::advance(it, ind);
		return (*it);
	}

/*

Function: operator,

Abstract:

Concatenateing two vectors.

Parameters:

rhs - a reference to one of the vectors (const)
Returns: A vector containing the sum of the concatenation.
*/
template <class T>
Vec<T> Vec<T>::operator,(const Vec& rhs) const
	{

		Vec<T> v;

		for (typename list<T>::const_iterator i = this->begin(); i != this->end(); i++)
		{
			v.push_back(*i); //adding the first vector to the new vector
		}
		for (typename list<T>::const_iterator i = rhs.begin(); i != rhs.end(); i++)
		{
			T el(*i);
			v.push_back(el); //adding the second vector to the new vector
		}
		return v;
	}

/*

Function: operator[]

Abstract:

Creating a new vector including several elemnts from the current vector (according to the indices vector).

Parameters:

ind - a reference to a vector including the indices number
Returns: The new vector including several elemnts from the current vector (according to the indices vector).
*/
template <class T>
Vec<T> Vec<T>::operator[](const Vec<unsigned int>& ind) const
	{
		Vec<T> v;
		for (unsigned int j = 0; j < ind.size(); j++)
		{
			if (this->size() <= ind[j]) throw ExceptionIndexExceed(); //trying to reach an index which doesn't exist in the vector.
			unsigned int i = ind[j]; 
			T val = this->operator[](i); //calling the operator[] for a single index
			v.push_back(val); //puting the element into the vector
		}
		return v;
	}

/*

Function: operator*

Abstract:

Multiplying a vector by a scalar (vector from right, i.e.: Scalar* Vec).

Parameters:
lhs - a reference to a T element (the scalar)
rhs - a reference to the vector.
Returns: A vector containing the sum of the multiplication.
*/
template <class T>
Vec<T> operator*(const T& lhs, const Vec<T>& rhs)
{
	if (rhs.size() == 0) throw ExceptionEmptyOperand();
	Vec<T> res = Vec<T>(rhs);
	res = res * lhs; //calling the operator* of class Vec.
	return res;
}

/*

Function: operator<<

Abstract:

printing the vector according to required format.

Parameters:
ro - a reference to what will be printed
rhs - a reference to the vector.
Returns: A reference to what will be printed
*/
template <class T>
ostream& operator<<(ostream& ro, const Vec<T>& v)
{
	if (v.size() == 0) throw ExceptionEmptyOperand();
	ro << "(";
	for (unsigned int i = 0; i < v.size()-1; i++)
	{
		ro << v[i] << ",\t";
	}
	ro << v[v.size() - 1] << ")";
	return ro;
}

/*

Function: range

Abstract:

creating a vector containing elemnts of numbers increasing by 1 (i.e. 1.1, 2.1, 3.1 etc.).

Parameters:
start - a T element with the number of the first element in the new vector
size - the amount of elements we want in the new vector.
Returns: a vector containing elemnts of numbers increasing by 1 (i.e. 1.1, 2.1, 3.1 etc.).
*/
template <class T>
Vec<T> range(T start, unsigned int size)
{
	if (size == 0) return Vec<T>();
	else
	{
	Vec<T> V(start);
	for (unsigned int i = 1; i < size; i++)
	{
		start = start + 1; //increasing elemnts number by one.
		V.push_back(start);
	}
	return V;
}
}



//norm_inf section

template <class T>
class norm_inf_comp
{
public:
	/*

	Function: operator()

	Abstract:

	Comparing to vectors according to their infinity norm.

	Parameters:
	a - Vector no 1 
	b - Vector no 2 
	Returns: TRUE if b is "bigger" (in inf. norm) than a, FALSE otherwise
	*/
	bool operator()(Vec<T> a, Vec<T> b) const
	{ //virtually return a<b
		double m1 = 0, m2 = 0;
		for (unsigned int i = 0; i < a.size(); i++)
		{
			if (abs(a[i])>m1) m1 = abs(a[i]); //finding the biggest number of vector a
		}
		for (unsigned int i = 0; i < b.size(); i++)
		{
			if (abs(b[i])>m1) m2 = abs(b[i]); //finding the biggest number of vector b
		}
		return m1 < m2;
	}

};


#endif // _VEC_H_IMPL
