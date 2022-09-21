#pragma once
#include <GLFW/glfw3.h>
#include <spdlog/spdlog.h>
#include "oaz_vulkan_wrapper.h"


namespace oaz::graphics {
	/**
	 * @brief Oaz Graphics Manager��, ���� �ھ�� �� �������־�� �ϸ�, GLFW ��� �� window��ü�� ���ε����־�� �մϴ�.
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