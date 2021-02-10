# Cracking the Coding Interview: 6th Edition (in C++)

## This repository
- [Cracking the Coding Interview: 6th Edition (in C++)](#cracking-the-coding-interview-6th-edition-in-c)
  - [This repository](#this-repository)
  - [Foreword](#foreword)
  - [Table of Contents (interview questions)](#table-of-contents-interview-questions)
  - [Questions I have completed](#questions-i-have-completed)
  - [Folder Structure](#folder-structure)
    - [`build/`](#build)
    - [`doc/`](#doc)
    - [`src/`](#src)
    - [`.clang-format`](#clang-format)
    - [`README.md`](#readmemd)
    - [`ctci6`](#ctci6)
    - [`exclude.txt`](#excludetxt)
    - [`makebuilds`](#makebuilds)
    - [`maketarball`](#maketarball)
  - [Quick Start (generate, build, run) on Unix-based systems](#quick-start-generate-build-run-on-unix-based-systems)
    - [Step 0](#step-0)
    - [Step 1](#step-1)
    - [Step 2](#step-2)
  - [More information on building](#more-information-on-building)

## Foreword

This repository contains work/solutions for<br>
<i>Cracking the Coding Interview: 6th Edition</i><br> by <b>Gayle Laakmann McDowell</b>.<p>
The sources (will be) written in <b>C++17</b>.<br>
All sources are WIP (work in progress).

I wanted to have a one-stop solution for practicing coding problems;<br>
the [Table of Contents](doc/toc.md) markdown file is hyperlinked with subpages for each chapter --<br>
each chapter page has links to the source files associated with each question.

I am using <b>Visual Studio Code</b> (with a markdown preview extension),<br>
and the Terminal (on macOS).

## Table of Contents (interview questions)

- Chapter `01` | [Arrays and Strings](doc/01.md)
- Chapter `02` | [Linked Lists](doc/02.md)
- Chapter `03` | [Stacks and Queues](doc/03.md)
- Chapter `04` | [Trees and Graphs](doc/04.md)
- Chapter `05` | [Bit Manipulation](doc/05.md)
- Chapter `06` | [Math and Logic Puzzles](doc/06.md)
- Chapter `07` | [Object-Oriented Design](doc/07.md)
- Chapter `08` | [Recursion and Dynamic Programming](doc/08.md)
- Chapter `09` | [System Design and Scalability](doc/09.md)
- Chapter `10` | [Sorting and Searching](doc/10.md)
- Chapter `12` | [C and C++](doc/12.md)
- Chapter `15` | [Threads and Locks](doc/15.md)
- Chapter `16` | [Moderate](doc/16.md)
- Chapter `17` | [Hard](doc/17.md)
  
## Questions I have completed

See [Completed Question List](doc/QTODO-list.md)<br>
for a checklist of questions I have completed.<br>
<p>Please feel free to fork this repository and have your own working copy.

## Folder Structure
### `build/`
  - This folder is not in the repository, but will be generated by CMake when the `makebuilds` script is run.<br>It is not to be added to the repository -- this directory is in the `.gitignore`.
### [`doc/`](doc)
  - Markdown documents (aside from `README.md`) are kept here.<br>
### [`src/`](src)
  - Source files for questions are kept here.<br>
  - The first level within [`src/`](src) are the <b>chapter directories</b>.
  - Within a <b>chapter directory</b> is a directory containing the sources for a given <b>question</b>.
    - For example: [`./src/01/01/`](src/01/01) is the directory that contains the sources for<br>[Chapter 01: Arrays and Strings, question 1.1](./doc/01.md).
  - A <b>question directory</b> has three files:
    - `main.cpp`
    - `header.hpp`
    - `source.cpp`
    - For example, here are the files for <br>[Chapter 01: Arrays and Strings, question 1.1](./doc/01.md):
      - [`./src/01/01/main.cpp`](src/01/01/main.cpp)
      - [`./src/01/01/header.hpp`](src/01/01/header.cpp)
      - [`./src/01/01/source.cpp`](src/01/01/source.cpp)
    - You can build and run these sources by invoking `./ctci6 01 01` in the Terminal.
      - Note: You must have the `cmake`-generated `Makefiles` first. <br>Run [`./makebuilds`](#makebuilds) (just once) to create the [`build`](#build) directory.
### [`.clang-format`](.clang-format)
  - Used by `clang-format` to format source code.
### [`README.md`](README.md)
  - This document.
### [`ctci6`](ctci6)
  - `zsh` script that
    -  runs `make` on the sources of a given question
    -  runs the executable for a given question
    -  For example: The shell command `./ctci6 01 01` will build and run<br>[Chapter 01: Arrays and Strings, question 1.1](./doc/01.md).
       -  Note: See [`makebuilds`](#makebuilds)
### [`exclude.txt`](exclude.txt)
  - Used by `maketarball` to <b>exclude</b> files from the archive generated by said script.
### [`makebuilds`](makebuilds)
  - `zsh` script for users running a <b>Unix-based</b> operating system, and [building with `Makefiles`](doc/building.md).
  - Runs `cmake` and creates the following directories with build configurations/`Makefiles`:
    - `build/make/Debug`
    - `build/make/Release`
    - `build/make/RelWithDebInfo`
    - `build/make/MinSizeRel`
  - You only need to run `./makebuilds` once.
### [`maketarball`](maketarball)
  - Creates a `.tar.gz` archive of this repository.
  - `./maketarball` creates the following file: <code>ctci_edition_06_<b>yyyy-mm-dd_hhmmss</b>.tar.gz;</code><br>the <b>boldfaced</b> portion is a timestamp. 
  - You may supply an argument, like this: `./maketarball my_filename.tar.gz` if a different filename is desired.

## Quick Start (generate, build, run) on Unix-based systems

### Step 0
First, write some source code!<br>
Read the [`src`](#src) section on where to find the sources.

To build,<br>
please have the following installed on your machine:
- `LLVM (clang)` or `gcc`
- `CMake`

We will use the <b>Terminal</b>.

### Step 1
Use the provided `makebuilds` script to generate <b>`Makefiles`</b>.
```c
your_username@your-machine ctci_edition_06 % ./makebuilds
```
After the <b>`Makefiles`</b> are generated,<br>
you will no longer need to use the `makebuilds` script.<br>
(unless you delete the generated <b>`Makefiles`</b>.)

### Step 2
Then, use the provided `ctci6` script to build & run an executable for a given question.
```c
your_username@your-machine ctci_edition_06 % ./ctci6 01 01
```

<img src="doc/images/terminal_q1_ex.png" alt="drawing" width="500"/><br>

The <b>first argument</b> is the <b>chapter number</b>. ([Chapter 01](doc/01.md))<br>
The <b>second argument</b> is the <b>question number</b>. ([Question 1.1](doc/01.md))<br>

There is an <b>implicit third argument</b>, which is the <b>build type</b>.<br>
<code>Debug</code> is the default</code>.<br>

You may supply a <b>third argument</b>; the following are supported:<br>
- <code>Debug</code>
- <code>Release</code>
- <code>RelWithDebInfo</code>
- <code>MinSizeRel</code>

The example below runs the same executable in <code>Release</code> mode.
```c
your_username@your-machine ctci_edition_06 % ./ctci6 01 01 Release
```

<img src="doc/images/terminal_q1_ex_release.png" alt="drawing" width="500"/><br>

## More information on building
This repository uses <b>CMake</b>. (see https://cmake.org) <p>
Review [Building](doc/building.md) for more details.
