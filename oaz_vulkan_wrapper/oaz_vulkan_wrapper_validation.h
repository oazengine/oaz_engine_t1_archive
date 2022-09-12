#pragma once

#include <vector>
#include "vulkan/vulkan.h"
#include "spdlog/spdlog.h"
#include "oaz_vulkan_wrapper_data.h"

namespace vkw
{
	/**
	 * @brief OazVulkanWrapper�� Validation Layer ��� ����ϴ� Class
	 */
	class Validation
	{
	public:
		/**
		 * @brief vkw::data::Layer Ÿ���� ���Ҹ� ���� validationLayers ���Ϳ� �� ���̾ �߰��մϴ�. ��, �� �Լ��� ���������� ȣ���Ѵٰ� �ؼ� �ٷ� Validation Layer�� ����Ǵ� ���� �ƴմϴ�.
		 * @param �߰��ϰ��� �ϴ� ValidationLayer�� �̸�
		 */
		void addValidationLayer(const char* validationLayerName);
		/**
		 * @brief ����ϰ��� �ϴ� validation
		 * @return validationLayers(vkw::data::Layer�� vector)
		 */
		inline std::vector<data::Layer> getValidationLayers();
		/**
		 * @brief ValidationLayer�� ����ϴ��� Ȯ���ϴ� �Լ��Դϴ�. �̶� validationLayers�� empty()���η� ��ȸ�ϰ� �Ǵµ�, ���� ��� Layer�� LayerStatus�� NOT_AVAILABLE�̿��� true�� ��ȯ�մϴ�.
		 * @return validationLayers ���Ϳ� ���Ұ� �ִٸ� true��, �ƴϸ� false�� ��ȯ�մϴ�. 
		*/
		inline bool isUsingValidationLayers() const;
		/**
		 * @brief Validation�� ����� validationLayers�� Layer���� �� �÷������� ��� ���������� ��� üũ�ϴ� �Լ�
		 * @return ��� ValidationLayer�� ��� �����ϸ� true��, �ƴϸ� false�� ��ȯ�մϴ�.
		*/
		bool checkAllValidationLayersAvailable() const;
	private:
		std::vector<data::Layer> validationLayers;
	};

}
