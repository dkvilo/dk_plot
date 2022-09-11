#if !defined(DK_BMP_H)
#define DK_BMP_H

#include "dk.h"
#include <math.h>

typedef u32 dk_color_t;

#define DK_BLACK 0x00000000
#define DK_WHITE 0x00FFFFFF
#define DK_RED 0x00FF0000
#define DK_GREEN 0x0000FF00
#define DK_BLUE 0x000000FF
#define DK_YELLOW 0x00FFFF00
#define DK_MAGENTA 0x00FF00FF
#define DK_CYAN 0x0000FFFF
#define DK_ORANGE 0x00FFA500
#define DK_PINK 0x00FFC0CB
#define DK_PURPLE 0x00800080
#define DK_BROWN 0x00A52A2A

#define M_PI 3.14159265358979323846

byte font[112][5] = {
  {0x00, 0x00, 0x00, 0x00, 0x00}, // (space)
  {0x00, 0x00, 0x4f, 0x00, 0x00}, // !
  {0x00, 0x07, 0x00, 0x07, 0x00}, // "
  {0x14, 0x7f, 0x14, 0x7f, 0x14}, // #
  {0x24, 0x2a, 0x7f, 0x2a, 0x12}, // $
  {0x23, 0x13, 0x08, 0x64, 0x62}, // %
  {0x36, 0x49, 0x55, 0x22, 0x50}, // &
  {0x00, 0x05, 0x03, 0x00, 0x00}, // '
  {0x00, 0x1c, 0x22, 0x41, 0x00}, // (
  {0x00, 0x41, 0x22, 0x1c, 0x00}, // )
  {0x14, 0x08, 0x3e, 0x08, 0x14}, // *
  {0x08, 0x08, 0x3e, 0x08, 0x08}, // +
  {0x00, 0x50, 0x30, 0x00, 0x00}, // ,
  {0x08, 0x08, 0x08, 0x08, 0x08}, // -
  {0x00, 0x60, 0x60, 0x00, 0x00}, // .
  {0x20, 0x10, 0x08, 0x04, 0x02}, // /
  {0x3e, 0x51, 0x49, 0x45, 0x3e}, //
  {0x00, 0x42, 0x7f, 0x40, 0x00}, // !
  {0x42, 0x61, 0x51, 0x49, 0x46}, // "
  {0x21, 0x41, 0x45, 0x4b, 0x31}, // #
  {0x18, 0x14, 0x12, 0x7f, 0x10}, // $
  {0x27, 0x45, 0x45, 0x45, 0x39}, // %
  {0x3c, 0x4a, 0x49, 0x49, 0x30}, // &
  {0x01, 0x71, 0x09, 0x05, 0x03}, // '
  {0x3e, 0x41, 0x41, 0x00, 0x00}, // (
  {0x00, 0x00, 0x41, 0x41, 0x3e}, // )
  {0x04, 0x02, 0x7f, 0x02, 0x04}, // *
  {0x08, 0x08, 0x3e, 0x08, 0x08}, // +
  {0x00, 0x80, 0x70, 0x30, 0x00}, // ,
  {0x08, 0x08, 0x08, 0x08, 0x08}, // -
  {0x00, 0x00, 0x60, 0x60, 0x00}, // .
  {0x20, 0x10, 0x08, 0x04, 0x02}, // /
  {0x3e, 0x51, 0x49, 0x45, 0x3e}, // 0
  {0x00, 0x42, 0x7f, 0x40, 0x00}, // 1
  {0x42, 0x61, 0x51, 0x49, 0x46}, // 2
  {0x21, 0x41, 0x45, 0x4b, 0x31}, // 3
  {0x18, 0x14, 0x12, 0x7f, 0x10}, // 4
  {0x27, 0x45, 0x45, 0x45, 0x39}, // 5
  {0x3c, 0x4a, 0x49, 0x49, 0x30}, // 6
  {0x01, 0x71, 0x09, 0x05, 0x03}, // 7
  {0x3e, 0x41, 0x41, 0x41, 0x3e}, // 8
  {0x4e, 0x51, 0x51, 0x51, 0x3e}, // 9
  {0x00, 0x00, 0x14, 0x00, 0x00}, // :
  {0x00, 0x40, 0x34, 0x00, 0x00}, // ;
  {0x00, 0x08, 0x14, 0x22, 0x41}, // <
  {0x14, 0x14, 0x14, 0x14, 0x14}, // =
  {0x41, 0x22, 0x14, 0x08, 0x00}, // >
  {0x02, 0x01, 0x51, 0x09, 0x06}, // ?
  {0x32, 0x49, 0x79, 0x41, 0x3e}, // @
  {0x7e, 0x11, 0x11, 0x11, 0x7e}, // A
  {0x7f, 0x49, 0x49, 0x49, 0x36}, // B
  {0x3e, 0x41, 0x41, 0x41, 0x22}, // C
  {0x7f, 0x41, 0x41, 0x22, 0x1c}, // D
  {0x7f, 0x49, 0x49, 0x49, 0x41}, // E
  {0x7f, 0x09, 0x09, 0x09, 0x01}, // F
  {0x3e, 0x41, 0x49, 0x49, 0x7a}, // G
  {0x7f, 0x08, 0x08, 0x08, 0x7f}, // H
  {0x00, 0x41, 0x7f, 0x41, 0x00}, // I
  {0x20, 0x40, 0x41, 0x3f, 0x01}, // J
  {0x7f, 0x08, 0x14, 0x22, 0x41}, // K
  {0x7f, 0x40, 0x40, 0x40, 0x40}, // L
  {0x7f, 0x02, 0x0c, 0x02, 0x7f}, // M
  {0x7f, 0x04, 0x08, 0x10, 0x7f}, // N
  {0x3e, 0x41, 0x41, 0x41, 0x3e}, // O
  {0x7f, 0x09, 0x09, 0x09, 0x06}, // P
  {0x3e, 0x41, 0x51, 0x21, 0x5e}, // Q
  {0x7f, 0x09, 0x19, 0x29, 0x46}, // R
  {0x46, 0x49, 0x49, 0x49, 0x31}, // S
  {0x01, 0x01, 0x7f, 0x01, 0x01}, // T
  {0x3f, 0x40, 0x40, 0x40, 0x3f}, // U
  {0x1f, 0x20, 0x40, 0x20, 0x1f}, // V
  {0x3f, 0x40, 0x38, 0x40, 0x3f}, // W
  {0x63, 0x14, 0x08, 0x14, 0x63}, // X
  {0x07, 0x08, 0x70, 0x08, 0x07}, // Y
  {0x61, 0x51, 0x49, 0x45, 0x43}, // Z
  {0x00, 0x7f, 0x41, 0x41, 0x00}, // [
  {0x02, 0x04, 0x08, 0x10, 0x20}, // "\"
  {0x00, 0x41, 0x41, 0x7f, 0x00}, // ]
  {0x04, 0x02, 0x01, 0x02, 0x04}, // ^
  {0x40, 0x40, 0x40, 0x40, 0x40}, // _
  {0x00, 0x01, 0x02, 0x04, 0x00}, // `
  {0x20, 0x54, 0x54, 0x54, 0x78}, // a
  {0x7f, 0x48, 0x44, 0x44, 0x38}, // b
  {0x38, 0x44, 0x44, 0x44, 0x20}, // c
  {0x38, 0x44, 0x44, 0x48, 0x7f}, // d
  {0x38, 0x54, 0x54, 0x54, 0x18}, // e
  {0x08, 0x7e, 0x09, 0x01, 0x02}, // f
  {0x0c, 0x52, 0x52, 0x52, 0x3e}, // g
  {0x7f, 0x08, 0x04, 0x04, 0x78}, // h
  {0x00, 0x44, 0x7d, 0x40, 0x00}, // i
  {0x20, 0x40, 0x44, 0x3d, 0x00}, // j
  {0x7f, 0x10, 0x28, 0x44, 0x00}, // k
  {0x00, 0x41, 0x7f, 0x40, 0x00}, // l
  {0x7c, 0x04, 0x18, 0x04, 0x78}, // m
  {0x7c, 0x08, 0x04, 0x04, 0x78}, // n
  {0x38, 0x44, 0x44, 0x44, 0x38}, // o
  {0x7c, 0x14, 0x14, 0x14, 0x08}, // p
  {0x08, 0x14, 0x14, 0x18, 0x7c}, // q
  {0x7c, 0x08, 0x04, 0x04, 0x08}, // r
  {0x48, 0x54, 0x54, 0x54, 0x20}, // s
  {0x04, 0x3f, 0x44, 0x40, 0x20}, // t
  {0x3c, 0x40, 0x40, 0x20, 0x7c}, // u
  {0x1c, 0x20, 0x40, 0x20, 0x1c}, // v
  {0x3c, 0x40, 0x30, 0x40, 0x3c}, // w
  {0x44, 0x28, 0x10, 0x28, 0x44}, // x
  {0x0c, 0x50, 0x50, 0x50, 0x3c}, // y
  {0x44, 0x64, 0x54, 0x4c, 0x44}, // z
  {0x00, 0x08, 0x36, 0x41, 0x00}, // {
  {0x00, 0x00, 0x7f, 0x00, 0x00}, // |
  {0x00, 0x41, 0x36, 0x08, 0x00}, // }
  {0x08, 0x08, 0x2a, 0x1c, 0x08}, // ->
  {0x08, 0x1c, 0x2a, 0x08, 0x08}, // <-
};

