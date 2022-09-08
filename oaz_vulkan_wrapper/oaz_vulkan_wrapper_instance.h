#pragma once

#include <vector>
#include "vulkan/vulkan.h"
#include "oaz_vulkan_wrapper_validation.h"

namespace vkw
{
	class OVWInstance
	{
	public:
		void createVulkanInstance(OVWValidation ovwValidation);
	private:
		VkInstance instance;
	};
}
