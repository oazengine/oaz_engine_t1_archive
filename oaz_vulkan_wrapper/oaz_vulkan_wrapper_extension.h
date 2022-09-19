#pragma once
#include <vector>

namespace ovw
{
	/**
	 * @brief GLFW로부터 extension을 받아오는 함수
	 * @return 
	*/
	std::vector<const char*> getRequiredExtensionsByGLFW();
}
