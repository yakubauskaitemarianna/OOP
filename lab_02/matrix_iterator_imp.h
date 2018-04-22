#ifndef MATRIX_ITERATOR_IMP_H
#define MATRIX_ITERATOR_IMP_H

#include "matrix_iterator.h"

namespace csl
{
    template<typename ValueType>
        ValueType& matrix_iterator<ValueType>::operator *()
        {
            return *(this->ptr);
        }

    template<typename ValueType>
        ValueType* matrix_iterator<ValueType>::operator ->()
        {
            return this->ptr;
        }

    template<typename ValueType>
        const ValueType& matrix_iterator<ValueType>::operator *() const
        {
            return *(this->ptr);
        }

    template<typename ValueType>
        const ValueType* matrix_iterator<ValueType>::operator ->() const
        {
            return this->ptr;
        }

    template<typename ValueType>
        matrix_iterator<ValueType>::matrix_iterator(const matrix_iterator<ValueType> &iter)
            : csl_core::base_iterator<ValueType>(iter.ptr)
        {

        }

    template<typename ValueType>
        matrix_iterator<ValueType>::matrix_iterator(ValueType *ptr)
            : csl_core::base_iterator<ValueType>(ptr)
        {

        }
}


#endif // MATRIX_ITERATOR_IMP_H
