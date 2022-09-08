#include "oaz_graphics_manager.h"

namespace oaz::graphics {
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

}