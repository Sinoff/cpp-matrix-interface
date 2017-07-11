#ifndef _MAT_H_
#define _MAT_H_

#include "vec.h"

template <class T>
class Mat: public Vec< Vec<T> >
{
public:
	Mat(unsigned int w);
	Mat(Vec<T> vec_1d);
	Mat(Vec< Vec<T> > vec_2d);
	unsigned int width() const;
	unsigned int height() const;
	Mat operator+(const Mat& rhs) const;
	Mat operator*(const T& rhs) const;
	Mat operator*(const Mat<T>& rhs) const;
	Mat operator,(const Mat<T>& rhs) const;
	Mat get_rows(const Vec<unsigned int>& ind) const;
	Mat get_cols(const Vec<unsigned int>& ind) const;
	Mat transpose() const;

protected:
	unsigned int w_;
};

template <class T>
Mat<T> operator*(const T& lhs, const Mat<T>& rhs);

template <class T>
ostream& operator<<(ostream& ro, const Mat<T>& m);

#include "mat_impl.h"

#endif // _MAT_H_