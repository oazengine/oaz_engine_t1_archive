#include <iostream>
#include <fstream>
#include "GLFW/glfw3.h"
#include "json.hpp"
#include "spdlog/spdlog.h"

#include "oaz_graphics.h"
#include "oaz_vulkan_wrapper.h"
#include "oaz_data.h"


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
		cleanOazGraphics();
	}
private:
	GLFWwindow* window;
	oaz::data::GraphicsAPI graphicsAPI;
	oaz::data::WindowLibrary windowLibrary;
	oaz::graphics::OGM ogm;

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
		// ���� Graphics API�� Vulkan���� �����Դϴ�.
		if (appConfigData["graphicsOption"]["graphicsAPI"] == "Vulkan")
		{
			spdlog::info("Selected Graphics API: Vulkan");
			graphicsAPI.graphicsAPItype = oaz::data::GraphicsAPItype::Vulkan;
		}
		else
		{
			spdlog::critical("{0} is not supported", appConfigData["graphicsOption"]["graphicsAPI"]);
		}
		appConfigStream.close();
	}

	void initWindow() {
		// ���� Window���� Library�� GLFW�� �����Դϴ�.
		windowLibrary.windowLibraryType = oaz::data::WindowLibraryType::GLFW;
		if (graphicsAPI.graphicsAPItype == oaz::data::GraphicsAPItype::Vulkan && windowLibrary.windowLibraryType == oaz::data::WindowLibraryType::GLFW)
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
		ogm.init(window);
	}

	void cleanWindow()
	{
		glfwDestroyWindow(window);
		glfwTerminate();
	}

	void cleanOazGraphics()
	{
		ogm.cleanUp();
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