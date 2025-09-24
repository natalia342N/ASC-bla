#include <iostream>

#include <matrix.hpp>

namespace bla = ASC_bla;


int main()
{
    bla::Matrix<double, bla::RowMajor> A(2, 3);

    std::cout << "demo_matrix test\n";
    std::cout << "Rows = " << A.Rows() 
              << ", Cols = " << A.Cols() << std::endl;

    // test also MatVec, MatMul, Transpose

    return 0;
}
