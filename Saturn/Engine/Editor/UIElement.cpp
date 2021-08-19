#include "UIElement.h"
#include <GLFW/glfw3.h>

Saturn::UI::UIElement::UIElement(GLFWwindow* windowRef) : u_Window(windowRef)
{
	const char* glsl_version = "#version 460";

	ImGui::CreateContext();
	ImGui_ImplGlfw_InitForOpenGL(u_Window, true);
	ImGui_ImplOpenGL3_Init(glsl_version);
	ImGui::StyleColorsDark();
}

void Saturn::UI::UIElement::DrawUI(glm::vec4& skyboxColor, float& x, float& y, float& z, float& xPos, float& yPos, float& zPos, float& sx, float& sy, float& sz, glm::vec3& lightColor, float& diffuseFactor, float& ambientFactor) {
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();

	if (ImGui::BeginMainMenuBar())
	{
		if (ImGui::BeginMenu("File"))
		{
			if (ImGui::MenuItem("New", "Ctrl + N"))
			{
				//Do something
			}
			if (ImGui::MenuItem("Close", "Alt + F4"))
			{
				glfwSetWindowShouldClose(u_Window, GLFW_TRUE);
			}
			ImGui::EndMenu();
		}

		ImGui::EndMainMenuBar();
	}

	ImGui::Text("Editor");
	ImGui::ColorEdit3("SkyBox Color", glm::value_ptr(skyboxColor));
	ImGui::Text("Object Controls");
	ImGui::SliderFloat("Object X-Rotation", &x, 0.0f, 360.0f);
	ImGui::SliderFloat("Object Y-Rotation", &y, 0.0f, 360.0f);
	ImGui::SliderFloat("Object Z-Rotation", &z, 0.0f, 360.0f);
	ImGui::SliderFloat("Object X-Position", &xPos, -10.0f, 10.0f);
	ImGui::SliderFloat("Object Y-Position", &yPos, -10.0f, 10.0f);
	ImGui::SliderFloat("Object Z-Position", &zPos, -10.0f, 10.0f);
	ImGui::SliderFloat("Object X-Scale", &sx, 0.01f, 2.0f);
	ImGui::SliderFloat("Object Y-Scale", &sy, 0.01f, 2.0f);
	ImGui::SliderFloat("Object Z-Scale", &sz, 0.01f, 2.0f);
	ImGui::Text("Light Controls");
	ImGui::ColorEdit3("Light Color", glm::value_ptr(lightColor));
	ImGui::SliderFloat("Diffuse Factor", &diffuseFactor, 0.0f, 1.0f);
	ImGui::SliderFloat("Specular Factor", &ambientFactor, 0.01f, 2.0f);

	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

Saturn::UI::UIElement::~UIElement()
{
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
}
