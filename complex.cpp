#include "complex.h"
#include <math.h>

/*

Function: Complex (Default Constructor)

Abstract:

Creating a complex with real and imaginary =0.

Parameters:

N/A/
Returns: N/A
*/
Complex::Complex()
{
	x = y = 0.0;
}

/*

Function: Complex (Constructor)

Abstract:

Creating a complex with real as requested

Parameters:

a - the real part of the complex class.
Returns: N/A
*/
Complex::Complex(double a)
{
	this->x = a;
	this->y = 0.0;
}

/*

Function: Complex (Constructor)

Abstract:

Creating a complex with real as requested

Parameters:

a - the real part of the complex class.
b - the imaginary part of the complex class.
Returns: N/A
*/
Complex::Complex(double a, double b)
{
	this->x = a;
	this->y = b;
}

/*

Function: Complex (Copy Constructor)

Abstract:

Creating a complex by copying data from a pointer to a complex number.

Parameters:

c - a pointer to a complex number.

Returns: N/A
*/
Complex::Complex(const Complex *c)
{
	this->x = c->x;
	this->y = c->y;
}

/*

Function: Complex (Copy Constructor)

Abstract:

Creating a complex by copying data from a reference to a complex number.

Parameters:

c - a reference to a complex number.

Returns: N/A
*/
Complex::Complex(const Complex& c)
{
	this->x = c.x;
	this->y = c.y;
}

/*

Function: norm 

Abstract:

Calculating the norm of the vector. 

Parameters:
N/A

Returns: the norm of the vector
*/
double Complex::norm() const
{
	double norm;
	norm = sqrt(x*x + y*y);
	return norm;
}

/*

Function: getReal

Abstract:

Returning the real part of the complex number

Parameters:
N/A

Returns: the real part of the complex number
*/
double Complex::getReal() const
{
	return x;
}

/*

Function: getIm

Abstract:

Returning the imaginary part of the complex number

Parameters:
N/A

Returns: the imaginary part of the complex number
*/
double Complex::getIm() const
{
	return y;
}

/*

Function: operator++

Abstract:

Adding 1 to the real part of the complex number (chaning the current complex instance!)

Parameters:
N/A

Returns: the updated complex number.
*/
Complex Complex::operator++()
{
	this->x = this->x + 1.0;
	return this;
}

/*

Function: operator*

Abstract:

Multiplying two complex numbers

Parameters:
c - a complex number.

Returns: A complex number containing the sum of the multiplication.
*/
Complex Complex::operator*(Complex c) const
{
	Complex res;
	res.x = (this->x)*(c.x) - (this->y)*(c.y);
	res.y = (this->x)*(c.y) + (this->y)*(c.x);
	return res;
}

/*

Function: operator+

Abstract:

Adding two complex numbers

Parameters:
c - a complex number.

Returns: A complex number containing the sum of the addition.
*/
Complex Complex::operator+(Complex c) const
{
	Complex res;// = Complex();
	res.x = this->x + c.x;
	res.y = this->y + c.y;
	return res;
}

/*

Function: operator-

Abstract:

Subtracting two complex numbers

Parameters:
c - a complex number.

Returns: A complex number containing the sum of the subtraction.
*/
Complex Complex::operator-(Complex c) const
{
	Complex res;// = Complex();
	res.x = this->x - c.x;
	res.y = this->y - c.y;
	return res;
}

/*

Function: operator<

Abstract:

Comparing two complex numbers according to their norm

Parameters:
c - a complex number.

Returns: TRUE if c is bigger than current complex number
*/
inline bool Complex::operator<(Complex c) const
{
	return (this->norm()<c.norm());
}

/*

Function: operator>

Abstract:

Comparing two complex numbers according to their norm

Parameters:
c - a complex number.

Returns: TRUE if c is smaller than current complex number
*/
inline bool Complex::operator>(Complex c) const
{

	return (c<Complex(this->x,this->y));
}

/*

Function: operator<=

Abstract:

Comparing two complex numbers according to their norm

Parameters:
c - a complex number.

Returns: TRUE if c is smaller or equal to current complex number
*/
inline bool Complex::operator<=(Complex c) const
{
	return !(c<Complex(this->x, this->y));
}

/*

Function: operator<=

Abstract:

Comparing two complex numbers according to their norm

Parameters:
c - a complex number.

Returns: TRUE if c is bigger or equal to current complex number
*/
inline bool Complex::operator>=(Complex c) const
{
	return !(c>Complex(this->x, this->y));
}

/*

Function: operator==

Abstract:

Comparing two complex numbers according to their norm

Parameters:
c - a complex number.

Returns: TRUE if c is equal to current complex number
*/
inline bool Complex::operator==(Complex c) const
{
	if (x == c.x && y == c.y) return true;
	else return false;
}

/*

Function: ~complex (destructor)

Abstract:

Deleting an instance of a complex

Parameters:
N/A

Returns: N/A
*/
Complex::~Complex()
{
}

/*

Function: abs

Abstract:

returning the absloute value of a complex number

Parameters:
c - a complex number.

Returns: the absloute value of a complex number
*/
double abs(Complex c)
{
	return c.norm();
}

/*

Function: operator<<

Abstract:

printing the complex number according to required format.

Parameters:
ro - a reference to what will be printed
m - a reference to the complex.
Returns: A reference to what will be printed
*/
ostream& operator<<(ostream& ro, const Complex& rhs)
{

	ro << rhs.getReal() << " + " << rhs.getIm() << "i";

	return ro;
}