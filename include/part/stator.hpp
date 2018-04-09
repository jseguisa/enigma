#pragma once

#include <cstdint>
#include <scrambler/scrambler.hpp>

namespace part
{

struct stator
{
    uint8_t encode(uint8_t data);

private:
    scrambler::scrambler scrambler_;
};

}
