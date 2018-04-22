#ifndef MATRIX_ITERATOR_H
#define MATRIX_ITERATOR_H

#include "cslspace.h"
#include "base_iterator.h"

namespace csl
{
    template<typename ValueType>
        class matrix_iterator : public csl_core::base_iterator<ValueType>
        {
            public:
                matrix_iterator(const matrix_iterator<ValueType>&);

                ValueType &operator *();
                ValueType *operator ->();
                const ValueType &operator *() const;
                const ValueType *operator ->() const;

                //friend class csl::matrix<ValueType>;

                matrix_iterator(ValueType *);
            private:
        };
}

#include "matrix_iterator_imp.h"

#endif // MATRIX_ITERATOR_H
