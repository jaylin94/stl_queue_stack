/*********************************************************************
** Program name: STL Queue and Stack
** Author: Jay Lin
** Date: 05/24/2019
** Description: This program asks the user to pick between a queue or a
** stack. The user will enter the number of percentages to add or remove
** a random number from the queue and display the average length of the queue.
** If a stack is selected, the user will be prompted to enter a string and 
** the palindrome of that string will be displayed.
** To start, extract all files. Type "make" to compile the program.
** Then type "./main" to run the program.
*********************************************************************/
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <queue>
#include <stack>
#include <string>
#include "menu.hpp"
using std::cin;
using std::cout;
using std::endl;
using std::queue;
using std::stack;
using std::string;

int main()
{
    //Seeds the random number generator in queue.cpp
    srand(time(0));

    //Declaring objects and data structures required
    Menu menu1;
    queue<double> rQueue;
    stack<char> rStack;

    //Runs main menu and program's functions
    menu1.runMenu(rQueue, rStack);

    return 0;
}
