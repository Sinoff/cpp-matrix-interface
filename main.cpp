#include "vec.h"
#include "mat.h"
#include "sq_mat.h"
#include <iostream>
#include "complex.h"

void test1() 
{
	unsigned int stage;
	using namespace std;

	// Stage 1: vector interface
	stage = 1;
	cout << "Stage "<< stage << endl;
	cout << "----------" << endl;
	try 
	{
		Mat<double> m1(7);
		cout << "PRINT : should be : empty operand" << endl;
		cout << "result:";
		cout << "PRINT : " << m1;
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
		Mat<double> m1(7);
		cout << "TRANSPOSE : should be : empty operand" << endl;
		cout << "result:";
		cout << "TRAMSPOSE : " << m1.transpose();
	}
	catch (exception& e) 
	{
		cout << "Error in stage " << stage << ": " << e.what() << endl;
		cout << endl;
	}

	// Stage 3: ExceptionWrongDimensions
	stage = 3;
	cout << "Stage "<< stage << endl;
	cout << "----------" << endl;
	try 
	{
		Mat<double> m1(7);
		cout << "GET ROWS : should be : index exceed" << endl;
		cout << "result:";
		cout << "GET ROWS : " << m1.get_rows(Vec<unsigned int>(3));
	}
	catch (exception& e) 
	{
		cout << "Error in stage " << stage << ": " << e.what() << endl;
		cout << endl;
	}

	// Stage 4: ExceptionWrongDimensions
	stage = 4;
	cout << "Stage "<< stage << endl;
	cout << "----------" << endl;
	try 
	{
		Mat<double> m1(7);
		cout << "GET COLS : should be : empty operand" << endl;
		cout << "result:";
		cout << "GET COLS : " << m1.get_cols(Vec<unsigned int>(3));
	}
	catch (exception& e) 
	{
		cout << "Error in stage " << stage << ": " << e.what() << endl;
		cout << endl;
	}

	// Stage 5: ExceptionWrongDimensions
	stage = 5;
	cout << "Stage "<< stage << endl;
	cout << "----------" << endl;
	try 
	{
		Mat<double> m1(7);
		Mat<double> m2(7);
		cout << "ADD+ : should be : empty operand" << endl;
		cout << "result:";
		cout << "ADD+ : " << m1 + m2;
	}
	catch (exception& e) 
	{
		cout << "Error in stage " << stage << ": " << e.what() << endl;
		cout << endl;
	}

	// Stage 6: ExceptionWrongDimensions
	stage = 6;
	cout << "Stage "<< stage << endl;
	cout << "----------" << endl;
	try 
	{
		Mat<double> m1(7);
		cout << "MUL SCALAR* : should be : empty operand" << endl;
		cout << "result:";
		cout << "MUL SCALAR* : " << m1*3;
	}
	catch (exception& e) 
	{
		cout << "Error in stage " << stage << ": " << e.what() << endl;
		cout << endl;
	}

	// Stage 7: ExceptionWrongDimensions
	stage = 7;
	cout << "Stage "<< stage << endl;
	cout << "----------" << endl;
	try 
	{
		Mat<double> m1(7);
		Mat<double> m2(7);
		cout << "MUL MAT* : should be : wrong dimensions" << endl;
		cout << "result:";
		cout << "MUL MAT* : " << m1 * m2;
	}
	catch (exception& e) 
	{
		cout << "Error in stage " << stage << ": " << e.what() << endl;
		cout << endl;
	}

	// Stage 8: ExceptionWrongDimensions
	stage = 8;
	cout << "Stage "<< stage << endl;
	cout << "----------" << endl;
	try 
	{
		Mat<double> m1(5);
		Mat<double> m2(5);
		Mat<double> m3 = (
			Mat<double>((Vec<double>(-25), 14, -12, -15, 0)),
			Mat<double>((Vec<double>(-44), 6, 3, -16, 23)),
			Mat<double>((Vec<double>(-7), 8, -33, 10, 0))
			);
		cout << "CONCAT, : should be : concatenated mat" << endl;
		cout << "result:";
		Mat<double> m4 = (m1, m2, m3);
		cout << "CONCAT, : " << m4;
	}
	catch (exception& e) 
	{
		cout << "Error in stage " << stage << ": " << e.what() << endl;
		cout << endl;
	}

	// Stage 9: ExceptionWrongDimensions
	stage = 9;
	cout << "Stage "<< stage << endl;
	cout << "----------" << endl;
	try 
	{
		cout << "DETER : should be : empty operand" << endl;
		cout << "result:";
		SqMat<double> sq(7);
		cout << "DETER : " << sq.determinant();
	}
	catch (exception& e) 
	{
		cout << "Error in stage " << stage << ": " << e.what() << endl;
		cout << endl;
	}

}

	int main()
{
	cout << "Beginning Test 1: \n";
	test1();

	return 0;
}