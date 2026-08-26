#ifndef ROOM_H
#define ROOM_H

#include <string.h>

/// @brief Represents a room in the game world.
typedef struct{

    char name[50];
    char description[256];

    int north;
    int south;
    int east;
    int west;

} Room;

/// @brief Initializes the rooms used by the game world.
/// @param rooms Pointer to the array of `Room` structs.
void rooms_initialize(Room *rooms);

#endif // ROOM_H
