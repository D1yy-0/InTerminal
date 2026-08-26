#ifndef COMMANDS_H
#define COMMANDS_H

#include <stdio.h>
#include <string.h>

#include "player.h"
#include "room.h"

/// @brief Displays information about the player's current room.
/// @param player Pointer to the `Player` struct.
/// @param rooms Pointer to the array of `Room` structs.
void command_look(Player *player, Room *rooms);

/// @brief Moves the player in the specified direction if possible.
/// @param player Pointer to the `Player` struct.
/// @param rooms Pointer to the array of `Room` structs.
/// @param command The command string containing the direction.
void command_move(Player *player, Room *rooms, char command[100]);

#endif