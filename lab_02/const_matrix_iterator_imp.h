#ifndef CONST_MATRIX_ITERATOR_IMP_H
#define CONST_MATRIX_ITERATOR_IMP_H

#include "const_matrix_iterator.h"

namespace csl
{
    template<typename ValueType>
        const ValueType& const_matrix_iterator<ValueType>::operator *() const
        {
            return *(this->ptr);
        }

    template<typename ValueType>
        const ValueType* const_matrix_iterator<ValueType>::operator ->() const
        {
            return this->ptr;
        }

    template<typename ValueType>
        const_matrix_iterator<ValueType>::const_matrix_iterator(const const_matrix_iterator<ValueType>& iter)
            : csl_core::base_iterator<ValueType>(iter.ptr)
        {

        }

    template<typename ValueType>
        const_matrix_iterator<ValueType>::const_matrix_iterator(ValueType* ptr)
            : csl_core::base_iterator<ValueType>(ptr)
        {

        }
}

#endif // CONST_MATRIX_ITERATOR_IMP_H
