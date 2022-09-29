#ifndef OAZ_DATA_H
#define OAZ_DATA_H

#include <string>

namespace oaz::data {
	// Graphics API의 종류를 담은 Enum
	enum class GraphicsAPItype {
		Vulkan,
		DirectX,
		OpenGL,
		Metal
	};

	// Window Library의 종류를 담은 Enum
	enum class WindowLibraryType {
		GLFW,
		SDL,
		OazWindow
	};

	enum class OazResult
	{
		OAZ_SUCCESS = 0,
		OAZ_NOT_READY = 1,
		OAZ_TIMEOUT = 2,
	};

	struct SoftwareVersion {
		unsigned short major;
		unsigned short minor;
		unsigned short patch;
	};

	// Oaz Application에서 사용하는 GraphicsAPI의 정보를 담은 구조체 
	struct GraphicsAPI {
		GraphicsAPItype graphicsAPItype;
		SoftwareVersion softwareVersion;
	};

	// Oaz Application에서 사용하는 Window Library의 정보를 담은 구조체
	struct WindowLibrary {
		WindowLibraryType windowLibraryType;
		SoftwareVersion softwareVersion;
	};

}
#endif