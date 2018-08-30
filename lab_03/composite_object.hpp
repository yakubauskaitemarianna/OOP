#ifndef COMPOSITE_OBJECT_HPP
#define COMPOSITE_OBJECT_HPP

#include "base_transformations.hpp"
#include "scene_exceptions.hpp"
#include "vector.hpp"
#include "model.hpp"
#include "camera.hpp"

class composite_object : public scene_object {
    public:
        composite_object();
        virtual ~composite_object() = default;

        void transform(base_transformations&);
        bool visible() override;

        void add_model(scene_object*);
        void remove_model(size_t);

        void add_camera(scene_object*);
        void remove_camera(size_t);

        scene_object*& get_model(size_t);
        scene_object*& get_camera(size_t);

        friend class draw_manager;

    private:
        size_t camera_count;
        size_t model_count;
        vector<scene_object*> scene_objects;
};

#endif // COMPOSITE_OBJECT_HPP
