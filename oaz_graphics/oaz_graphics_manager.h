#pragma once
#include <GLFW/glfw3.h>
#include <spdlog/spdlog.h>


namespace oaz {
	/**
	 * @brief Oaz Graphics Manager��, ���� �ھ�� �� �������־�� �ϸ�, GLFW ��� �� window��ü�� ���ε����־�� �մϴ�.
	*/
	class OGM {
	public:
		void bindGLFWwindow(GLFWwindow* window);
		void testGLFWPoint();
		void testSymbol();
	private:
		GLFWwindow* window;
	};
}