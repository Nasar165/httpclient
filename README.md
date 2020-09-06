# HTTP CLIENT

## Introduction

Single threaded socket capable of connecting to a API trough HTTP protocol.
Suitable for embedded systems such as a small arduino project or a simple
application.

## Key Highlights

- GET and POST methods.
- Convert Domain to IP.
- Support URL.
- Single Thread/Thread safe
- Memory optimized.
- Small Codebase.

## Testing the Code before implementation

This section explains how to test the C code before running it on a real project.
We expect that you possess some basic understanding of C and GCC running in a
Linux environment.

```
1 Go to source directory and enter gcc main.c -o out/out
2 run the app by entering ./a.out GET google.com
```

## Development environment

- Fedora 32/ GNU Linux - Operating System
- GCC - C compiler
- GDB - C Debugger
- VS Code - Code editor
- Github - Version Control

## USE CASE

The code is designed to run on embedded systems such as an arduino connected to
the internet trough WiFi or ethernet. It can also be used in Linux OS applications.
