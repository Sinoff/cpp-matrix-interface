#include "vec.h"
#include "mat.h"
#include "sq_mat.h"
#include <iostream>
#include "complex.h"

using namespace std;

void test1() 
{
	unsigned int stage;

	// Stage 1: vector interface
	stage = 1;
	cout << "Stage "<< stage << endl;
	cout << "----------" << endl;
	try 
	{
		Vec<double> v1 = (Vec<double>(3), 5, 8, Vec<double>(6), 7, 15);
		const Vec<double> v2 = v1[Vec<unsigned int>(1), 5, 0, 2, 4, 3];
		cout << "v1 = " << v1 << endl;
		cout << "v2 = " << v2 << endl;
		Vec<double> v3 = (double)2 * v2 + v1 * 3.0;
		cout << "v3 = " << v3 << endl;
		Vec<double> v4 = (Vec<double>(0), 0);
		v4[0] = v1[2];
		v4[1] = v2[5];
		cout << "v4 = " << v4 << endl;
		cout << endl;
	}
	catch (exception& e) 
	{
		cout << "Error in stage " << stage << ": " << e.what() << endl;
		cout << endl;
	}

	// Stage 2: ExceptionWrongDimensions
	stage = 2;
	cout << "Stage "<< stage << endl;
	cout << "----------" << endl;
	try 
	{
		Vec<unsigned int> v1 = range((unsigned int)0, 5) + Vec<unsigned int>(3);
		cout << "v1 = " << v1 << endl;
		cout << endl;
	}
	catch (exception& e) 
	{
		cout << "Error in stage " << stage << ": " << e.what() << endl;
		cout << endl;
	}

	// Stage 3: ExceptionEmptyOperand 
	stage = 3;
	cout << "Stage "<< stage << endl;
	cout << "----------" << endl;
	try
	{
		Vec<unsigned int> v;
		cout << v << endl;
		cout << endl;
	}
	catch (exception& e) 
	{
		cout << "Error in stage " << stage << ": " << e.what() << endl;
		cout << endl;
	}

	// Stage 4: ExceptionIndexExceed  
	stage = 4;
	cout << "Stage "<< stage << endl;
	cout << "----------" << endl;
	try 
	{
		Vec<double> v1 = range(5.1, 8);
		cout << "v1 = " << v1 << endl;
		cout << "v1[15] = " << v1[15] << endl;
		cout << endl;
	}
	catch (exception& e) 
	{
		cout << "Error in stage " << stage << ": " << e.what() << endl;
		cout << endl;
	}

	// Stage 5: matrix interface
	stage = 5;
	cout << "Stage "<< stage << endl;
	cout << "----------" << endl;
	try 
	{
		Mat<double> m1 = ( Mat<double>( range(1.0, 5) ), range(-3.0, 5), range(7.0, 5) );
		cout << "m1 = " << endl << m1 << endl;
		cout << "m1 * transpose(m1) = " << endl << m1 * m1.transpose() << endl;
		Mat<double> m2 = ( Mat<double>( (Vec<double>(3), 7, 5) ), range((double)1, 3) );
		cout << "m2 = " << endl << m2 << endl;
		cout << "3 * m2 * (0.5) = " << endl << 3.0 * m2 * (0.5) << endl;
		cout << endl;
	}
	catch (exception& e) 
	{
		cout << "Error in stage " << stage << ": " << e.what() << endl;
		cout << endl;
	}

	// Stage 6: square matrix interface
	stage = 6;
	cout << "Stage "<< stage << endl;
	cout << "----------" << endl;
	try 
	{
		SqMat<double> m1 = SqMat<double>( (
			Mat<double>( ( Vec<double>(1), 1, -1, -2, -2 ) ), 
			Mat<double>( ( Vec<double>(-3), -1, 1, 1, -2 ) ), 
			Mat<double>( ( Vec<double>(2), 0, -1, 2, -5 ) ), 
			Mat<double>( ( Vec<double>(-2), 2, 1, 0, 3 ) ),
			Mat<double>( ( Vec<double>(-2), 3, 1, 5, 3 ) ) 
			) );
		cout << "m1 = " << endl << m1 << endl;
		cout << "det(m1) = " << m1.determinant() << endl;
		cout << endl;
	}
	catch (exception& e) 
	{
		cout << "Error in stage " << stage << ": " << e.what() << endl;
		cout << endl;
	}

	// Stage 7: sorting
	stage = 7;
	cout << "Stage "<< stage << endl;
	cout << "----------" << endl;
	try 
	{
		norm_inf_comp<double> vec_cmp;
		Mat<double> m1 = ( 
			Mat<double>( ( Vec<double>(-25), 14, -12, -15, 0 ) ), 
			Mat<double>( ( Vec<double>(-44), 6, 3, -16, 23 ) ), 
			Mat<double>( ( Vec<double>(-7), 8, -33, 10, 0 ) )
			).transpose();
		cout << "m1 = " << endl << m1 << endl;
		m1.sort(vec_cmp);
		cout << "after sorting m1 = " << endl << m1 << endl;
		cout << endl;
	}
	catch (exception& e) 
	{
		cout << endl;
		cout << "Error in stage " << stage << ": " << e.what() << endl;
	}

	// Stage 8: complex numbers
	stage = 8;
	cout << "Stage "<< stage << endl;
	cout << "----------" << endl;
	try 
	{
		Complex c1(3, 7);
		cout << "c1 = " << c1 << endl;
		Complex c2(1, 3.5);
		cout << "c2 = " << c2 << endl;
		Mat<Complex> m1 = ( Mat<Complex>( range(Complex(-1, -2.5), 5) ), range(Complex(-2, 2.5), 5), range(Complex(-3, -1), 5) );
		cout << "m1 = " << endl << m1 << endl;
		cout << "m1 * transpose(m1) = " << endl << m1 * m1.transpose() << endl;
		cout << "det(m1 * transpose(m1)) = " << SqMat<Complex>(m1 * m1.transpose()).determinant() << endl;
		Mat<Complex> m2 = ( 
			Mat<Complex>( ( Vec<Complex>( Complex(-25, 1) ), Complex(14, 3), Complex(-12, 7), Complex(-15, 0 ) ) ), 
			Mat<Complex>( ( Vec<Complex>( Complex(-44, 2) ), Complex(6, 0), Complex(3, 0), Complex(-16, 23 ) ) )
			).transpose();
		cout << "m2 = " << endl << m2 << endl;
		norm_inf_comp<Complex> vec_cmp;
		m2.sort(vec_cmp);
		cout << "after sorting m2 = " << endl << m2 << endl;
		cout << endl;
	}
	catch (exception& e) 
	{
		cout << "Error in stage " << stage << ": " << e.what() << endl;
		cout << endl;
	}
}

int main()
{
	test1();

	return 0;
}