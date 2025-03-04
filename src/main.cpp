#ifdef _WIN32
#include <windows.h>

#endif


#include <iostream>
#include <vector>
#include "fogpi/Math.hpp"
#include <time.h>
#include <stdio.h>
#include <string.h>

#include "Dice.hpp"
#include "Entity.hpp"
#include "Room.hpp"

int main(int argc, char* argv[])
{
    srand(time(NULL));

    Room room;
    room.Load("assets/level_1.map");

    while(true)
    {
        room.Update();
    }
  
    return 0;
}
