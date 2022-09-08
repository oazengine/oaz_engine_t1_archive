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
		 * @brief OVWValidation Ŭ������
		 */
		void init();
		/**
		 * @brief OVWValidation�� member�� 
		 * @param validationLayerName ���ϴ� ValidationLayer�� �̸��� �޽��ϴ�.
		 */
		void addValidationLayer(const char* validationLayerName);
		/**
		 * @brief ����ϰ��� �ϴ� validationLayer���� ���(vector)�� ��ȯ�ϴ� �Լ�
		 * @return validationLayers(vkw::data::Layer�� vector)
		 */
		inline std::vector<data::Layer> getValidationLayers();
		inline bool isUsingValidationLayers() const;
		/**
		 * @brief Validation�� ����� validationLayers�� Layer���� �� �÷������� ��� ���������� ��� üũ�ϴ� �Լ�
		 * @return ��� ValidationLayer�� ��� �����ϸ� true��,�ƴϸ� false�� ��ȯ�մϴ�.
		*/
		bool checkAllValidationLayersAvailable() const;
	private:
		std::vector<data::Layer> validationLayers;
	};

}
