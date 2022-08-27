#pragma once

#include <string>

namespace oaz {
	struct LibraryInfo {
		std::string name;
		unsigned short Major;
		unsigned short Minor;
		unsigned short patch;
	};
}