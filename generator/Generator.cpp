#include"Generator.h"
#include<iostream>
#include<vector>
#include<fstream>

std::string Generator::GenerateRequestFile(std::string inputfileName, std::string trackIdxMaxStr, std::string dataIdxMaxStr) {
	std::string outputfileName;
	
	size_t pos = inputfileName.find_last_of("/");
	if (pos != std::string::npos) {
		outputfileName = inputfileName.substr(pos+1, inputfileName.size());
	}
	outputfileName = "./requests/requestFiles/" + outputfileName.substr(0,outputfileName.find("."))+"_"+trackIdxMaxStr+"_"+dataIdxMaxStr+outputfileName.substr(outputfileName.find("."),outputfileName.size());

	int trackIdxMax = atoi(trackIdxMaxStr.c_str());
	int dataIdxMax = atoi(dataIdxMaxStr.c_str());
	srand(time(NULL));
	std::string line;
	std::string subline;
	std::ifstream inputFile(inputfileName.c_str());
	std::ofstream ouputFile(outputfileName.c_str());
	if (inputFile.is_open() && ouputFile.is_open()) {
		while (!inputFile.eof()) {
			getline(inputFile, line);
			size_t pos = line.find("UPDATE");
			if (pos == std::string::npos || pos != 0) {
				continue;
			}
			else {
				std::string goal = "usertable ";
				pos = line.find(goal);
				pos += goal.size() + 4;
				std::string dataStr = "";
				while (line[pos] != ' ') {
					dataStr = dataStr + line[pos++];
				}
				char* z;
				uint64_t data = strtoull(dataStr.c_str(), &z, 10);
				int trackIdx = rand() % trackIdxMax;
				int dataIdx = rand() % dataIdxMax;
				ouputFile << "W " << trackIdx << " " << dataIdx << " " << data << std::endl;
			}
		}
	}
	else {
		std::cout << "Could not open file." << std::endl;
		exit(1);
	}
	return outputfileName;
}

void Generator::GenerateInformation(){
    std::fstream outFile;

    std::vector<std::string> Distribution;
    Distribution.push_back("uniform");
    Distribution.push_back("zipf");
    std::vector<std::string> dataN;
    dataN.push_back("1E5");
    dataN.push_back("1E6");
    dataN.push_back("1E7");
    std::vector<std::string> length;
    length.push_back("512");
    length.push_back("1024");
    length.push_back("2048");
    length.push_back("4096");
    std::vector<std::string> MoudleName;
    MoudleName.push_back("Naive");
    MoudleName.push_back("DCW");
    MoudleName.push_back("Flip_N_Write");
    MoudleName.push_back("MOutOfNWrite_8");
    MoudleName.push_back("MOutOfNWrite_16");
    MoudleName.push_back("Permutation_Write");
    MoudleName.push_back("Combine_PW_FNW");

    for(int i = 0; i < Distribution.size(); i++){
        for(int j = 0; j < dataN.size(); j++){
            std::string outFileName = "outputFile/information/" + Distribution[i] + "_" + dataN[j] + ".csv" ;
            outFile.open(outFileName, std::ios::out);
            outFile << "Distribution" << "," << Distribution[i] << std::endl;
            outFile << "#Data" << "," << dataN[j] << std::endl;
            outFile << "#Requests" << "," << "1E7" << std::endl;
            outFile << "#Racetrack" << "," << "1" << std::endl;
            outFile << "\n\n";
            

            for(int k = 0; k < length.size(); k++){
                outFile << "Track capacity" << "," << length[k] << std::endl;
                outFile << "\n";
                outFile << "Mode" << "," << "Shift" << "," << "Detection" << "," << "Remove" << "," << "Injection" << "," << "Track size" << "," << "Times (sec.)" << std::endl;
                for(int m = 0; m < MoudleName.size(); m++){
                    outFile << MoudleName[m] << ",";
                    std::string inResultFileName = "outputFile/results/" + MoudleName[m] + "_" + length[k] + "_" + Distribution[i] + "_" + dataN[j] + ".txt";
                    std::string inParamsFileName = "outputFile/params/" + MoudleName[m] + "_" + length[k] + ".txt";
                    std::ifstream inResultFile(inResultFileName.c_str());
                    std::ifstream inParamsFile(inParamsFileName.c_str());
                    std::string line;
                    size_t pos;
                    double weight[4]={0.5, 0.1, 0.8, 1.0};
                    double time = 0;
                    int tracklength = 0;
                    int NSDR=0;
                    if(inResultFile.is_open()){
                        for(int i = 0; i < 4; i++){
                            getline(inResultFile, line);
                            pos = line.find(" ");
                            line = line.substr(pos + 1, line.size());
                            outFile << line << ","; 
                            time += (atof(line.c_str())*weight[i]);
                        }
                    }
                    else{
                        std::cout<< "Could not open input file = \" "<< inResultFileName << " \"" << std::endl;
                        exit(1);
                    }

                    if(inParamsFile.is_open()){
                        while(!inParamsFile.eof()){

                            getline(inParamsFile, line);
                            std::string f = "racetrackLength = ";
                            
                            pos = line.find(f);
                            if(pos != std::string::npos) {
                                line = line.substr(pos + f.size(), line.size());
                                tracklength = atoi(line.c_str());
                            }
                            f = "NSDR = ";
                            pos = line.find(f);
                            if(pos != std::string::npos) {
                                line = line.substr(pos + f.size(), line.size());
                                NSDR = atoi(line.c_str());
                                
                            }
                        }
                        tracklength -= NSDR;
                        outFile << tracklength << "+";
                        outFile << NSDR << ","; 
                    }
                    else {
                        std::cout<< "Could not open input file = \" "<< inParamsFileName << " \"" << std::endl;
                            exit(1);
                    }
                    outFile.precision (10);
                    outFile << std::dec << time << std::endl; 
                    inResultFile.close();
                    inParamsFile.close();
                }
                outFile << "\n\n";
            }
            outFile.close();
        }    
    }
}
