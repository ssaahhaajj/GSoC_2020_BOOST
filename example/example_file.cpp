#include<chrono> 
#include <vector>
#include <iostream>
#include "/Users/sahajjain/Desktop/COMPETENCY_TEST/include/CPP20Matrix.hpp"
#include "/Users/sahajjain/Desktop/COMPETENCY_TEST/include/ETMatrix.hpp"
#include <cassert>

using namespace std;
/*
    It produces following output:

    USING CPP20Matrix Library
    200 200 200 200 200 
    200 200 200 200 200 
    200 200 200 200 200 
    200 200 200 200 200 
    200 200 200 200 200 

    USING ETMatrix Library
    200 200 200 200 200 
    200 200 200 200 200 
    200 200 200 200 200 
    200 200 200 200 200 
    200 200 200 200 200 
*/

int main(void) {

    // Exampleof CPP20Matrix adding two matrices
	CPP20Matrix<int> b0(5,5,100);
	CPP20Matrix<int> c0(5,5,100);

    CPP20Matrix<int> a(5,5);
    
    a=b0+c0;
    
    cout<<"USING CPP20Matrix Library\n"<<a;

    cout<<endl;
	// Exampleof ETMatrix adding two matrices
    ETMatrix<int> b1(5,5,100);
	ETMatrix<int> c1(5,5,100);

    ETMatrix<int> a1(5,5);
    
    a1=b1+c1;
    
    cout<<"USING ETMatrix Library\n"<<a;
    cout<<endl;
   return 0; 
}