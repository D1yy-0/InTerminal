# Game Design

## Vision

InTerminal is a text-based RPG focused on exploration, discovery, progression, and procedural generation.

Although the world changes between playthroughs, the main story remains consistent.

Every adventure should feel familiar but never identical.

---

# Core Gameplay Loop

```text
Explore
   ↓
Fight
   ↓
Collect Loot
   ↓
Become Stronger
   ↓
Discover New Areas
   ↓
Continue Exploring
```

This is the long-term gameplay direction.

The current game only implements a small portion of this loop.

---

# Current Gameplay

The current prototype supports:

* Text-based terminal interaction
* A player character
* Player health
* Player gold
* Player room location
* Multiple rooms
* Room descriptions
* Basic room connections
* Looking at the current room
* Movement between connected rooms

The current world contains:

```text
Room 0 → Tutorial Room
Room 1 → Village
```

---

# Rooms

Rooms represent locations in the game world.

Each room currently has:

* Name
* Description
* North exit
* South exit
* East exit
* West exit

Rooms are connected using room IDs.

Example:

```text
Tutorial Room
    North → Village

Village
    South → Tutorial Room
```

A room can also have no exit in a direction.

This is currently represented using:

```text
-1
```

---

# Room Discovery

Not every room should necessarily provide the player with complete information immediately.

Some rooms may be simple locations where the player can easily understand where to go.

Other rooms may require the player to:

* look around
* inspect objects
* solve puzzles
* discover hidden paths
* understand environmental clues

The exact amount of information shown will depend on the room and game design.

---

# Player

The player currently has:

```text
Health: 100 / 100
Gold: 0
Current Room: Tutorial Room
```

The initial values are intentionally simple.

The player begins with full health and no gold because they are just starting their adventure.

The tutorial room provides the starting environment where the player can learn the game's systems.

---

# Commands

Commands are the primary way the player interacts with the game.

Current commands:

```text
look
north
south
east
west
quit
```

Current command behavior includes:

* `look` — display information about the current room.
* `north` — attempt to move north.
* `south` — attempt to move south.
* `east` — attempt to move east.
* `west` — attempt to move west.
* `quit` — exit the game.

More commands will be added as gameplay systems are developed.

---

# Main Features

Planned features include:

* Text-based gameplay
* Procedurally generated world
* Randomized dungeons
* Different items each playthrough
* Story-driven main quest
* Optional side quests
* Inventory system
* Character progression
* Save and load system

---

# Design Goals

* Easy to understand
* Easy to expand
* Replayable
* Modular
* Fun to experiment with
* Encourage exploration
* Allow discovery
* Keep the core systems understandable

---

# Future Ideas

Possible future features include:

* Multiple biomes
* Dynamic weather
* Crafting
* Trading
* NPC factions
* Boss fights
* Secret locations
* Environmental puzzles
* Random encounters
* Procedurally generated areas
* Seed-based worlds

Future ideas are not commitments. They may change as development continues.

---
