#pragma once
#include <MorpoEngine/ECS/Entity.hpp>
#include <MorpoEngine/ECS/ComponentStorage.hpp>
#include <cstdint>
#include <unordered_map>
#include <typeindex>
#include <memory>

namespace MorpoEngine::ECS {    
    class Registry {
    public:
        Entity create() {
            if(m_nextId >= MAX_ENTITY) {
                return INVALID_ENTITY;
            }
            return ++m_nextId;
        }

        void destroy(Entity e) {
            for (auto& [_, storage] : m_storages) {
                storage->remove(e);
            }
        }
        
        template<typename Component>
        void emplace(Entity e) {
            getStorage<Component>().emplace(e);
        }

        template<typename Component>
        bool has(Entity e) {
            return getStorage<Component>().has(e);
        }

        template<typename Component>
        Component& get(Entity e) {
            return getStorage<Component>().get(e);
        }

        template<typename Component>
        void remove(Entity e) {
            getStorage<Component>().remove(e);
        }

        template<typename... Components>
        std::vector<Entity> view() {
            std::vector<Entity> result;

            auto& firstStorage = getStorage<typename std::tuple_element<0, std::tuple<Components...>>:: type>().data();

            for(const auto& [entity, _] : firstStorage) {
                if((has<Components>(entity) && ...)) {
                    result.push_back(entity);
                }
            }

            return result;
        }

    private:
        template<typename Component>
        ComponentStorage<Component>& getStorage() {
            auto type = std::type_index(typeid(Component));

            if(!m_storages.contains(type)) {
                m_storages[type] = std::make_unique<ComponentStorage<Component>>();
            }

            return *static_cast<ComponentStorage<Component>*>(m_storages[type].get());
        }

    private:
        Entity m_nextId = 0;
        std::unordered_map<std::type_index, std::unique_ptr<IStorage>> m_storages;
    };
}