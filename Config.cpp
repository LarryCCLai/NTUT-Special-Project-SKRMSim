#include"Config.h"
#include<cassert>
#include<iostream>

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
	else {
		std::cout << "Could not read configuration file: "<< this->fileName << std::endl;
		exit(1);
	}
}

std::string Config::GetFileName() {
	return this->fileName;
}

bool Config::KeyExists(std::string key) {
	std::map<std::string, std::string>::iterator idx;

	if (values.empty()) {
		return false;
	}

	idx = values.find(key);

	if (idx == values.end()) {
		return false;
	}

	return true;
}

uint64_t Config::GetValueUL(std::string key) {
	std::map<std::string, std::string>::iterator idx;
	uint64_t value;
	if (values.empty()) {
		std::cerr << "Configuration has not been read yet." << std::endl;
		return std::numeric_limits<uint64_t>::max();
	}
	idx = values.find(key);

	if (!KeyExists(key) && !warned.count(key)){
		std::cout << "Config: Warning: Key [" << key << "] is not set. Using '-1' as the default. Please configure this value if this is wrong." << std::endl;
		warned.insert(key);
	}

	if (idx == values.end()) {
		value = std::numeric_limits<uint64_t>::max();
	}
	else {
		value = strtoul(idx->second.c_str(), NULL, 10);
	}
	return value;
}

void Config::GetValueUL(std::string key, uint64_t& value) {
	std::map<std::string, std::string>::iterator idx;
	if (values.empty()) {
		std::cerr << "Configuration has not been read yet." << std::endl;
		value = std::numeric_limits<uint64_t>::max();
	}
	idx = values.find(key);

	if (!KeyExists(key) && !warned.count(key)) {
		std::cout << "Config: Warning: Key [" << key << "] is not set. Using '-1' as the default. Please configure this value if this is wrong." << std::endl;
		warned.insert(key);
	}

	if (idx == values.end()) {
		value = std::numeric_limits<uint64_t>::max();
	}
	else {
		value = strtoul(idx->second.c_str(), NULL, 10);
	}
}

int  Config::GetValue(std::string key) {
	std::map<std::string, std::string>::iterator idx;
	int value;
	if (values.empty()) {
		std::cerr << "Configuration has not been read yet." << std::endl;
		return std::numeric_limits<uint64_t>::max();
	}
	idx = values.find(key);

	if (!KeyExists(key) && !warned.count(key)) {
		std::cout << "Config: Warning: Key [" << key << "] is not set. Using '-1' as the default. Please configure this value if this is wrong." << std::endl;
		warned.insert(key);
	}

	if (idx == values.end()) {
		value = std::numeric_limits<uint64_t>::max();
	}
	else {
		value = strtoul(idx->second.c_str(), NULL, 10);
	}
	return value;
}

void Config::GetValue(std::string key, int& value) {
	std::map<std::string, std::string>::iterator idx;
	if (values.empty()) {
		std::cerr << "Configuration has not been read yet." << std::endl;
		value = std::numeric_limits<uint64_t>::max();
	}
	idx = values.find(key);

	if (!KeyExists(key) && !warned.count(key)) {
		std::cout << "Config: Warning: Key [" << key << "] is not set. Using '-1' as the default. Please configure this value if this is wrong." << std::endl;
		warned.insert(key);
	}

	if (idx == values.end()) {
		value = std::numeric_limits<uint64_t>::max();
	}
	else {
		value = strtoul(idx->second.c_str(), NULL, 10);
	}
}

void Config::SetValue(std::string key, std::string value) {
	std::map<std::string, std::string>::iterator idx;

	idx = values.find(key);

	if (idx != values.end()) {
		values.erase(idx);
	}
	values.insert(std::pair<std::string, std::string>(key, value));
}

std::string Config::GetString(std::string key) {
	std::map<std::string, std::string>::iterator idx;
	std::string value;
	if (values.empty()) {
		std::cerr << "Configuration has not been read yet." << std::endl;
		return "";
	}
	idx = values.find(key);

	if (!KeyExists(key) && !warned.count(key)) {
		std::cout << "Config: Warning: Key [" << key << "] is not set. Using '-1' as the default. Please configure this value if this is wrong." << std::endl;
		warned.insert(key);
	}

	if (idx == values.end()) {
		value = "";
	}
	else {
		value = idx->second;
	}
	return value;
}

void  Config::GetString(std::string key, std::string& value) {

	if (!KeyExists(key) && !warned.count(key)) {
		std::cout << "Config: Warning: Key [" << key << "] is not set. Using '-1' as the default. Please configure this value if this is wrong." << std::endl;
		warned.insert(key);
	}
	else if (KeyExists(key)) {
		value = GetString(key);
	}
}

void  Config::SetString(std::string key, std::string value) {
	values.insert(std::pair<std::string, std::string>(key, value));
}

void Config::Print() {
	std::map<std::string, std::string>::iterator idx;

	for (idx = values.begin(); idx != values.end(); ++idx)
	{
		std::cout << (idx->first) << " = " << (idx->second) << std::endl;
	}
}

