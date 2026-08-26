#include "room.h"

void rooms_initialize(Room *rooms){

    strcpy(rooms[0].name, "Tutorial Room");
    strcpy(rooms[0].description, "You are in the tutorial room. There is a door to the north.");
    rooms[0].north = 1;
    rooms[0].south = -1;
    rooms[0].east = -1;
    rooms[0].west = -1;

    strcpy(rooms[1].name, "Village");
    strcpy(rooms[1].description, "Very strange and magical village.");
    rooms[1].north = -1;
    rooms[1].south = 0;
    rooms[1].east = -1;
    rooms[1].west = -1;
}