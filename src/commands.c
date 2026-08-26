#include "commands.h"


void command_look(Player *player, Room *rooms){

    Room *current_room = &rooms[player->current_room];

    printf("%s\n", current_room->name);
    printf("%s\n", current_room->description);
    
}

void command_move(Player *player, Room *rooms, char command[100]){

    Room *current_room = &rooms[player->current_room];

    if(strcmp(command, "north") == 0){

        if(current_room->north == -1){
            printf("You can't go there.\n");
        }
        else{
            player->current_room = current_room->north;
        }

    }
    else if(strcmp(command, "south") == 0){
        
        if(current_room->south == -1){
            printf("You can't go there.\n");
        }
        else{
            player->current_room = current_room->south;
        }

    }
    else if(strcmp(command, "east") == 0 ){
        
        if(current_room->east == -1){
            printf("You can't go there.\n");
        }
        else{
            player->current_room = current_room->east;
        }

    }
    else if(strcmp(command, "west") == 0){
        
        if(current_room->west == -1){
            printf("You can't go there.\n");
        }
        else{
            player->current_room = current_room->west;
        }
        
    }

}