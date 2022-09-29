#ifndef OAZ_VULKAN_WRAPPER_DATA
#define OAZ_VULKAN_WRAPPER_DATA

namespace ovw::data
{
	/**
	 * @brief Vulkan Layer�� ���¸� ���� Enum Class
	*/
	enum class LayerStatus
	{
		NOT_CHECKED,
		AVAILABLE,
		NOT_AVAILABLE
	};
	

	/**
	 * @brief  Vulkan Layer�� �̸��� ����(LayerStatus)�� ���� ����ü 
	*/
	struct Layer
	{
		const char* name;
		LayerStatus layerStatus = LayerStatus::NOT_CHECKED;
	};

}

#endif OAZ_VULKAN_WRAPPER_DATA