typedef struct dk_bmp_t
{
  u32 width;
  u32 height;
  u32 size;
  u8 *data;
} dk_bmp_t;

i32 dk_bmp_read(dk_bmp_t *bmp, const char *filename);

i32 dk_bmp_write(const dk_bmp_t *bmp, const char *filename);

void dk_bmp_free(dk_bmp_t *bmp);

i32 dk_bmp_get_pixel(const dk_bmp_t *bmp, i32 x, i32 y, dk_color_t *color);

i32 dk_bmp_set_pixel(dk_bmp_t *bmp, i32 x, i32 y, const dk_color_t *color);

void dk_bmp_display(const dk_bmp_t *bmp);

void dk_bmp_flip(dk_bmp_t *bmp);

void dk_bmp_mirror(dk_bmp_t *bmp);

void dk_bmp_rotate(dk_bmp_t *bmp);

#if defined(DK_BMP_IMPLEMENTATION)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DK_BMP_HEADER_SIZE 54

i32 dk_bmp_read(dk_bmp_t *bmp, const char *filename)
{
  FILE *file = fopen(filename, "rb");
  if (!file)
    return -1;

  u8 header[DK_BMP_HEADER_SIZE];
  fread(header, 1, DK_BMP_HEADER_SIZE, file);

  if (header[0] != 'B' || header[1] != 'M')
  {
    fclose(file);
    return -1;
  }

  // read the width and height
  bmp->width = *(i32 *)&header[18];
  bmp->height = *(i32 *)&header[22];

  // read the size
  bmp->size = *(i32 *)&header[2];

  // allocate memory
  bmp->data = (u8 *)malloc(bmp->size - DK_BMP_HEADER_SIZE);
  if (!bmp->data)
  {
    fclose(file);
    return -1;
  }

  fread(bmp->data, 1, bmp->size - DK_BMP_HEADER_SIZE, file);
  fclose(file);
  return 0;
}

