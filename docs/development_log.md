# InTerminal Development Log

## Session 1 - Project Initialization

**Date:** 2026-06-28

### Goals

* Create the GitHub repository.
* Set up the project structure.
* Build the foundation of the game engine.
* Understand the responsibilities of the main game loop.

### Completed

* Initialized the Git repository and connected it to GitHub.
* Created the project directory structure:

  * `src/`
  * `include/`
  * `assets/`
  * `docs/`
  * `saves/`
  * `build/`
* Added a `.gitignore` file.
* Learned that Git does not track empty directories and used `.gitkeep` where appropriate.
* Created the first game module:

  * `main.c`
  * `game.c`
  * `game.h`
* Learned the difference between header (`.h`) and source (`.c`) files.
* Learned about include guards (`#ifndef`, `#define`, `#endif`).
* Learned the difference between public functions and private (`static`) functions.
* Implemented the initial engine architecture:

  * `game_run()`
  * `game_initialize()`
  * `game_input()`
  * `game_update()`
  * `game_render()`
  * `game_shutdown()`
* Implemented the basic game loop using:

  * `while (running)`

### What I Learned

* `main()` should stay as small as possible.
* Every function should have a single responsibility.
* The game loop is the heart of every game.
* Input, Update, and Render are separate systems with different responsibilities.
* The Update phase is responsible for changing the game state.
* Good software architecture is more important than writing many lines of code.

### Problems Encountered

* Git was not recognized because it was not correctly configured in the PATH.
* Git does not track empty folders.
* Initially placed too much responsibility inside `game_initialize()`, then redesigned the architecture so that `game_run()` controls the engine.

### Next Session Goals

* Make the engine interactive.
* Read commands from the terminal.
* Implement the first command (`quit`).
* Begin designing a command system for future gameplay.

### Notes

Today focused on building a solid foundation rather than adding gameplay. The goal is to create an engine that can grow cleanly as new features are added.


###

## Session 2 - 

**Date:** 2026-06-29

### Goal

Make the engine receive input from the player.

### Completed

- Added a command buffer.
- Implemented `game_input()`.
- Added the terminal prompt (`>`).
- Learned how input flows through the engine.
- Studied strings and character arrays in memory.

### Next Session

- Learn `strcmp()`.
- Compare player commands.
- Remove the newline from `fgets()`.
- Implement the first command: `quit`.


