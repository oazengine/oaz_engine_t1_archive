#include "oaz_graphics_manager.h"

namespace oaz::graphics {
	OGM::OGM()
	{
			
	}

	OGM::OGM(GLFWwindow* window)
	{
		bindGLFWwindow(window);
	}

	void OGM::init(GLFWwindow* window)
	{
		bindGLFWwindow(window);
		initVulkan();
	}


	void OGM::bindGLFWwindow(GLFWwindow * window)
	{
		this->window = window;
	}
	void OGM::testGLFWPoint()
	{
		int xpos, ypos;
		glfwGetWindowPos(window, &xpos, &ypos);
		spdlog::info("test {0} {1}", xpos, ypos);
	}

	void OGM::testSymbol()
	{
		spdlog::info("hi");
	}

	void OGM::cleanUp()
	{
		
	}


	void OGM::initVulkan()
	{
		extensionManager.addExtensionByName(VK_KHR_SWAPCHAIN_EXTENSION_NAME);
		validation.setEnableValidationLayers(true);
		validation.addValidationLayerByName("VK_LAYER_KHRONOS_validation");
		validation.checkAllValidationLayersAvailable();
		instance.createVulkanInstance(&validation, true);
		surface.createSurfaceByGLFW(&instance, window, nullptr);
		physicalDeviceManager.bindInstance(&instance);
		physicalDeviceManager.bindExtension(&extensionManager);
		physicalDeviceManager.bindSurface(&surface);
		physicalDeviceManager.findPhysicalDevices();
		physicalDeviceManager.selectFirstGPU();
	}


}