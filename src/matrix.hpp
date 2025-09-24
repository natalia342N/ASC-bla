#ifndef FILE_MATRIX
#define FILE_MATRIX

#include <iostream>
#include "vector.hpp"  

#include <cstddef> 

// solve exercise again 

namespace ASC_bla
{
  enum ORDERING { ColMajor, RowMajor };

  template <typename T, ORDERING ORD>
    class Matrix {
    public:
    Matrix() : rows_(0), cols_(0), data_(0) {}               
    Matrix(std::size_t rows, std::size_t cols)                 
        : rows_(rows), cols_(cols), data_(rows*cols) {}
    ~Matrix() = default;                                      

    std::size_t Rows() const { return rows_; }
    std::size_t Cols() const { return cols_; }

    T& operator()(std::size_t i, std::size_t j)       { return data_(Index(i,j)); }
    const T& operator()(std::size_t i, std::size_t j) const { return data_(Index(i,j)); }

    private:
    static constexpr bool kRowMajor = (ORD == RowMajor);
    std::size_t Index(std::size_t i, std::size_t j) const {
        return kRowMajor ? (i*cols_ + j) : (j*rows_ + i);
    }

    std::size_t rows_, cols_;
    Vector<T>   data_;  
    };

    template <typename T, ORDERING ORD>
    Vector<T> MatVec(const Matrix<T,ORD>& /*A*/, const Vector<T>& /*x*/);

    template <typename T, ORDERING OA, ORDERING OB>
    Matrix<T,OA> MatMul(const Matrix<T,OA>& /*A*/, const Matrix<T,OB>& /*B*/);

    template <typename T, ORDERING ORD>
    Matrix<T,ORD> Transpose(const Matrix<T,ORD>& /*A*/);

    // to do : swap,add, scale rows, Gauss Jordan alg 

    } 
    #endif