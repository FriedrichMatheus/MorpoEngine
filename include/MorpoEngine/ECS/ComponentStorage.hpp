#pragma once
#include <MorpoEngine/ECS/Entity.hpp>
#include <unordered_map>

namespace MorpoEngine::ECS {
    struct IStorage {
        virtual ~IStorage() = default;
        virtual void remove(MorpoEngine::ECS::Entity e) = 0;
    };

    template<typename Component>
    class ComponentStorage final : IStorage {
    public:

        void emplace(Entity e) {
            m_data[e] = Component{};
        }

        Component& get(Entity e) {
            return m_data.at(e);
        }

        void remove(Entity e) override {
            m_data.erase(e);
        }

        const std::unordered_map<Entity, Component>& data() const {
            return m_data;
        }

    private:
        std::unordered_map<Entity, Component> m_data;
    };
}

