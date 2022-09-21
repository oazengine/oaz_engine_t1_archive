#pragma once
#include <GLFW/glfw3.h>
#include <spdlog/spdlog.h>
#include "oaz_vulkan_wrapper.h"


namespace oaz::graphics {
	/**
	 * @brief Oaz Graphics Manager로, 엔진 코어에서 꼭 생성해주어야 하며, GLFW 사용 시 window객체를 바인딩해주어야 합니다.
	*/
	class OGM {
	public:
		OGM();
		OGM(GLFWwindow* window);
		void init(GLFWwindow* window);
		void bindGLFWwindow(GLFWwindow* window);
		void testGLFWPoint();
		void testSymbol();
	private:
		GLFWwindow* window;
		ovw::Instance instance;
		ovw::Validation validation;
		ovw::DebugMessenger debugMessenger;

		void initVulkan();
	};
}