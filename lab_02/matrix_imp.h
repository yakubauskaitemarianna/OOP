#ifndef MATRIX_IMP_H
#define MATRIX_IMP_H

#include "matrix.h"
#include "exceptions.h"

namespace csl {

    template<typename T>
        matrix<T>::matrix(unsigned int n, unsigned int m):base_container()
        {
            if (n == 0 || m == 0) throw csl_matr_wrong_size_exception();

            this->n = n;
            this->m = m;
            this->element_count = n * m;

            try
            {
                data = new T[n*m];
            }
            catch (std::bad_alloc)
            {
                throw csl_memory_allocate_exception();
            }
    }

    template<typename T>
        matrix<T>::matrix(const matrix<T>& matr):base_container()
        {
            this->n = matr.get_n();
            this->m = matr.get_m();
            this->element_count = matr.size();
            try
            {
                this->data = new T[n*m];
            }
            catch (std::bad_alloc)
            {
                throw csl_memory_allocate_exception();
            }

            for (unsigned int i = 0; i < n; ++i)
            {
                for (unsigned int j = 0; j < m; ++j)
                {
                    this->data[i*m+j] = matr.data[i*m+j];
                }
            }
    }

    template<typename T>
    matrix<T>::matrix(matrix<T>&& matr)
    {
        this->n = matr.get_n();
        this->m = matr.get_m();
        this->element_count = matr.size();
        try
        {
            this->data = new T[n*m];
        }
        catch (std::bad_alloc)
        {
            throw csl_memory_allocate_exception();
        }

        for (unsigned int i = 0; i < n; ++i)
        {
            for (unsigned int j = 0; j < m; ++j)
            {
                this->data[i*m+j] = matr.data[i*m+j];
            }
        }
    }

    template<typename T>
    matrix<T>::matrix(std::initializer_list<std::initializer_list<T>> lst):base_container()
    {
        this->n = lst.size();
        this->m = lst.begin()->size();
        auto iter = lst.begin();
        try
        {
            this->data = new T[n*m];
        }
        catch (std::bad_alloc)
        {
            throw csl_memory_allocate_exception();
        }

        if (lst.size() != n) throw csl_matr_wrong_size_exception();

        for (unsigned int i = 0; iter != lst.end(); ++iter, ++i)
        {
            if (m != iter->size()) throw csl_matr_wrong_size_exception();

            unsigned int j = 0;
            for (auto in_iter = iter->begin(); in_iter != iter->end(); ++in_iter, ++j)
            {
                this->data[i*m+j] = *in_iter;
            }
        }
        this->element_count = this->n * this->m;
    }


    template<typename T>
    matrix<T>::~matrix()
    {
        delete data;
    }


    template<typename T>
    matrix<T>& matrix<T>::operator =(const matrix<T>& matr)
    {
        (*this) = matrix(matr);
        return *this;
    }

    template<typename T>
    matrix<T>& matrix<T>::operator +=(const matrix<T>& matr)
    {
        if (this->get_n() != matr.get_n() || this->get_m() != matr.get_m()) throw csl_matr_sizes_exception();

        unsigned int n = this->get_n();
        unsigned int m = this->get_m();
        for (unsigned int i = 0; i < n; ++i)
        {
            for (unsigned int j = 0; j < m; ++j)
            {
                this->data[i*m+j] = this->data[i*m+j] + matr.data[i*m+j];
            }
        }
        return *this;
    }


    template<typename T>
    matrix<T>& matrix<T>::operator -=(const matrix<T>& matr)
    {
        if (this->get_n() != matr.get_n() || this->get_m() != matr.get_m()) throw csl_matr_sizes_exception();

        unsigned int n = this->get_n();
        unsigned int m = this->get_m();
        for (unsigned int i = 0; i < n; ++i)
        {
            for (unsigned int j = 0; j < m; ++j)
            {
                this->data[i*m+j] = this->data[i*m+j] - matr.data[i*m+j];
            }
        }
        return *this;
    }



    template<typename _T>
    matrix<_T> operator +(const matrix<_T>& m1, const matrix<_T>& m2)
    {
        if (m1.get_n() != m2.get_n() || m1.get_m() != m2.get_m()) throw csl_matr_sizes_exception();

        unsigned int n = m1.get_n();
        unsigned int m = m1.get_m();
        matrix<_T> res = matrix<_T>(n, m);
        for (unsigned int i = 0; i < n; ++i)
        {
            for (unsigned int j = 0; j < m; ++j)
            {
                res.data[i*m+j] = m1.data[i*m+j] + m2.data[i*m+j];
            }
        }
        return res;
    }

    template<typename _T>
    matrix<_T> operator -(const matrix<_T>& m1, const matrix<_T>& m2)
    {
        if (m1.get_n() != m2.get_n() || m1.get_m() != m2.get_m()) throw csl_matr_sizes_exception();

        unsigned int n = m1.get_n();
        unsigned int m = m1.get_m();
        matrix<_T> res = matrix<_T>(n, m);
        for (unsigned int i = 0; i < n; ++i)
        {
            for (unsigned int j = 0; j < m; ++j)
            {
                res.data[i*m+j] = m1.data[i*m+j] - m2.data[i*m+j];
            }
        }
        return res;
    }


