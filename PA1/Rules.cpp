#include "Rules.hpp"


void Rules()
{
    cout << "Rules of the Game:\nThe user will be prompted with a linux command along with 3 multiple choices of command "
    "descriptions. The users should pick the correct command description that "
    "corresponds to the give command. If the user gets the correct answer, one point will "
    "be given. If the user gets the incorrect answer then one point will be " 
    "lost. The user is able to choose from 5-30 questions to generate in the game." << endl;

}

void to_Continue()
{
    cout << "\n...Press Enter...\n" << endl;
    cin.get();
}