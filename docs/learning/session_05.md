# Session 5 – Making the World Interactive

## Goal

Connect the Player, Room, and Command systems so the player can inspect their current room and move between rooms.

This session marked the transition from having room data stored in the game to actually using that data to create a playable world.

---

# What We Built

At the beginning of the session, the game already had:

* A `Player` structure.
* A `Room` structure.
* A game loop.
* A command-processing system.
* A Tutorial Room.

During this session we added:

* `commands.c`
* `commands.h`
* `command_look()`
* `command_move()`
* `room.c`
* `rooms_initialize()`
* A second room: Village.
* Basic movement between connected rooms.

---

# Command Module

We decided that commands should have their own module.

```text
include/
└── commands.h

src/
└── commands.c
```

The purpose of this separation is to prevent `game.c` and `process_command()` from becoming overloaded with the actual behavior of every command.

The command system is structured so that `process_command()` identifies what the player requested and calls the appropriate command function.

Conceptually:

```text
User Input
    ↓
process_command()
    ├── look → command_look()
    ├── movement → command_move()
    └── future commands
```

---

# `command_look()`

The first command implemented during this session was `command_look()`.

Its responsibility is to display information about the player's current room.

The function receives:

```c
Player *player
Room *rooms
```

The Player tells us **which room the player is currently in**.

The Room array contains the actual information about that room.

The important relationship is:

```text
Player
    │
    └── current_room = Room ID
                  ↓
              rooms[ID]
                  ↓
              Current Room
```

---

# Finding the Current Room

We used a pointer to access the player's current Room:

```c
Room *current_room = &rooms[player->current_room];
```

This works in two stages.

First:

```c
player->current_room
```

gives the ID/index of the room the player occupies.

For example:

```text
player->current_room = 0
```

Then:

```c
rooms[player->current_room]
```

accesses:

```text
rooms[0]
```

The `&` obtains the address of that Room, allowing us to store it in:

```c
Room *current_room
```

The pointer can then be used with:

```c
current_room->name
current_room->description
```

---

# Why Use a Room Pointer?

We could access the room directly through:

```c
rooms[player->current_room]
```

but creating:

```c
Room *current_room
```

makes the code easier to read and allows us to refer to the current room without repeatedly writing the complete array expression.

It also reinforces the important C concept of using pointers to access existing structures rather than making unnecessary copies.

---

# Separating Room Initialization

Originally, room initialization was handled directly inside `game.c`.

We decided this should be separated because the world will eventually contain many rooms.

A new module was created:

```text
src/
└── room.c
```

with its interface:

```text
include/
└── room.h
```

The room module is now responsible for initializing the room data.

The game initialization only needs to request that the rooms be initialized.

Conceptually:

```text
game_initialize()
       │
       └── rooms_initialize()
                    │
                    ├── Room 0
                    ├── Room 1
                    └── future rooms
```

This keeps `game.c` focused on the game engine instead of the details of every individual room.

---

# Room Initialization

The `rooms_initialize()` function currently creates two rooms.

## Room 0 – Tutorial Room

```text
North → Room 1
South → None
East  → None
West  → None
```

## Room 1 – Village

```text
North → None
South → Room 0
East  → None
West  → None
```

This creates a two-way connection:

```text
       North
Tutorial ─────→ Village
   ↑              │
   └──── South ───┘
```

---

# Room IDs

The room connections use integer IDs.

For example:

```c
rooms[0].north = 1;
```

means:

> The north exit of Room 0 leads to Room 1.

Likewise:

```c
rooms[1].south = 0;
```

means:

> The south exit of Room 1 leads to Room 0.

We do not hardcode the destination inside the movement command.

Instead, the Room itself stores where each exit leads.

This is important because the command system should not need to know the structure of the world.

---

# Invalid Exits

A value of:

```text
-1
```

represents an exit that does not exist.

For example:

```c
rooms[0].south = -1;
```

means that the Tutorial Room has no southern exit.

When the player attempts to move in that direction, the command displays:

```text
You can't go there.
```

and the player's current room is not changed.

---

# `command_move()`

We created `command_move()` to handle movement.

Its responsibility is to:

1. Determine the player's current room.
2. Check the requested direction.
3. Read the destination Room ID from the current room.
4. Check whether the destination is `-1`.
5. If the exit exists, update `player->current_room`.
6. If the exit does not exist, prevent movement.

The important part is that the destination is obtained from the Room data.

For example:

```text
Player
current_room = 0
       ↓
Room 0
north = 1
       ↓
Player
current_room = 1
```

