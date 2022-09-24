#ifndef OAZ_VULKAN_WRAPPER_DATA
#define OAZ_VULKAN_WRAPPER_DATA

namespace ovw::data
{
	/**
	 * @brief Vulkan Layer의 상태를 담은 Enum Class
	*/
	enum class LayerStatus
	{
		NOT_CHECKED,
		AVAILABLE,
		NOT_AVAILABLE
	};
	

	/**
	 * @brief  Vulkan Layer의 이름과 상태(LayerStatus)를 담은 구조체 
	*/
	struct Layer
	{
		const char* name;
		LayerStatus layerStatus = LayerStatus::NOT_CHECKED;
	};

}

#endif OAZ_VULKAN_WRAPPER_DATA