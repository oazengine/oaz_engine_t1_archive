#pragma once

#include <iostream>
#include <vector>
#include "vulkan/vulkan.h"
#include "oaz_vulkan_wrapper_validation.h"
#include "oaz_vulkan_wrapper_extension.h"
#include "oaz_vulkan_wrapper_debugmessenger.h"

namespace ovw
{
	class Instance
	{
	public:
		void createVulkanInstance(Validation ovwValidation, bool isUsingGLFWExtensions);
	private:
		VkInstance instance;
	};
}
