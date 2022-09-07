#pragma once
#include <GLFW/glfw3.h>
#include <spdlog/spdlog.h>


namespace oaz {
	/**
	 * @brief Oaz Graphics Manager로, 엔진 코어에서 꼭 생성해주어야 하며, GLFW 사용 시 window객체를 바인딩해주어야 합니다.
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