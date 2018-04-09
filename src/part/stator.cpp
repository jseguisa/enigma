#include <part/stator.hpp>

namespace part
{

uint8_t stator::encode(uint8_t data)
{
    return scrambler_.encode(data);
}

}
