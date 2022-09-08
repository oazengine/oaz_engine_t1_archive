#pragma once

#include <vector>
#include "vulkan/vulkan.h"
#include "oaz_vulkan_wrapper_validation.h"

namespace vkw
{
	class Instance
	{
	public:
		void createVulkanInstance(Validation ovwValidation);
	private:
		VkInstance instance;
	};
}
