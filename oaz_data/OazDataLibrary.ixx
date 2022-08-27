module;
#include <string>


export module OazData:Library;

export struct LibraryInfo {
	std::string name;
	unsigned short Major;
	unsigned short Minor;
	unsigned short patch;
};