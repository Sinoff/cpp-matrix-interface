#ifndef _SQ_MAT_H_IMPL
#define _SQ_MAT_H_IMPL

#include "sq_mat.h"
#include <math.h>


/*

Function: SqMat (Constructor)

Abstract:

Creating a new object of class SqMat.

Parameters:

m - a mat which we creating a new copy of (with more features)
Returns: N/A
*/
template <class T>
SqMat<T>::SqMat(Mat<T> m):Mat<T>(m)
{
	if (m.height() != m.width()) throw ExceptionWrongDimensions();
}

/*

Function: size

Abstract:

Returning how wide/long (same since sq) the matrix is.
Parameters:

N/A
Returns: how wide/long (same since sq) the matrix is.
*/
template <class T>
unsigned int SqMat<T>::size() const
{
	return this->Mat<T>::size(); 
}

/*

Function: determinant

Abstract:

Returning the determinant of the matrix
Parameters:

N/A
Returns: the determinant of the matrix
*/

template <class T>
T SqMat<T>::determinant() const
{
	if (this->height() == 0) throw ExceptionEmptyOperand(); // todo: review change
	T det(0.0);
	if (this->size() == 1) return (*this)[0][0]; //stop condition no. 1 (will only be reached if original matrix was size 1).
	else if (this->size() == 2)
	{
		return ((*this)[0][0] * (*this)[1][1] - (*this)[0][1] * (*this)[1][0]); //stop condition no. 2
	}
	else {
		for (unsigned int i = 0; i < this->size(); i++) // calculate by first row
		{
			Mat<T> m = Mat<T>(this->size() - 1);
			for (unsigned int j = 1; j < this->size(); j++) //start from second row
			{
				Vec<T> newrow = Vec<T>();
				for (unsigned int k = 0; k < this->size(); k++)
				{
					if (i == k) continue; // skip i'th column
					else newrow.push_back((*this)[j][k]);
				}
				m.push_back(newrow);
			}
			SqMat sqm(m); //by now m is sq, so we can create a sqmat so we can recursively call determinant
			T d2 = sqm.determinant(); //recursively calling determinant
			det = det + (*this)[0][i] * pow(-1,i) * d2; //full calculation
		}
		return det;
	}
}

#endif // _SQ_MAT_H_IMPL