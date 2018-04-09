#include <enigma.hpp>
#include <algorithm>
#include <iostream>

void enigma::setInitialConfig(uint8_t p1, uint8_t p2, uint8_t p3)
{
    rotorset_.setInitialConfig(p1, p2, p3);
}

std::string enigma::encode(const std::string& data)
{
    const unsigned char OFFSET = static_cast<unsigned char>('a');
    std::string encodedData;
    std::transform(
        data.cbegin(),
        data.cend(),
        std::back_inserter(encodedData),
        [this](unsigned char charData)
        {
            const auto dataToBeEncoded = std::tolower(charData) - OFFSET;
            auto result = rotorset_.encode(dataToBeEncoded);
            result = reflector_.encode(result);
            result = rotorset_.encode(result);
            return (result + OFFSET);
        });
    return encodedData;
}
