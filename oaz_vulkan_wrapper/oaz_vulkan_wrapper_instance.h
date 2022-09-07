#pragma once

#include <vector>
#include "oaz_data.h"
#include "vulkan/vulkan.h"

namespace oaz
{
	class OVWInstance
	{
	public:
		void createVulkanInstance();
	private:
		VkInstance instance;
	};
}
