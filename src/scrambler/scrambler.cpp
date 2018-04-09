#include <scrambler/scrambler.hpp>

namespace
{
constexpr auto MOD_CYCLE = 13u;
}

namespace scrambler
{

uint8_t scrambler::encode(uint8_t data)
{
    const auto cycledNum = (data % MOD_CYCLE);
    const unsigned quotient = (data / MOD_CYCLE);
    return (cycledNum * 2) + quotient;
}

}
