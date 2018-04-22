#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>
#include <exception>

class csl_base_exception : public std::exception
{
    public:
        virtual const char* what()
        {
            return message.c_str();
        }

        explicit csl_base_exception() = default;

        explicit csl_base_exception(const char* message)
            : message(message) {}

        explicit csl_base_exception(const std::string& message)
            : message(message) {}

        explicit csl_base_exception(const std::string& message, const std::string& add_message)
            : message(message), additional_message(add_message) {}

        explicit csl_base_exception(const char* message, const char* add_message)
            : message(message), additional_message(add_message) {}


    protected:
        std::string message;
        std::string additional_message;
};

class csl_out_of_range_exception : public csl_base_exception
{
    public:
        explicit csl_out_of_range_exception()
            : csl_base_exception("Index out of range"){}

        explicit csl_out_of_range_exception(const std::string& add_message)
            : csl_base_exception("Index out of range", add_message){}
};

class csl_memory_allocate_exception : public csl_base_exception
{
    public:
        explicit csl_memory_allocate_exception()
            : csl_base_exception("Bad memory allocation"){}

        explicit csl_memory_allocate_exception(const std::string& add_message)
            : csl_base_exception("Bad memory allocation", add_message){}
};

class csl_matr_sizes_exception : public csl_base_exception
{
    public:
        explicit csl_matr_sizes_exception()
            : csl_base_exception("Matrixes have bad sizes"){}

        explicit csl_matr_sizes_exception(const std::string& add_message)
            : csl_base_exception("Matrixes have bad sizes", add_message){}
};

class csl_matr_wrong_size_exception : public csl_base_exception
{
    public:
        explicit csl_matr_wrong_size_exception()
            : csl_base_exception("Matrixes with zero sizes"){}

        explicit csl_matr_wrong_size_exception(const std::string& add_message)
            : csl_base_exception("Matrixes with zero sizes", add_message){}
};

class csl_zero_devision_exception : public csl_base_exception
{
    public:
        explicit csl_zero_devision_exception()
            : csl_base_exception("Devision by zero"){}

        explicit csl_zero_devision_exception(const std::string& add_message)
            : csl_base_exception("Devision by zero", add_message){}
};

#endif // EXCEPTION_H
