#include <mlx.h>

void    my_draw_function(void *mlx_ptr, void *win_ptr)
{
    // Example function to draw something on the window.
    mlx_string_put(mlx_ptr, win_ptr, 50, 50, 0xFFFFFF, "Window Redrawn!");
}

int     mouse_click(int button, int x, int y, void *param)
{
    void    *mlx_ptr;
    void    *win_ptr;

    mlx_ptr = ((void **)param)[0];  // Get mlx_ptr
    win_ptr = ((void **)param)[1];  // Get win_ptr

    if (button == 1)  // Left click event
    {
        mlx_clear_window(mlx_ptr, win_ptr);  // Clear the window
        my_draw_function(mlx_ptr, win_ptr);  // Redraw the window (you can draw whatever you want here)
    }
    return (0);
}

int main()
{
    void    *mlx_ptr;
    void    *win_ptr;
    void    *param[2];

    mlx_ptr = mlx_init();  // Initialize the mlx
    win_ptr = mlx_new_window(mlx_ptr, 800, 600, "MLX Window");

    param[0] = mlx_ptr;  // Pass mlx_ptr to event handler
    param[1] = win_ptr;  // Pass win_ptr to event handler

    mlx_hook(win_ptr, 4, 1L<<2, mouse_click, param);  // Hook to mouse click event

    mlx_loop(mlx_ptr);  // Start the mlx loop
    return (0);
}
