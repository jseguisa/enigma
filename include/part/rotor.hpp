#pragma once

#include <cstdint>
#include <functional>

namespace part
{

struct rotor
{
    rotor();
    uint8_t encode(uint8_t data);
    void triggerAction();
    void setActionCallback(std::function<void()> callback);
    void setIndex(uint8_t initialIndex);
    uint8_t getIndex() const;

private:
    static constexpr auto MAX_DATA_SET_SIZE = 26;

    uint8_t encodeData(auto&& scramblerLut, uint8_t data);

    std::function<void()> callback_ = nullptr;
    uint8_t index_ = 0;
    bool isReflectionMode_ = false;
    std::array<uint8_t, MAX_DATA_SET_SIZE> nonReflectionData_;
    std::array<uint8_t, MAX_DATA_SET_SIZE> reflectionData_;
};

}
