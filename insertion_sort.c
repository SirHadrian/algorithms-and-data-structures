#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>

#include "timer.h"

typedef unsigned int uint;

#define WIDTH 800
#define HEIGTH 600
#define WINDOW_NAME "Alg Visualizer"
#define FPS 60

#define START_DELAY 1
#define DELAY 0

#define BAR_WIDTH 1
#define BARS WIDTH / BAR_WIDTH

#define LEN(array) sizeof(array)/sizeof(array[0])

void insertion_sort(int *const array, const int length, const int step);

int
main(void)
{
  SetTraceLogLevel(LOG_NONE);
  InitWindow(WIDTH, HEIGTH, WINDOW_NAME);
  SetTargetFPS(FPS);

  Color black = {0x00, 0x00, 0x00, 0xFF};

  Timer timer;
  start_timer(&timer, GetTime(), START_DELAY);

  int step = 0;

  int bars_array[BARS];

  for (int i = 0; i < BARS; ++i)
  {
    bars_array[i] = GetRandomValue(10, HEIGTH);
  }

  while (!WindowShouldClose()) 
  {
    if (IsKeyDown(KEY_Q)) break;

    BeginDrawing();
    {
      ClearBackground(black);

      for (int i = 0; i < BARS; ++i)
      {
        DrawRectangle(i * BAR_WIDTH, HEIGTH - bars_array[i], BAR_WIDTH, 
            bars_array[i], RED);
      }

      if (timer_done(&timer, GetTime())) 
      {
        start_timer(&timer, GetTime(), DELAY);
        if (step < BARS) step++;
      }
      insertion_sort(bars_array, BARS, step);

    }
    EndDrawing();
  }
  CloseWindow();

  return EXIT_SUCCESS;
}

void 
insertion_sort(int *const array, const int length, const int step) 
{
  for (int i = 1; i < length; ++i)
  {
    // Delay next step
    if (i >= step) break;

    int key = array[i];

    int j = i - 1;
    while (j >= 0 && key < array[j])
    {
      array[j + 1] = array[j];
      --j;
    }
    array[j + 1] = key;
  }
}