i32 dk_bmp_write(const dk_bmp_t *bmp, const char *filename)
{
  FILE *file = fopen(filename, "wb");
  if (!file)
    return -1;

  u8 header[DK_BMP_HEADER_SIZE] = {0};
  header[0] = 'B';
  header[1] = 'M';
  *(u32 *)&header[2] = DK_BMP_HEADER_SIZE;
  *(u32 *)&header[10] = DK_BMP_HEADER_SIZE;
  *(u32 *)&header[14] = 40;
  *(u32 *)&header[18] = bmp->width;
  *(u32 *)&header[22] = bmp->height;
  *(u16 *)&header[26] = 1;
  *(u16 *)&header[28] = 24;
  *(u32 *)&header[34] = bmp->size;

  if (fwrite(header, 1, DK_BMP_HEADER_SIZE, file) != DK_BMP_HEADER_SIZE)
    dk_exit_failure();

  if (fwrite(bmp->data, 1, bmp->size, file) != bmp->size)
    dk_exit_failure();

  fclose(file);
  return 0;
}

void dk_bmp_free(dk_bmp_t *bmp)
{
  free(bmp->data);
}

i32 dk_bmp_get_pixel(const dk_bmp_t *bmp, i32 x, i32 y, dk_color_t *color)
{
  if (x < 0 || x >= bmp->width || y < 0 || y >= bmp->height)
    return -1;

  u8 *pixel = &bmp->data[(y * bmp->width + x) * 3];
  *color = (pixel[2] << 16) | (pixel[1] << 8) | pixel[0];
  return 0;
}

i32 dk_bmp_set_pixel(dk_bmp_t *bmp, i32 x, i32 y, const dk_color_t *color)
{
  if (x < 0 || x >= bmp->width || y < 0 || y >= bmp->height)
    return -1;

  u8 *pixel = &bmp->data[(y * bmp->width + x) * 3];
  pixel[0] = *color & 0xff;
  pixel[1] = (*color >> 8) & 0xff;
  pixel[2] = (*color >> 16) & 0xff;
  return 0;
}

void dk_bmp_clear(const dk_bmp_t *bmp, dk_color_t color)
{
  for (i32 y = 0; y < bmp->height; y++)
  {
    for (i32 x = 0; x < bmp->width; x++)
    {
      dk_bmp_set_pixel(bmp, x, y, &color);
    }
  }
}

void dk_bmp_create(dk_bmp_t *bmp, i32 width, i32 height, dk_color_t color)
{
  bmp->width = width;
  bmp->height = height;
  bmp->size = width * height * 3;
  bmp->data = (u8 *)malloc(bmp->size);
  dk_bmp_clear(bmp, color);
}

void dk_bmp_display(const dk_bmp_t *bmp)
{
  for (i32 x = 0; x < bmp->width; ++x)
  {
    for (i32 y = 0; y < bmp->height; ++y)
    {
      dk_color_t color;
      dk_bmp_get_pixel(bmp, x, y, &color);
      u8 r = (color >> 16) & 0xff;
      u8 g = (color >> 8) & 0xff;
      u8 b = color & 0xff;
      printf("\x1b[48;2;%d;%d;%dm  \x1b[0m", r, g, b);
    }
    printf("\n");
  }
}

void dk_bmp_flip(dk_bmp_t *bmp)
{
  u8 *data = (u8 *)malloc(bmp->size - DK_BMP_HEADER_SIZE);
  if (!data)
    dk_exit_failure();

  for (i32 y = 0; y < bmp->height; ++y)
  {
    memcpy(&data[y * bmp->width * 3], &bmp->data[(bmp->height - y - 1) * bmp->width * 3], bmp->width * 3);
  }

  free(bmp->data);
  bmp->data = data;
}

