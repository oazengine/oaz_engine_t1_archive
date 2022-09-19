#pragma once

#include <vector>
#include "vulkan/vulkan.h"
#include "spdlog/spdlog.h"
#include "oaz_vulkan_wrapper_data.h"

namespace ovw
{
	class Validation
	{
	public:
#ifdef NDEBUG
		const bool enableValidationLayers = false;
#else
		const bool enableValidationLayers = true;
#endif
		void addValidationLayerByName(const char* validationLayerName);
		void checkAllValidationLayersAvailable();
		inline std::vector<const char*> getActualValidationLayers() const;
	private:
		std::vector<data::Layer> validationLayerQueue;
		std::vector<const char*> actualValidationLayers;
	};

}
