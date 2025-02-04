#ifdef _WIN32
#include <windows.h>
#endif

#include <iostream>
#include <vector>

#include "fogpi/Math.hpp"

int main(int argc, char *argv[])
{
    Vector2D v(5.0f);
    Vector2D v1(2.0f, 10.0f);

    v = v + v1;
    v -= v1;

    std::cout << v.x << " " << v.y << std::endl;

    int r = rand() % 5;

    std::vector<Vector2D> points = {};

    for (int i = 0; i < 1000; i++)
    {
        // Add
        points.push_back(Vector2D(5.0f));
    }

    Print(points[0]);

    std::cout << "Size: " << points.size() << std::endl;

    return 0;
}