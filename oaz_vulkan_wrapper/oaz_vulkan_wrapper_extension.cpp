#include "oaz_vulkan_wrapper_extension.h"

#include <vector>
#include <vulkan/vulkan_core.h>
#include "GLFW/glfw3.h"


namespace vkw
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

