#include <iostream>
#include <cstdint>
#include <vector>
#include <algorithm>

#include <enigma.hpp>

int main(int argc, char** argv)
{
    enigma myEnigma;
    myEnigma.setInitialConfig(25, 25, 10);

    const std::string data = "supercalifragilisticexpialidocious";
    std::cout << "original: " << data << std::endl;
    auto result = myEnigma.encode(data);
    std::cout << "encrypted: " << result << std::endl;
    
    myEnigma.setInitialConfig(25, 25, 10);
    result = myEnigma.encode(result);
    std::cout << "recovered: " << result << std::endl;

    return 0;
}