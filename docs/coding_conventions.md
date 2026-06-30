# Coding Conventions

---

# Philosophy

Code is written more often than it is written.

Our goal is to write code that is easy to understand, maintain, and extend.

Readability is more important than cleverness.

---

# Naming

## Files

Use snake_case.

Examples:

```
game.c
player.c
inventory.c
```

Header files:

```
game.h
player.h
inventory.h
```

---

## Functions

Use snake_case.

Examples:

```c
game_run();
player_move();
inventory_add_item();
```

---

## Variables

Use snake_case.

Examples:

```c
player_health
current_room
enemy_count
```

---

## Constants

Use UPPER_CASE.

Examples:

```c
MAX_NAME_LENGTH
MAX_INVENTORY_SIZE
```

---

# Function Design

Each function should have one clear responsibility.

Functions should be short whenever possible.

If a function becomes difficult to understand, consider splitting it into smaller functions.

---

# Modules

Each module should own one responsibility.

A module consists of:

```
module.c
module.h
```

Other modules should interact through the header file.

---

# Comments

Write comments that explain **why**, not **what**.

Good:

```c
// Prevent the player from leaving the map.
```

Avoid:

```c
// Add 1 to x.
x++;
```

---

# Formatting

- Use 4 spaces for indentation.
- Always use braces for control statements.
- Leave a blank line between logical sections of code.
- Keep code consistently formatted.

---

# Philosophy

When in doubt, choose the solution that Future Diyar will understand most easily.
