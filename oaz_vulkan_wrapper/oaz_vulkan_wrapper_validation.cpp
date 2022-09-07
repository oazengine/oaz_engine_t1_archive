#include "oaz_vulkan_wrapper_validation.h"

namespace oaz
{
	void OVWValidation::addValidationLayer(const char* validationLayerName)
	{
		validationLayers.push_back(validationLayerName);
		if(isUsingValidationLayers == false)
		{
			isUsingValidationLayers = true;
		}
	};
	inline std::vector<const char*> OVWValidation::getValidationLayers()
	{
		return validationLayers;
	};
	inline bool OVWValidation::getIsUsingValidation()
	{
		return isUsingValidationLayers;
	}

}