#include <mlx.h>

#define TILE_SIZE 40

int map[7][10] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 0, 0, 0, 0, 1, 1},
    {1, 0, 1, 0, 0, 1, 1, 0, 0, 1},
    {1, 0, 1, 1, 0, 0, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

int main()
{
    void *mlx;
    void *win;
    void *wall_img;
    void *empty_img;
    int img_width, img_height;

    // Initialize mlx and create window
    mlx = mlx_init();
    win = mlx_new_window(mlx, 1000, 400, "So_Long");

    // Load wall and empty space images
    wall_img = mlx_xpm_file_to_image(mlx, "picss/wall.xpm", &img_width, &img_height);
    empty_img = mlx_xpm_file_to_image(mlx, "picss/player.xpm", &img_width, &img_height);

    // for (int y = 0; y < 20; y++) {
    //     for (int x = 0; x < 32; x++) {
    //         if (map[y][x] == 1) {
    //             // Draw wall
    mlx_put_image_to_window(mlx, win, wall_img, 0, 0);
            // } else {
            //     // Draw empty space
    mlx_put_image_to_window(mlx, win, empty_img, 40, 0);
    //         }
    //     }
    // }
	

    // Start the event loop
    mlx_loop(mlx);

    return (0);
}
