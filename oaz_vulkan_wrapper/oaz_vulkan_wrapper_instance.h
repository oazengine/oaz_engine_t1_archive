#pragma once

#include <iostream>
#include <vector>
#include "vulkan/vulkan.h"
#include "oaz_vulkan_wrapper_validation.h"
#include "oaz_vulkan_wrapper_extension.h"

namespace ovw
{
	class Instance
	{
	public:
		void createVulkanInstance(Validation ovwValidation);
	private:
		VkInstance instance;
		void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);
		static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageType, const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData, void* pUserData);
	};
}
