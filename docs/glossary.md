# Glossary

## Architecture

The overall organization and structure of the software.

---

## Module

A group of source and header files responsible for one part of the program.

A typical module consists of:

```text
module.c
module.h
```

---

## Game Loop

The continuous loop responsible for keeping the game running.

Current stages are:

```text
Initialize
Input
Update
Render
Shutdown
```

---

## Engine

The code responsible for running and coordinating the game.

---

## Responsibility

The specific job that a function or module is designed to perform.

---

## Ownership

The part of the program responsible for managing a particular piece of data.

---

## Interface

The public functions and types that a module exposes through its header file.

---

## Character Array

An array of `char` values.

Example:

```c
char name[50];
```

---

## C String

A sequence of characters terminated by the null character:

```c
'\0'
```

---

## Null Terminator

The character:

```c
'\0'
```

that marks the end of a C string.

---

## Pointer

A variable that stores the memory address of another object.

Example:

```c
Room *current_room;
```

---

## Structure

A user-defined C type that groups related pieces of data.

Example:

```c
typedef struct {
    char name[50];
    int north;
    int south;
} Room;
```

---

## Structure Pointer

A pointer that points to a structure.

Example:

```c
Room *current_room;
```

Structure members can be accessed through the pointer using `->`.

```c
current_room->north
```

---

## `->` Operator

The C operator used to access a member of a structure through a pointer.

Example:

```c
Room *room;

room->north;
```

---

## `.` Operator

The C operator used to access a member of a structure directly.

Example:

```c
Room room;

room.north;
```

---

## Array Index

The position used to access an element of an array.

C arrays begin at index `0`.

Example:

```c
rooms[0]
rooms[1]
rooms[2]
```

---

## Room ID

The integer used to identify a room inside the room array.

For example:

```text
0 → Tutorial Room
1 → Village
```

A room's exit stores the ID of the destination room.

---

## Function Prototype

A declaration that tells the compiler about a function before its implementation is encountered.

Example:

```c
void command_look(Player *player, Room *rooms);
```

---

## Header File

A `.h` file containing declarations, structures, constants, and interfaces that can be shared between source files.

---

## Implementation File

A `.c` file containing the implementation of functions declared by a header.

---

## Undefined Behavior

Program behavior that the C standard does not define.

The program may appear to work, crash, or produce unexpected results.

Undefined behavior should not be relied upon.

---

## Command Dispatcher

The part of the command system responsible for determining which command the player entered and calling the corresponding command function.

In InTerminal this role is currently handled by:

```text
process_command()
```

---

## Procedural Generation

The process of generating game content algorithmically rather than manually defining every piece of content.

InTerminal is planned to use procedural generation for parts of its world.

---

## Seed

A value used to initialize a random number generator.

A seed can allow the same procedural world or sequence of generated content to be reproduced.

---
