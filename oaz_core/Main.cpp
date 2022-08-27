#include <iostream>
#include "GLFW/glfw3.h"
#include "oaz_vulkan_wrapper.h"
#include "oaz_data.h"



class OazApplication {
public:	
	void init() {
		initOazEngine();
		initWindow();
	}
	void mainLoop() {
		while (1) {

		}
	}
	void cleanUp() {

	}
private:
	oaz::GraphicsAPI graphicsAPI;
	oaz::WindowLibrary windowLibrary;
	void initOazEngine() {
		// 현재 Graphics API는 Vulkan으로 고정입니다.
		graphicsAPI.graphicsAPItype = oaz::GraphicsAPItype::Vulkan;
		// 현재 Window관련 Library는 GLFW로 고정입니다.
		windowLibrary.windowLibraryType = oaz::WindowLibraryType::GLFW;
	}
	void initWindow() {
		if (graphicsAPI.graphicsAPItype == oaz::GraphicsAPItype::Vulkan && windowLibrary.windowLibraryType == oaz::WindowLibraryType::GLFW)
		{
			glfwInit();
			glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
			glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
		}
		else {
			std::cout << "현재 지원하지 않는 환경입니다" << std::endl;
		}
	}
};

int main()
{
	OazApplication oazApp;
	try {
		oazApp.init();
		oazApp.mainLoop();
		oazApp.cleanUp();
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}