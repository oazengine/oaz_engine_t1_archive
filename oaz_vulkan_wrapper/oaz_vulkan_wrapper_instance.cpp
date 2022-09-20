#include "oaz_vulkan_wrapper_instance.h"

namespace ovw
{
	void Instance::createVulkanInstance(Validation ovwValidation, bool isUsingGLFWExtensions)
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

        if(isUsingGLFWExtensions)
        {
            auto extensions = ext::getRequiredExtensionsByGLFW();
            if(ovwValidation.enableValidationLayers)
            {
                extensions.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
            }
            createInfo.enabledExtensionCount = static_cast<uint32_t>(extensions.size());
            createInfo.ppEnabledExtensionNames = extensions.data();
        } else
        {
            spdlog::warn("Only GLFW extensions are supported now");
        }
        
        if (ovwValidation.enableValidationLayers) {
            VkDebugUtilsMessengerCreateInfoEXT debugCreateInfo{};
            createInfo.enabledLayerCount = static_cast<uint32_t>(ovwValidation.getActualValidationLayers().size());
            createInfo.ppEnabledLayerNames = ovwValidation.getActualValidationLayers().data();

            dm::populateDebugMessengerCreateInfo(debugCreateInfo);
            createInfo.pNext = (VkDebugUtilsMessengerCreateInfoEXT*)&debugCreateInfo;
        }
        else {
            createInfo.enabledLayerCount = 0;
            createInfo.pNext = nullptr;
        }

        if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS) {
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

