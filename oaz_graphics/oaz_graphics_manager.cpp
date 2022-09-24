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
		validation.addValidationLayerByName("VK_LAYER_KHRONOS_validation");
		validation.setEnableValidationLayers(true);
		validation.checkAllValidationLayersAvailable();
		instance.createVulkanInstance(validation, true);
		
	}


}