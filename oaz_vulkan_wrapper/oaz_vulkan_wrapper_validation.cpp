#include "oaz_vulkan_wrapper_validation.h"

namespace oaz
{
	void OVWValidation::addValidationLayer(const char* validationLayerName)
	{
		validationLayers.push_back(validationLayerName);
	};
	inline std::vector<const char*> OVWValidation::getValidationLayers()
	{
		return validationLayers;
	};
	inline bool OVWValidation::isUsingValidationLayers()
	{
		if (validationLayers.size() == 0)
		{
			return false;
		}
		else {
			return true;
		}
	}

}