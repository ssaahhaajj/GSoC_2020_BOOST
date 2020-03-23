/********************************************************************
********************************************************************
 Author: Sahaj Jain
 
 Purpose: Competency Test for the participation in
          GSOC 2020 in BOOST uBLAS.
          
Copyright: It is not allowed to be used for submitting competency
           test to BOOST GSoC 2020, however, feel free to learn
           from it.
********************************************************************
*********************************************************************/

#ifndef CPP20MATRIX_H
#define CPP20MATRIX_H

#include <iostream>
#include <cassert>
#include<time.h>
#include <range/v3/algorithm/for_each.hpp>
#include <range/v3/view/transform.hpp>
#include<range/v3/all.hpp>

// Class for matrix using latest features of C++20
template <class T>
class CPP20Matrix
{
  std::vector<T> _array;
  const std::size_t size_x;
  const std::size_t size_y;
  
  public:

    // Constructor
    CPP20Matrix() : size_x(0), size_y(0) {}
  
    // Constructor
    CPP20Matrix(const std::size_t &n, const std::size_t &m)
        : _array(n * m), size_x(n), size_y(m) {}

    // Constructor
    CPP20Matrix(const std::size_t &n, const std::size_t &m, const T &val)
        : _array(n * m, val), size_x(n), size_y(m) {}

    // Construction with 2D Vector
    CPP20Matrix(const std::vector<std::vector<T>> &vec)
        : size_x(vec.size()), size_y((*vec.begin()).size()) {

        for (auto &it : vec) {
            _array.insert(_array.end(), it.begin(), it.end());
        }
    }

    // Construction with 2D initializer_list
    CPP20Matrix(const std::initializer_list<std::initializer_list<T>> &l)
        : size_x(l.size()), size_y((*l.begin()).size()) {
        for (auto &it : l) {
            _array.insert(_array.end(), it.begin(), it.end());
        }
    }
    
    // Returns the shape or dimension of Matrix
    constexpr auto shape() const { return std::make_pair(size_x, size_y); }

    // Returns the (i,j)th element of Matrix assuming data is stored in vector in row major form
    constexpr inline const T operator()(const std::size_t i, const std::size_t j) const {
        return _array[i * size_y + j];
    }

    // Returns the (i,j)th element of Matrix assuming data is stored in vector in row major form
    constexpr inline T &operator()(const std::size_t i, const std::size_t j) {
        return _array[i * size_y + j];
    }

    // Operator Overloading of ostream Operator(<<)
    friend std::ostream &operator<<(std::ostream &out, CPP20Matrix<T> &other) {
    std::size_t size_x = other.shape().first;
    std::size_t size_y = other.shape().second;

    for (std::size_t i = 0; i < size_x; i++) {
        for (std::size_t j = 0; j < size_y; j++) {
        out << other(i, j) << ' ';
        }
        out << std::endl;
    }
    return out;
    }

    // Operator Overloading of Assignment Operator(=)
    constexpr auto& operator=(const CPP20Matrix<T> &other) {
    assert(shape() == other.shape());
    (*this)._array=(other)._array;

    return *this;
    }

    // Operator Overloading of Addition Operator(+)
    constexpr auto operator+(const CPP20Matrix<T> &mat2) {
    assert(shape() == mat2.shape());
    (*this)._array=ranges::views::zip_with(std::plus<>{},(*this)._array,mat2._array);
    return (*this);
    }
};

#endif