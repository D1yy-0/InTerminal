# Session 4 – Designing the Game World

## Goal

Begin building the actual game world by introducing the first game objects and deciding how they relate to each other.

---

# What We Learned

This session focused on software architecture rather than simply writing C code.

Before implementing anything, we discussed the responsibilities of each game object and why separating responsibilities leads to cleaner and more maintainable code.

The philosophy remains:

Design → Think → Code → Test → Review → Document

---

# Designing the Player

We designed the first real game object.

```text
Player
├── Health
├── Max Health
├── Gold
└── Current Room
```

The initial Player structure contains only the information necessary for the game to function.

We intentionally avoided adding unnecessary RPG features such as:

* Level
* Experience
* Strength
* Mana
* Skills

These will only be added when the game actually requires them.

This follows the principle:

> Don't build features until you need them.

---

# Initial Player State

The player starts with:

Health = 100

Max Health = 100

Gold = 0

Current Room = 0

Reasons:

* 100 health is easy for both the player and programmer to understand.
* Maximum health allows future upgrades without changing the meaning of health.
* A new adventurer starts with no money.
* Room 0 is reserved as the Tutorial Room.

---

# Creating player.h

The Player structure was moved into its own module.

Project structure now begins separating game systems.

```text
include/
    game.h
    player.h
```

Each module should own its own data and responsibilities.

---

# Game State

The player is stored as:

```c
static Player player;
```

inside game.c.

Reason:

The player exists for the entire lifetime of the game.

It should not be recreated every frame or every function call.

---

# Designing the Room

Before writing code we discussed what information every room should contain.

Initial ideas included:

* Name
* Description
* Safety
* Details
* Enemies
* Equipment
* Windows
* Doors

After discussion we decided Version 1 should remain simple.

Current Room design:

```text
Room
├── Name
├── Description
├── North Exit
├── South Exit
├── East Exit
└── West Exit
```

Additional systems such as enemies, NPCs, items and puzzles will be added later.

---

# Creating room.h

A new Room module was created.

```text
include/
    game.h
    player.h
    room.h
```

The Room structure currently stores:

* Name
* Description
* Four exits

---

# Room Connections

Each exit stores another room ID.

Example:

```text
Tutorial Room

North -> Room 1

South -> No Exit

East -> No Exit

West -> No Exit
```

"No Exit" is represented by:

```text
-1
```

Reason:

Room IDs begin at 0.

Therefore -1 can never be a valid room.

This value is called a sentinel value.

---

# Initial Tutorial Room

Room 0 was created.

Name:

Tutorial Room

Description:

You are in the tutorial room.
There is a door to the north.

Connections:

North -> Room 1

South -> -1

East -> -1

West -> -1

---

# Game Architecture Decisions

Several important design decisions were made.

Player owns:

* Current room
* Health
* Gold

World owns:

* Collection of all rooms

Room owns:

* Information about itself
* Its exits

The engine should not care what a room looks like.

It only needs to know how rooms connect together.

---

# World Size

Instead of hardcoding:

```c
Room rooms[10];
```

we decided future versions should use:

```c
#define MAX_ROOMS ...
```

Reason:

The limit should exist in one place only.

Version 1 will use a fixed number of rooms.

Future procedural generation may remove this limit completely.

---

# Software Engineering Principles

This session introduced several important principles.

## Separation of Responsibilities

Each object owns only the data it is responsible for.

## Iterative Design

Build the simplest version that works.

Improve it later.

## Avoid Overengineering

Do not add systems until they are actually needed.

## Think About Data Before Functions

Functions become much easier to write after the data model is designed correctly.

---

# Looking Ahead

Next session will begin using the world we created.

Objectives include:

* Implement the first "look" command using room data.
* Display the player's current room dynamically.
* Begin using the player's current_room field to navigate the world.
* Start turning the engine into a playable text RPG.

---

# Session Summary

By the end of Session 4, InTerminal now contains:

```text
Game
│
├── Engine
│
├── Player
│   ├── Health
│   ├── Max Health
│   ├── Gold
│   └── Current Room
│
└── Rooms
    ├── Name
    ├── Description
    └── Exits
```

This marks the transition from building the engine's foundation to building the game world itself.

The project now has its first real game state and the architecture necessary to begin implementing exploration.
