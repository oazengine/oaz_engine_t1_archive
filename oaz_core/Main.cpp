#include <iostream>
#include "GLFW/glfw3.h"
#include "oaz_vulkan_wrapper.h"
#include "oaz_data.h"
#include "GLFW/glfw3.h"


class OazApplication {
public:	
	void init() {
		initWindow();
		initOazEngine();
	}
	void mainLoop() {
		while (!glfwWindowShouldClose(window)) {
			glfwPollEvents();
		}
	}
	void cleanUp() {
		cleanWindow();
	}
private:
	GLFWwindow* window;
	oaz::GraphicsAPI graphicsAPI;
	oaz::WindowLibrary windowLibrary;
	const int windowWidth = 900;
	const int windowHeight = 600;

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
			window = glfwCreateWindow(windowWidth, windowHeight, "Oaz Application", nullptr, nullptr);

		}
		else {
			std::cout << "현재 지원하지 않는 환경입니다" << std::endl;
		}
	}

	void cleanWindow()
	{
		glfwDestroyWindow(window);
		glfwTerminate();
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