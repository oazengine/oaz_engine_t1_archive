#include <iostream>
#include <fstream>
#include "GLFW/glfw3.h"
#include "oaz_vulkan_wrapper.h"
#include "oaz_data.h"
#include "GLFW/glfw3.h"
#include "json.hpp"


class OazApplication {
public:	
	void init() {
		initOazEngine();
		initApplication();
		initWindow();
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
		std::ifstream engineConfigStream("..\\oaz_engine_config.json");
		nlohmann::json engineConfigData = nlohmann::json::parse(engineConfigStream);
		std::cout << engineConfigData["OazGraphics"]["graphicsAPISupport"] << std::endl;
		// ���� Graphics API�� Vulkan���� �����Դϴ�.
		graphicsAPI.graphicsAPItype = oaz::GraphicsAPItype::Vulkan;
		// ���� Window���� Library�� GLFW�� �����Դϴ�.
		windowLibrary.windowLibraryType = oaz::WindowLibraryType::GLFW;
	}

	void initApplication()
	{
		std::ifstream appConfigStream("..\\oaz_application_config.json");
		nlohmann::json appConfigData = nlohmann::json::parse(appConfigStream);
		if(appConfigData["graphicsOption"]["graphcisAPI"] == "Vulkan")
		{
			graphicsAPI.graphicsAPItype = oaz::GraphicsAPItype::Vulkan;
		}
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
			std::cout << "���� �������� �ʴ� ȯ���Դϴ�" << std::endl;
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