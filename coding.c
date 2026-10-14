#include <stdio.h>
#include <stdlib.h>

// ANSI color codes for frontend-like output
const char *colors[] = {
    "\033[38;5;196m", // Red
    "\033[38;5;202m", // Orange
    "\033[38;5;226m", // Yellow
    "\033[38;5;46m",  // Green
    "\033[38;5;51m",  // Cyan
    "\033[38;5;21m",  // Blue
    "\033[38;5;93m",  // Purple
    "\033[0m"         // Reset
};

int main(int argc, char *argv[]) {
    int rows = 30, cols = 100, maxIter = 100;
    double zoom = 1.0, offsetX = -0.5, offsetY = 0.0;

    // Allow user to customize
    if (argc > 1) rows = atoi(argv[1]);
    if (argc > 2) cols = atoi(argv[2]);
    if (argc > 3) maxIter = atoi(argv[3]);

    printf("Rendering Mandelbrot Set (%dx%d, %d iterations)...\n", rows, cols, maxIter);

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            double u = (col - cols / 2.0) / (20.0 * zoom) + offsetX;
            double v = (row - rows / 2.0) / (10.0 * zoom) + offsetY;
            double x = 0, y = 0;
            int i;

            for (i = 0; i < maxIter; i++) {
                double temp = x * x - y * y + u;
                y = 2.0 * x * y + v;
                x = temp;
                if (x * x + y * y > 4.0) break;
            }

            if (i == maxIter) {
                printf(" "); // Inside set
            } else {
                int colorIndex = i % 7;
                printf("%s%c\033[0m", colors[colorIndex], " .:-=+*#%@"[i % 10]);
            }
        }
        printf("\n");
    }

    return 0;
}
