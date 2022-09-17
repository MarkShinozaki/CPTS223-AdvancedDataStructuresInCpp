#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

// ADVANTAGES/DISADVANTAGES LINKED LIST
/*
Advantages of a linked list are it is dynamic. It allocates memory when requird
and it can easily implement insertion and deletion operations. 
Disadvantages of linked list are memeory is wasted because the linked list requires
extra memory to store and it cannot access elements randomly.
*/


/*****************************************************************
* Programmer: Mark Shinozaki                                     *
* Class: Computer Science 223                                    *
* Programming Assignment 1: Learning Linux commands matching game*
* Descriprion: In this assignment we are meant to match linux
  commands to their prospective descriptions                     *
******************************************************************/

#include "Wrapper.cpp"

int main()
{
    srand((unsigned)time(NULL));
    run();
    return 0;
}