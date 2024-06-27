# (1 - 2) More Linux, Tools & Git

## CptS 223
Washington State University

### Options for Linux access

- Install VirtualBox (or something else) and make a Virtual Linux machine
- Install Windows Subsystem for Linux (WSL)
  - Find the tutorial for WSL installation on Canvas "Modules" page
- Install Linux on a computer, either solely or dual boot

### Common command line programs

- `pwd` – print working directory
- `ls` - list files in directory
- `cd` - change directory
- `rm` - remove file
- `cp` - copy file
- `mkdir` - make directory
- `rmdir` - remove directory
- `nano` / `vi` / `emacs` - edit a file
- `ssh` - use ssh to connect to server
- `scp` - copy file over ssh to server
- `man` - manual page for tools
- `g++` - use GNU C++ compiler
- `make` - run make to build a program
- `ps` - list running programs
- `kill` - kill a running program
- `top` - watch running programs

### Tons of Linux tutorials out there:

- [GeeksforGeeks Linux Commands](https://www.geeksforgeeks.org/linux-commands/)
- [Ryan's Tutorials](https://ryanstutorials.net/linuxtutorial/)
- [Linux Command](http://linuxcommand.org/index.php)
- [Codecademy Command Line](https://www.codecademy.com/learn/learn-the-command-line)
- [Unix Tutorial](http://www.ee.surrey.ac.uk/Teaching/Unix/)

### Grab a Cheat Sheet

The world of UNIX commands is large. As you’re starting out, grab a cheat sheet and even keep a notepad of commands you’ve used until you’re more comfortable with the tool set.

- Here’s a pretty reasonable one:
  - [FossWire UNIX Cheat Sheet](https://files.fosswire.com/2007/08/fwunixref.pdf)
- Another source for commands:
  - [GeeksforGeeks Linux Commands](https://www.geeksforgeeks.org/linux-commands/)

### How to run commands on the command line

On the command line, the first thing you type is the name of a program to run. If it’s not a standard program, you also need to have the path to the file. Everything after the name of the program are command line options, unless you chain multiple programs together with pipes or give shell I/O redirections.

- `ls` (lists the files and directories)
- `ls -la` (lists all including hidden, plus other stuff)
- The man page (`man ls`) will tell you more of what’s available for a tool

### More

- Your home directory is also called: `~`
  - `$HOME` is the variable (the shell is a coding environment, right?) holding it too
- Filesystem norms: `/home`, `/etc`, `/usr`, `/dev`, `/var`, `/tmp`, `/mnt`, `/opt`, `/root`
- Can this class be done on a Raspberry Pi computer? Yes!
  - Raspbian is a Debian fork, just FYI
- There are various shells, but most people use bash

### WAIT!!! How do programs use command line options?

Remember how your programs would sometimes start with:
```cpp
int main( int argc, char* argv[] )
```

- `argc` is the number of strings (split by spaces) the program was with
- `argv` is an array of `char*` strings, one with each "word"
- `argc` is always at least 1 since the first string is the name of the file used to run the program, including the path
- GUI IDE (VS) have ways to set the options passed while testing builds

### The UNIX filesystem structure
- Where's `c:\`? - Windows! Not part of this system!
- Everything lives in a single tree under `/`
  - This is called "slash" or root (not to be confused with the root user)
- More filesystems (disks,etc) are just mounted under `/` somewhere
  - Command to add a disk is: `mount`
  - Removing is: `unmount`
  - All disks are in the devices directory: /dev
  - Ex: `/dev/sda1`
- Most of this is taken care of for you in a default Linux install from a distro
  - But if you start using thumb drives or adding hard drives to your system, this shows up

### Editing files
- **The big three options:**

- Vi
- Emacs
- Nano

There’s plenty more options, but these are the big 3.


### Building software via g++

- Run the program `g++` and tell it which cpp files you want built. In simple programs, it’s just that simple. Options to include:

-`-g` (leaves in debugging symbols)
- `-Wall` (enables ALL warnings)
- `-o` [filename] (tells g++ what to name the final program)
- `-std=c++11` (tells g++ to use the c++11 language standard)

Could be more specific and build object files (`*.o`), then link those. Great for larger programs with LONG build times. Can actually do partial rebuilds based on which source files have changed.

### What is make?

- A tool to help build software but platform dependent
- Huge supply of documentation: [GNU Make Manual](https://www.gnu.org/software/make/manual/make.html)
- Rely on a “makefile” to specify the compilation details
  - I.e., what are the source files, how to link them together
- `make [target] → make build → make run → make test`
- A tutorial: [Makefile Tutorial](https://makefiletutorial.com/)

### What is CMake?
- A Cross-platform Make tool using a compiler-independent and platform-independent method
- CMake is not a build system. It is a build-system generator
- CMake relies on a “CMakeLists.txt” file to generate makefile
- You can use the same C++ project in Linux, MacOS, Windows with no or tiny modification
- You can also develop your project in IDE
- An example: [CPTS-223-Examples](https://github.com/DataOceanLab/CPTS-223-Examples)
- Installation: [CMake Install](https://cmake.org/install/)
- Comparison with make: [CMake vs Make](https://prateekvjoshi.com/2014/02/01/cmake-vs-make/)

### GUI IDE options

If you’ve got a desktop, there’s options for GUI tools:

- CLion
- netbeans
- Code::Blocks
- KDevelop
- Eclipse
- CodeLite IDE
- Geany IDE
- vscode

### Git 

- A distributed version-control system for tracking changes in any set of files, originally designed for coordinating work among programmers
- Created by Linus for Linux kernel in 2005
- Install on Ubuntu: `sudo apt install git`
- SVN: a centralized version-control system. Good for big companies, requires a dedicated centralized server

### The Git model

#### GitHub - [GitHub](https://github.com/)

- Consider it a central place for a copy of your repo to live. Web interface for management of things. You can push/pull commits to any remote repository, there’s no real difference between a server and a client. This is a truly distributed architecture.

### How to get a copy of a repo is by “cloning” it

#### Some Definitions

- Staging changes for committing
  - `git add or git rm`

- Commits are only local until they’re pushed or cloned away
- After adding (or rm’ing) and committing...

#### What branch are you on at the moment? Just ask!
- The default is `master/main`
- Work on a different branch
- Create a branch

```
git branch my-new-branch
```
  - It will create a branch based on the current commit you are at
- Switch to a branch

```
git checkout my-new-branch
```
- It will search for the origin if your local one does not have such a branch

#### Extra Material: Commands to know


`git help` - manual for git & commands
`git add` - add a file/changes to be tracked and staged by git
`git commit` - comment and staged file(s)
`git status` - review tracked & untracked file(s)
`git diff` - show unstaged changes since last commit
`git log` - show commit logs

#### Git guide and GitHub cheat sheet on Canvas

`git branch` - list, create, delete branches
`git checkout` - switch branches and more
`git fetch` - grab updates from remote and stage them in [remote]/[branch] branch
`git merge` - attempt to combine [remote]/[branch] into current branch
`git pull` - fetch and merge
`git rebase` - reapply commits on top of another base tip

#### Git GUI
- SmartGit: Free for Non-commercial use
- GitHub: Free
- SourceTree: Free
- And more: [Git GUIs](https://git-scm.com/downloads/guis)

---

### [Next Section: Introduction to Linux ](https://github.com/MarkShinozaki/CPTS223-AdvancedDataStructuresInCpp/tree/Helpful-Material/(4)%20Introduction%20to%20Linux)











