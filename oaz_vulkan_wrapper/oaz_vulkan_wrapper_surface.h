#ifndef OAZ_VULKAN_WRAPPER_SURFACE
#define OAZ_VULKAN_WRAPPER_SURFACE

#include "vulkan/vulkan.h"
#include "oaz_vulkan_wrapper_instance.h"
#include "GLFW/glfw3.h"

namespace ovw
{
	class Surface
	{
	public:
		VkResult createSurfaceByGLFW(Instance *instance, GLFWwindow* window, const VkAllocationCallbacks* allocator);
		VkSurfaceKHR surface;
	private:
	};
}

#endif
