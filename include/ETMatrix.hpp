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

#ifndef ETMATRIX_H
#define ETMATRIX_H

#include <cassert>
#include <iostream>
#include <typeinfo>
#include <vector>

// Function Object for addition
struct plus_op {
  template <typename R1, typename R2>
  decltype(auto) operator()(const R1 &op1, const R2 &op2, const std::size_t &i, const std::size_t &j) const {
    return op1(i, j) + op2(i, j);
  }
};

// Class for expression
template <typename R1, typename R2, typename Op> class expr {
private:
  const R1 &op1;
  const R2 &op2;
  const std::size_t size_x;
  const std::size_t size_y;
  Op op;

public:
  
  // Constructor
  expr(const R1 &a, const R2 &b, Op f)
      : op1(a), op2(b), size_x(a.shape().first), size_y(b.shape().second),
        op(f) {}
  
  // Returns the shape or dimensions
  decltype(auto) shape() const { return std::make_pair(size_x, size_y); }

  // Operator overloading of + operator
  template <typename F> decltype(auto) operator+(const F &other) {
    assert(shape() == other.shape());
    return expr<expr<R1, R2, Op>, F, plus_op>(*this, other, plus_op());
  }

  // Returns the (i,j)th expresiion element
  decltype(auto) operator()(const std::size_t &i, const std::size_t &j) const {
    return op(op1, op2, i, j);
  }

};

// Class for matrix using expression templates
template <typename T> class ETMatrix {
private:
  std::vector<T> _array;
  const std::size_t size_x;
  const std::size_t size_y;

public:
  
  // Constructor
  ETMatrix() : size_x(0), size_y(0) {}

  // Constructor
  ETMatrix(const std::size_t &n, const std::size_t &m)
      : _array(n * m), size_x(n), size_y(m) {}

  // Constructor
  ETMatrix(const std::size_t &n, const std::size_t &m, const T &val)
      : _array(n * m, val), size_x(n), size_y(m) {}

  // Construction with 2D Vector
  ETMatrix(const std::vector<std::vector<T>> &vec)
      : size_x(vec.size()), size_y((*vec.begin()).size()) {
      for (auto &it : vec) {
        _array.insert(_array.end(), it.begin(), it.end());
      }
  }
  // Construction with 2D initializer_list
  ETMatrix(const std::initializer_list<std::initializer_list<T>> &l)
      : size_x(l.size()), size_y((*l.begin()).size()) {
      for (auto &it : l) {
        _array.insert(_array.end(), it.begin(), it.end());
      }
  }
  // Constructing from Expression 
  template <typename R1, typename R2, typename R3>
  ETMatrix(const expr<R1, R2, R3> &exp)
      : size_x(exp.shape().first), size_y(exp.shape().second) {
      for (std::size_t i = 0; i < size_x; i++) {
        for (std::size_t j = 0; j < size_y; j++) {
          _array.push_back(exp(i, j));
        }
      }
  }

  // Returns the shape or dimension of Matrix
  decltype(auto) shape() const { return std::make_pair(size_x, size_y); }

  // Returns the (i,j)th element of Matrix assuming data is stored in vector in row major form
  inline const T operator()(const std::size_t i, const std::size_t j) const {
    return _array[i * size_y + j];
  }

  // Returns the (i,j)th element of Matrix assuming data is stored in vector in row major form
  inline T &operator()(const std::size_t i, const std::size_t j) {
    return _array[i * size_y + j];
  }
  
  // Operator Overloading of Assignment Operator(=)
  template <typename R1> ETMatrix operator=(const R1 &other) {
    assert(shape() == other.shape());
    ETMatrix<T> temp(size_x, size_y);
    for (std::size_t i = 0; i < size_x; i++) {
      for (std::size_t j = 0; j < size_y; j++) {
        temp(i, j) = other(i, j);
      }
    }
    for (std::size_t i = 0; i < size_x; i++) {
      for (std::size_t j = 0; j < size_y; j++) {
        (*this)(i, j) = temp(i, j);
      }
    }
    return *this;
  }

  // Operator Overloading of ostream Operator(<<)
  friend std::ostream &operator<<(std::ostream &out,ETMatrix<T> &other) {
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
  
  // Operator Overloading of Addition Operator(+)
  template <typename R1> decltype(auto) operator+(const R1 &other) {
    assert(shape() == other.shape());
    return expr<ETMatrix<T>, R1, plus_op>(*this, other, plus_op());
  }
  
};

#endif