#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include <QGraphicsScene>

#include "scene.hpp"
#include "model_view.hpp"
#include "camera_manager.hpp"
#include "model_manager.hpp"
#include "draw_manager.hpp"
#include "upload_manager.hpp"
#include "drawer.hpp"

class controller {
    public:
        static controller* instance();
        ~controller() = default;

        void upload_view(base_uploader&);
        void delete_view(size_t);

        void add_model(size_t);
        void remove_model(size_t);

        void add_camera();
        void remove_camera(size_t);

        void transform_model(base_transformations&, ssize_t);
        void transform_camera(command_interface&, size_t);

        void draw_scene(base_drawer&, ssize_t);

    protected:
        controller() = default;
        controller(controller&) = delete;
        controller(const controller&) = delete;

    private:
        scene __scene;
        model_view __model_view;
        camera_manager __camera_manager;
        model_manager __model_manager;
        draw_manager __draw_manager;
        upload_manager __upload_manager;
};

#endif // CONTROLLER_HPP
