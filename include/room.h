#ifndef ROOM_H
#define ROOM_H

typedef struct{

    char name[50];
    char description[256];

    int north;
    int south;
    int east;
    int west;

}Room;

#endif // ROOM_H
