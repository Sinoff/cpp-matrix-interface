***************************************************************************************************
						Matrix Interface 
***************************************************************************************************

This repo includes a simple interface for working with vectors & metrices (similar to Matlab/numpy).

vec: 	Interface for template vectors, defined in vec.h and implemented in vec_impl.h
		It is implemented using a template stl list.
		See more documantaion under vec_impl.h
		
		Please note there's also an example of a comperator method needed for the sort method of vec.
		The exmplae provided is for infinity norm (see norm_inf_comp class at the bottom of vec_impl.h)
		
mat: 	Interface for template metrices, defined in mat.h and implemented in mat_impl.h
		It is implemented as a vector of vectors (which was defined in vec.h).
		See more documantaion under mat_impl.h

sq_mat: Interface for template squared metrices, defined in sq_mat.h and implemented in sq_mat_impl.h
		It inheriets from mat, and adds an option to calculate deteminant.
		See more documantaion under sq_mat_impl.h

complex: Interface for complex numbers, defined in complex.h and implemented in complex.cpp.
		It is implemeneted as an x+yi representation.
		See more documantaion under complex.h
		
main:	An example code of initiating objects of the above classes and calling their different methods.
