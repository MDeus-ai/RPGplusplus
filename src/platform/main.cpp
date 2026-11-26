#include <iostream>
#include <raylib.h>

#include <imgui.h>
#include <rlImGui.h>

#include <gameMain.h>

int main(void) {

#if PRODUCTION_BUILD == 1
    SetTraceLogLevel(LOG_NONE); // no log output to the console by raylib
#endif

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(800, 600, "RPG++");
    SetExitKey(KEY_NULL); // Disable exit key (default is ESC)
    SetTargetFPS(240);

    // INITIALIZE IMGUI
    rlImGuiSetup(true);

    ImGuiIO &io = ImGui::GetIO();
    ////io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;  // Enable
    /// Keyboard /io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;   //
    /// Enable Gamepad
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable; // Enable Docking
    io.FontGlobalScale = 2;

    // INITIALIZE GAME
    if (!initGame()) {
        return 0;
    }

    // ================================================================
    // GAME LOOP
    // ================================================================
    while (!WindowShouldClose()) {
        rlImGuiBegin();
        BeginDrawing();
        ClearBackground(RAYWHITE);

        ImGui::Begin("Another Window");
        ImGui::Text("This is another window!");
        ImGui::Separator();
        ImGui::NewLine();
        static float a = 0;

        ImGui::SliderFloat("Slider", &a, 0, 1);

        // Call the ImGui end function to finish the window
        ImGui::End();

        // = Update Game =
        if (!updateGame()) {
            CloseWindow();
        }

        // Call the rlImGui end function to finish the ImGui frame
        rlImGuiEnd();
        EndDrawing();
    }
    // ================================================================
    // END OF GAME LOOP
    // ================================================================

    CloseWindow();

    closeGame();

    rlImGuiShutdown();
    return 0;
}