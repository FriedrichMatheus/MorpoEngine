#pragma once
#include <cstdint>

namespace MorpoEngine::ECS {
    using Entity = uint32_t;
    static constexpr Entity MAX_ENTITY = 5000;
    static constexpr Entity INVALID_ENTITY = 0;
}