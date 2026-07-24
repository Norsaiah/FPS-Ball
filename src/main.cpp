#include "raylib.h"

#include <string>

int main()
{
  // Window Initialization
  //---------------------------------------------

  constexpr int screenWidth {1280};
  constexpr int screenHeight {720};

  InitWindow(screenWidth, screenHeight, "FPS Ball");

  //SetTargetFPS(GetMonitorRefreshRate(GetCurrentMonitor()));

  // Ball Properties
  //---------------------------------------------

  Vector2 ballSpeed {1000.0f, 1000.0f};
  constexpr float ballRadius {40.0f};

  Vector2 ball {screenWidth / 2, screenHeight / 2};

  //---------------------------------------------

  Color backgroundColor {RAYWHITE};
  
  while(!WindowShouldClose())
  {
    ClearBackground(backgroundColor);

    // Ball Motion
    //-------------------------------------------

    ball.x += ballSpeed.x * GetFrameTime();
    ball.y += ballSpeed.y * GetFrameTime();

    // Right edge
    if(ball.x >= screenWidth - ballRadius)
    {
      ball.x = screenWidth - ballRadius;
      ballSpeed.x = -ballSpeed.x;
      backgroundColor = RED;
    }
    // Left edge
    else if(ball.x <= ballRadius)
    {
      ball.x = ballRadius;
      ballSpeed.x = -ballSpeed.x;
      backgroundColor = GRAY;
    }

    // Bottom edge
    if(ball.y >= screenHeight - ballRadius)
    {
      ball.y = screenHeight - ballRadius;
      ballSpeed.y = -ballSpeed.y;
      backgroundColor = GREEN;
    }
    // Top edge
    else if(ball.y <= ballRadius)
    {
      ball.y = ballRadius;
      ballSpeed.y = -ballSpeed.y;
      backgroundColor = YELLOW;
    }

    //-------------------------------------------

    BeginDrawing();

      // Drawing text
      //-----------------------------------------

      std::string fpsText {"FPS: " + std::to_string(GetFPS())};
      DrawText(fpsText.c_str(), 10, 10, 50, BLACK);

      std::string refreshRateText {"Refresh rate: " + std::to_string(GetMonitorRefreshRate(GetCurrentMonitor()))};
      DrawText(refreshRateText.c_str(), 10, 60, 50, BLACK);

      DrawText(std::to_string(GetTime()).c_str(), 10, 110, 50, BLACK);

      // Drawing Ball
      //-----------------------------------------

      DrawCircleV(ball, ballRadius, BLUE);

    EndDrawing();
  }

  return 0;
}