    template<typename _T>
    matrix<_T> operator *(const matrix<_T>& m1, const matrix<_T>& m2)
    {
        if (m1.get_m() != m2.get_n()) throw csl_matr_sizes_exception();

        unsigned int n = m1.get_n();
        unsigned int m = m2.get_m();
        unsigned int l = m1.get_m();
        matrix<_T> res = matrix<_T>(n, m);
        for (unsigned int i = 0; i < n; ++i)
        {
            for (unsigned int j = 0; j < m; ++j)
            {
                res.data[i*m+j] = m1.data[i*m1.get_m()] * m2.data[j];
                for (unsigned int k = 1; k < l; ++k)
                {
                    res.data[i*m+j] += m1.data[i*m1.get_m()+k] * m2.data[k*m2.get_m()+j];
                }
            }
        }
        return res;
    }


    template<typename _T>
    matrix<_T> operator +(const matrix<_T>& m1, double num)
    {
        unsigned int n = m1.get_n();
        unsigned int m = m1.get_m();
        matrix<_T> res = matrix<_T>(n, m);
        for (unsigned int i = 0; i < n; ++i)
        {
            for (unsigned int j = 0; j < m; ++j)
            {
                res.data[i*m+j] = m1.data[i*m+j] + num;
            }
        }
        return res;
    }

    template<typename _T>
    matrix<_T> operator -(const matrix<_T>& m1, double num)
    {
        unsigned int n = m1.get_n();
        unsigned int m = m1.get_m();
        matrix<_T> res = matrix<_T>(n, m);
        for (unsigned int i = 0; i < n; ++i)
        {
            for (unsigned int j = 0; j < m; ++j)
            {
                res.data[i*m+j] = m1.data[i*m+j] - num;
            }
        }
        return res;
    }

    template<typename _T>
    matrix<_T> operator *(const matrix<_T>& m1, double num)
    {
        unsigned int n = m1.get_n();
        unsigned int m = m1.get_m();
        matrix<_T> res = matrix<_T>(n, m);
        for (unsigned int i = 0; i < n; ++i)
        {
            for (unsigned int j = 0; j < m; ++j)
            {
                res.data[i*m+j] = m1.data[i*m+j] * num;
            }
        }
        return res;
    }

    template<typename _T>
    matrix<_T> operator /(const matrix<_T>& m1, double num)
    {
        if (num == 0) throw csl_zero_devision_exception();

        unsigned int n = m1.get_n();
        unsigned int m = m1.get_m();
        matrix<_T> res = matrix<_T>(n, m);
        for (unsigned int i = 0; i < n; ++i)
        {
            for (unsigned int j = 0; j < m; ++j)
            {
                res.data[i*m+j] = m1.data[i*m+j] / num;
            }
        }
        return res;
    }



    template<typename _T>
    std::ostream& operator <<(std::ostream& os, const matrix<_T>& matr)
    {
        for (unsigned int i = 0; i < matr.get_n(); ++i)
        {
            for(unsigned int j = 0; j < matr.get_m(); ++j)
            {
                os << "[" << i << "][" << j << "] " << matr.data[i*matr.get_m()+j] << " " << std::endl;
            }
        }
        return os;
    }


    template<typename T>
    void matrix<T>::set_elem(unsigned int i, unsigned int j,const T& elem)
    {
        if (i < this->get_n() && j < this->get_m()) throw csl_out_of_range_exception();

        this[i][j] = elem;
    }


    template<typename T>
    T& matrix<T>::get_elem(unsigned int i, unsigned int j)
    {
        if (i < this->get_n() && j < this->get_m()) throw csl_out_of_range_exception();

        return this[i][j];
    }

    template<typename T>
    T matrix<T>::get_elem(unsigned int i, unsigned int j) const
    {
        if (i < this->get_n() && j < this->get_m()) throw csl_out_of_range_exception();

        return this[i][j];
    }

    template<typename T>
    T& matrix<T>::operator ()(unsigned int i, unsigned int j)
    {
        if (i < this->n || j < this->m) throw csl_out_of_range_exception();

        return this->data[i*m+j];
    }

    template<typename T>
    T matrix<T>::operator ()(unsigned int i, unsigned int j) const
    {
        if (i < this->n || j < this->m) throw csl_out_of_range_exception();

        return this->data[i*m+j];
    }

    template<typename T>
    bool matrix<T>::is_square()
    {
        return (this->get_n() == this->get_m());
    }

    template<typename T>
    unsigned int matrix<T>::get_n() const
    {
        return this->n;
    }

    template<typename T>
    unsigned int matrix<T>::get_m() const
    {
        return this->m;
    }

    template<typename T>
    matrix_iterator<T> matrix<T>::begin()
    {
        return matrix_iterator<T>(data);
    }

    template<typename T>
    matrix_iterator<T> matrix<T>::end()
    {
        return matrix_iterator<T>(data+n*m);
    }

    template<typename T>
    const_matrix_iterator<T> matrix<T>::begin() const
    {
        return const_matrix_iterator<T>(data);
    }

    template<typename T>
    const_matrix_iterator<T> matrix<T>::end() const
    {
        return const_matrix_iterator<T>(data+n*m);
    }
}

#endif // MATRIX_IMP_H
