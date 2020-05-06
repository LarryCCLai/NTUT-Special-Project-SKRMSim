#include<cassert>
#include<iostream>
#include <fstream>
#include<ctime>
#include"Request.h"
Request::Request() {
	this->operation = "R";
	this->trackIdx = -1;
	this->dataIdx = -1;
	this->data = -1;
}

Request::Request(std::string operation, int trackIdx, int dataIdx, uint64_t data) {
	this->operation = operation;
	this->trackIdx = trackIdx;
	this->dataIdx = dataIdx;
	this->data = data;
}

Request::~Request() {

}

std::string Request::TransFormat(std::string inputfileName, std::string trackIdxMaxStr, std::string dataIdxMaxStr) {
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
	/*
	int trackIdxMax = atoi(trackIdxMaxStr.c_str());
	int dataIdxMax = atoi(dataIdxMaxStr.c_str());
	std::string outputfileName;
	size_t pos = inputfileName.find_last_of("/");
	if (pos != std::string::npos) {
		outputfileName = inputfileName.substr(pos + 1, inputfileName.size());
	}
	
	outputfileName = "./requests/requests_" + outputfileName.substr(0, outputfileName.find(".")) + "_" + trackIdxMaxStr + "_" + dataIdxMaxStr + outputfileName.substr(outputfileName.find("."), outputfileName.size());
	srand(time(NULL));
	std::string line;
	std::string subline;
	std::ifstream inputFile(inputfileName.c_str());
	std::ofstream ouputFile(outputfileName.c_str());
	if (inputFile.is_open() && ouputFile.is_open()) {
		while (!inputFile.eof()) {
			getline(inputFile, line);
			size_t pos = line.find("INSERT");
			if (pos != 0) {
				continue;
			}
			else {
				for (int i = 0; i < 128; i++) {
					std::string goal = "field" + std::to_string(i) + "=";
					pos = line.find(goal);
					pos += goal.size();
					std::string dataStr = line.substr(pos, 8);
					uint64_t data = 0;
					for (int j = 7; j >= 0; j--) {
						char ch = dataStr[j];
						uint64_t part = static_cast<uint64_t>(ch);
						data += (part << ((7 - j) * 8));
					}
					int trackIdx = rand() % trackIdxMax;
					int dataIdx = rand() % dataIdxMax;
					ouputFile << "W " << trackIdx << " " << dataIdx << " " << data << std::endl;
				}
			}
		}
	}
	else {
		std::cout << "Could not open file." << std::endl;
		exit(1);
	}
	return outputfileName;*/
}
//Use yet.
//================================================================
RequestQueue::RequestQueue() {

}

RequestQueue::~RequestQueue() {

}

void RequestQueue::Read(std::string fileName) {
	std::string line;
	std::string subline;
	std::ifstream configFile(fileName.c_str());
	this->fileName = fileName;
	if (configFile.is_open()) {
		while (!configFile.eof()) {
			getline(configFile, line);
			/* find the first character that is not space, tab, return */
			size_t pos = line.find_first_not_of("\t\r\n");
			/* if not found, the line is empty. just skip it */
			if (pos == std::string::npos) {
				continue;
			}
			else if (line[pos] == ';') {/* else, check whether the first character is the comment flag. */
				continue;				/* if so, skip it */
			}
			else {
				/* find the position of the first ';' */
				size_t colonPos = line.find_first_of(";");
				/* if there is no ';', extract all */
				if (colonPos == std::string::npos) {
					subline = line.substr(pos);
				}
				else {
					/* colonPos must be larger than pos */
					assert(colonPos > pos);
					/* extract the useful message from the line */
					subline = line.substr(pos, colonPos - pos);
				}
			}
			Request* request = new Request();
			
			
			std::string::size_type sz = 0;
			pos = subline.find(" ");
			assert(pos != std::string::npos);
			request->operation = subline.substr(0, pos);
			subline = subline.substr(pos + 1, subline.size());

			pos = subline.find(" ");
			assert(pos != std::string::npos);
			request->trackIdx = std::stoull(subline.substr(0, pos), &sz, 0);
			subline = subline.substr(sz+1);

			pos = subline.find(" ");
			assert(pos != std::string::npos);
			request->dataIdx = std::stoi(subline.substr(0, pos), &sz, 0);
			subline = subline.substr(sz+1);

			pos = subline.find(" ");
			assert(pos == std::string::npos);
			request->data = std::stoull(subline.substr(0, pos), &sz, 0);

			this->requests.push(request);
		}
	}
	else {
		std::cout << "Could not read configuration file: " << this->fileName << std::endl;
		exit(1);
	}
}

Request* RequestQueue::getNextRequest() {
	if (!requests.empty()) {
		Request* request = requests.front();
		requests.pop();
		return request;
	}
	else {
		return nullptr;
	}
}

void RequestQueue::getNextRequest(Request** request) {
	if (!requests.empty()) {
		*request = requests.front();
		requests.pop();
	}
	else {
		*request = nullptr;
	}
}
//================