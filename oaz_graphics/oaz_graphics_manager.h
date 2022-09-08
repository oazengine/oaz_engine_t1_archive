#pragma once
#include <GLFW/glfw3.h>
#include <spdlog/spdlog.h>


namespace oaz::graphics {
	/**
	 * @brief Oaz Graphics Manager로, 엔진 코어에서 꼭 생성해주어야 하며, GLFW 사용 시 window객체를 바인딩해주어야 합니다.
	*/
	class OGM {
	public:
		/**
		 * @brief GLFWwindow 객체 포인터를 받아 OGM 객체의 멤버 변수(GLFWwindow* window)에 저장합니다.
		 * @param window GLFWwindow 객체 포인터
		*/
		void bindGLFWwindow(GLFWwindow* window);
		void testGLFWPoint();
		void testSymbol();
	private:
		GLFWwindow* window;
	};
}