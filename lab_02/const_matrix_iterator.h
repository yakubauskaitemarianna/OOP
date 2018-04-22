#ifndef MATRIX_CONST_ITERATOR_H
#define MATRIX_CONST_ITERATOR_H

#include "cslspace.h"

#include "base_iterator.h"

namespace csl
{
    template <typename ValueType>
    class const_matrix_iterator : public csl_core::base_iterator<ValueType>
    {
        public:
            const_matrix_iterator(const const_matrix_iterator<ValueType>&);

            const ValueType& operator *() const;
            const ValueType* operator ->() const;

            //friend class csl::matrix<ValueType>;

            const_matrix_iterator(ValueType*);
    };
}

#include "const_matrix_iterator_imp.h"

#endif // MATRIX_CONST_ITERATOR_H
