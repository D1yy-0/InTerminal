# Learning Journal

# Purpose

The learning journal records what was learned during development rather than only recording what code was written.

The goal is to make it possible to look back at the project and understand:

* what concepts were learned
* why design decisions were made
* what problems were encountered
* how those problems were solved
* how understanding changed during development

---

# Session 1

## Focus

Project foundation and basic C program structure.

## Learned

* How the project is organized.
* The purpose of `main.c`.
* Why the program needs a clear entry point.
* Why the game engine should be separated from the program entry point.
* Basic separation between source and header files.

## Important Design Decision

`main.c` should remain small.

Its purpose is to start the engine rather than contain the game itself.

---

# Session 2

## Focus

Game engine structure and game loop.

## Learned

* Why the game engine needs a loop.
* The purpose of initialization, input, update, render, and shutdown.
* Why different engine stages should have separate responsibilities.
* Why separating systems makes debugging easier.

## Important Design Decision

The game engine follows:

```text
Initialize
↓
Input
↓
Update
↓
Render
↓
Shutdown
```

---

# Session 3

## Focus

Command processing and user input.

## Learned

* How commands can be represented as C strings.
* How `strcmp()` compares strings.
* Why C strings end with `'\0'`.
* The difference between `sizeof()` and `strlen()`.
* How user input from `fgets()` includes the newline character.
* Why input processing will eventually need a more robust parser.

## Important Design Decision

`process_command()` should process commands but should not contain the implementation of every command.

Individual commands should eventually become separate functions.

---

# Session 4

## Focus

Player state and the beginning of the world system.

## Learned

* How the Player structure can store the player's state.
* Why the Player should know its current location.
* Why player-owned information should remain associated with the Player.
* How a Room structure can represent a location.
* Why the world should describe the locations and their relationships.
* How room IDs can be used to connect rooms.
* Why a maximum room count is useful during early development.

## Initial Player State

```text
Health: 100 / 100
Gold: 0
Current Room: 0
```

The initial room is the tutorial room.

---

# Session 5

## Focus

Connecting the Player, Room, and Command systems.

## Learned

### Command Modules

Commands were separated into:

```text
commands.c
commands.h
```

This allows individual commands to have their own implementations.

---

### `command_look()`

Implemented a command that retrieves the player's current room and displays its information.

Important relationship:

```text
Player
  ↓
current_room
  ↓
rooms[current_room]
  ↓
Current Room
```

---

### Pointers to Structures

Learned that:

```c
Room *current_room;
```

stores the address of a Room.

When accessing a member through the pointer:

```c
current_room->north
```

is used.

When accessing a structure directly:

```c
room.north
```

is used.

---

### Room Initialization

Room initialization was separated from `game.c` into:

```text
room.c
room.h
```

This makes the game engine cleaner and gives the Room system its own responsibility.

---

### Room Connections

Created:

```text
Room 0 → Tutorial Room
Room 1 → Village
```

with:

```text
Tutorial
    North → Village

Village
    South → Tutorial
```

The room itself stores the destination ID.

This means movement does not need to hardcode the world's layout.

---

### `command_move()`

Implemented basic movement.

The command:

1. Finds the player's current room.
2. Checks the requested direction.
3. Reads the destination room ID.
4. Rejects the movement if the destination is `-1`.
5. Updates `player->current_room` when the destination exists.

---

### Command Responsibilities

Learned why individual commands should have their own responsibilities.

Instead of putting all command behavior inside `process_command()`:

```text
process_command()
    ↓
    ├── command_look()
    └── command_move()
```

This makes the program easier to read, debug, and expand.

---

# Development Lessons

The most important lesson so far is:

> Build the system in small pieces and make sure each piece works before adding the next one.

Another important lesson is:

> The data should describe the world, while the game systems operate on that data.

For example, the Room contains the destination IDs.

The movement command does not need to know which room is the Village.

---

# Current Understanding

At the end of Session 5, the project has moved from a simple game loop toward an actual game system.

The current relationship is:

```text
Player
   │
   │ current_room
   ▼
Room
   │
   ├── name
   ├── description
   ├── north
   ├── south
   ├── east
   └── west
```

Commands operate on this data:

```text
command_look()
command_move()
```

This forms the foundation for future systems such as:

* inventory
* items
* combat
* NPCs
* quests
* puzzles
* procedural generation
* saving and loading

---

# Future Journal Entries

Each future session should record:

## Session

### Focus

What the session was primarily about.

### Learned

New C concepts and programming concepts.

### Built

What was actually implemented.

### Problems

Important bugs or mistakes encountered.

### Solutions

How the problems were solved.

### Design Decisions

Why important architectural decisions were made.

### Current Understanding

What became clearer as a result of the session.

### Next Step

What the project is expected to work on next.

---

# Journal Philosophy

The learning journal should document the **learning process**, not become another copy of the technical documentation.

The technical documents explain the project.

The journal explains the journey of learning how to build it.

---
