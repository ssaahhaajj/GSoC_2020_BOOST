#define BOOST_TEST_MODULE TEST_CPP20MATRIX
#define BOOST_TEST_DYN_LINK
#include <boost/test/included/unit_test.hpp>  //for macOS
#include "/Users/sahajjain/Desktop/COMPETENCY_TEST/include/CPP20Matrix.hpp"  //path to the library
#include <initializer_list>
#include <iostream>
using namespace std;

BOOST_AUTO_TEST_SUITE(test_CPP20Matrix)

BOOST_AUTO_TEST_CASE(CPP20Matrix_initialize_from_value) {
  CPP20Matrix<int> b0(5,5,100);
  for(int i=0;i<5;i++)
    for(int j=0;j<5;j++)
      BOOST_CHECK_EQUAL(b0(i,j),100);
}

BOOST_AUTO_TEST_CASE(CPP20Matrix_initialize_from_initializer_list) {
  std::initializer_list< initializer_list<int> > l={ {1,2,3}, {2,3,4}, {3,4,5} };
  CPP20Matrix<int> b0(l);
  for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
      BOOST_CHECK_EQUAL(b0(i,j),(i+j+1));
}

BOOST_AUTO_TEST_CASE(CPP20Matrix_addition) {
  CPP20Matrix<int> b1(5,5,10);
  CPP20Matrix<int> b2(5,5,10);
  CPP20Matrix<int> b0(5,5);

  b0=(b1+b2);

  for(int i=0;i<5;i++)
    for(int j=0;j<5;j++)
      BOOST_CHECK_EQUAL(b0(i,j),b1(i,j)+b2(i,j));
}
BOOST_AUTO_TEST_SUITE_END()
