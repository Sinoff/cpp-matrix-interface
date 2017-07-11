#ifndef _MAT_H_IMPL
#define _MAT_H_IMPL

#include "mat.h"


/*

Function: Mat (Constructor)

Abstract:

Creating an empty object of class mat.

Parameters:

w - the size of the vector in the new mat
Returns: N/A
*/
template <class T>
Mat<T>::Mat(unsigned int w) : Vec<Vec <T> >()
	{
		if (w < 1) throw ExceptionEmptyOperand(); //size must be at least one
		else w_ = w;
	}

/*

Function: Mat (Constructor)

Abstract:

Creating a new object of class Mat with one vector.

Parameters:

vec_1d - a vector (going to be first row of mat)
Returns: N/A
*/
template <class T>
Mat<T>::Mat(Vec<T> vec_1d): Vec<Vec <T> >(vec_1d)
	{
		unsigned int size = vec_1d.size();
		if (size < 1) throw ExceptionEmptyOperand(); //size must be at least one
		else
		{
			w_ = size;
		}
	}

/*

Function: Mat (Copy Constructor)

Abstract:

Creating a new object of class Mat containing the same elements as vec_2d

Parameters:

vec_2d - a mat which we creating a new copy of
Returns: N/A
*/
template <class T>
Mat<T>::Mat(Vec< Vec<T> > vec_2d): Vec<Vec <T> > (vec_2d)
	{ 
		Vec<T> vec_1d = vec_2d[0];
		unsigned int size = vec_1d.size();
		if (vec_2d.size() < 1) throw ExceptionEmptyOperand(); //size must be at least one

		for (unsigned int i = 0; i < vec_2d.size(); i++)
		{
			if (vec_2d[i].size() != size)
				throw ExceptionWrongDimensions(); //trying to add to mat vectors of different sizes
		}
		w_ = size;

	}

/*

Function: width

Abstract:

Returning the size of the vectors in mat (length of row)

Parameters:
N/A

Returns: the size of the vectors in mat (length of row)
*/
template <class T>
unsigned int Mat<T>::width() const
	{
		return w_;
	}

/*

Function: height

Abstract:

Returning the amount of vectors in the matrix (lenght of col)

Parameters:
N/A

Returns: the amount of vectors in the matrix (lenght of col)
*/
template <class T>
unsigned int Mat<T>::height() const
	{
		return this->vals_.size();
	}

/*

Function: operator+

Abstract:

Adding two matrices.

Parameters:

rhs - a reference to a matrix
Returns: A matrix containing the sum of the addition.
*/
template <class T>
Mat<T> Mat<T>::operator+(const Mat& rhs) const
	{

		unsigned int height1 = this->height();
		if (height1 != rhs.height()) throw ExceptionWrongDimensions();
		unsigned int width1 = this->width();
		if (width1 != rhs.width()) throw ExceptionWrongDimensions();

		Mat sum(width1);

		for (unsigned int i = 0; i < height1; i++)
		{//going over line vector by line vector
			Vec<T> vec((*this)[i] + (rhs[i])); //creating line vector
			sum.push_back(vec); //adding line vectors one by one
		}
		return sum;
	}

/*

Function: operator*

Abstract:

Multiplying a matrix by a scalar (matrix from left, i.e: mat * Scalar).

Parameters:

rhs - a reference to a T element (the scalar)
Returns: A matrix containing the sum of the multiplication.
*/
template <class T>
Mat<T> Mat<T>::operator*(const T& rhs) const
{
	unsigned int height1 = this->height();
	unsigned int width1 = this->width();
	Mat sum = Mat(width1);

	for (unsigned int i = 0; i < height1; i++)
	{//going over line vector by line vector
		Vec<T> vec = Vec<T>();
		sum.push_back(((*this)[i]*(rhs))); //multiplying line vectors one by one
	}
	return sum;
}

/*

Function: operator*

Abstract:

Multiplying 2 matrices

Parameters:

rhs - a reference to a matrix
Returns: A matrix containing the sum of the multiplication.
*/
template <class T>
Mat<T>	Mat<T>::operator*(const Mat<T>& rhs) const
{
	if (this->width() != rhs.height()) throw ExceptionWrongDimensions(); //checking that the multiplication is legal.

	Mat<T> outmat(rhs.width());
	for (unsigned int row = 0; row < this->height(); row++) //going row by row of left vector
	{
		Vec<T> vec = Vec<T>();
		for (unsigned int col = 0; col < rhs.width(); col++) //going col by col of right vector
		{
			T sum = T();
			for (unsigned int k = 0; k < this->width(); k++) //going over all row / col, and creating one element
			{
				T arg1, arg2;
				arg1 = ((*this)[row])[k];
				arg2 = (rhs[k])[col];
				T prod = arg1*arg2;
				sum = sum + prod; //T object * T object
			}
			vec.push_back(sum); //adding the elements to a vector 
		}
		outmat.push_back(vec); // adding the vectors to a matrix
	}
	return outmat;
}

