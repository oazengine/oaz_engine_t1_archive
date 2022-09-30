#ifndef OAZ_VULKAN_WRAPPER_PHYSICALDEVICE
#define OAZ_VULKAN_WRAPPER_PHYSICALDEVICE

#include <vector>
#include <set>
#include <string>

#include "oaz_vulkan_wrapper_instance.h"
#include "oaz_vulkan_wrapper_data.h"
#include "oaz_vulkan_wrapper_surface.h"
#include "oaz_vulkan_wrapper_extension.h"
#include "vulkan/vulkan.h"

#include "spdlog/spdlog.h"


namespace ovw
{
	class PhysicalDeviceManager
	{
	public:
		VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;

		void bindInstance(Instance* pInstance);
		void bindSurface(Surface* pSurface);
		void bindExtension(ExtensionManager* pExtensionManager);
		void findPhysicalDevices();
		void selectFirstGPU();

		
	private:
		Instance* pInstance;
		Surface* pSurface;
		ExtensionManager* pExtensionManager;
		std::vector<VkPhysicalDevice> physicalDevicesQueue;
		
		bool checkPhysicalDeviceSuitability(VkPhysicalDevice iPhysicalDevice);
		bool checkDeviceExtensionSupport(VkPhysicalDevice iPhysicalDevice);
		data::QueueFamilyIndices findQueueFamilies(VkPhysicalDevice iPhysicalDevice);
		data::SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice iPhysicalDevice);
	};
}

#endif