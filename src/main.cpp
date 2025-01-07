#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <GLFW/glfw3.h>

#include "SDRConfigWindow.h"
#include "ConstellationWindow.h"
#include "SDR.h"

int main(int argc, char *argv[]) {
	if (!glfwInit()) return -1;

	SDR* sdr = new SDR();

	sdr->startRX(sdr);

	SDRConfigWindow* sdrConfigWindow = new SDRConfigWindow("SDR Config", sdr);
	ConstellationWindow* constellationWindow = new ConstellationWindow("Constellation");

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

		sdrConfigWindow->draw();
		constellationWindow->draw();

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