void dk_bmp_mirror(dk_bmp_t *bmp)
{
  u8 *data = (u8 *)malloc(bmp->size - DK_BMP_HEADER_SIZE);
  if (!data)
    dk_exit_failure();

  for (i32 y = 0; y < bmp->height; ++y)
  {
    for (i32 x = 0; x < bmp->width; ++x)
    {
      memcpy(&data[(y * bmp->width + x) * 3], &bmp->data[(y * bmp->width + bmp->width - x - 1) * 3], 3);
    }
  }

  free(bmp->data);
  bmp->data = data;
}

void dk_bmp_rotate(dk_bmp_t *bmp)
{
  u8 *data = (u8 *)malloc(bmp->size - DK_BMP_HEADER_SIZE);
  if (!data)
    dk_exit_failure();

  for (i32 y = 0; y < bmp->height; ++y)
  {
    for (i32 x = 0; x < bmp->width; ++x)
    {
      memcpy(&data[(x * bmp->height + bmp->height - y - 1) * 3], &bmp->data[(y * bmp->width + x) * 3], 3);
    }
  }

  free(bmp->data);
  bmp->data = data;

  i32 tmp = bmp->width;
  bmp->width = bmp->height;
  bmp->height = tmp;
}

void dk_bmp_resize(dk_bmp_t *bmp, i32 width, i32 height)
{
  u8 *data = (u8 *)malloc(width * height * 3);
  if (!data)
    dk_exit_failure();

  for (i32 y = 0; y < height; ++y)
  {
    for (i32 x = 0; x < width; ++x)
    {
      i32 x0 = x * bmp->width / width;
      i32 y0 = y * bmp->height / height;
      memcpy(&data[(y * width + x) * 3], &bmp->data[(y0 * bmp->width + x0) * 3], 3);
    }
  }

  free(bmp->data);
  bmp->data = data;

  bmp->width = width;
  bmp->height = height;
}

void dk_bmp_crop(dk_bmp_t *bmp, i32 x, i32 y, i32 width, i32 height)
{
  u8 *data = (u8 *)malloc(width * height * 3);
  if (!data)
    dk_exit_failure();

  for (i32 y0 = 0; y0 < height; ++y0)
  {
    for (i32 x0 = 0; x0 < width; ++x0)
    {
      memcpy(&data[(y0 * width + x0) * 3], &bmp->data[((y + y0) * bmp->width + x + x0) * 3], 3);
    }
  }

  free(bmp->data);
  bmp->data = data;

  bmp->width = width;
  bmp->height = height;
}

void dk_bmp_grayscale(dk_bmp_t *bmp)
{
  for (i32 y = 0; y < bmp->height; ++y)
  {
    for (i32 x = 0; x < bmp->width; ++x)
    {
      dk_color_t color;
      dk_bmp_get_pixel(bmp, x, y, &color);
      u8 r = (color >> 16) & 0xff;
      u8 g = (color >> 8) & 0xff;
      u8 b = color & 0xff;
      u8 gray = (r + g + b) / 3;
      color = (gray << 16) | (gray << 8) | gray;
      dk_bmp_set_pixel(bmp, x, y, &color);
    }
  }
}

void dk_bmp_draw_rect(dk_bmp_t *bmp, i32 x, i32 y, i32 width, i32 height, dk_color_t color)
{
  for (i32 y0 = 0; y0 < height; ++y0)
  {
    for (i32 x0 = 0; x0 < width; ++x0)
    {
      if (x0 == 0 || x0 == width - 1 || y0 == 0 || y0 == height - 1)
        dk_bmp_set_pixel(bmp, x + x0, y + y0, &color);
    }
  }
}

void dk_bmp_draw_circle(dk_bmp_t *bmp, i32 x, i32 y, i32 radius, dk_color_t color)
{
  for (i32 y0 = -radius; y0 <= radius; ++y0)
  {
    for (i32 x0 = -radius; x0 <= radius; ++x0)
    {
      if (x0 * x0 + y0 * y0 <= radius * radius)
        dk_bmp_set_pixel(bmp, x + x0, y + y0, &color);
    }
  }
}

