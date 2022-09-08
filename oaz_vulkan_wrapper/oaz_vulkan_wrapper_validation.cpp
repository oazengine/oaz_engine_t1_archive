#include "oaz_vulkan_wrapper_validation.h"


namespace vkw
{
	void Validation::addValidationLayer(const char* validationLayerName)
	{
		data::Layer newLayer;
		newLayer.name = validationLayerName;
		validationLayers.push_back(newLayer);
	};
	inline std::vector<data::Layer> Validation::getValidationLayers()
	{
		return validationLayers;
	};
	inline bool Validation::isUsingValidationLayers() const
	{
		if (validationLayers.empty())
		{
			return false;
		}
		return true;
	}
	bool Validation::checkAllValidationLayersAvailable() const
	{
		if (validationLayers.empty())
		{
			spdlog::warn("There are no validation layers that use");
		}
		uint32_t layerCount;
		vkEnumerateInstanceLayerProperties(&layerCount, nullptr);
		spdlog::info("Validation Layer Count: {0}", layerCount);

		std::vector<VkLayerProperties> availableLayers(layerCount);
		vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data());

		for (data::Layer layer : validationLayers) {
			bool isLayerFound = false;

			for (const auto& layerProperties : availableLayers) {
				if (strcmp(layer.name, layerProperties.layerName) == 0) {
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
