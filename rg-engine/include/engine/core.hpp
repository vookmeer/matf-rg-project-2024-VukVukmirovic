//
// Created by spaske00 on 20.5.24..
//

#ifndef MATF_RG_PROJECT_CORE_HPP
#define MATF_RG_PROJECT_CORE_HPP

#include <string_view>
#include <memory>
#include <source_location>
#include <format>
#include <vector>

#include "errors.hpp"

namespace rg {

    class Controller {
        friend class ControllerManager;

    public:
        virtual std::string_view name() const = 0;

        virtual ~Controller() = default;

    private:
        virtual void initialize() {
        }

        virtual void terminate() {
        }

        virtual bool loop() {
            return true;
        }

        virtual void update() {
        }

        virtual void poll_events() {
        }
    };

    class ControllerManager {
        friend class App;

    public:
        static ControllerManager *singleton();

        template<typename TController>
        static TController *get() {
            static std::unique_ptr<TController> controller = TController::create();
            return controller.get();
        }

        template<typename TController>
        void register_controller(std::source_location location = std::source_location::current()) {
            auto new_controller = ControllerManager::get<TController>();
            for (auto existing_controller: m_controllers) {
                rg::guarantee(existing_controller != new_controller,
                              std::format("Trying to register Controller: `{}` twice in file: {}:{}. Please make "
                                          "sure that every Controller is registered exactly once.",
                                          new_controller->name(), location.file_name(), location.line()));
            }
            m_controllers.push_back(new_controller);
        }

    private:
        void initialize();

        void poll_events();

        void terminate();

        bool loop();

        void update();

        std::vector<Controller *> m_controllers;
    };


}

#endif //MATF_RG_PROJECT_CORE_HPP
