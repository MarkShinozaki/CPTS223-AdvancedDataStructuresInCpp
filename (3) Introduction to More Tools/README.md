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
  - a

