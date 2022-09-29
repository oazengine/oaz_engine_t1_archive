#ifndef OAZ_VULKAN_WRAPPER_EXTENSION
#define OAZ_VULKAN_WRAPPER_EXTENSION

#include <vector>

namespace ovw::ext
{
	std::vector<const char*> getRequiredExtensionsByGLFW();
}

#endif