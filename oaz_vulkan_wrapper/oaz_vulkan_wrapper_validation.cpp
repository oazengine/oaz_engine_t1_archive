#include "oaz_vulkan_wrapper_validation.h"


namespace ovw
{

	void inline Validation::setEnableValidationLayers(bool isEnable)
	{
		this->enableValidationLayers = isEnable;
	}

	bool Validation::getEnableValidationLayers() const
	{
		return this->enableValidationLayers;
	}


	void Validation::addValidationLayerByName(const char* validationLayerName)
	{
		data::Layer newLayer;
		newLayer.name = validationLayerName;
		validationLayerQueue.push_back(newLayer);
	};
	void Validation::checkAllValidationLayersAvailable()
	{
		uint32_t layerCount;
		vkEnumerateInstanceLayerProperties(&layerCount, nullptr);
		spdlog::info("Validation Layer Count: {0}", layerCount);

		std::vector<VkLayerProperties> availableLayers(layerCount);
		vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data());

		for (data::Layer layer : validationLayerQueue) {
			bool isLayerFound = false;

			for (const auto& layerProperties : availableLayers) {
				if (strcmp(layer.name, layerProperties.layerName) == 0) {
					isLayerFound = true;
					layer.layerStatus = data::LayerStatus::AVAILABLE;
					actualValidationLayers.push_back(layer.name);
					break;
				}
			}

			if (!isLayerFound) {
				layer.layerStatus = data::LayerStatus::NOT_AVAILABLE;
			}
		}
	}
	inline std::vector<const char*> Validation::getActualValidationLayers() const
	{
		return actualValidationLayers;
	}
}
