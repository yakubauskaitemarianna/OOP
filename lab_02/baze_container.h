#ifndef BAZE_CONTAINER_H
#define BAZE_CONTAINER_H

#include "cslspace.h"

namespace csl
{
    namespace csl_core
    {
        class base_container
        {
            public:
                explicit base_container();
                explicit base_container(size_t);
                virtual ~base_container();

                bool is_empty() const;
                size_t size() const;
            protected:
                size_t element_count;
        };
    }
}

#endif // BAZE_CONTAINER_H
