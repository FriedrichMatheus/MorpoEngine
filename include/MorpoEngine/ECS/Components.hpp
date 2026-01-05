#pragma once

namespace MorpoEngine::ECS {
    struct Vector {
        float x = 0.f;
        float y = 0.f;
    };

    struct Transform {
        Vector vec;
    };

    struct Velocity {
        float dx = 0.f;
    };

    struct PlayerTag {};
}

