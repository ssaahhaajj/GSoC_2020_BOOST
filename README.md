# Building Matrix Libraries

## Overview

It contains two libraries in `include` folder. First is the `CPP20Matrix.hpp` which is a Matrix Library for addition of two or more matrices built using advanced features of C++20. Other is the `ETMatrix.hpp` library which is also used for addition of two or more matrices but it is built using Expression Templates.

I have also performed unit testing for the `CPP20Matrix.hpp` written for competency test in `test/CPP20Matrix_unit_test.cpp`.

## To run the program

I would like to explain by running `example\example_file.cpp`

```
cd example
g++ example_file.cpp
./a.out
```

## Speed Comparisions

I have made time analysis files for both `ETMatrix.hpp` and `CPP20Matrix.hpp` present in `test` folder. Below are the comparisons between the speed of both libraries on different data types and sizes of matrices.

1)  Below represents the time consumption analysis of both the libraries for **Integer data type**
    
    <img src="images/int_comp.png" width="400" height="230" />

2)  Below represents the time consumption analysis of both the libraries for **Float data type**
    
    <img src="images/float_comp.png" width="400" height="230" />
   
3)  Below represents the time consumption analysis of both the libraries for **String data type**
    
    <img src="images/string_comp.png" width="400" height="230" />
