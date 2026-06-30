# Session 1 - Project Setup and Engine Skeleton

**Date:** 2026-06-28
**Project:** InTerminal
**Project Version:** Pre-Alpha

---

# Objective

The goal of this session was **not** to build gameplay.

Instead, we focused on building a solid foundation that every future feature will rely on.

By the end of the session we wanted a project that was:

- organized
- modular
- easy to extend
- tracked with Git
- ready for long-term development

---

# Prerequisites

Before starting this session, you should understand:

- Functions
- Variables
- Header files
- Basic project structure

---

# What We Built

## Project Structure

```
InTerminal/
│
├── assets/
├── build/
├── docs/
├── include/
├── saves/
├── src/
├── tools/
│
├── .gitignore
├── README.md
```

---

## Source Files

```
src/

main.c
game.c
```

```
include/

game.h
```

---

## Engine Entry Point

Execution starts here:

```
main()

↓

game_run()
```

`main()` should stay very small.

Its only responsibility is starting the game.

---

## The First Module

Our first module is:

```
game
```

It consists of:

```
game.c
game.h
```

This introduced the idea that each module owns one responsibility.

---

# New Concepts

## Modules

Instead of writing everything inside one file,
we split the program into modules.

Benefits:

- easier to read
- easier to debug
- easier to expand
- easier to maintain

---

## Header Files

Header files describe **what** a module provides.

Example:

```c
void game_run(void);
```

The implementation belongs inside:

```
game.c
```

---

## Source Files

Source files contain the actual implementation.

Example:

```c
void game_run(void)
{
    ...
}
```

---

## Information Hiding

Other modules should not know how `game.c` works internally.

They only know what is declared in:

```
game.h
```

This is called **encapsulation**.

---

# Design Decisions

## Why Keep main() Small?

Large projects often contain hundreds of source files.

Keeping `main()` simple makes it easier to understand where the program begins.

Instead of containing game logic, it simply starts the engine.

---

## Why Separate Files?

Every file should have one clear responsibility.

This keeps the project organized as it grows.

---

# Coding Conventions Introduced

- Use snake_case for function names.
- One module = one `.c` file and one `.h` file.
- Keep `main()` as small as possible.
- Expose only the functions other modules need.

---

# Questions We Discussed

## Why shouldn't main() contain the game logic?

Answer:

Because `main()` should only start the engine.

Keeping it small makes the project easier to maintain and allows the engine to grow without turning `main()` into a large function.

# Git

Created the Git repository.

Learned basic workflow:

```
git add .

git commit

git push
```

---

# Looking Ahead

Next session we will build the game loop.

The engine will finally begin running continuously instead of executing only once.

# Summary

At the end of this session we successfully:

✓ Created the project
✓ Initialized Git
✓ Built the first module
✓ Created the engine entry point
✓ Prepared the project for future development