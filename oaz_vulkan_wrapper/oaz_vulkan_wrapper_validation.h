#ifndef OAZ_VULKAN_WRAPPER_VALIDATION
#define OAZ_VULKAN_WRAPPER_VALIDATION

#include <vector>
#include "vulkan/vulkan.h"
#include "spdlog/spdlog.h"
#include "oaz_vulkan_wrapper_data.h"

namespace ovw
{
	class Validation
	{
	public:
		void inline setEnableValidationLayers(bool isEnable);
		bool inline getEnableValidationLayers() const;
		void addValidationLayerByName(const char* validationLayerName);
		void checkAllValidationLayersAvailable();
		inline std::vector<const char*> getActualValidationLayers() const;
	private:
		bool enableValidationLayers = false;
		std::vector<data::Layer> validationLayerQueue;
		std::vector<const char*> actualValidationLayers;
	};

}

#endif