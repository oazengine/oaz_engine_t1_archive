#ifndef OAZ_VULKAN_WRAPPER_DATA
#define OAZ_VULKAN_WRAPPER_DATA

#include <optional>

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

	struct QueueFamilyIndices
	{
		std::optional<uint32_t> graphicsFamily;
		std::optional<uint32_t> presentFamily;

		bool isComplete()
		{
			return graphicsFamily.has_value() && presentFamily.has_value();
		}
	};

	struct SwapChainSupportDetails {
		VkSurfaceCapabilitiesKHR capabilities;
		std::vector<VkSurfaceFormatKHR> formats;
		std::vector<VkPresentModeKHR> presentModes;
	};
}

#endif 