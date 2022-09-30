#include "oaz_vulkan_wrapper_extension.h"

#include <vector>
#include <vulkan/vulkan_core.h>
#include "GLFW/glfw3.h"


namespace ovw::ext
{
	std::vector<const char*> getRequiredExtensionsByGLFW()
	{
        uint32_t glfwExtensionCount = 0;
        const char** glfwExtensions;
        glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

        std::vector<const char*> extensions(glfwExtensions, glfwExtensions + glfwExtensionCount);

        return extensions;
	}
}

namespace ovw
{
	void ExtensionManager::addExtensionByName(const char* extensionName)
	{
		this->neededValidationLayers.push_back(extensionName);
	}

}