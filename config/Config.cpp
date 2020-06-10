#include"Config.h"
#include<cassert>
#include<iostream>
#include<limits>
void Config::Read(std::string fileName) {
	
	size_t pos; 
	this->fileName = fileName;
	pos	= this->fileName.find_last_of("/");
	if (pos != std::string::npos) {
		this->fileName = this->fileName.substr(pos+1,this->fileName.size());
	}
	this->fileNameExtension = this->fileName.substr(this->fileName.find('.')+1,this->fileName.size());
	this->fileName = this->fileName.substr(0,this->fileName.find('.'));

	std::string line;
	std::string subline;
	std::ifstream configFile(fileName.c_str());

	if (configFile.is_open()) {
		while (!configFile.eof()) {
			getline(configFile, line);
			/* find the first character that is not space, tab, return */
			pos = line.find_first_not_of("\t\r\n");
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
std::string Config::GetFileNameExtension(){
	return this->fileNameExtension;
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
		return std::numeric_limits<int>::max();
	}
	idx = values.find(key);

	if (!KeyExists(key) && !warned.count(key)) {
		std::cout << "Config: Warning: Key [" << key << "] is not set. Using '-1' as the default. Please configure this value if this is wrong." << std::endl;
		warned.insert(key);
	}

	if (idx == values.end()) {
		value = std::numeric_limits<int>::max();
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
		value = std::numeric_limits<int>::max();
	}
	idx = values.find(key);

	if (!KeyExists(key) && !warned.count(key)) {
		std::cout << "Config: Warning: Key [" << key << "] is not set. Using '-1' as the default. Please configure this value if this is wrong." << std::endl;
		warned.insert(key);
	}

	if (idx == values.end()) {
		value = std::numeric_limits<int>::max();
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

void Config::GetBool(std::string key, bool& value){
	std::map<std::string, std::string>::iterator idx;
	if (values.empty()) {
		std::cerr << "Configuration has not been read yet." << std::endl;
		exit(1);
	}
	idx = values.find(key);

	if (!KeyExists(key) && !warned.count(key)) {
		warned.insert(key);
		value=false;
	}
	else{
		if(idx->second=="true"){
			value = true;
		}
		else{
			value = false;
		}
	}
}

void  Config::GetMode(std::string key, WriteMode& value) {
	std::map<std::string, std::string>::iterator idx;
	int V;
	if (values.empty()) {
		std::cerr << "Configuration has not been read yet." << std::endl;
	}
	idx = values.find(key);

	if (!KeyExists(key) && !warned.count(key)) {
		std::cout << "Config: Warning: Key [" << key << "] is not set. Using '-1' as the default. Please configure this value if this is wrong." << std::endl;
		warned.insert(key);
	}

	if (idx == values.end()) {
		V = std::numeric_limits<int>::max();
	}
	else {
		V = strtoul(idx->second.c_str(), NULL, 10);
	}
	if (V == 0) {
		value = WriteMode::Naive;
	}
	else if (V == 1) {
		value = WriteMode::DCW;
	}
	else if (V == 2) {
		value = WriteMode::Flip_N_Write;
	}
	else if (V == 3) {
		value = WriteMode::Permutation_Write;
	}
	else if (V == 4) {
		value = WriteMode::M_Out_Of_N_Write;
	}
	else if (V == 5) {
		value = WriteMode::Combine_PW_FNW;
	}
	else {
		std::cout << "[error] Config: Get write mode value." << std::endl;
		exit(1);
	}
}

void Config::Print() {
	std::map<std::string, std::string>::iterator idx;

	for (idx = values.begin(); idx != values.end(); ++idx)
	{
		std::cout << (idx->first) << " = " << (idx->second) << std::endl;
	}
}

