#include <iostream>
#include <raylib.h>

#include <imgui.h>
#include <rlImGui.h>

int main() {
	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitWindow(800, 600, "Game++");

	// Initialize ImGui
	rlImGuiSetup(true);

	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(RAYWHITE);

		rlImGuiBegin();

		DrawText("First Window Created!!!", 265, 250, 30, RED);

		ImGui::Begin("test window");
		ImGui::Text("Hello, world!");
		ImGui::Button("Click me!");
		ImGui::End();

		rlImGuiEnd();
		EndDrawing();
	}

	rlImGuiShutdown();
	CloseWindow();
	return 0;
}