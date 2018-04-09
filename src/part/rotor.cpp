#include <part/rotor.hpp>
#include <scrambler/scrambler.hpp>

namespace part
{

rotor::rotor()
{
    scrambler::scrambler scrambler;
    for (uint8_t i = 0; i < MAX_DATA_SET_SIZE; ++i)
    {
        const auto scrambledValue = scrambler.encode(i);
        nonReflectionData_[i] = scrambledValue;
        reflectionData_[scrambledValue] = i;
    }
}

void rotor::triggerAction()
{
    if((MAX_DATA_SET_SIZE - 1) == index_)
    {
        index_ = 0;
        if (callback_)
        {
            callback_();
        }
        return;
    }
    ++index_;
}

void rotor::setActionCallback(std::function<void()> callback)
{
    callback_ = callback;
}

void rotor::setIndex(uint8_t initialIndex)
{
    index_ = initialIndex;
}

uint8_t rotor::getIndex() const
{
    return index_;
}

uint8_t rotor::encode(uint8_t data)
{
    const auto result = encodeData((isReflectionMode_ ?
        reflectionData_ : nonReflectionData_), data);
    isReflectionMode_ = !isReflectionMode_;
    return result;
}

uint8_t rotor::encodeData(auto&& scramblerLut, uint8_t data)
{
    const auto targetIndex = ((data + index_) % MAX_DATA_SET_SIZE);
    const auto scrambledValue = scramblerLut[targetIndex];

    return ((scrambledValue + MAX_DATA_SET_SIZE) - index_) % MAX_DATA_SET_SIZE;
}

}
