#ifndef MODEL_HPP
#define MODEL_HPP

#include <string>

#include "visible_object.hpp"
#include "convector.hpp"
#include "pair.hpp"
#include "point3d.hpp"

class model : public visible_object {
    public:
        explicit model() = default;
        explicit model(const std::string&, const vector<pair<point3d<double>, point3d<double>>>&);
        model(const model&);
        ~model() = default;

        model& operator=(const model&);
        model& operator=(model&&);

        friend class model_transformations;
        friend class draw_manager;

    protected:
        void set_up_center();

    private:
        std::string name;
        vector<pair<point3d<double>, point3d<double>>> lines;
};

#endif // MODEL_HPP
