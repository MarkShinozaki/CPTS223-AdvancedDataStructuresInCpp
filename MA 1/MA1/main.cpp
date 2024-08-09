#include <iostream>
#include <cstdlib>
using namespace std;
#include "testQueue.hpp"
#include "header.h"

/*
IN
1. Not having the files separated was not a good design decision 

2. In terms of structure I think putting size, isfull and isempty higher is a smarter design design choice 

3. The \n isnt great for separation when testing 

4. Organization of file, the file was not organized 

5. Readability, there wasnt must comments in important sections 



*/
int main()
{

    cout << "Hello this is the start of the program" << endl;
    testDequeueEmpty();
    testDequeueFull();
    testEnqueueEmpty();
    testEnqueueFull();
    testPeekEmpty();
    testPeekFull();


    testSize();
    testIsEmpty();
    testIsFull();
    return 0;
}
