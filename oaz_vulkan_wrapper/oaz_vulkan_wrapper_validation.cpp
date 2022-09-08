#include "oaz_vulkan_wrapper_validation.h"


namespace vkw
{
	void OVWValidation::addValidationLayer(const char* validationLayerName)
	{
		validationLayers.push_back(validationLayerName);
	};
	inline std::vector<const char*> OVWValidation::getValidationLayers()
	{
		return validationLayers;
	};
	inline bool OVWValidation::isUsingValidationLayers() const
	{
		if (validationLayers.empty())
		{
			return false;
		}
		else {
			return true;
		}
	}
	bool OVWValidation::checkValidationLayerSupport() const
	{
		if(validationLayers.empty())
		{
			spdlog::warn("There are no validation layers that use");
		}
		uint32_t layerCount;
		vkEnumerateInstanceLayerProperties(&layerCount, nullptr);
		spdlog::info("Validation Layer Count: {0}", layerCount);

		std::vector<VkLayerProperties> availableLayers(layerCount);
		vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data());

		for (const char* layerName : validationLayers) {
			bool isLayerFound = false;

			for (const auto& layerProperties : availableLayers) {
				if (strcmp(layerName, layerProperties.layerName) == 0) {
					isLayerFound = true;
					break;
				}
			}

			if (!isLayerFound) {
				return false;
			}
		}
		return true;
	}


}
