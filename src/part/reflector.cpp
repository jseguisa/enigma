#include <part/reflector.hpp>

namespace
{
constexpr auto MAX_DATA_SET_SIZE = 26;
constexpr auto REFLECTION_OFFSET = 13;
}

namespace part
{

uint8_t reflector::encode(uint8_t data)
{
    return (data + REFLECTION_OFFSET) % MAX_DATA_SET_SIZE;
}

}
