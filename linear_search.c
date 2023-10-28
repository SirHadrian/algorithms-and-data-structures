#include <raylib.h>
#include <stdlib.h>

#include "timer.h"

#define WIDTH 800
#define HEIGTH 600
#define WINDOW_NAME "Alg Visualizer"
#define FPS 60
#define OFFSET_Y 50

#define FAT 20
#define DELAY .2
#define TALL 20
#define START_HEIGHT HEIGTH - OFFSET_Y
#define GAP_SIZE 30
#define HALF_WIDTH WIDTH / 2

#define LEN(array) sizeof(array)/sizeof(array[0])

int linear_search(const int * const array, const int length, const int step, 
    const int search);
void draw_array(const int * const array, const int length);

int 
main(void) 
{
  SetTraceLogLevel(LOG_NONE);
  InitWindow(WIDTH, HEIGTH, WINDOW_NAME);
  SetTargetFPS(FPS);

  Color black = {0x00, 0x00, 0x00, 0xFF};

  int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int length = LEN(array);

  Timer timer;
  start_timer(&timer, GetTime(), DELAY);

  int step = 0;

  while (!WindowShouldClose()) 
  {
    if (IsKeyDown(KEY_Q)) break;

    BeginDrawing();
    {
      ClearBackground(black);
      draw_array(array, length);

      if (timer_done(&timer, GetTime())) 
      {
        start_timer(&timer, GetTime(), DELAY);
        if (step < length) step++;
      }

      linear_search(array, length, step, 7);
    }
    EndDrawing();
  }
  CloseWindow();

  return EXIT_SUCCESS;
}

void 
draw_array(const int *const array, const int length) 
{
  for (int i = 0; i < length; ++i) 
  {
    int item_size = array[i] * TALL;
    int gaps = i * GAP_SIZE;
    int span = length * GAP_SIZE;

    DrawText(TextFormat("%d", array[i]), gaps + HALF_WIDTH - span / 2,
        START_HEIGHT - item_size - 20, 20, BLUE);
    DrawRectangle(gaps + HALF_WIDTH - span / 2, START_HEIGHT - item_size, TALL,
        item_size, GRAY);
    DrawText(TextFormat("%d", i), gaps + HALF_WIDTH - span / 2,
        START_HEIGHT + 10, 20, ORANGE);
  }
}

int
linear_search(const int *const array, const int length, const int step,
    const int search) 
{
  for (int i = 0; i < length; ++i) 
  {
    int gaps = i * GAP_SIZE;
    int span = length * GAP_SIZE;

    // Delay next step
    if (i >= step) break;

    DrawRectangle(gaps + HALF_WIDTH - span / 2, START_HEIGHT - TALL * array[i],
        FAT, array[i] * TALL, (Color){0xF0, 0xF0, 0x6F, 0xFF});

    if (array[i] == search) 
    {
      DrawRectangle(gaps + HALF_WIDTH - span / 2,
          START_HEIGHT - TALL * array[i], FAT, array[i] * TALL,
          GREEN);
      return i;
    }
  }
  return -1;
}
