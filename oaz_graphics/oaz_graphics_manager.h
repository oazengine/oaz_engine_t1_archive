#pragma once
#include <GLFW/glfw3.h>
#include <spdlog/spdlog.h>


namespace oaz {
	/**
	 * @brief Oaz Graphics Manager��, ���� �ھ�� �� �������־�� �ϸ�, GLFW ��� �� window��ü�� ���ε����־�� �մϴ�.
	*/
	class OGM {
	public:
		OGM(GLFWwindow* window) {
			this->window = window;
			testGLFW();
		}
	private:
		GLFWwindow* window;
		void testGLFW() {
			int xpos, ypos;
			glfwGetWindowPos(window, &xpos,&ypos);
			spdlog::info("test {0} {1}", xpos, ypos);
		}
	};

	OGM* createOGMWithGLFW(GLFWwindow* glfw);
}