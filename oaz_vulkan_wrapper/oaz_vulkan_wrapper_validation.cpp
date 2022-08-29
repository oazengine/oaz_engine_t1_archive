#include "oaz_vulkan_wrapper_validation.h"

namespace oaz
{
	void OVWValidation::addValidationLayer(const char* validationLayerName)
	{
		validationLayers.push_back(validationLayerName);
	};
	std::vector<const char*> OVWValidation::getValidationLayers()
	{
		return validationLayers;
	};
}