The movement function does not need to know that Room 1 happens to be the Village.

It simply follows the room's connection.

---

# Why Movement Does Not Hardcode Room IDs

We deliberately avoided code such as:

```c
player->current_room = 1;
```

for north movement.

That would only work for the current two-room world.

As the world grows, hardcoded destinations inside the command system would become difficult to maintain.

Instead:

```c
player->current_room = current_room->north;
```

allows the Room data to determine the destination.

This separates:

```text
World layout
```

from:

```text
Command behavior
```

The World says where a room leads.

The movement command simply follows that information.

---

# Pointer vs Structure Access

This session reinforced an important C distinction.

When working directly with a structure:

```c
Room current_room;
```

we use:

```c
current_room.north
```

When working with a pointer to a structure:

```c
Room *current_room;
```

we use:

```c
current_room->north
```

The `->` operator accesses a structure member through a pointer.

---

# Command Responsibilities

We deliberately separated command behavior.

For example:

```text
command_look()
```

is responsible for looking.

```text
command_move()
```

is responsible for movement.

`process_command()` is responsible for determining which command the player entered and dispatching it.

This prevents `process_command()` from becoming one enormous function containing the implementation of every command.

---

# Current Architecture

At the end of Session 5, the project has the following structure:

```text
include/
├── game.h
├── player.h
├── room.h
└── commands.h

src/
├── game.c
├── main.c
├── room.c
└── commands.c
```

Responsibilities:

```text
game.c
    Game loop
    Game state
    Game initialization

main.c
    Program entry point

room.c
    Room initialization

room.h
    Room structure
    Room interface

commands.c
    Command implementations

commands.h
    Command interface

player.h
    Player structure
```

---

# Current Gameplay

The game can now do:

```text
> look
Tutorial Room
You are in the tutorial room. There is a door to the north.

> north

> look
Village
Very strange and magical village.

> south

> look
Tutorial Room
You are in the tutorial room. There is a door to the north.
```

The player can therefore move through an actual connected world.

---

# Architectural Lessons

## Data should describe the world

The Room structure contains the information about where each room leads.

## Commands should operate on the data

`command_move()` doesn't define the world.

It reads the world data and changes the player's state accordingly.

## Keep modules focused

Each module should have a clear responsibility.

## Avoid hardcoding relationships in behavior

Room connections belong to Room data rather than movement logic.

## Use pointers when working with existing structures

Pointers allow functions to work with the actual game state instead of unnecessary copies.

## Build incrementally

We did not try to implement the entire world or command system at once.

We built:

```text
Player
   ↓
Room
   ↓
Look
   ↓
Movement
```

and verified each stage before continuing.

---

# Future Improvements

Several systems were intentionally left for future sessions.

### Command parsing

Currently commands are compared using `strcmp()`.

Eventually we will introduce a better command representation, including `enum`, once the relevant C concepts have been properly learned.

### More rooms

The current world contains only two rooms.

More rooms will be added as the world system develops.

### World data files

Currently room information is hardcoded in C.

In the future, room data may be moved into external files such as JSON.

The current separation of `room.c` helps prepare the architecture for that future change.

### More room information

Rooms will eventually contain more than:

* Name
* Description
* Exits

Possible future systems include:

* Items
* Equipment
* Enemies
* NPCs
* Doors
* Windows
* Puzzles
* Safety information
* Environmental details

These will be added when the game actually needs them.

---

# Session 5 Summary

Session 5 connected the game's data systems and created the first functional world.

The player now has a location.

Rooms now have connections.

Commands can interact with the world.

The engine can determine the player's current room and change it when the player moves.

The most important architectural relationship introduced in this session is:

```text
Player
  │
  │ current_room
  ▼
Room
  │
  ├── north
  ├── south
  ├── east
  └── west
```

This forms the foundation for future exploration, interaction, combat, inventory, NPCs, puzzles, and procedural world systems.

---

# Session 5 Completion Checklist

* [x] Create `commands.h`
* [x] Create `commands.c`
* [x] Implement `command_look()`
* [x] Connect `command_look()` to `process_command()`
* [x] Create `room.c`
* [x] Move room initialization into `rooms_initialize()`
* [x] Create Room 1 – Village
* [x] Connect Tutorial Room and Village
* [x] Implement `command_move()`
* [x] Connect movement to `process_command()`
* [x] Test north movement
* [x] Test south movement
* [x] Test invalid exits
* [x] Verify `look` after moving
* [x] Verify `quit` still works

**Session 5 complete.**
