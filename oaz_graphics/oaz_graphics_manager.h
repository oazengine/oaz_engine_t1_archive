#pragma once
#include <GLFW/glfw3.h>
#include <spdlog/spdlog.h>


namespace oaz::graphics {
	/**
	 * @brief Oaz Graphics Manager��, ���� �ھ�� �� �������־�� �ϸ�, GLFW ��� �� window��ü�� ���ε����־�� �մϴ�.
	*/
	class OGM {
	public:
		/**
		 * @brief GLFWwindow ��ü �����͸� �޾� OGM ��ü�� ��� ����(GLFWwindow* window)�� �����մϴ�.
		 * @param window GLFWwindow ��ü ������
		*/
		void bindGLFWwindow(GLFWwindow* window);
		void testGLFWPoint();
		void testSymbol();
	private:
		GLFWwindow* window;
	};
}