#ifndef _COMPLEX_H_
#define _COMPLEX_H_

#include <iostream>

using namespace std;


class Complex
{
public:
	/*

	Function: Complex (Default Constructor)

	Abstract:

	Creating a complex with real and imaginary =0.

	Parameters:

	N/A/
	Returns: N/A
	*/
	Complex();

	/*

	Function: Complex (Constructor)

	Abstract:

	Creating a complex with real as requested

	Parameters:

	a - the real part of the complex class.
	Returns: N/A
	*/
	Complex(double a);

	/*

	Function: Complex (Constructor)

	Abstract:

	Creating a complex with real as requested

	Parameters:

	a - the real part of the complex class.
	b - the imaginary part of the complex class.
	Returns: N/A
	*/
	Complex(double a, double b);

	/*

	Function: Complex (Copy Constructor)

	Abstract:

	Creating a complex by copying data from a pointer to a complex number.

	Parameters:

	c - a pointer to a complex number.

	Returns: N/A
	*/
	Complex(const Complex *c);

	/*

	Function: Complex (Copy Constructor)

	Abstract:

	Creating a complex by copying data from a reference to a complex number.

	Parameters:

	c - a reference to a complex number.

	Returns: N/A
	*/
	Complex(const Complex& c);

	/*

	Function: norm

	Abstract:

	Calculating the norm of the vector.

	Parameters:
	N/A

	Returns: the norm of the vector
	*/
	double norm() const;

	/*

	Function: getReal

	Abstract:

	Returning the real part of the complex number

	Parameters:
	N/A

	Returns: the real part of the complex number
	*/
	double getReal() const;

	/*

	Function: getIm

	Abstract:

	Returning the imaginary part of the complex number

	Parameters:
	N/A

	Returns: the imaginary part of the complex number
	*/
	double getIm() const;

	/*

	Function: operator++

	Abstract:

	Adding 1 to the real part of the complex number (chaning the current complex instance!)

	Parameters:
	N/A

	Returns: the updated complex number.
	*/
	Complex operator++();

	/*

	Function: operator*

	Abstract:

	Multiplying two complex numbers

	Parameters:
	c - a complex number.

	Returns: A complex number containing the sum of the multiplication.
	*/
	Complex operator*(Complex c) const;

	/*

	Function: operator+

	Abstract:

	Adding two complex numbers

	Parameters:
	c - a complex number.

	Returns: A complex number containing the sum of the addition.
	*/
	Complex operator+(Complex c) const;

	/*

	Function: operator-

	Abstract:

	Subtracting two complex numbers

	Parameters:
	c - a complex number.

	Returns: A complex number containing the sum of the subtraction.
	*/
	Complex operator-(Complex c) const;

	/*

	Function: operator<

	Abstract:

	Comparing two complex numbers according to their norm

	Parameters:
	c - a complex number.

	Returns: TRUE if c is bigger than current complex number
	*/
	inline bool operator<(Complex c) const;

	/*

	Function: operator>

	Abstract:

	Comparing two complex numbers according to their norm

	Parameters:
	c - a complex number.

	Returns: TRUE if c is smaller than current complex number
	*/
	inline bool operator>(Complex c) const;

	/*

	Function: operator<=

	Abstract:

	Comparing two complex numbers according to their norm

	Parameters:
	c - a complex number.

	Returns: TRUE if c is smaller or equal to current complex number
	*/
	inline bool operator<=(Complex c) const;

	/*

	Function: operator<=

	Abstract:

	Comparing two complex numbers according to their norm

	Parameters:
	c - a complex number.

	Returns: TRUE if c is bigger or equal to current complex number
	*/
	inline bool operator>=(Complex c) const;

	/*

	Function: operator==

	Abstract:

	Comparing two complex numbers according to their norm

	Parameters:
	c - a complex number.

	Returns: TRUE if c is equal to current complex number
	*/
	inline bool operator==(Complex c) const;
	
	/*

	Function: ~complex (destructor)

	Abstract:

	Deleting an instance of a complex

	Parameters:
	N/A

	Returns: N/A
	*/
	~Complex();
	
	/*

	Function: abs

	Abstract:

	returning the absloute value of a complex number

	Parameters:
	c - a complex number.

	Returns: the absloute value of a complex number
	*/
	friend double abs(Complex c);



protected:
	double x, y;
};

/*

Function: operator<<

Abstract:

printing the complex number according to required format.

Parameters:
ro - a reference to what will be printed
m - a reference to the complex.
Returns: A reference to what will be printed
*/
ostream& operator<<(ostream& ro, const Complex& rhs);


#endif // _COMPLEX_H_