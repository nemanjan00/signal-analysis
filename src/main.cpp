#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <iostream>
#include <GLFW/glfw3.h>

int main(int argc, char *argv[]) {
	if (!glfwInit()) return -1;

	GLFWwindow* window = glfwCreateWindow(1280, 720, "Signal Analysis", NULL, NULL);
	glfwMakeContextCurrent(window);

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO &io = ImGui::GetIO();
	(void)io;

	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init("#version 130"); // GLSL version

	while(!glfwWindowShouldClose(window)) {
		glfwPollEvents();

		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		ImGui::Begin("Signal Analysis Control");
		static float frequency = 100.0f;
		ImGui::InputFloat("Frequency (MHz)", &frequency);
		if(ImGui::Button("Set")) {
			std::cout<<"Set frequency to " << frequency << "\n";
		}
		ImGui::End();

		// Render
		ImGui::Render();
		glViewport(0, 0, 1280, 720);
		glClearColor(0.f, 0.f, 0.f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
		glfwSwapBuffers(window);
	}

	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}
