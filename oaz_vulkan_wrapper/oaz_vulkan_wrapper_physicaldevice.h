#ifndef OAZ_VULKAN_WRAPPER_PHYSICALDEVICE
#define OAZ_VULKAN_WRAPPER_PHYSICALDEVICE

#include <vector>
#include "vulkan/vulkan.h"

namespace ovw
{
	class PhysicalDeviceManager
	{
	public:
		void findPhysicalDevices();
	private:
		std::vector<VkPhysicalDevice> physicalDevices;
	};
}

#endif