#ifndef OAZ_DATA_H
#define OAZ_DATA_H

#include <string>

namespace oaz::data {
	// Graphics API�� ������ ���� Enum
	enum class GraphicsAPItype {
		Vulkan,
		DirectX,
		OpenGL,
		Metal
	};

	// Window Library�� ������ ���� Enum
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

	// Oaz Application���� ����ϴ� GraphicsAPI�� ������ ���� ����ü 
	struct GraphicsAPI {
		GraphicsAPItype graphicsAPItype;
		SoftwareVersion softwareVersion;
	};

	// Oaz Application���� ����ϴ� Window Library�� ������ ���� ����ü
	struct WindowLibrary {
		WindowLibraryType windowLibraryType;
		SoftwareVersion softwareVersion;
	};

}
#endif