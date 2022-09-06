#include <iostream>
#include <fstream>
#include "GLFW/glfw3.h"
#include "oaz_vulkan_wrapper.h"
#include "oaz_data.h"
#include "GLFW/glfw3.h"
#include "json.hpp"
#include "spdlog/spdlog.h"
#include "oaz_graphics.h"



class OazApplication {
public:	
	void init() {
		initOazEngine();
		initApplication();
		initWindow();
		initOazGraphics();
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
	oaz::OGM ogm;
	
	const int windowWidth = 900;
	const int windowHeight = 600;

	void initOazEngine() {
		std::ifstream engineConfigStream("..\\oaz_engine_config.json");
		nlohmann::json engineConfigData = nlohmann::json::parse(engineConfigStream);
		engineConfigStream.close();
		}

	void initApplication()
	{
		std::ifstream appConfigStream("..\\oaz_application_config.json");
		nlohmann::json appConfigData = nlohmann::json::parse(appConfigStream);
		// 현재 Graphics API는 Vulkan으로 고정입니다.
		if(appConfigData["graphicsOption"]["graphicsAPI"] == "Vulkan")
		{
			spdlog::info("Selected Graphics API: Vulkan");
			graphicsAPI.graphicsAPItype = oaz::GraphicsAPItype::Vulkan;
		} else
		{
			spdlog::critical("{0} is not supported", appConfigData["graphicsOption"]["graphicsAPI"]);
		}
		appConfigStream.close();
	}

	void initWindow() {
		// 현재 Window관련 Library는 GLFW로 고정입니다.
		windowLibrary.windowLibraryType = oaz::WindowLibraryType::GLFW;
		if (graphicsAPI.graphicsAPItype == oaz::GraphicsAPItype::Vulkan && windowLibrary.windowLibraryType == oaz::WindowLibraryType::GLFW)
		{
			glfwInit();
			glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
			glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
			window = glfwCreateWindow(windowWidth, windowHeight, "Oaz Application", nullptr, nullptr);

		}
		else {
			spdlog::critical("Selected graphics enviroment is not supported");
		}
	}

	void initOazGraphics() {
		
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