/*

Function: operator,

Abstract:

Concatenateing two matrices.

Parameters:

rhs - a reference to one of the matrices (const)
Returns: A matrix containing the sum of the concatenation.
*/
template <class T>
Mat<T> Mat<T>::operator,(const Mat<T>& rhs) const
{
	if (this->height() == 0) return rhs;
	if (rhs.height() == 0) return *this;
	if (this->width() != rhs.width()) throw ExceptionWrongDimensions(); //making sure concatenation is legal (same row sizes)
	Mat outmat = this->Vec<Vec <T> >::operator, (rhs); 
	return outmat;

}

/*

Function: get_rows

Abstract:

Creating a new matrix including specific rows of the current matrix.

Parameters:

ind - a vector including the indices of the required rows
Returns: a new matrix including specific rows of the current matrix.
*/
template <class T>
Mat<T> Mat<T>::get_rows(const Vec<unsigned int>& ind) const //todo: why not call [] operator?
{
	if (this->height() == 0) throw  ExceptionIndexExceed();
	Mat outmat(this->width()) ;

	for (unsigned int i = 0; i < ind.size(); i++)
	{
		outmat.push_back((*this)[ind[i]]); //adding vector by vector
	}

	return outmat;
}

/*

Function: get_cols

Abstract:

Creating a new matrix including specific cols of the current matrix.

Parameters:

ind - a vector including the indices of the required cols
Returns: a new matrix including specific cols of the current matrix.
*/
template <class T>
Mat<T> Mat<T>::get_cols(const Vec<unsigned int>& ind) const //todo: why not call [] operator?
{
	if(this->height()==0) throw  ExceptionEmptyOperand();
	Mat outmat(ind.size());
	for (unsigned int i = 0; i < this->height(); i++)
	{
		Vec<T> vec;
		for (unsigned int j = 0; j < ind.size(); j++) //creating row by row
		{
			vec.push_back((*this)[i][ind[j]]); //adding only desired elements to new row
		}
		outmat.push_back(vec); //adding row by row to mat
	}
	return outmat;
	
}

/*

Function: transpose

Abstract:

Creating a transposed matrix of the current matrix

Parameters:

N/A/
Returns: the transposed matrix.
*/
template <class T>
Mat<T> Mat<T>::transpose() const 
{
	Mat outmat(this->height());
	for (unsigned int i = 0; i < this->width(); i++) //i = rows of new matrix.
	{
		Vec<T> vec = Vec<T>();
		for (unsigned int j = 0; j < this->height(); j++) //j = cols of new matrix.
		{
			vec.push_back((*this)[j][i]);
		}
		outmat.push_back(vec);
	}
	return outmat;
}

/*

Function: operator*

Abstract:

Multiplying a matrix by a scalar (matrix from right, i.e: Scalar * mat).

Parameters:
lhs - a reference to a T element (the scalar)
rhs - a reference to the matrix

Returns: A matrix containing the sum of the multiplication.
*/
template <class T>
Mat<T> operator*(const T& lhs, const Mat<T>& rhs)
{

	Mat<T> sum = Mat<T>(rhs);


	unsigned int height1 = sum.height();

	for (unsigned int i = 0; i < height1; i++)
	{//going over line vector by line vector
		sum[i] = rhs[i] * lhs; //multiplying line vectors one by one
	}
	return sum;

}


/*

Function: operator<<

Abstract:

printing the vector according to required format.

Parameters:
ro - a reference to what will be printed
m - a reference to the matrix.
Returns: A reference to what will be printed
*/
template <class T>
ostream& operator<<(ostream& ro, const Mat<T>& m)
{
	if (m.height()==0) throw ExceptionEmptyOperand(); //mat is empty
	ro << "(\n";
	for (unsigned int i = 0; i < m.height(); i++)
	{
		ro << m[i];
		if (i != (m.height() - 1)) ro << ",\n";
	}
	ro << "\n)";
	return ro;
}

#endif // _MAT_H_IMPL