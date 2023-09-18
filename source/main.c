/**
 * David Kviloria
 * License: Public Domain
 */
#include "dk.h"

#include <stdlib.h>
#include <string.h>

#define DK_BMP_IMPLEMENTATION
#include "dk_bmp.h"

int
main(int argc, char const* argv[])
{
  i32 width = 1080;
  i32 height = 720;

  dk_bmp_t bmp;
  dk_bmp_create(&bmp, width, height, DK_RED);
  dk_bmp_clear(&bmp, DK_WHITE);

  dk_bmp_draw_rect(&bmp, 5, 5, 10, 10, 0x00FF00FF);
  dk_bmp_draw_line(&bmp, 25, 25, 10, 10, 0x00FF00FF);
  dk_bmp_draw_line(&bmp, 25, 9, 9, 25, 0x00FF00FF);
  dk_bmp_draw_circle(&bmp, 20, 20, 200, DK_BLUE);

  dk_bmp_draw_grid(&bmp, 0, 0, width, height, 50, 50, 0xCCCCCC);
  dk_bmp_draw_ruler(&bmp, 0, 0, width, height, 50, 50, DK_RED);

  dk_bm_draw_text(&bmp, 20, 700, "Hello/World", 4, DK_BLACK);
  dk_bm_draw_text(&bmp, 860, 700, "DK-CHART", 4, DK_BLACK);

  dk_bmp_write(&bmp, "samples/output.bmp");

  return 0;
}
