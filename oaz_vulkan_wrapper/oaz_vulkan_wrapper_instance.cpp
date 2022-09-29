#include "oaz_vulkan_wrapper_instance.h"


const std::vector<const char*> testLayers = {
    "VK_LAYER_KHRONOS_validation"
};

namespace ovw
{
	void Instance::createVulkanInstance(Validation* ovwValidation, bool isUsingGLFWExtensions)
	{
        VkApplicationInfo appInfo{};
        appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
        appInfo.pApplicationName = "Hello Triangle";
        appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
        appInfo.pEngineName = "No Engine";
        appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
        appInfo.apiVersion = VK_API_VERSION_1_0;

        VkInstanceCreateInfo createInfo{};
        createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
        createInfo.pApplicationInfo = &appInfo;

        std::vector<const char*> extensions;
        std::vector<const char*> actualValidationLayer;
        if(isUsingGLFWExtensions)
        {
        	extensions = ext::getRequiredExtensionsByGLFW();
            if(ovwValidation->getEnableValidationLayers())
            {
                extensions.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
            }
            createInfo.enabledExtensionCount = static_cast<uint32_t>(extensions.size());
            createInfo.ppEnabledExtensionNames = extensions.data();
        } else
        {
            spdlog::warn("[OAZ_VULKAN_WRAPPER] Only GLFW extensions are supported now");
        }

        VkDebugUtilsMessengerCreateInfoEXT debugCreateInfo{};
        if (ovwValidation->getEnableValidationLayers()) {
            createInfo.enabledLayerCount = static_cast<uint32_t>(ovwValidation->getActualValidationLayers().size());
        	actualValidationLayer = ovwValidation->getActualValidationLayers();
        	createInfo.ppEnabledLayerNames = actualValidationLayer.data();

            dm::populateDebugMessengerCreateInfo(debugCreateInfo);
            createInfo.pNext = (VkDebugUtilsMessengerCreateInfoEXT*)&debugCreateInfo;
        }
        else {
            createInfo.enabledLayerCount = 0;
            createInfo.pNext = nullptr;
        }
        
        if (VkResult result = vkCreateInstance(&createInfo, nullptr, &instance); result == VK_SUCCESS) {
            spdlog::info("[OAZ_VULKAN_WRAPPER] create vulkan instance ");
        } else
        {
            spdlog::warn("[OAZ_VULKAN_WRAPPER] something was wrong when OVW create a vulkan instance. The VkResult is : '{0}'", result);
            throw std::runtime_error("failed to create instance!");
        }
	}

	void Instance::cleanUpVulkanInstance()
	{
        vkDestroyInstance(this->instance, nullptr);
	}

    Instance::~Instance()
	{
        this->cleanUpVulkanInstance();
	}
}

