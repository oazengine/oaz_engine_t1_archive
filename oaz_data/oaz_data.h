#ifndef OAZ_DATA_H
#define OAZ_DATA_H

#include <string>

namespace oaz {
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