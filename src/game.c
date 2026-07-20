#include <stdio.h>
#include <string.h>
#include "game.h"


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

    running = 1;

    printf("Game initializing...\n");

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

