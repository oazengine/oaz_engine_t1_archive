#ifndef OAZ_VULKAN_WRAPPER_INSTANCE
#define OAZ_VULKAN_WRAPPER_INSTANCE

#include <iostream>
#include <vector>
#include "vulkan/vulkan.h"
#include "oaz_vulkan_wrapper_validation.h"
#include "oaz_vulkan_wrapper_extension.h"
#include "oaz_vulkan_wrapper_debugmessenger.h"
#include "spdlog/spdlog.h"
#include <vector>

namespace ovw
{
	class Instance
	{
	public:
		VkInstance instance;

		void createVulkanInstance(Validation* ovwValidation, bool isUsingGLFWExtensions);
		void cleanUpVulkanInstance();

		~Instance();
	private:

	};
}

#endif 