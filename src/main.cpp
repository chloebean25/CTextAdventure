#ifdef _WIN32
#include <windows.h>

#endif

#include <iostream>
#include <vector>
#include "fogpi/Math.hpp"
#include <time.h>



int Add(int &_a, int &_b)
{
    _a = _a * 2;
    return _a + _b;
}

int main(int argc, char* argv[])
{
    int a = 2;
    int b = 3;

    std::cout << "Hello, World!" << Add(a,b) << "\n";

    std::cout << a << std::endl;

    Vector2D v(5.0f,5.0f);
    Vector2D v1(2.0f, 10.0f);

    v=v+v1;
    v-=v1;

    std::cout << v.x << " " << v.y << std::endl;

    std::vector<Vector2D> points = {};

    srand(time(NULL));

    for (int i = 0; i < 1000; i++){
        int _tempX = (rand()%1001) - 500;
        int _tempY = (rand()%1001) - 500;
        if (i == 0)
            Print(Vector2D(_tempX, _tempY));
        points.push_back(Vector2D(_tempX, _tempY));
    }
    int max = 0;
    int min = 0;
    std::vector<int> quadrents = {0,0,0,0};
    
    for (int i =0; i <1000; i++){
        //Checkign for farthest point positive
        if (points[i].x +points[i].y > points[max].x + points[max].y){
            max = i;
        }
        //Checking for farthest negative number
        if (points[i].x +points[i].y < points[min].x + points[min].y){
            min = i;
        }

        if (points[i].x < 0){
            if (points[i].y <0)
            {
                quadrents[2] +=1;
            }
            else{
                quadrents[1] +=1;
            }
        }
        else{

            if (points[i].y <0)
            {
                quadrents[4] +=1;
            }
            else{
                quadrents[0] +=1;
            }
        }


    }

    

    Print(points[max]);
    Print(points[min]);
    std::cout << "Quadrents 1: " << quadrents[0] << std::endl
             << "Quadrents 2: " << quadrents[1] << std::endl 
             <<"Quadrents 3: " << quadrents[2] << std::endl 
             << "Quadrents 4: " << quadrents[0] << std::endl;

    std::cout << "Size: " << time(NULL) << std::endl;

    return 0;
}