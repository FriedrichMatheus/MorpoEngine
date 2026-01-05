#include <SDL.h>
#include <unordered_map>

namespace MorpoEngine::Input {

    class Input {
    public:
        static void setKeyIsPressed(const char* key, bool pressed);
        static bool isKeyPressed(const char* key);
    private:
        static std::unordered_map<const char*, bool> s_keyState;
    };

}