void dk_bmp_draw_cube(dk_bmp_t *bmp, i32 x, i32 y, i32 width, i32 height, i32 depth, dk_color_t color)
{
  i32 x0 = x + width / 2;
  i32 y0 = y + height / 2;
  i32 z0 = depth / 2;

  // front
  dk_bmp_draw_line(bmp, x0 - width / 2, y0 - height / 2, x0 + width / 2, y0 - height / 2, color);
  dk_bmp_draw_line(bmp, x0 + width / 2, y0 - height / 2, x0 + width / 2, y0 + height / 2, color);
  dk_bmp_draw_line(bmp, x0 + width / 2, y0 + height / 2, x0 - width / 2, y0 + height / 2, color);
  dk_bmp_draw_line(bmp, x0 - width / 2, y0 + height / 2, x0 - width / 2, y0 - height / 2, color);

  // back
  dk_bmp_draw_line(bmp, x0 - width / 2, y0 - height / 2, x0 - width / 2, y0 - height / 2 - depth, color);
  dk_bmp_draw_line(bmp, x0 + width / 2, y0 - height / 2, x0 + width / 2, y0 - height / 2 - depth, color);
  dk_bmp_draw_line(bmp, x0 + width / 2, y0 + height / 2, x0 + width / 2, y0 + height / 2 - depth, color);
  dk_bmp_draw_line(bmp, x0 - width / 2, y0 + height / 2, x0 - width / 2, y0 + height / 2 - depth, color);

  // sides
  dk_bmp_draw_line(bmp, x0 - width / 2, y0 - height / 2, x0 - width / 2, y0 - height / 2 - depth, color);
  dk_bmp_draw_line(bmp, x0 + width / 2, y0 - height / 2, x0 + width / 2, y0 - height / 2 - depth, color);
  dk_bmp_draw_line(bmp, x0 + width / 2, y0 + height / 2, x0 + width / 2, y0 + height / 2 - depth, color);
  dk_bmp_draw_line(bmp, x0 - width / 2, y0 + height / 2, x0 - width / 2, y0 + height / 2 - depth, color);

  // top
  dk_bmp_draw_line(bmp, x0 - width / 2, y0 - height / 2 - depth, x0 + width / 2, y0 - height / 2 - depth, color);
  dk_bmp_draw_line(bmp, x0 + width / 2, y0 - height / 2 - depth, x0 + width / 2, y0 + height / 2 - depth, color);
  dk_bmp_draw_line(bmp, x0 + width / 2, y0 + height / 2 - depth, x0 - width / 2, y0 + height / 2 - depth, color);
  dk_bmp_draw_line(bmp, x0 - width / 2, y0 + height / 2 - depth, x0 - width / 2, y0 - height / 2 - depth, color);

  // bottom
  dk_bmp_draw_line(bmp, x0 - width / 2, y0 - height / 2, x0 + width / 2, y0 - height / 2, color);
  dk_bmp_draw_line(bmp, x0 + width / 2, y0 - height / 2, x0 + width / 2, y0 + height / 2, color);
  dk_bmp_draw_line(bmp, x0 + width / 2, y0 + height / 2, x0 - width / 2, y0 + height / 2, color);
  dk_bmp_draw_line(bmp, x0 - width / 2, y0 + height / 2, x0 - width / 2, y0 - height / 2, color);
}

// merge two bitmaps
// FIXME: this is not working correctly
void dk_bmp_merge(dk_bmp_t *bmp, dk_bmp_t *bmp2, i32 x, i32 y)
{
  for (i32 y0 = 0; y0 < bmp2->height; ++y0)
  {
    for (i32 x0 = 0; x0 < bmp2->width; ++x0)
    {
      dk_color_t color;
      dk_bmp_get_pixel(bmp2, x0, y0, &color);
      if (color != 0)
        dk_bmp_set_pixel(bmp, x + x0, y + y0, &color);
    }
  }
}

void dk_bmp_draw_pixel(dk_bmp_t *bmp, i32 x, i32 y, dk_color_t color)
{
  if (x < 0 || x >= bmp->width || y < 0 || y >= bmp->height)
    return;

  bmp->data[y * bmp->width + x] = color;
}

void dk_bmp_skew(dk_bmp_t *bmp, i32 skew)
{
  u8 *data = (u8 *)malloc(bmp->width * bmp->height * 3);
  if (!data)
    dk_exit_failure();

  for (i32 y = 0; y < bmp->height; ++y)
  {
    for (i32 x = 0; x < bmp->width; ++x)
    {
      i32 y0 = y + (x - bmp->width / 2) * skew / 100;
      if (y0 < 0)
        y0 = 0;
      if (y0 >= bmp->height)
        y0 = bmp->height - 1;
      memcpy(&data[(y * bmp->width + x) * 3], &bmp->data[(y0 * bmp->width + x) * 3], 3);
    }
  }

  free(bmp->data);
  bmp->data = data;
}

u32 dk_color_to_hex(dk_color_t color)
{
  return (color & 0xFF0000) >> 16 | (color & 0xFF00) | (color & 0xFF) << 16;
}

void dk_bmp_draw_mandelbrot (dk_bmp_t *bmp, i32 x, i32 y, i32 width, i32 height, i32 max_iter)
{
  for (i32 y0 = 0; y0 < height; ++y0)
  {
    for (i32 x0 = 0; x0 < width; ++x0)
    {
      double c_re = (x0 - width / 2.0) * 4.0 / width;
      double c_im = (y0 - height / 2.0) * 4.0 / width;
      double x = 0, y = 0;
      i32 iter = 0;
      while (x * x + y * y <= 4 && iter < max_iter)
      {
        double x_new = x * x - y * y + c_re;
        y = 2 * x * y + c_im;
        x = x_new;
        iter++;
      }

      dk_color_t color = 0;
      if (iter < max_iter)
      {
        i32 r = iter * 255 / max_iter;
        i32 g = 255 - r;
        i32 b = 0;
        color = dk_color_to_hex(r << 32 | g << 16 | b << 8);
      }
      dk_bmp_set_pixel(bmp, x0 + x, y0 + y, &color);
    }
  }
}

