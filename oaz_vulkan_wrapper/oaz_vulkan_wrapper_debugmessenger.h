#ifndef OAZ_VULKAN_WRAPPER_DEBUGMESSENGER
#define OAZ_VULKAN_WRAPPER_DEBUGMESSENGER

#include "vulkan/vulkan.h"
#include "spdlog/spdlog.h"

namespace ovw::dm
{
	void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);
	VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageType, const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData, void* pUserData);
}

#endif
