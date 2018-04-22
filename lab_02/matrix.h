#ifndef MATRIX_H
#define MATRIX_H

#include "baze_container.h"
#include "exceptions.h"
#include "cslspace.h"
#include "matrix_iterator.h"
#include "const_matrix_iterator.h"
#include <iostream>


namespace csl
{

    template<typename T>
        class matrix : public csl_core::base_container
        {
            public:

                matrix() = delete;
                matrix(unsigned int n, unsigned int m);
                matrix(const matrix<T>& matr);
                matrix(matrix<T>&& matr);
                explicit matrix(std::initializer_list<std::initializer_list<T>> lst);

                ~matrix();

                matrix<T>& operator =(const matrix<T>& matr);
                matrix<T>& operator +=(const matrix<T>& matr);
                matrix<T>& operator -=(const matrix<T>& matr);

                template<typename _T>
                friend matrix<_T> operator +(const matrix<_T>& m1, const matrix<_T>& m2);
                template<typename _T>
                friend matrix<_T> operator -(const matrix<_T>& m1, const matrix<_T>& m2);
                template<typename _T>
                friend matrix<_T> operator *(const matrix<_T>& m1, const matrix<_T>& m2);

                template<typename _T>
                friend matrix<_T> operator +(const matrix<_T>& m1, double num);
                template<typename _T>
                friend matrix<_T> operator -(const matrix<_T>& m1, double num);
                template<typename _T>
                friend matrix<_T> operator *(const matrix<_T>& m1, double num);
                template<typename _T>
                friend matrix<_T> operator /(const matrix<_T>& m1, double num);

                // вывод в поток
                template<typename _T>
                friend std::ostream& operator <<(std::ostream& os, const matrix<_T>& matr);

                // итераторы
                matrix_iterator<T> begin();
                matrix_iterator<T> end();

                const_matrix_iterator<T> begin() const;
                const_matrix_iterator<T> end() const;

                //геттеры и сеттеры
                void set_elem(unsigned int i, unsigned int j,const T& elem);
                T& get_elem(unsigned int i, unsigned int j);
                T get_elem(unsigned int i, unsigned int j) const;

                T& operator ()(unsigned int i, unsigned int j);
                T operator ()(unsigned int i, unsigned int j) const;

                bool is_square();
                unsigned int get_n() const;
                unsigned int get_m() const;

            protected:

                template<typename ValueType>
                class proxy_line
                {
                    public:
                        proxy_line() = delete;

                        proxy_line(ValueType* array, unsigned int n)
                            : data_row(array), m(n) {}

                        T& operator[](unsigned int index)
                        {
                            if (index >= this->m) throw csl_out_of_range_exception();

                            return (data_row[index]);
                        }

                        T operator[](unsigned int index) const
                        {
                            if (index >= this->m) throw csl_out_of_range_exception();

                            return (data_row[index]);
                        }

                    private:
                        unsigned int m;
                        ValueType* data_row = nullptr;
                };

            public:

                proxy_line<T> operator[](unsigned int index)
                {
                    if (index >= this->n) throw csl_out_of_range_exception();

                    return proxy_line<T>(this->data+index*this->m, this->m);
                }

                proxy_line<T> operator[](unsigned int index) const
                {
                    if (index >= this->n) throw csl_out_of_range_exception();

                    return proxy_line<T>(this->data+index*this->m, this->m);
                }

            private:

                unsigned int n;
                unsigned int m;
                T* data;
        };

}

#include "matrix_imp.h"

#endif // MATRIX_H