void dk_bmp_draw_line(dk_bmp_t *bmp, i32 x0, i32 y0, i32 x1, i32 y1, dk_color_t color)
{
  i32 dx = abs(x1 - x0);
  i32 sx = x0 < x1 ? 1 : -1;
  i32 dy = -abs(y1 - y0);
  i32 sy = y0 < y1 ? 1 : -1;
  i32 err = dx + dy;
  i32 e2;

  while (1)
  {
    dk_bmp_set_pixel(bmp, x0, y0, &color);
    if (x0 == x1 && y0 == y1)
      break;
    e2 = 2 * err;
    if (e2 >= dy)
    {
      err += dy;
      x0 += sx;
    }
    if (e2 <= dx)
    {
      err += dx;
      y0 += sy;
    }
  }
}

void dk_bmp_draw_arc(dk_bmp_t *bmp, i32 x, i32 y, i32 radius, i32 start_angle, i32 end_angle, dk_color_t color)
{
  for (i32 angle = start_angle; angle <= end_angle; ++angle)
  {
    double rad = angle * M_PI / 180;
    i32 x0 = x + radius * cos(rad);
    i32 y0 = y + radius * sin(rad);
    dk_bmp_set_pixel(bmp, x0, y0, &color);
  }
}

// draw arch filled with color
void dk_bmp_draw_arc_filled(dk_bmp_t *bmp, i32 x, i32 y, i32 radius, i32 start_angle, i32 end_angle, dk_color_t color)
{
  for (i32 angle = start_angle; angle <= end_angle; ++angle)
  {
    double rad = angle * M_PI / 180;
    i32 x0 = x + radius * cos(rad);
    i32 y0 = y + radius * sin(rad);

    for (i32 i = 0; i < 10; ++i)
    {
      dk_bmp_draw_line(bmp, x + i, y + i, x0 + i, y0 +i, color);
    }
  }
}

// draw PIE CHART on the bitmap
void dk_bmp_draw_pie_chart(dk_bmp_t *bmp, i32 x, i32 y, i32 radius, i32 *values, i32 count, i32 max_value, dk_color_t *colors)
{
  i32 total = 0;
  for (i32 i = 0; i < count; ++i)
    total += values[i];

  i32 start_angle = 0;
  for (i32 i = 0; i < count; ++i)
  {
    i32 end_angle = start_angle + values[i] * 360 / total;
    dk_bmp_draw_arc_filled(bmp, x, y, radius, start_angle, end_angle, colors[i]);
    start_angle = end_angle;
  }
}


void dk_bmp_draw_dot_chart(dk_bmp_t *bmp, i32 x, i32 y, i32 width, i32 height, i32 *values, i32 count, i32 max_value, dk_color_t *colors)
{
  i32 step = width / count;
  for (i32 i = 0; i < count; ++i)
  {
    i32 x0 = x + i * step;
    i32 y0 = y + height - values[i] * height / max_value;
    y0 = y + height - (y0 - y);
    dk_bmp_draw_arc_filled(bmp, x0, y0, 10, 0, 360, colors[i]);
    dk_bmp_draw_arc(bmp, x0, y0, 10, 0, 360, 0x000000);
  }
}

// draw filled rect on the bitmap
void dk_bmp_draw_rect_filled(dk_bmp_t *bmp, i32 x, i32 y, i32 width, i32 height, dk_color_t color)
{
  for (i32 y0 = y; y0 < y + height; ++y0)
  {
    for (i32 x0 = x; x0 < x + width; ++x0)
    {
      dk_bmp_set_pixel(bmp, x0, y0, &color);
    }
  }
}

// draw grid on the bitmap
void dk_bmp_draw_grid(dk_bmp_t *bmp, i32 x, i32 y, i32 width, i32 height, i32 cell_width, i32 cell_height, dk_color_t color)
{
  for (i32 y0 = y; y0 < y + height; y0 += cell_height)
  {
    for (i32 x0 = x; x0 < x + width; x0 += cell_width)
    {
      dk_bmp_draw_rect(bmp, x0, y0, cell_width, cell_height, color);
    }
  }
}

// draw ruler on the bitmap
void dk_bmp_draw_ruler(dk_bmp_t *bmp, i32 x, i32 y, i32 width, i32 height, i32 cell_width, i32 cell_height, dk_color_t color)
{
  for (i32 y0 = y; y0 < y + height; y0 += cell_height)
  {
    for (i32 x0 = x; x0 < x + width; x0 += cell_width)
    {
      dk_bmp_draw_line(bmp, x0, y0, x0 + cell_width, y0 + cell_height, color);
    }
  }
}

void dk_bmp_draw_bar_chart(dk_bmp_t *bmp, i32 x, i32 y, i32 width, i32 height, i32 *values, i32 count, i32 max_value, dk_color_t *colors)
{
  i32 bar_width = width / count;
  for (i32 i = 0; i < count; ++i)
  {
    i32 bar_height = values[i] * height / max_value;
    dk_bmp_draw_rect_filled(bmp, x + i * bar_width, y, bar_width, bar_height, colors[i]);
    dk_bmp_draw_rect(bmp, x + i * bar_width, y, bar_width, bar_height, 0x000000);
  }
}


