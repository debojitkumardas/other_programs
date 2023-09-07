#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "GLFW/glfw3.h"
#include <stdio.h>

#define WIDTH 1280
#define HEIGHT 720

static void glfw_error_callback(int error, const char* description) {
    fprintf(stderr, "GLFW Error %d: %s\n", error, description);
}

// Main code
int main() {
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit())
        return 1;

    // GL 3.0 + GLSL 130
    const char* glsl_version = "#version 130";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    // Create window with graphics context
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Basic Calculator", nullptr, nullptr);
    if (window == nullptr)
        return 1;
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Enable vsync

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
    //ImGui::StyleColorsLight();

    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);

    // Load Fonts
    io.Fonts->AddFontFromFileTTF("fonts/iosevka-term-regular.ttf", 32.0f);

    // Our state
    // bool show_demo_window = true;
    // bool show_another_window = false;
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    float num1 = 0.0f;
    float num2 = 0.0f;
    float result = 0.0f;

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        // Poll and handle events (inputs, window resize, etc.)
        // You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to tell if dear imgui wants to use your inputs.
        // - When io.WantCaptureMouse is true, do not dispatch mouse input data to your main application, or clear/overwrite your copy of the mouse data.
        // - When io.WantCaptureKeyboard is true, do not dispatch keyboard input data to your main application, or clear/overwrite your copy of the keyboard data.
        // Generally you may always pass all inputs to dear imgui, and hide them from your application based on those two flags.
        glfwPollEvents();

        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        ImGui::ShowDemoWindow();

        ImGuiWindowFlags window_flags = 0;

        window_flags |= ImGuiWindowFlags_NoTitleBar;
        bool p_open = true;

        const ImGuiViewport* main_viewport = ImGui::GetMainViewport();

        ImGui::SetNextWindowPos(ImVec2(main_viewport->WorkPos.x, main_viewport->WorkPos.y));
        ImGui::SetNextWindowSize(ImVec2(600, 600));

        ImGui::Begin("##", &p_open, window_flags);

        ImGui::Text("Enter two number: ");

        ImGui::SetNextItemWidth(300);
        ImGui::InputFloat("##1", &num1);

        ImGui::SameLine();

        ImGui::SetNextItemWidth(300);
        ImGui::InputFloat("##2", &num2);

        ImGui::BeginGroup();
        ImGui::Button("1", ImVec2(150, 150));
        ImGui::Button("4", ImVec2(150, 150));
        ImGui::Button("7", ImVec2(150, 150));
        ImGui::Button(".", ImVec2(150, 150));
        ImGui::EndGroup();

        ImGui::SameLine();
        ImGui::BeginGroup();
        ImGui::Button("2", ImVec2(150, 150));
        ImGui::Button("5", ImVec2(150, 150));
        ImGui::Button("8", ImVec2(150, 150));
        ImGui::Button("0", ImVec2(150, 150));
        ImGui::EndGroup();

        ImGui::SameLine();
        ImGui::BeginGroup();
        ImGui::Button("3", ImVec2(150, 150));
        ImGui::Button("6", ImVec2(150, 150));
        ImGui::Button("9", ImVec2(150, 150));
        ImGui::Button("=", ImVec2(150, 150));
        ImGui::EndGroup();

        // if (ImGui::Button("1"))

        if (ImGui::Button("Calculate sum"))
            result = num1 + num2;

        ImGui::Text("Result: %.2f", result);
        ImGui::End();

        // Rendering
        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
    }

    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
