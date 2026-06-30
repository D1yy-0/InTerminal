# InTerminal Architecture

---

# Philosophy

The architecture of InTerminal is designed around one primary goal:

> Build a game that is easy to understand, maintain, and extend.

Every module should have one clear responsibility.

As the game grows, new systems should be added without requiring major changes to existing code.

---

# Engine Overview

The program begins in:

```
main()
```

Its only responsibility is starting the engine.

```
main()

↓

game_run()
```

---

# Engine Loop

The engine follows a fixed execution order.

```
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

This loop is the heart of the engine.

Every gameplay system eventually executes inside this loop.

---

# Responsibilities

## Initialize

Prepare the engine.

Examples:

- initialize variables
- load save files
- load assets

---

## Input

Receive information from the player.

Input should **not** modify the game world.

---

## Update

Update the game state.

Examples:

- movement
- combat
- inventory
- quests
- NPC behavior

This is where game logic belongs.

---

## Render

Display the current game state.

For now:

Terminal text.

Future versions may include:

- colors
- animations
- interface improvements

---

## Shutdown

Cleanly close the engine.

Eventually this will:

- save the game
- release memory
- close files

---

# Current Modules

```
game
```

Responsibilities:

- own the game loop
- coordinate engine stages

---

# Future Modules

The architecture is expected to grow gradually.

Examples:

```
player
world
inventory
combat
items
quests
save_system
parser
rng
procedural_generation
```

Each module should own one responsibility.

---

# Design Principles

Throughout development we will follow these principles:

- Single Responsibility
- Information Hiding
- Modular Design
- Readability over Cleverness
- Simplicity First

---

# Ownership

As the engine grows, every piece of data should have one clear owner.

Examples:

- The game engine owns the game loop.
- The player module will own player data.
- The inventory module will own inventory data.
- The world module will own world data.

Modules should communicate through well-defined interfaces instead of directly modifying each other's internal data.

