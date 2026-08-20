#ifndef COMMANDS_H
#define COMMANDS_H

#include <stdio.h>

#include "player.h"
#include "room.h"

/// @brief Displays information about the player's current room.
/// @param player Pointer to the Player struct.
/// @param rooms Pointer to the array of Room structs.
void command_look(Player *player, Room *rooms);

#endif