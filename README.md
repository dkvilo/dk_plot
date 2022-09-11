
# DK_Plot

This is super simple bitmap render written in C99, and implements couple of fun algorithms.
Have Fun

- David

<img src="https://github.com/dkvilo/dk_plot/blob/master/samples/plot.bmp" />

<img src="https://github.com/dkvilo/dk_plot/blob/master/samples/sierpinski_carpet.bmp" />

<img src="https://github.com/dkvilo/dk_plot/blob/master/samples/mandelbrot.bmp" />

# Plotting

```c
#define DK_BMP_IMPLEMENTATION
#include "dk_bmp.h"

int main(void) {

  dk_bmp_t bmp; 

  // Createa BMP Buffer and FILL with Red
  dk_bmp_create(&bmp, width, height, DK_RED);
  
  // FLUSH the buffer, with color
  dk_bmp_clear(&bmp, DK_WHITE);


  // Defien Data
  u32 values[10] = {20, 5, 30, 60, 10, 20, 5, 30, 60, 10};
  u32 colors[10] = {DK_RED, DK_GREEN, DK_BLUE, DK_YELLOW, DK_CYAN, DK_MAGENTA, DK_ORANGE, DK_PINK, DK_PURPLE, DK_BROWN};

  // Draw
  dk_bmp_draw_grid(&bmp, 0, 0, width, height, 50, 50, 0xCCCCCC);
  dk_bmp_draw_ruler(&bmp, 0, 0, width, height, 50, 50, DK_RED);
  dk_bmp_draw_bar_chart(&bmp, 0, 0, width, height / 2, values, 10, 60, colors);

  dk_bmp_draw_line_chart(&bmp, 100, 0, width, height / 2, values, 10, 60, colors);
  dk_bmp_draw_dot_chart(&bmp, 100, 0, width, height / 2, values, 10, 60, colors);
  dk_bm_draw_text(&bmp, 20, 700, "2022/09/11", 4, DK_BLACK);
  dk_bm_draw_text(&bmp, 860, 700, "DK-CHART", 4, DK_BLACK);
  dk_bmp_draw_pie_chart(&bmp, width / 2, height / 2, 100, values, 10, 60, colors);

  // Write out to .bmp file
  dk_bmp_write(&bmp, "output.bmp");
  
  return 0;
} 
```

# Drawing Custom Shapes

```c
#define DK_BMP_IMPLEMENTATION
#include "dk_bmp.h"

int main(void) {

  dk_bmp_t bmp; 

  // Createa BMP Buffer and FILL with Red
  dk_bmp_create(&bmp, width, height, DK_RED);
  
  // FLUSH the buffer, with color
  dk_bmp_clear(&bmp, DK_WHITE);

  // Draw Rect
  //
  // To draw other pimitives please check out the code
  dk_bmp_draw_rect(&bmp, 5, 5, 10, 10, DK_ORANGE);

  // Write out to .bmp file
  dk_bmp_write(&bmp, "output.bmp");
  
  return 0;
} 
```


