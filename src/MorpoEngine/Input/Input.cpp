#include <MorpoEngine/Input/Input.hpp>

namespace MorpoEngine::Input {
    std::unordered_map<const char*, bool> Input::s_keyState;

    void Input::setKeyIsPressed(const char* key, bool pressed) {
        s_keyState[key] = pressed;
    }

    bool Input::isKeyPressed(const char* key) {
        return s_keyState[key];
    }
}