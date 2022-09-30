#ifndef OAZ_VULKAN_WRAPPER_EXTENSION
#define OAZ_VULKAN_WRAPPER_EXTENSION

#include <vector>

namespace ovw::ext
{
	std::vector<const char*> getRequiredExtensionsByGLFW();
}

namespace ovw
{
	class ExtensionManager
	{
	public:
		void addExtensionByName(const char* extensionName);
		std::vector<const char*> neededValidationLayers;

	private:
	};
}

#endif