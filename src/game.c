/*
 * game.c
 *
 *  Created on: 2026-06-28
*/

/* C standard library headers */

#include <stdio.h>
#include <string.h>

/* Project headers */

#include "game.h"
#include "player.h"
#include "room.h"
#include "constants.h"


/* Private Functions prototypes */

static void game_initialize(void);
static void game_input(void);
static void game_update(void);
static void process_command(void);
static void game_render(void);
static void game_shutdown(void);

/* Private State */

static int running = 0;
static char command[100];

static Player player;
static Room rooms[MAX_ROOMS];

/* Public Functions */

void game_run(void) {

    game_initialize();

    while (running) {

        game_input();

        game_update();

        game_render();

    }

    game_shutdown();

}

static void game_initialize(void) {

    player.health = 100;
    player.max_health = 100;
    player.gold = 0;
    player.current_room = 0;

    strcpy(rooms[0].name, "Tutorial Room");
    strcpy(rooms[0].description, "You are in the tutorial room. There is a door to the north.");
    rooms[0].north = 1;
    rooms[0].south = -1;
    rooms[0].east = -1;
    rooms[0].west = -1;

    running = 1;

    printf("Game initializing...\n");

    printf("Player has been created...\n");

    printf("Player health: %d/%d\n", player.health, player.max_health);
    printf("Player gold: %d\n", player.gold);
    printf("Player current room: %d\n", player.current_room);

}

static void game_input(void) {

    printf("> ");

    if(fgets(command, sizeof(command), stdin) != NULL){
        command[strcspn(command, "\n")] = 0; // Remove newline character
    }

}

static void game_update(void) {

    process_command();

}

static void process_command(void) {

    if(strcmp(command, "quit") == 0){
        printf("Quitting detected...\n");
        running = 0;
    }

}

static void game_render(void) {

    printf("Game rendering...\n");

}

static void game_shutdown(void) {

    printf("Game shutting down...\n");

}

