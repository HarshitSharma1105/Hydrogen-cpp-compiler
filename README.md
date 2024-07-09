# Hydrogen Lang (CPP Compiler)

Hydrogen is a Hobby programming language. It is called Hydrogen because it is simple, lightweight, and will catch on
fire if handled improperly🔥

This compiler is written in C++ but hopefully it will get to a point where it can be self-hosted.

## Building

Requires `nasm` and `ld` on a Linux operating system.

```bash
git clone https://github.com/HarshitSharma1105/Hydrogen-compiler-in-cpp.git
cd hydrogen-cpp
mkdir build
cmake -S . -B build
cmake --build build
```

Executable will be `hydro` in the `build/` directory.


