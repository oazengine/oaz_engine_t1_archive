#pragma once

#include <vector>
#include "vulkan/vulkan.h"
#include "spdlog/spdlog.h"
#include "oaz_vulkan_wrapper_data.h"

namespace vkw
{
	/**
	 * @brief OazVulkanWrapper의 Validation Layer 제어를 담당하는 Class
	 */
	class Validation
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
		 * @return validationLayers(vkw::data::Layer의 vector)
		 */
		inline std::vector<data::Layer> getValidationLayers();
		inline bool isUsingValidationLayers() const;
		/**
		 * @brief Validation의 멤버인 validationLayers의 Layer들이 현 플랫폼에서 사용 가능한지를 모두 체크하는 함수
		 * @return 모든 ValidationLayer가 사용 가능하면 true를,아니면 false를 반환합니다.
		*/
		bool checkAllValidationLayersAvailable() const;
	private:
		std::vector<data::Layer> validationLayers;
	};

}
