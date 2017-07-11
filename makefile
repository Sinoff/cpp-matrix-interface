#makefile for creating the 'matrix' program

#Flags
CCC= g++
CXXFLAGS = -Wall -g
LIBS = -lStack
OBJS = main.o complex.o 
TARGET = matrix
RM = rm -f

#Default target
all: $(TARGET)

#link the final excecutable
$(TARGET): $(OBJS)
	$(CCC) $(CXXFLAGS) -o $(TARGET) $(OBJS)
   
#compile main.C to create main.o 
main.o: main.c vec.h vec_impl.h mat.h mat_impl.h sq_mat.h sq_mat_impl.h complex.h
	$(CCC) $(CXXFLAGS) -c main.c
  
#compile StArray.C to create StArray.o
complex.o:  complex.cpp complex.h
	$(CCC) $(CXXFLAGS) -c complex.cpp
		
#Cleaning old files before new makefile
clean:
	$(RM) $(TARGET) *.o *.bak *~ "#"* core