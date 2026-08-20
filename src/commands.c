#include "commands.h"


void command_look(Player *player, Room *rooms){

    Room *current_room = &rooms[player->current_room];

    printf("%s\n", current_room->name);
    printf("%s\n", current_room->description);
    
}