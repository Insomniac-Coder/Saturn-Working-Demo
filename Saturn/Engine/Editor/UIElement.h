#ifndef UIELEMENT_H
#define UIELEMENT_H

#include "imgui/imgui.h"
#include "imgui/imgui_impl_opengl3.h"
#include "imgui/imgui_impl_glfw.h"
#include "glm/glm.hpp"
#include "glm/gtc/type_ptr.hpp"

namespace Saturn {
	namespace UI {
		class UIElement
		{
		private:
			GLFWwindow* u_Window;
		public:
			UIElement(GLFWwindow* windowRef);
			~UIElement();
			void DrawUI(glm::vec4& skyboxColor, float& x, float& y, float& z, float& xPos, float& yPos, float& zPos, float& sx, float& sy, float& sz, glm::vec3& lightColor, float& diffuseFactor, float& ambientFactor);
		};
	}
}

#endif UIELEMENT_H