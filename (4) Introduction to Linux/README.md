
# Intro to Linux and gcc/g++

## Course Collaborators

A lot of material for this course was adapted from Andrew S. O’Fallon’s, Aaron Crandall’s, Ananth Kalyanaraman’s and Jia Yu’s courses or developed concurrently with them

  - [Aaron Crandalls](https://school.eecs.wsu.edu/people/faculty/aaron-crandall/)
  - [Ananth Kalyanaraman](https://www.eecs.wsu.edu/~ananth/)


## Motivation for this introduction

Today we’re going to do a bit on:
- Linux (operating systems)
- G++/gcc (compilers)
- Philosophy

Goal: basics for completing assignments in this course

## Operating system (OS)?

Short answer: It’s a program

## Diagram of OS

Normally, computers are envisioned as onion layers or stacks

## Officially “Linux” is just a kernel

- Linux is only the operating system kernel
- Colloquially, it’s used to refer to a whole distribution with user tools
- The result is the GNU/Linux name, since the user tools are (mostly) GNU
- Packaged together they become Linux distributions or “distros” like Debian, Ubuntu, Arch, SUSE, RedHat, etc.

(Core of OS)

## Really, there are LOTS of operating systems

- Linux: Unix-like
- BSD (freeBSD, OpenBSD, NetBSD): Unix-like
- macOS (Darwin, from BSD): Unix-like
- WinNT
- Plan9

[List_of_operating_systems](https://en.wikipedia.org/wiki/List_of_operating_systems)


## WAIT! Isn’t Linux UNIX?

- No, well… kinda. They’re cousins
- UNIX was developed at AT&T Bell Labs 1971.11.03 by Ken Thompson and Dennis Ritchie (who invented C ‘69-’73 to rewrite UNIX)
- Linux was modeled after Minix (a stripped down UNIX clone for education) and released by Linus Torvalds in October 1991
- Linux was inspired by UNIX, but doesn’t share the same code
- They do share many of the same philosophies though: [https://goo.gl/99Owcx](https://goo.gl/99Owcx)
- There are still official UNIX OS releases: FreeBSD, OSX, others: - [https://www.opengroup.org/openbrand/register/](https://www.opengroup.org/openbrand/register/)

- [Ken Tompson & Dennie Ritchie](https://goo.gl/99Owcx)
- [https://www.opengroup.org/openbrand/register/](https://www.opengroup.org/openbrand/register/)



## Okay… so what’s that UNIX philosophy?

- [https://en.wikipedia.org/wiki/Unix_philosophy](https://en.wikipedia.org/wiki/Unix_philosophy)
The Unix philosophy, originated by Ken Thompson, is a set of cultural norms and philosophical approaches to minimalist, modular software development.

- Emphasis on building simple, short, clear, modular, and extensible code that can be easily maintained and repurposed by developers other than its creators



## GUI vs. Command Line

- The eternal question (since about 1973)
- Both are great!
- But… since all data are strings in the end, the command line has more power for the user to interact with the OS
- Read “In the Beginning Was the Command Line” by Neal Stephenson
  - [http://faculty.georgetown.edu/irvinem/theory/Stephenson-CommandLine-1999.pdf](http://faculty.georgetown.edu/irvinem/theory/Stephenson-CommandLine-1999.pdf)
  - Highly recommended for understanding UNIX and Linux philosophy

[http://faculty.georgetown.edu/irvinem/theory/Stephenson-CommandLine-1999.pdf](http://faculty.georgetown.edu/irvinem/theory/Stephenson-CommandLine-1999.pdf)



## Why Linux and not [Fill in the blank]

Probably 2 primary reasons: Control & Utility
- You have control over your system (at ALL levels)
- It has a large suite of extant tools for most uses

Linux can be used for almost any computing environment
- The Kernel scales very well, and you can use/edit the source to suit your needs
- Linux/UNIX was designed for remote access by default
  - GUIs aren’t great over the network.
  - UNIX was built for multi-user and multi-tasks and Linux inherited that powerful structure



## Plus… Why is Linux free‽

We’ll talk about Open Source and Free Software during this class
- Basically: if you don’t have the source to your programs you have nothing
- This actually does matter
- The Free Software Foundation (FSF) are the makers of GNU (GNU’s not UNIX)
  - They also released the GPL license to make copyright work for us

- Open Source Software (OSS) is the idea that software should be shared
  - OSS created a huge field of people developing code and freely releasing it to others
  - Linux is released under the GPL license, as are many OSS tools and distros
  - Linux Kernel source: [https://github.com/torvalds/linux](https://github.com/torvalds/linux)
  - Top OSS licenses: MIT (25%) -- GPL 3.0 (19%) -- Apache 2.0 (15%) -- GPL 2.0 (15%) -- BSD 3 (6%)

[https://en.wikipedia.org/wiki/GNU_General_Public_License](https://en.wikipedia.org/wiki/GNU_General_Public_License)
[https://github.com/torvalds/linux](https://github.com/torvalds/linux)
[https://opensource.org/licenses](https://opensource.org/licenses)



## So, which Linux distro should I use?

- Actually, all of them have the GNU gcc/g++ compiler
  - That’s what they use to build the Linux kernel itself, so this is a requirement
  - We will use Ubuntu 20.04 in our class

- Debian, Mint, Ubuntu, RedHat/Fedora/CentOS
  - If you feel like reaching: Arch, ElementaryOS, geez 100+ options: [http://futurist.se/gldt/wp-content/uploads/11.10/gldt1110.svg](http://futurist.se/gldt/wp-content/uploads/11.10/gldt1110.svg)



## There’s a whole lotta Linux distros out there



## Now… to sum up OSes:

- An operating system manages and mediates the hardware in your computer
- An operating system launches other programs and schedules them
- An operating system manages memory and disk use
- The user starts in a shell (GUI or command line), which launches other applications as needed
- Pick the right one for the job! But, I’m hoping that we can convince you of why Linux has taken over all serious lifting in the computer world



## Compilers



## The Compiler Concept

What is a compiler?
- It’s a program! (or several programs that work together)
- It’s a very special program - it has to take itself as input!
- It takes a string of text and converts it to a different string of text
- It takes a string in one language and converts it to another language:
  - C → Assembly → Machine code
  - Java → Byte Code

Visual Studio has a compiler within the IDE called Visual C++
- You’ve used it every time you “built” your programs



## There’s LOTS of compilers out there

- Visual C++
- GNU gcc/g++
- Clang C/C++ (LLVM)
- Intel C Compiler
- Python interpreter
- A huge list: [https://en.wikipedia.org/wiki/List_of_compilers](https://en.wikipedia.org/wiki/List_of_compilers)

To make a programming language useful (beyond a spec), you’ll need to build a compiler for it.

[https://en.wikipedia.org/wiki/List_of_compilers](https://en.wikipedia.org/wiki/List_of_compilers)



## So, the process of programming is:

1. Create a string in a given language
2. Pass that string to a compiler
3. Take results from compiler and execute those

You’ve been doing this all along inside of VS’ IDE, but here it’s going to be more explicit:
1. Edit a text file (or more text files)
2. Pass that text file to g++
3. Run resulting file as a program



## Quick VirtualBox intro

- VirtualBox is a program to run operating systems on other operating systems!
- These are called virtual machines (actually, the hardware is virtual, not the OS)
- Can use it for testing OSes, virtual networks, trying different tools out, etc.

---

### [Next Section: Math Review](https://github.com/MarkShinozaki/CPTS223-AdvancedDataStructuresInCpp/tree/Helpful-Material/(5)%20Math%20Review)
