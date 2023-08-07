#include <string.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <vector>

#include <boost/numeric/ublas/storage.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>

namespace ublas = boost::numeric::ublas;
template <typename T, typename F=ublas::row_major, typename A=boost::numeric::ublas::unbounded_array<T>>
ublas::matrix<T, F, A> makeMatrix(std::size_t m, std::size_t n, const std::vector<T> & v)
{
    if(m*n!=v.size()) {
        ; // Handle this case
    }
    ublas::unbounded_array<T> storage(m*n);
    std::copy(v.begin(), v.end(), storage.begin());
    return ublas::matrix<T, F, A>(m, n, storage);
}

int main() 
{
    std::vector<double> weight_1_vector {1, 2, 3, 4, 0, 0, 1, 2};
    ublas::matrix<double> weight_1 = makeMatrix(2,4,weight_1_vector);

    std::vector<double> bias_vector {5,6};
    ublas::matrix<double> bias_1 = makeMatrix(2,1,bias_vector);

    std::vector<double> embedding_vector {1,1,2,2};
    ublas::matrix<double> embedding = makeMatrix(1,4,embedding_vector);

    ublas::matrix<double> ret = ublas::prod(embedding, ublas::trans(weight_1)) + ublas::trans(bias_1);
    std::cout << ret(0,0) << std::endl;

    return 0;
}
