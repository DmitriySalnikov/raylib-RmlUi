#include "example.h"
#include "raylib.h"

int main()
{
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_MSAA_4X_HINT);
	auto size = Example::GetWindowSize();
	InitWindow(size.x, size.y, TextFormat("Raylib RmlUi %s", Example::GetWindowTitle()));
	SetTargetFPS(500);
	SetExitKey(0);
	Example::Initialize();
	while (Example::RunProgram())
	{
		if (WindowShouldClose())
		{
			Example::StopProgram();
			break;
		}
		Example::Update(GetFrameTime());

		if (IsKeyPressed(KEY_F8))
		{
			Example::ToggleDebugger();
		}

		BeginDrawing();

		ClearBackground(BLACK);

		Example::Render();

		DrawFPS(10, 10);

		EndDrawing();
	}

	Example::DeInitialize();

	CloseWindow();

	return 0;
}
