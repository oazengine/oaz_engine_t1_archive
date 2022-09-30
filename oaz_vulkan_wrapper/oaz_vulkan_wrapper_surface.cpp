#include "oaz_vulkan_wrapper_surface.h"

namespace ovw
{
	VkResult Surface::createSurfaceByGLFW(Instance* instance, GLFWwindow* window, const VkAllocationCallbacks* allocator)
	{
		if(VkResult result = glfwCreateWindowSurface(instance->instance, window, allocator, &surface); result == VK_SUCCESS)
		{
			spdlog::info("[OAZ_VULKAN_WRAPPER] create surface by GLFW");
		} else
		{
			spdlog::warn("[OAZ_VULKAN_WRAPPER] something was wrong when OVW create a window surface. VkResult value is '{0}'", result);
		}
	}

}