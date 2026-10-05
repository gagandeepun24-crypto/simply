#include <stdio.h>

int main() {
    int row, col;
    float x, y, u, v, temp;
    int i;

    // Loop through rows and columns of the terminal grid
    for (row = 0; row < 25; row++) {
        for (col = 0; col < 80; col++) {
            x = 0;
            y = 0;
            // Scale coordinates to fit the Mandelbrot set boundaries
            u = (col - 40) / 20.0f;
            v = (row - 12.5f) / 10.0f;
            
            // Iteration formula: z = z^2 + c
            for (i = 0; i < 50; i++) {
                temp = x * x - y * y + u;
                y = 2.0f * x * y + v;
                x = temp;
                if (x * x + y * y > 4.0f) break;
            }
            
            // Print characters based on escape speed
            if (i < 50) {
                putchar(" .:-=+*#%@"[i % 10]);
            } else {
                putchar(' ');
            }
        }
        putchar('\n');
    }
    return 0;
}
