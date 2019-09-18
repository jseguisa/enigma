#include <iostream>
#include <cstdint>
#include <array>
#include <cstdlib>
#include <algorithm>


#include <enigma.hpp>

int main(int argc, char** argv)
{
    enigma myEnigma;
	unsigned long dials[3];
	
	if (4 != argc)
	{
		std::cout << "Invalid Number of Dials!!!" << std::endl;
		return EXIT_FAILURE;
	}
	
	for (auto i = 1; i < argc; ++i)
	{
		auto dialNum = strtoul(argv[i], NULL, 10);
		if (dialNum < 1 || dialNum > 26)
		{
			std::cout << "Invalid Value of a Dial" << std::endl;
			return EXIT_FAILURE;
		}
			
		dials[i - 1] = dialNum;
	}

	myEnigma.setInitialConfig(dials[0], dials[1], dials[2]);
    const std::string data = "supercalifragilisticexpialidocious";
    std::cout << "original: " << data << std::endl;
    auto result = myEnigma.encode(data);
    std::cout << "encrypted: " << result << std::endl;
    
    myEnigma.setInitialConfig(dials[0], dials[1], dials[2]);
    result = myEnigma.encode(result);
    std::cout << "recovered: " << result << std::endl;

    return EXIT_SUCCESS;
}