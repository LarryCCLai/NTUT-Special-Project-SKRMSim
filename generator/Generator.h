#ifndef GENERATOR_H
#define GENERATOR_H
#include<string>
class Generator{
private:
public:
    static std::string GenerateRequestFile(std::string inputfileName, std::string trackIdxMaxStr, std::string dataIdxMaxStr);
	static void GenerateInformation();
    
};
#endif //GENERATOR_H