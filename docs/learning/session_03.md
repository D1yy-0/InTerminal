# Session 3 – Command Processing and String Handling

**Project:** InTerminal  
**Language:** C  
**Session Goal:** Transform the engine from a simple game loop into an engine capable of processing player commands.

---

# Objectives

By the end of this session we wanted to:

- Build the first command processing pipeline.
- Keep the game loop clean by separating responsibilities.
- Learn how strings are stored in memory.
- Understand why `strcmp()` exists.
- Understand why `fgets()` caused our first bug.
- Learn the difference between `sizeof()` and `strlen()`.
- Practice systematic debugging instead of guessing.

---

# What We Built

The engine now follows this flow:

Player

↓

game_input()

↓

game_update()

↓

process_command()

↓

game_render()

↓

game_shutdown()

The player can now type commands that are interpreted by the engine.

Currently the engine supports one command:

```
quit
```

Typing `quit` exits the game cleanly.

---

# Why We Created process_command()

Originally it was tempting to place every command inside `game_update()`.

Instead we created a dedicated function:

```c
static void process_command(void);
```

This follows the **Single Responsibility Principle**.

Instead of making one huge function:

```
game_update()
```

become:

```
500 lines

1000 lines

2000 lines
```

we keep it small.

Its responsibility becomes:

```
Update the game.
```

while

```
process_command()
```

becomes responsible for understanding player input.

---

# The Command Pipeline

The complete command flow is now:

```
Keyboard

↓

fgets()

↓

command[]

↓

process_command()

↓

Engine State Changes

↓

Render
```

This pipeline will be reused throughout the entire project.

Future commands such as:

- help
- look
- inventory
- north
- south
- attack
- save
- load

will all pass through the same system.

---

# Understanding Strings

One of the biggest topics of this session was understanding what a string really is.

The string:

```
Hello
```

is actually stored as:

```
H
e
l
l
o
\0
```

The null terminator (`'\0'`) marks the end of the string.

Everything after the first null terminator is ignored by string functions.

---

# Why strcmp() Exists

Many beginners try to compare strings using:

```c
if (command == "quit")
```

This does **not** compare the text.

It compares memory addresses.

Instead:

```c
strcmp(command, "quit")
```

compares every character one by one until:

- characters differ
- or both strings reach `'\0'`

If they are identical it returns:

```c
0
```

---

# The fgets() Bug

Our first real bug appeared here:

```c
fgets(command, sizeof(command), stdin);
```

Typing:

```
quit
```

actually stores:

```
q
u
i
t
\n
\0
```

The Enter key becomes the newline character:

```
'\n'
```

Meanwhile the string literal:

```c
"quit"
```

is stored as:

```
q
u
i
t
\0
```

Because:

```
'\n'
!=
'\0'
```

`strcmp()` correctly reports that the strings are different.

---

# Fixing the Bug

We removed the newline using:

```c
command[strcspn(command, "\n")] = '\0';
```

Conceptually:

Before:

```
q
u
i
t
\n
\0
```

After:

```
q
u
i
t
\0
\0
```

The newline is replaced with a null terminator.

The string now matches:

```
"quit"
```

---

# strlen() vs sizeof()

One of the most important C concepts.

Example:

```c
char word[10] = "Cat";
```

Memory allocated:

```
10 bytes
```

Characters stored:

```
C
a
t
\0
```

Results:

```c
sizeof(word)
```

returns:

```
10
```

because it measures the array size.

---

```c
strlen(word)
```

returns:

```
3
```

because it counts characters until the first null terminator.

---

# Debugging Lesson

Instead of guessing, we traced execution step by step.

Questions we asked:

```
Does game_update() run?

↓

Yes

↓

Does process_command() run?

↓

Yes

↓

Does strcmp() succeed?

↓

No

↓

Inspect command[]

↓

Found newline

↓

Fix applied
```

This is an example of systematic debugging.

---

# Programming Principles Learned

## Separation of Responsibilities

Each function should have one clear purpose.

```
game_input()
```

reads input.

```
process_command()
```

interprets commands.

```
game_update()
```

coordinates the update step.

---

## Delegation

Instead of one function doing everything:

```
game_update()
```

delegates work to:

```
process_command()
```

Later it will also delegate to:

```
update_world()

update_enemies()

update_quests()

...
```

---

## Defensive Programming

Instead of assuming input succeeds:

```c
if (fgets(...) != NULL)
```

we verify success before processing the string.

This makes the program safer and more robust.

---

# Session Review Questions

Before moving to Session 4, make sure you can answer:

1. Why can't we compare strings using `==`?
2. What is the purpose of `strcmp()`?
3. Why does `fgets()` store the newline character?
4. Why does replacing `'\n'` with `'\0'` fix the comparison?
5. What is the difference between `strlen()` and `sizeof()`?
6. Why is `process_command()` separate from `game_update()`?
7. What does the null terminator represent?

If you can answer these without looking them up, you've understood the key concepts of this session.

---

# Key Takeaways

- Strings are arrays of characters ending with `'\0'`.
- `strcmp()` compares text, not memory addresses.
- `fgets()` keeps the newline character.
- `strcspn()` helps locate the newline.
- `sizeof()` measures allocated memory.
- `strlen()` measures string length.
- Small functions are easier to understand and maintain.
- Good debugging is based on observation and testing, not guessing.

---

# Looking Ahead – Session 4

Session 4 marks the beginning of the actual RPG.

The focus will shift from the engine itself to the game world.

Topics include:

- Designing the Player
- Designing Rooms
- Room connections
- World architecture
- Moving between rooms
- The `look` command
- The first handcrafted map

Procedural generation will **not** begin yet.

Instead, we will first build a complete handcrafted world.

Once that works, we will replace it with procedural generation in later sessions.

This follows the philosophy:

> Make it work.
>
> Make it clean.
>
> Make it dynamic.
