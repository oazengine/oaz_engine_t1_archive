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
		 * @brief vkw::data::Layer 타입의 원소를 가진 validationLayers 벡터에 새 레이어를 추가합니다. 단, 이 함수를 정상적으로 호출한다고 해서 바로 Validation Layer가 적용되는 것은 아닙니다.
		 * @param 추가하고자 하는 ValidationLayer의 이름
		 */
		void addValidationLayer(const char* validationLayerName);
		/**
		 * @brief 사용하고자 하는 validation
		 * @return validationLayers(vkw::data::Layer의 vector)
		 */
		inline std::vector<data::Layer> getValidationLayers();
		/**
		 * @brief ValidationLayer를 사용하는지 확인하는 함수입니다. 이때 validationLayers의 empty()여부로 조회하게 되는데, 만약 모든 Layer의 LayerStatus가 NOT_AVAILABLE이여도 true를 반환합니다.
		 * @return validationLayers 벡터에 원소가 있다면 true를, 아니면 false를 반환합니다. 
		*/
		inline bool isUsingValidationLayers() const;
		/**
		 * @brief Validation의 멤버인 validationLayers의 Layer들이 현 플랫폼에서 사용 가능한지를 모두 체크하는 함수
		 * @return 모든 ValidationLayer가 사용 가능하면 true를, 아니면 false를 반환합니다.
		*/
		bool checkAllValidationLayersAvailable() const;
	private:
		std::vector<data::Layer> validationLayers;
	};

}
