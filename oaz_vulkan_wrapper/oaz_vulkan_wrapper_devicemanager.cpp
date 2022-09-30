#include "oaz_vulkan_wrapper_devicemanager.h"


namespace ovw
{
	void PhysicalDeviceManager::bindInstance(Instance* pInstance)
	{
		this->pInstance = pInstance;
	}

	void PhysicalDeviceManager::bindSurface(Surface* pSurface)
	{
		this->pSurface = pSurface;
	}

	void PhysicalDeviceManager::bindExtension(ExtensionManager* pExtensionManager)
	{
		this->pExtensionManager = pExtensionManager;
	}




	void PhysicalDeviceManager::findPhysicalDevices()
	{
		uint32_t deviceCount = 0;
		vkEnumeratePhysicalDevices(pInstance->instance, &deviceCount, nullptr);

		if(deviceCount == 0)
		{
			throw std::runtime_error("[OAZ_VULKAN_WRAPPER] failed to find GPUs with Vulkan support");
		}
		physicalDevicesQueue.resize(deviceCount);
		vkEnumeratePhysicalDevices(pInstance->instance, &deviceCount, physicalDevicesQueue.data());
	}

	void PhysicalDeviceManager::selectFirstGPU()
	{
		if(physicalDevicesQueue.empty())
		{
			throw std::runtime_error("[OAZ_VULKAN_WRAPPER] There are no physical devices. ");
		}

		for(const auto& iPhysicalDevice: physicalDevicesQueue)
		{
			if (checkPhysicalDeviceSuitability(iPhysicalDevice))
			{
				this->physicalDevice = iPhysicalDevice;
				VkPhysicalDeviceProperties physicalDeviceProperties;
				vkGetPhysicalDeviceProperties(this->physicalDevice, &physicalDeviceProperties);
				spdlog::info("[OAZ_VULKAN_WRAPPER] selected physical device: {0}", physicalDeviceProperties.deviceName);
				
				break;
			}
		}
		
		if(this->physicalDevice == VK_NULL_HANDLE)
		{
			throw std::runtime_error("[OAZ_VULKAN_WRAPPER] failed to find a suitable GPU");
		}
		
	}

	
	bool PhysicalDeviceManager::checkPhysicalDeviceSuitability(VkPhysicalDevice iPhysicalDevice)
	{
		data::QueueFamilyIndices indices = findQueueFamilies(iPhysicalDevice);
		bool extensionsSupported = checkDeviceExtensionSupport(iPhysicalDevice);

		bool swapChainAdequate = false;
		if(extensionsSupported)
		{
			data::SwapChainSupportDetails swapChainSupport = querySwapChainSupport(iPhysicalDevice);
			swapChainAdequate = !swapChainSupport.formats.empty() && !swapChainSupport.presentModes.empty();
		}

		return indices.isComplete() && extensionsSupported && swapChainAdequate;
	}

	data::QueueFamilyIndices PhysicalDeviceManager::findQueueFamilies(VkPhysicalDevice iPhysicalDevice)
	{
		data::QueueFamilyIndices indices;
		uint32_t queueFamilyCount = 0;
		vkGetPhysicalDeviceQueueFamilyProperties(iPhysicalDevice, &queueFamilyCount, nullptr);

		std::vector<VkQueueFamilyProperties> queueFamilies(queueFamilyCount);
		vkGetPhysicalDeviceQueueFamilyProperties(iPhysicalDevice, &queueFamilyCount, queueFamilies.data());

		int i = 0;
		for (const auto& queueFamily : queueFamilies)
		{
			if(queueFamily.queueFlags & VK_QUEUE_GRAPHICS_BIT)
			{
				indices.graphicsFamily = i;
			}

			VkBool32 presentSupport = false;
			vkGetPhysicalDeviceSurfaceSupportKHR(iPhysicalDevice, i, pSurface->surface, &presentSupport);

			if(presentSupport)
			{
				indices.presentFamily = i;
			}
			if(indices.isComplete())
			{
				break;
			}
			i++;
		}

		spdlog::info("[OAZ_VULKAN_WRAPPER] graphicsFamily: {0}, presentFamily: {1}", indices.graphicsFamily.value(), indices.presentFamily.value());
		return indices;
	}

	bool PhysicalDeviceManager::checkDeviceExtensionSupport(VkPhysicalDevice iPhysicalDevice)
	{
		uint32_t extensionCount;
		vkEnumerateDeviceExtensionProperties(iPhysicalDevice, nullptr, &extensionCount, nullptr);

		std::vector<VkExtensionProperties> availableExtensions(extensionCount);
		vkEnumerateDeviceExtensionProperties(iPhysicalDevice, nullptr, &extensionCount, availableExtensions.data());

		std::set<std::string> requiredExtensions(this->pExtensionManager->neededValidationLayers.begin(), this->pExtensionManager->neededValidationLayers.end());

		for(const auto& extension: availableExtensions)
		{
			requiredExtensions.erase(extension.extensionName);
		}

		return requiredExtensions.empty();
	}

	data::SwapChainSupportDetails PhysicalDeviceManager::querySwapChainSupport(VkPhysicalDevice iPhysicalDevice)
	{
		data::SwapChainSupportDetails details;

		vkGetPhysicalDeviceSurfaceCapabilitiesKHR(iPhysicalDevice, this->pSurface->surface, &details.capabilities);
		uint32_t formatCount;
		vkGetPhysicalDeviceSurfaceFormatsKHR(iPhysicalDevice, this->pSurface->surface, &formatCount, nullptr);

		if(formatCount != 0)
		{
			details.formats.resize(formatCount);
			vkGetPhysicalDeviceSurfaceFormatsKHR(iPhysicalDevice, this->pSurface->surface, &formatCount, details.formats.data());
		}

		uint32_t presentModeCount;
		vkGetPhysicalDeviceSurfacePresentModesKHR(iPhysicalDevice, this->pSurface->surface, &presentModeCount, nullptr);

		if (presentModeCount != 0) {
			details.presentModes.resize(presentModeCount);
			vkGetPhysicalDeviceSurfacePresentModesKHR(iPhysicalDevice, this->pSurface->surface, &presentModeCount, details.presentModes.data());
		}

		return details;
	}

}
