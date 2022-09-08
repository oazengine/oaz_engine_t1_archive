#pragma once

#include <vector>
#include "vulkan/vulkan.h"
#include "spdlog/spdlog.h"

namespace vkw
{
	/**
	 * @brief OazVulkanWrapper의 Validation Layer 제어를 담당하는 Class
	 */
	class OVWValidation
	{
	public:
		/**
		 * @brief OVWValidation 클래스를
		 */
		void init();
		/**
		 * @brief OVWValidation의 member인 
		 * @param validationLayerName 원하는 ValidationLayer의 이름을 받습니다.
		 */
		void addValidationLayer(const char* validationLayerName);
		/**
		 * @brief 사용하고자 하는 validationLayer들의 목록(vector)를 반환하는 함수
		 * @return validationLayers
		 */
		inline std::vector<const char*> getValidationLayers();
		inline bool isUsingValidationLayers() const;
		bool checkValidationLayerSupport() const;
	private:
		std::vector<const char*> validationLayers;
	};

}
