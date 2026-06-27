#include <stdio.h>
#include "game.h"


/* Private Functions prototypes */

static void game_initialize(void);
static void game_input(void);
static void game_update(void);
static void game_render(void);
static void game_shutdown(void);

/* Private State */

static int running = 0;

/* Public Functions */

void game_run(void) {

    game_initialize();

    while (running) {

        game_input();

        game_update();

        game_render();

        /* if ( // some condition to exit the game ) {
            running = 0;
        } */
    }

    game_shutdown();

}

static void game_initialize(void) {

    running = 1;

    printf("Game initializing...\n");

}

static void game_input(void) {

    printf("Game input processing...\n");

}

static void game_update(void) {

    printf("Game updating...\n");

}

static void game_render(void) {

    printf("Game rendering...\n");

}

static void game_shutdown(void) {

    printf("Game shutting down...\n");

}

