#include <MorpoEngine/ECS/Registry.hpp>


namespace MorpoEngine::Systems {
    class InputSystem {
    public:
        void update(ECS::Registry& registry, float deltaTime);
    };
}