// draw line chart on the bitmap
// FIXME: ---
void dk_bmp_draw_line_chart(dk_bmp_t *bmp, i32 x, i32 y, i32 width, i32 height, i32 *values, i32 count, i32 max_value, dk_color_t *colors)
{
  i32 x0 = x;
  i32 y0 = y + height - values[0] * height / max_value;
  for (i32 i = 1; i < count; ++i)
  {
    i32 x1 = x + i * width / count;
    i32 y1 = y + height - values[i] * height / max_value;
  
    dk_bmp_draw_line(bmp, x0, y0, x1, y1, colors[i]);
    for (i32 j = 0; j < 8; ++j)
    {
      dk_bmp_draw_line(bmp, x0 + j, y0 + j, x1 + j, y1 + j, colors[i]);
    }

    x0 = x1;
    y0 = y1;
  }
}


void dk_bmp_draw_fern(dk_bmp_t *bmp, i32 x, i32 y, i32 width, i32 height, i32 max_iter)
{
  double x0 = 0, y0 = 0;
  for (i32 i = 0; i < max_iter; ++i)
  {
    double x1, y1;
    double r = (double)rand() / RAND_MAX;
    if (r < 0.01)
    {
      x1 = 0;
      y1 = 0.16 * y0;
    }
    else if (r < 0.86)
    {
      x1 = 0.85 * x0 + 0.04 * y0;
      y1 = -0.04 * x0 + 0.85 * y0 + 1.6;
    }
    else if (r < 0.93)
    {
      x1 = 0.2 * x0 - 0.26 * y0;
      y1 = 0.23 * x0 + 0.22 * y0 + 1.6;
    }
    else
    {
      x1 = -0.15 * x0 + 0.28 * y0;
      y1 = 0.26 * x0 + 0.24 * y0 + 0.44;
    }

    x0 = x1;
    y0 = y1;

    i32 x2 = x + x0 * width / 10;
    i32 y2 = y + y0 * height / 12;
    dk_color_t color = 0;
    dk_bmp_set_pixel(bmp, x2, y2, &color);
  }
}

void dk_bmp_draw_hilbert(dk_bmp_t *bmp, i32 x, i32 y, i32 width, i32 height, i32 depth, i32 angle, dk_color_t color)
{
  if (depth == 0)
    return;

  i32 width0 = width / 2;
  i32 height0 = height / 2;

  switch (angle)
  {
    case 0:
      dk_bmp_draw_hilbert(bmp, x, y, width0, height0, depth - 1, 1, color);
      dk_bmp_draw_line(bmp, x, y, x + width0, y, color);
      dk_bmp_draw_hilbert(bmp, x, y, width0, height0, depth - 1, 0, color);
      dk_bmp_draw_line(bmp, x + width0, y, x + width0, y + height0, color);
      dk_bmp_draw_hilbert(bmp, x + width0, y + height0, width0, height0, depth - 1, 0, color);
      dk_bmp_draw_line(bmp, x + width0, y + height0, x, y + height0, color);
      dk_bmp_draw_hilbert(bmp, x, y + height0, width0, height0, depth - 1, 3, color);
      break;
    case 1:
      dk_bmp_draw_hilbert(bmp, x + width0, y, width0, height0, depth - 1, 0, color);
      dk_bmp_draw_line(bmp, x + width0, y, x + width0, y + height0, color);
      dk_bmp_draw_hilbert(bmp, x, y, width0, height0, depth - 1, 1, color);
      dk_bmp_draw_line(bmp, x, y + height0, x + width0, y + height0, color);
      dk_bmp_draw_hilbert(bmp, x, y, width0, height0, depth - 1, 1, color);
      dk_bmp_draw_line(bmp, x, y, x, y + height0, color);
      dk_bmp_draw_hilbert(bmp, x, y + height0, width0, height0 , depth - 1, 2, color);
      break;
    case 2:
      dk_bmp_draw_hilbert(bmp, x, y + height0, width0, height0, depth - 1, 3, color);
      dk_bmp_draw_line(bmp, x, y + height0, x, y, color);
      dk_bmp_draw_hilbert(bmp, x + width0, y + height0, width0, height0, depth - 1, 2, color);
      dk_bmp_draw_line(bmp, x + width0, y + height0, x + width0, y, color);
      dk_bmp_draw_hilbert(bmp, x + width0, y + height0, width0, height0, depth - 1, 2, color);
      dk_bmp_draw_line(bmp, x + width0, y, x, y, color);
      dk_bmp_draw_hilbert(bmp, x, y, width0, height0, depth - 1, 1, color);
      break;
    case 3:
      dk_bmp_draw_hilbert(bmp, x, y, width0, height0, depth - 1, 2, color);
      dk_bmp_draw_line(bmp, x, y, x + width0, y, color);
      dk_bmp_draw_hilbert(bmp, x + width0, y + height0, width0, height0, depth - 1, 3, color);
      dk_bmp_draw_line(bmp, x + width0, y, x + width0, y + height0, color);
      dk_bmp_draw_hilbert(bmp, x + width0, y + height0, width0, height0, depth - 1, 3, color);
      dk_bmp_draw_line(bmp, x + width0, y + height0, x, y + height0, color);
      dk_bmp_draw_hilbert(bmp, x, y + height0, width0, height0, depth - 1, 0, color);
      break;
  }
}

