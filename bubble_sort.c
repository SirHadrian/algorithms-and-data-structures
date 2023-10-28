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

#define BAR_WIDTH 2
#define BARS WIDTH / BAR_WIDTH

#define LEN(array) sizeof(array)/sizeof(array[0])

void swap(int *a, int *b);
void bubble_sort(int *const array, const int length, const int step);

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
      bubble_sort(bars_array, BARS, step);

    }
    EndDrawing();
  }
  CloseWindow();

  return EXIT_SUCCESS;
}

void 
bubble_sort(int *const array, const int length, const int step) 
{
  bool swapped;
  for (int i = 0; i < length - 1; ++i) 
  {
    swapped = false;
    for (int j = 0; j < length - 1 - i; ++j) 
    {
      // Delay next step
      if (j >= step) break;

      if (array[j] > array[j + 1]) 
      {
        swap(&array[j], &array[j + 1]);
      }
    }
    if (swapped == false) break;
  }
}

void 
swap(int *const a, int *const b) 
{
  const int temp = *a;
  *a = *b;
  *b = temp;
}
