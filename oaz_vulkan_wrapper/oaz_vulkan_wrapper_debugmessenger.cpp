#include "oaz_vulkan_wrapper_debugmessenger.h"

namespace ovw::dm
{
    void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo) {
        createInfo = {};
        createInfo.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;
        createInfo.messageSeverity = VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT;
        createInfo.messageType = VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT;
        createInfo.pfnUserCallback = debugCallback;
    }

    VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageType, const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData, void* pUserData) {
        spdlog::warn("Message By Validation Layer: {0}", pCallbackData->pMessage);
        return VK_FALSE;
    }
}

namespace ovw
{
    void DebugMessenger::createDebugMessenger()
    {
        VkDebugUtilsMessengerCreateInfoEXT createInfo;
        dm::populateDebugMessengerCreateInfo(createInfo);

        if (CreateDebugUtilsMessengerEXT(*pInstance, &createInfo, nullptr, &debugMessengerEXT) != VK_SUCCESS) {
            throw std::runtime_error("failed to set up debug messenger!");
        }
    }

    DebugMessenger::DebugMessenger()
    {
        spdlog::info("Create: DebugMessenger");
    }

    DebugMessenger::DebugMessenger(VkInstance* pinstance)
    {
        this->pInstance = pinstance;
        this->createDebugMessenger();
    }


    VkResult DebugMessenger::CreateDebugUtilsMessengerEXT(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pDebugMessenger) {
        auto func = (PFN_vkCreateDebugUtilsMessengerEXT)vkGetInstanceProcAddr(instance, "vkCreateDebugUtilsMessengerEXT");
        if (func != nullptr) {
            return func(instance, pCreateInfo, pAllocator, pDebugMessenger);
        }
        else {
            return VK_ERROR_EXTENSION_NOT_PRESENT;
        }
    }

    DebugMessenger::~DebugMessenger()
    {
        this->cleanUpDebugMessenger();
    }


    void DebugMessenger::cleanUpDebugMessenger()
    {
        auto func = (PFN_vkDestroyDebugUtilsMessengerEXT)vkGetInstanceProcAddr(*pInstance, "vkDestroyDebugUtilsMessengerEXT");
        if (func != nullptr) {
            func(*pInstance, debugMessengerEXT, nullptr);
        }
    }

}