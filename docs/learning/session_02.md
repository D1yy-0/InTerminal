# Session 2 - Building the Game Loop and Understanding Strings

**Date:** 2026-06-29
**Project:** InTerminal  
**Version:** Pre-Alpha

---

# Objective

The goal of this session was to transform the project from a program that starts and immediately exits into a game engine capable of running continuously.

Although the visible result was only a terminal prompt, this session introduced the architecture that almost every game engine uses.

We also began studying one of the most important concepts in C: **strings**.

---

# Prerequisites

Before starting this session you should understand:

- Functions
- Variables
- Arrays
- Header files
- Source files
- Basic project structure

---

# What We Built

## Engine State

The engine now owns two pieces of state.

```c
static int running;
static char command[100];
```

`running` determines whether the engine should continue executing.

`command` stores the player's latest input.

---

## The Game Loop

The engine now follows this structure.

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

This loop will remain the heart of the engine throughout the entire project.

Future systems such as combat, NPCs, procedural generation, inventory, quests, and saving the game will all execute inside this loop.

---

## Responsibilities

Each stage of the loop has one responsibility.

### Initialize

Prepare the engine before the game begins.

---

### Input

Receive information from the player.

This stage **does not** modify the game world.

It simply gathers information.

---

### Update

Process everything that happened during this frame.

This stage changes the game state.

Examples:

- moving the player
- attacking an enemy
- opening a chest
- completing a quest

---

### Render

Display the current state of the game.

Currently this means printing text to the terminal.

---

### Shutdown

Cleanly close the game.

Future versions will save data and release resources here.

---

# New C Concepts

## Character Arrays

A character array is simply an array of characters.

Example:

```c
char word[6];
```

This reserves six bytes of memory.

---

## C Strings

A string in C is **not** an array.

A string is:

> A sequence of characters terminated by the null character (`'\0'`).

Example:

```
h e l l o \0
```

---

## The Null Terminator

The null terminator marks the end of a string.

Without it, functions such as

```c
printf("%s");
```

would continue reading memory until they accidentally found a zero byte.

---

## fgets()

Instead of using `scanf()`, we chose `fgets()`.

Reason:

`scanf("%s")` stops at the first space.

```
attack dragon
```

would become

```
attack
```

`fgets()` reads the entire line.

---

# Why Input and Update Are Separate

One of the biggest architectural lessons of this session was separating responsibilities.

Instead of this:

```
Input
↓

Everything happens here
```

we built this:

```
Input
↓

Store command

↓

Update

↓

Process command

↓

Render
```

This makes the engine easier to maintain and easier to expand.

---

# Questions We Explored

## Why shouldn't Input modify the world?

Because gathering information and changing the game world are different responsibilities.

Keeping them separate makes the engine easier to understand and easier to extend.

---

## Why keep `main()` small?

Because the engine should own the game.

`main()` only starts the engine.

---

## Why does replacing `'\0'` break strings?

Because string functions stop only when they encounter the first null terminator.

Removing it creates undefined behavior.

---

# Common Misconceptions

❌ A character array and a string are the same thing.

They are not.

A string is stored inside a character array.

---

❌ `printf("%s")` prints every character in the array.

False.

It stops at the first `'\0'`.

---

❌ `fgets()` removes the Enter key.

False.

It stores the newline character.

---

# Reflection

Although the engine still cannot understand player commands, this session introduced the foundation required for every future gameplay feature.

More importantly, it replaced several "magic" ideas about strings with a clear understanding of how they are represented in memory.

This understanding will make future topics such as `strcmp()`, parsing, file loading, and saving much easier to understand.

---

# Summary

By the end of this session we successfully:

- Built the game loop.
- Introduced engine state.
- Added player input.
- Learned how C strings are stored.
- Understood the purpose of the null terminator.
- Prepared the engine for command processing.