void dk_bmp_draw_sierpinski(dk_bmp_t *bmp, i32 x, i32 y, i32 width, i32 height, i32 depth, dk_color_t color)
{
  if (depth == 0)
    return;

  i32 width0 = width / 2;
  i32 height0 = height / 2;

  dk_bmp_draw_sierpinski(bmp, x, y, width0, height0, depth - 1, color);
  dk_bmp_draw_sierpinski(bmp, x + width0, y, width0, height0, depth - 1, color);
  dk_bmp_draw_sierpinski(bmp, x + width0 / 2, y + height0, width0, height0, depth - 1, color);

  dk_bmp_draw_line(bmp, x, y, x + width, y, color);
  dk_bmp_draw_line(bmp, x + width0, y, x + width0, y + height, color);
  dk_bmp_draw_line(bmp, x, y, x + width0, y + height, color);

  dk_bmp_draw_line(bmp, x + width0, y + height, x + width, y, color);
  dk_bmp_draw_line(bmp, x + width, y, x + width, y + height, color);
  dk_bmp_draw_line(bmp, x + width, y + height, x + width0, y + height, color);

  dk_bmp_draw_line(bmp, x + width0, y + height, x, y + height, color);
  dk_bmp_draw_line(bmp, x, y + height, x, y, color);
  dk_bmp_draw_line(bmp, x, y, x + width0, y, color);
}

void dk_bmp_draw_sierpinski_carpet(dk_bmp_t *bmp, i32 x, i32 y, i32 width, i32 height, i32 depth, dk_color_t color)
{
  if (depth == 0)
    return;

  i32 width0 = width / 3;
  i32 height0 = height / 3;

  dk_color_t color0 = dk_color_to_hex(((x + width) << 32 | (y + height) << 16 | (width + height) << 8));

  dk_bmp_draw_sierpinski_carpet(bmp, x, y, width0, height0, depth - 1, color0);
  dk_bmp_draw_sierpinski_carpet(bmp, x + width0, y, width0, height0, depth - 1, color0);
  dk_bmp_draw_sierpinski_carpet(bmp, x + width0 * 2, y, width0, height0, depth - 1, color0);

  dk_bmp_draw_sierpinski_carpet(bmp, x, y + height0, width0, height0, depth - 1, color);
  dk_bmp_draw_sierpinski_carpet(bmp, x + width0 * 2, y + height0, width0, height0, depth - 1, color0);

  dk_bmp_draw_sierpinski_carpet(bmp, x, y + height0 * 2, width0, height0, depth - 1, color);
  dk_bmp_draw_sierpinski_carpet(bmp, x + width0, y + height0 * 2, width0, height0, depth - 1, color0);
  dk_bmp_draw_sierpinski_carpet(bmp, x + width0 * 2, y + height0 * 2, width0, height0, depth - 1, color0);

  dk_bmp_draw_rect(bmp, x + width0, y + height0, width0, height0, color0);
}

void dk_bmp_draw_levy_c_curve(dk_bmp_t *bmp, i32 x, i32 y, i32 width, i32 height, i32 depth, i32 direction, dk_color_t color)
{
  if (depth == 0)
    return;

  i32 width0 = width / 2;
  i32 height0 = height / 2;

  switch (direction)
  {
    case 0:
      dk_bmp_draw_levy_c_curve(bmp, x, y, width0, height0, depth - 1, 0, color);
      dk_bmp_draw_line(bmp, x, y, x + width0, y + height0, color);
      dk_bmp_draw_levy_c_curve(bmp, x + width0, y + height0, width0, height0, depth - 1, 1, color);
      break;
    case 1:
      dk_bmp_draw_levy_c_curve(bmp, x + width0, y, width0, height0, depth - 1, 0, color);
      dk_bmp_draw_line(bmp, x + width0, y, x, y + height0, color);
      dk_bmp_draw_levy_c_curve(bmp, x, y + height0, width0, height0, depth - 1, 1, color);
      break;
  }
}

void dk_bm_draw_text(dk_bmp_t* bmp, i32 x, i32 y, byte *text, i32 size, i32 color) {
  i32 i, j, k, l, m, n;
  i32 c;
  i32 len = strlen(text);
  for (i = 0; i < len; i++) {
    c = text[i] - 16;
    for (j = 0; j < 5; j++) {
      for (k = 0; k < 8; k++) {
        if ((font[c][j] >> k) & 0x01) {
          for (l = 0; l < size; l++) {
            for (m = 0; m < size; m++) {
              dk_bmp_draw_rect_filled(bmp, x + (i * 6 * size) + (j * size) + l, y - (k * size) + m, 1, 1, color);
            }
          }
        } 
      }
    }
  }
}

#endif // DK_BMP_IMPLEMENTATION

#endif // DK_BMP_H