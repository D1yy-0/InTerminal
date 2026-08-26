# InTerminal Architecture

---

# Philosophy

The architecture of InTerminal is designed around one primary goal:

> Build a game that is easy to understand, maintain, and extend.

Every module should have one clear responsibility.

As the game grows, new systems should be added without requiring major changes to existing code.

Readability and clear separation of responsibilities are prioritized over clever or overly complicated solutions.

---

# Engine Overview

The program begins in:

```c
main()
```

Its responsibility is to start the game engine.

```text
main()

↓

game_run()
```

`game_run()` owns the main game loop.

---

# Engine Loop

The engine follows a fixed execution order.

```text
Initialize

↓

while (running)

↓

Input

↓

Update

↓

Render

↓

Shutdown
```

This loop is the heart of the game.

Every gameplay system will eventually interact with one or more stages of this loop.

---

# Engine Responsibilities

## Initialize

Prepare the game before the main loop begins.

Current responsibilities include:

* initialize player data
* initialize rooms
* initialize the running state

Future responsibilities may include:

* load save files
* load external data
* initialize additional systems

---

## Input

Receive information from the player.

Current input is text entered through the terminal.

Input should primarily collect player input rather than directly modify the game state.

---

## Update

Process the current game state and commands.

Current responsibilities include:

* processing commands
* movement
* changing the player's current room

Future responsibilities may include:

* combat
* inventory
* quests
* NPC behavior
* world events

---

## Render

Display the current game state.

Currently this is handled through terminal output.

Future versions may include:

* colors
* animations
* improved terminal UI
* additional visual feedback

---

## Shutdown

Cleanly close the engine.

Future responsibilities may include:

* save the game
* release allocated memory
* close files
* shut down systems

---

# Current Modules

## `main.c`

Responsible for the program entry point.

Its purpose is to start the game engine and remain as small as possible.

---

## `game.c`

Responsible for the main game engine.

Current responsibilities:

* game loop
* game state
* game initialization
* input/update/render/shutdown stages
* command processing

The game engine coordinates systems but should not contain the detailed implementation of every gameplay feature.

---

## `room.c`

Responsible for room initialization.

Current responsibilities:

* initialize the room array
* define the current hardcoded rooms
* define room connections

Future versions may load room data from external files instead of defining everything directly in C.

---

## `room.h`

Defines the `Room` structure and exposes the room module's public interface.

---

## `commands.c`

Contains individual command implementations.

Current commands include:

* `command_look()`
* `command_move()`

Future commands may include:

* inventory
* take
* drop
* attack
* use
* inspect

---

## `commands.h`

Defines the public interface for command functions.

Other modules should use the command interface rather than depending on the internal implementation of individual commands.

---

## `player.h`

Currently defines the `Player` structure.

The Player stores information such as:

* health
* maximum health
* gold
* current room

A dedicated `player.c` module may be introduced when the Player system becomes complex enough to require its own behavior.

---

# Current World Model

The current world consists of an array of `Room` structures.

Each room contains:

* name
* description
* north connection
* south connection
* east connection
* west connection

Room connections use integer room IDs.

For example:

```text
Room 0
    north → Room 1

Room 1
    south → Room 0
```

A value of `-1` currently represents an unavailable exit.

The Player stores the ID of their current room.

```text
Player
    current_room
         ↓
      Room ID
         ↓
    rooms[Room ID]
```

---

# Command Architecture

Commands are separated from command processing.

The command processor determines what the player requested and calls the appropriate command function.

```text
User Input
    ↓
process_command()
    ├── look  → command_look()
    ├── north → command_move()
    ├── south → command_move()
    ├── east  → command_move()
    └── west  → command_move()
```

This prevents `process_command()` from becoming responsible for the implementation of every command.

---

# Ownership

Every important piece of data should eventually have one clear owner.

Current ownership is intentionally simple.

* `game.c` owns the current game state and engine loop.
* `Player` represents player data.
* `room.c` manages room initialization.
* `Room` structures contain world location data.
* `commands.c` contains command behavior.

As the project grows, ownership may be moved into dedicated modules.

For example:

```text
player
world
inventory
combat
items
quests
save_system
```

Modules should communicate through well-defined interfaces instead of unnecessarily accessing each other's internal implementation.

---

# Future Architecture

The architecture is expected to grow gradually.

Possible future modules include:

```text
player
world
inventory
items
combat
quests
save_system
parser
rng
procedural_generation
```

These should only be introduced when the project actually needs them.

The goal is to avoid creating unnecessary complexity too early.

---

# Design Principles

Throughout development we will follow these principles:

* Single Responsibility
* Information Hiding
* Modular Design
* Readability over Cleverness
* Simplicity First
* Data should describe the world
* Behavior should operate on that data
* Avoid unnecessary hardcoding
* Introduce complexity only when it solves a real problem

---

# Future Data Loading

Room information is currently hardcoded in `room.c`.

In the future, room and world data may be moved into external files such as JSON.

The intended architecture is:

```text
External Data
     ↓
Loading System
     ↓
C Structures
     ↓
Game Engine
```

The current separation of room initialization helps keep this future change possible without coupling the game engine directly to room data.

---

# Current Status

At the end of Session 5:

* The game loop exists.
* The Player exists.
* Rooms exist.
* Room initialization is separated from the game engine.
* The player can inspect their current room.
* The player can move between connected rooms.
* Commands have their own module.
* Room connections are represented using room IDs.

---
