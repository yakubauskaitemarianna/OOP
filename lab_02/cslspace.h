#ifndef CSLSPACE_H
#define CSLSPACE_H

#include <iostream>
#include <cstddef>

namespace csl
{
    namespace csl_core
    {
        class base_container;
        template<typename ValueType>
        class base_iterator;
    }

    template<typename T>
        class matrix;

    template<typename ValueType>
        class matrix_iterator;

    template<typename ValueType>
        class const_matrix_iterator;
}


#endif // CSLSPACE_H
