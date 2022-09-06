#pragma once

#include <vector>

namespace oaz
{
	/**
	 * @brief OazVulkanWrapper�� Validation Layer ��� ����ϴ� Class
	 */
	class OVWValidation
	{
	public:
		/**
		 * @brief OVWValidation�� member�� 
		 * @param validationLayerName ���ϴ� ValidationLayer�� �̸��� �޽��ϴ�.
		 */
		void addValidationLayer(const char* validationLayerName);
		/**
		 * @brief ����ϰ��� �ϴ� validationLayer���� ���(vector)�� ��ȯ�ϴ� �Լ�
		 * @return validationLayers
		 */
		std::vector<const char*> getValidationLayers();
	private:
		bool isUsingValidationLayers = false;
		std::vector<const char*> validationLayers;
	};

}
