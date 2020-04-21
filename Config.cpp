#include"Config.h"
#include<cassert>
#include<iostream>
//#include<cstring>
void Config::Read(std::string fileName) {
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
				else{
					/* colonPos must be larger than pos */
					assert(colonPos > pos);
					/* extract the useful message from the line */
					subline = line.substr(pos, colonPos - pos);
				}
			}
			/* parse the parameters and values */
			pos = subline.find(" ");
			assert(pos != std::string::npos);
			std::string strParameterName = subline.substr(0, pos);
			std::string strParameterValue = subline.substr(pos + 1, subline.size() - 1);
			values.insert(std::pair<std::string,std::string>(strParameterName, strParameterValue));
		}
		
	}
}

void Config::Print() {
	std::map<std::string, std::string>::iterator idx;

	for (idx = values.begin(); idx != values.end(); ++idx)
	{
		std::cout << (idx->first) << " = " << (idx->second) << std::endl;
	}
}