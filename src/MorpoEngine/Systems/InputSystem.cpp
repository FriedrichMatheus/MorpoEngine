#include <MorpoEngine/Systems/InputSystem.hpp>
#include <SDL.h>
#include <MorpoEngine/Input/Input.hpp>
#include <MorpoEngine/ECS/Registry.hpp>
#include <MorpoEngine/ECS/Components.hpp>


namespace MorpoEngine::Systems {
    void InputSystem::update(ECS::Registry& registry, float deltaTime) {
        auto& entities = registry.view<ECS::PlayerTag, ECS::Transform>();

        for (auto entity : entities) {
        auto& transform = registry.get<ECS::Transform>(entity);

        float speed = 200.f * deltaTime;

        if (Input::Input::isKeyPressed(SDLK_w)) {
            transform.vec.y -= speed;
        }
        if (Input::Input::isKeyPressed(SDLK_s)) {
            transform.vec.y += speed;
        }
        if (Input::Input::isKeyPressed(SDLK_a)) {
            transform.vec.x -= speed;
        }
        if (Input::Input::isKeyPressed(SDLK_d)) {
            transform.vec.x += speed;
        }
    }
    }
}