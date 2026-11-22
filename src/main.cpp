#include <iostream>
#include <raylib.h>

int main() {
	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitWindow(800, 600, "Game++");

	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(RAYWHITE);

		DrawText("First Window Created!!!", 265, 250, 30, RED);
		EndDrawing();
	}

	CloseWindow();
	return 0;
}