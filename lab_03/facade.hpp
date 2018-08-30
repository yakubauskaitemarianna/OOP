#ifndef FACADE_HPP
#define FACADE_HPP

#include <string>

#include "controller.hpp"
#include "command.hpp"
#include "base_exception.hpp"

class facade {
    public:
        facade() {
            this->__controller = controller::instance();
        }

        facade(facade&) = delete;
        facade(const facade&) = delete;

        ~facade() {
            delete this->__controller;
        }

        void execute_command(command& c) {
            c.execute(this->__controller);
        }

    private:
        controller* __controller;
};

#endif // FACADE_HPP
