#include <stdio.h>
#include <stdlib.h>

struct point_t {
    int x, y;
};

struct triangle_t {
    struct point_t pts[3];
};

int double_square(struct triangle_t tr);

int main() {
    int x1, y1, x2, y2, x3, y3;
    printf("Enter cordinates of three points: ");
    if (scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3) != 6) {
        printf("Invalid input! Please enter six integer number\n");
        return 1;
    }
    struct triangle_t tr = { { {x1, y1}, {x2, y2}, {x3, y3} } };

    int area = double_square(tr);

    if (area == 0) {
        printf("The given points are collinear. No valid triangle.\n");
        return 1;
    }

    printf("Double area square of triangle: %d\n", area);

    return 0;
}

int double_square(struct triangle_t tr) {
    int x1 = tr.pts[0].x, y1 = tr.pts[0].y;
    int x2 = tr.pts[1].x, y2 = tr.pts[1].y;
    int x3 = tr.pts[2].x, y3 = tr.pts[2].y;

    return abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
}
