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

#if 0
  dk_bmp_draw_rect(&bmp, 5, 5, 10, 10, 0x00FF00FF);
  dk_bmp_draw_line(&bmp, 25, 25, 10, 10, 0x00FF00FF);
  dk_bmp_draw_line(&bmp, 25, 9, 9, 25, 0x00FF00FF);
  dk_bmp_draw_circle(&bmp, 20, 20, 10, DK_BLUE);
  dk_bmp_draw_cube(&bmp, 5, 5, 10, 10, 10, DK_CYAN);
  dk_bmp_draw_mandelbrot(&bmp, 0, 0, width, height, 10000);
#endif

  u32 values[10] = {20, 5, 30, 60, 10, 20, 5, 30, 60, 10};
  u32 colors[10] = {DK_RED, DK_GREEN, DK_BLUE, DK_YELLOW, DK_CYAN, DK_MAGENTA, DK_ORANGE, DK_PINK, DK_PURPLE, DK_BROWN};

  dk_bmp_draw_grid(&bmp, 0, 0, width, height, 50, 50, 0xCCCCCC);
  dk_bmp_draw_ruler(&bmp, 0, 0, width, height, 50, 50, DK_RED);
  dk_bmp_draw_bar_chart(&bmp, 0, 0, width, height / 2, values, 10, 60, colors);

  dk_bmp_draw_line_chart(&bmp, 100, 0, width, height / 2, values, 10, 60, colors);
  dk_bmp_draw_dot_chart(&bmp, 100, 0, width, height / 2, values, 10, 60, colors);
  dk_bm_draw_text(&bmp, 20, 700, "2022/09/11", 4, DK_BLACK);
  dk_bm_draw_text(&bmp, 860, 700, "DK-CHART", 4, DK_BLACK);
  dk_bmp_draw_pie_chart(&bmp, width / 2, height / 2, 100, values, 10, 60, colors);

#if 0
    dk_bmp_draw_fern(&bmp, 250, 0, 500, 500, 10000000);
    dk_bmp_draw_hilbert(&bmp, 0, 0, 500, 500, 10, 0, DK_BLUE);
    dk_bmp_draw_sierpinski(&bmp, 0, 0, 500, 500, 10, DK_BLUE);
    dk_bmp_draw_sierpinski_carpet(&bmp, 0, 0, 500, 500, 10, DK_BLUE);
    dk_bmp_draw_levy_c_curve(&bmp, 0, 0, 400, 200, 10, 0, DK_BLUE);
#endif

  dk_bmp_write(&bmp, "samples/output.bmp");

  return 0;
}
