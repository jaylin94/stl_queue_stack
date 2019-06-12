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
#include <stack>
#include <string>
#include "stack.hpp"
using std::cin;
using std::cout;
using std::endl;
using std::stack;
using std::string;

//Generates a palindrome from a string entered by the user. Takes a reference to a stack of char as a parameter.
void generatePalindrome(string userString, stack<char> &rStack)
{
    //Pushes string on stack forwards, pops off stack in reverse
    for (int i = 0; i < userString.length(); i++)
    {
        rStack.push(userString[i]);
    }
    //Pushes string on stack in reverse, pops off forwards
    for (int i = userString.length() - 1; i >= 0; i--)
    {
        rStack.push(userString[i]);
    }

    //Outputs palindrome
    cout << "Your palindrome is: ";
    showStack(rStack);
    cout << endl;
}

//Shows all values of a given stack. Takes a reference to a stack of char as a parameter.
void showStack(stack<char> &rStack)
{
    while (rStack.empty() == false)
    {
        cout << rStack.top();
        rStack.pop();
    }
}