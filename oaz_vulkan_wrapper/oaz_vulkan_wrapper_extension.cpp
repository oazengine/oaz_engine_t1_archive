#include "oaz_vulkan_wrapper_extension.h"

#include <vector>
#include <vulkan/vulkan_core.h>
#include "GLFW/glfw3.h"


namespace oaz
{
	std::vector<const char*> getRequiredExtensionsByGLFW()
	{
        uint32_t glfwExtensionCount = 0;
        const char** glfwExtensions;
        glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

        std::vector<const char*> extensions(glfwExtensions, glfwExtensions + glfwExtensionCount);

        /*
        if (enableValidationLayers) {
            extensions.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
        }*/

        return extensions;
	}
}

