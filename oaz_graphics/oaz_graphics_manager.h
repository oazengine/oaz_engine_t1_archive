#pragma once
#include <GLFW/glfw3.h>
#include <spdlog/spdlog.h>


namespace oaz {
	/**
	 * @brief Oaz Graphics Manager로, 엔진 코어에서 꼭 생성해주어야 하며, GLFW 사용 시 window객체를 바인딩해주어야 합니다.
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