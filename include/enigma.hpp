#pragma once

#include <cstdint>
#include <string>

#include <part/reflector.hpp>
#include <part/stator.hpp>
#include <part/rotor.hpp>
#include <part/rotorset.hpp>

struct enigma
{
    void setInitialConfig(uint8_t, uint8_t, uint8_t);
    std::string encode(const std::string&);

private:
    part::rotorset<part::rotor, part::rotor, part::rotor> rotorset_;
    part::reflector reflector_;
};
