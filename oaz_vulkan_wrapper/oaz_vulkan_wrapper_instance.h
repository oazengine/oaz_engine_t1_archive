#pragma once

#include <vector>
#include "oaz_data.h"
#include "vulkan/vulkan.h"
#include "oaz_vulkan_wrapper_validation.h"

namespace oaz
{
	class OVWInstance
	{
	public:
		void createVulkanInstance(OVWValidation ovwValidation);
	private:
		VkInstance instance;
	};
}
