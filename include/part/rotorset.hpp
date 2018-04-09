#pragma once

#include <cstdint>
#include <tuple>

namespace part
{

template<typename R1, typename R2, typename R3>
struct rotorset
{
    rotorset();
    void setInitialConfig(uint8_t, uint8_t, uint8_t);
    uint8_t encode(uint8_t data);

private:
    std::tuple<R1, R2, R3> rotors_;
    bool isReflectionMode_ = false;
};

template<typename R1, typename R2, typename R3>
rotorset<R1, R2, R3>::rotorset()
{
    rotors_ = std::make_tuple(R1(), R2(), R3());
    auto&& r1 = std::get<0>(rotors_);
    auto&& r2 = std::get<1>(rotors_);
    auto&& r3 = std::get<2>(rotors_);

    r1.setActionCallback(std::bind(&R2::triggerAction, &r2));
    r2.setActionCallback(std::bind(&R3::triggerAction, &r3));
}

template<typename R1, typename R2, typename R3>
void rotorset<R1, R2, R3>::setInitialConfig(uint8_t p1, uint8_t p2, uint8_t p3)
{
    std::get<0>(rotors_).setIndex(p1);
    std::get<1>(rotors_).setIndex(p2);
    std::get<2>(rotors_).setIndex(p3);
}

template<typename R1, typename R2, typename R3>
uint8_t rotorset<R1, R2, R3>::encode(uint8_t data)
{
    auto&& r1 = std::get<0>(rotors_);
    auto&& r2 = std::get<1>(rotors_);
    auto&& r3 = std::get<2>(rotors_);
    auto encodingResult = 0u;

    if(!isReflectionMode_)
    {
        encodingResult = r3.encode(r2.encode(r1.encode(data)));
    }
    else
    {
        encodingResult = r1.encode(r2.encode(r3.encode(data)));
        r1.triggerAction();
    }

    isReflectionMode_ = !isReflectionMode_;
    return encodingResult;
}


}
