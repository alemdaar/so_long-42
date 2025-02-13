#include <mlx.h>

#define TILE_SIZE 1

int main()
{
    void *mlx;
    void *win;
    void *img;
    int img_width, img_height;
    img_width = 0;
    img_height = 0;
    int map[10][10] = { /* Example Map */ 
                        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                        {1, 0, 1, 1, 0, 0, 0, 0, 1, 1},
                        {1, 0, 1, 0, 0, 1, 1, 0, 0, 1},
                        {1, 0, 1, 1, 0, 0, 1, 1, 0, 1},
                        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
                     };

    mlx = mlx_init();
    win = mlx_new_window(mlx, 1000, 900, "test");

    img = mlx_xpm_file_to_image(mlx, "enemy.xpm", &img_width, &img_height);

    for (int y = 0; y < 7; y++)
    {
        for (int x = 0; x < 10; x++)
        {
            if (map[y][x] == 1)  // Example: 1 is a wall, 0 is empty space
                mlx_put_image_to_window(mlx, win, img, x * TILE_SIZE, y * TILE_SIZE);
        }
    }

    mlx_loop(mlx);
    return (0);
}

