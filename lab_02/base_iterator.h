#ifndef BASE_ITERATOR_H
#define BASE_ITERATOR_H

#include "cslspace.h"

namespace csl
{
    namespace csl_core
    {
        template<typename ValueType>
        class base_iterator
        {
            public:
                base_iterator();
                base_iterator(const base_iterator<ValueType>&);
                base_iterator(ValueType*);
                virtual ~base_iterator();

                base_iterator<ValueType>& operator =(const base_iterator<ValueType>&);

                base_iterator<ValueType>& operator ++();
                base_iterator<ValueType> operator ++(int);
                base_iterator<ValueType>& operator --();
                base_iterator<ValueType> operator --(int);


                bool operator ==(const base_iterator<ValueType>&) const;
                bool operator !=(const base_iterator<ValueType>&) const;
            protected:
                ValueType *ptr;
        };
    }
}

#include "base_iterator_imp.h"

#endif // BASE_ITERATOR_H
