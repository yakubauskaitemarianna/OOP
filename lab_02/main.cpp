#include <iostream>
#include "matrix.h"

using namespace std;

int main()
{
    try
    {
        csl::matrix<int> matr1 = csl::matrix<int>({{1,1},{2,2},{3,3}});
        //csl::matrix<int> matr1 = csl::matrix<int>({{1,2,3},{4,5,6}});
        csl::matrix<int> matr2 = csl::matrix<int>({{1,2,3},{4,5,6}});
        csl::matrix<int> matr3 = matr1 * matr2;
        std::cout << matr1 << endl;
        std::cout << matr2 << endl;
        std::cout << matr3 << endl;\

        auto iter = matr3.begin();
        for (; iter != matr3.end(); ++iter)
        {
            std::cout << *iter << ' ';
        }

    }
    catch (csl_base_exception ex)
    {
        cout << ex.what();
    }

    return 0;
}
