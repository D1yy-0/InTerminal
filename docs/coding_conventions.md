# Coding Conventions

---

# Philosophy

Code is written more often than it is written.

Our goal is to write code that is easy to understand, maintain, and extend.

Readability is more important than cleverness.

When choosing between a clever solution and a simple understandable solution, prefer the understandable solution.

---

# Naming

## Files

Use snake_case.

Examples:

```text
game.c
player.c
inventory.c
```

Header files:

```text
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

## Struct Types

Struct type names use PascalCase.

Examples:

```c
Player
Room
```

---

## Constants

Use UPPER_CASE.

Examples:

```c
MAX_NAME_LENGTH
MAX_INVENTORY_SIZE
MAX_ROOMS
```

---

# Function Design

Each function should have one clear responsibility.

Functions should be short whenever possible.

If a function becomes difficult to understand, consider splitting it into smaller functions.

A function should do what its name suggests and avoid unrelated responsibilities.

---

# Modules

Each module should own one responsibility.

A module generally consists of:

```text
module.c
module.h
```

The header defines the public interface.

The `.c` file contains the implementation.

Other modules should interact with a module through its header rather than depending on its internal implementation.

---

# Header Files

Header files should contain information required by other source files, such as:

* structures
* function declarations
* constants
* public interfaces

Implementation details should remain in the `.c` file whenever possible.

---

# Comments

Comments should explain **why** when the reason is not obvious.

Good:

```c
// Prevent the player from leaving the map.
```

Avoid unnecessary comments such as:

```c
// Add 1 to x.
x++;
```

Function documentation should primarily describe what the function does and what its parameters represent.

Example:

```c
/// @brief Initializes the rooms used by the game world.
/// @param rooms Pointer to the array of Room structs.
void rooms_initialize(Room *rooms);
```

Avoid documenting implementation details that may change.

For example, the documentation does not need to explain that `strcpy()` is currently used internally.

---

# Pointers and Structures

When accessing a structure directly:

```c
Room room;
room.north;
```

When accessing a structure through a pointer:

```c
Room *room;
room->north;
```

Use pointers when a function needs to work with an existing structure rather than an unnecessary copy.

---

# Formatting

* Use 4 spaces for indentation.
* Always use braces for control statements.
* Leave a blank line between logical sections of code.
* Keep code consistently formatted.
* Avoid unnecessarily long functions.
* Keep related code together.

---

# Function Prototypes

Public functions should be declared in the appropriate header file.

Example:

```c
void command_look(Player *player, Room *rooms);
```

The implementation belongs in the corresponding `.c` file.

---

# Include Organization

A source file should include the headers required by its implementation.

For example, if a source file directly uses `strcpy()`, it should include:

```c
#include <string.h>
```

rather than relying on another header to include it indirectly.

---

# Git Commits

Commit messages should be short and describe the change clearly.

The project will gradually move toward a more structured commit style.

Examples:

```text
feat: add room movement
fix: correct room connection
docs: add session 5 documentation
refactor: separate room initialization
```

Commit messages should describe the change rather than the development process.

---
