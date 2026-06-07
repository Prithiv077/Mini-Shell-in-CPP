# MiniShell - Unix Shell Implementation in C++

A lightweight Unix-like shell built in C++ to understand core Operating System concepts such as process creation, process management, inter-process communication (IPC), file descriptors, redirection, and command execution.

## Features

### Built-in Commands

* `cd <directory>` - Change current working directory
* `pwd` - Print current working directory
* `history` - Display command history
* `source <file>` - Execute commands from a script file
* `exit` - Exit the shell

### External Commands

Supports execution of standard Linux commands using `fork()` and `execvp()`:

```bash
ls
cat
grep
touch
mkdir
rm
date
whoami
```

### Input / Output Redirection

```bash
ls > output.txt
ls >> output.txt
cat < input.txt
```

### Pipes

```bash
ls | grep cpp
cat file.txt | sort
```

### Background Processes

```bash
sleep 10 &
```

Runs processes in the background without blocking the shell.

---

## Operating System Concepts Implemented

### Process Creation

```cpp
fork()
```

Creates a child process for command execution.

### Program Execution

```cpp
execvp()
```

Replaces the child process image with the requested command.

### Process Synchronization

```cpp
waitpid()
```

Waits for foreground processes to finish.

### File Descriptors

```cpp
STDIN_FILENO
STDOUT_FILENO
```

Used for implementing redirection.

### File Operations

```cpp
open()
close()
```

Used to access files for input and output redirection.

### File Descriptor Duplication

```cpp
dup2()
```

Redirects standard input/output streams.

### Inter Process Communication (IPC)

```cpp
pipe()
```

Used to implement shell pipelines.

---

## Project Structure

```text
MiniShell
│
├── main.cpp
├── Shell.h
├── Shell.cpp
│
├── Parser.h
├── Parser.cpp
│
├── Builtins.h
├── Builtins.cpp
│
├── Executor.h
├── Executor.cpp
```

---

## Build

Compile using g++:

```bash
g++ *.cpp -o myshell
```

---

## Run

```bash
./myshell
```

---

## Example Usage

### Built-in Commands

```bash
myshell> pwd
/home/user/project

myshell> cd ..

myshell> history
```

### External Commands

```bash
myshell> ls
myshell> whoami
myshell> date
```

### Redirection

```bash
myshell> ls > files.txt

myshell> cat < files.txt
```

### Pipes

```bash
myshell> ls | grep cpp
```

### Background Processes

```bash
myshell> sleep 20 &
```

### Source Command

commands.txt

```text
pwd
date
whoami
```

```bash
myshell> source commands.txt
```

---

## Learning Outcomes

This project helped reinforce:

* Process Management
* Parent and Child Processes
* System Calls
* Linux File Descriptors
* Shell Internals
* Process Synchronization
* Inter Process Communication (IPC)
* Command Parsing
* Input/Output Redirection
* Background Job Execution

---


Associate Software Engineer | Java Developer | Operating Systems Enthusiast
