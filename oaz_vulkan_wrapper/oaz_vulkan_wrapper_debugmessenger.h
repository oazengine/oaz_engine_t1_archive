#ifndef OAZ_VULKAN_WRAPPER_DEBUGMESSENGER
#define OAZ_VULKAN_WRAPPER_DEBUGMESSENGER

#include "vulkan/vulkan.h"
#include "spdlog/spdlog.h"

namespace ovw::dm
{
	void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);
	static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageType, const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData, void* pUserData);

}

namespace ovw
{
	class DebugMessenger
	{
	public:
		DebugMessenger();
		DebugMessenger(VkInstance* pInstance);

		void bingVkInstance(VkInstance* pInstance);

		~DebugMessenger();
	private:
		VkInstance* pInstance;
		VkDebugUtilsMessengerEXT debugMessengerEXT;

		void createDebugMessenger();
		VkResult CreateDebugUtilsMessengerEXT(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pDebugMessenger);
		void cleanUpDebugMessenger();
	};
}

#endif
