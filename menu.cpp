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
#include <string>
#include <queue>
#include <stack>
#include "menu.hpp"
using std::cin;
using std::cout;
using std::endl;
using std::string;

//Displays menu for the game, prompts user to start or quit. Provides a
//quick description of the game. Displays menu to rerun as well.
void Menu::displayMenu()
{
    //Times run checks if this is the first time running.
    //The welcome message will only be displayed if timesRun is 0.
    if (timesRun == 0)
    {
        //gameName is set by getProgramName() in the constructor.
        cout << "Welcome to " << getProgramName() << "." << endl;

        cout << "This is a program that demonstrates a queue and a stack." << endl;

        cout << "Please enter 's' to start, or 'q' to quit. " << endl;
    }
    //Displays rerun prompt if timesRun is > 0.
    else if (timesRun > 0)
    {
        cout << "Continue with " << getProgramName() << "? "
             << "Enter 's' to start, 'q' to quit." << endl;
    }
    setTimesRun(getTimesRun() + 1);
}

//Displays function options menu
void Menu::displayMenu2()
{
    cout << "Please choose from the following options: " << endl;
    cout << "1. Queue" << endl;
    cout << "2. Stack" << endl;
    cout << "3. Exit " << endl;
}

//Runs all menu options for the program, including the main functions. Takes a
//queue reference and stack reference as parameters.
void Menu::runMenu(std::queue<double> &rQueue, std::stack<char> &rStack)
{
    displayMenu();
    validateStartChoice();

    while (startCheck())
    {
        if (menuChoice(rQueue, rStack) == false)
        {
            break;
        }

        displayMenu();
        validateStartChoice();
    }
}
//Gets the user choice for the second menu, runs main functions. Takes a reference to
//a queue and stack as parameters.
bool Menu::menuChoice(std::queue<double> &rQueue, std::stack<char> &rStack)
{
    bool run = true;
    int userChoice;
    int rounds;
    int addChance;
    int removeChance;
    string userString;
    //Gets and validates user integer input for menu options 1-3.
    do
    {
        displayMenu2();
        int userChoice = validateInt(1);

        switch (userChoice)
        {
        case 1:
            validateQueueOptions(rounds, addChance, removeChance);
            runQueueSim(rounds, addChance, removeChance, rQueue);
            break;

        case 2:
            cout << "Please enter a string to create a palindrome with a stack data structure: " << endl;
            getline(cin, userString);
            generatePalindrome(userString, rStack);
            break;

        case 3:
            run = false;
            return run;
        }
    } while (userChoice != 3);
}

//Validates integers for rounds, add chance and remove chance %. Takes 3 integer references as parameters.
void Menu::validateQueueOptions(int &rounds, int &addChance, int &removeChance)
{
    cout << "Please enter an integer 1 - 32767 for the number of rounds to simulate the queue: " << endl;
    rounds = validateInt(2);
    cout << "Please enter an integer 1-100 for the percentage chance to add an item to the queue: " << endl;
    addChance = validateInt(3);
    cout << "Please enter an integer 1-100 for the percentage chance to remove an item from the queue: " << endl;
    removeChance = validateInt(3);
}

//Validates user integer input for a variety of functinos in Menu. Takes an integer parameter to
//determine the range of acceptable inputs from the user. Returns an integer as a choice for
//corresponding menu functions.
int Menu::validateInt(int key)
{
    //Float validation adapted from: https://www.quora.com/How-do-I-check-if-a-number-is-float-on-C++
    double choice = 0.0;
    int floatTest = 0;

    int upperLim = 0;
    int lowerLim = 0;
    string message;

    //Range for main menu choice, 1 - 5
    if (key == 1)
    {
        message = "Please enter a valid integer 1, 2, or 3.";
        upperLim = 3;
        lowerLim = 1;
    }
    //Range for steps, rows and columns, 1 - 32767
    else if (key == 2)
    {
        message = "Please enter a valid integer > 1, < 32767. ";
        upperLim = 32767;
        lowerLim = 1;
    }
    else if (key == 3)
    {
        message = "Please enter a valid integer 1-100. ";
        upperLim = 100;
        lowerLim = 1;
    }

    while (true)
    {
        //Detects invalid string/char input and reprompts user
        while (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << message << endl;
        }
        //Detects float input, out of range input
        floatTest = choice * 100000000.0;
        if (((floatTest % 100000000) > 0) || choice < lowerLim || choice > upperLim)
        {
            //Clears extraction failure flag
            cin.clear();
            //Ignores next 10000 inputs in the buffer until \n
            cin.ignore(10000, '\n');
            cout << message << endl;
        }
        //Valid input, returns integer
        else
        {
            cin.ignore(10000, '\n');
            return choice;
        }
    }
}

//Validates menu input choice to start the program or quit.
//Ensures that input is a character of 's' to start or
//'q' to quit. Returns a character of 's' or 'q'.
char Menu::validateStartChoice()
{
    string choice;
    while (true)
    {
        cin >> (choice);
        //Character array to validate user input for a character, other inputs are
        //invalid.
        char newChoice[1];
        newChoice[0] = choice[0];
        cin.ignore(10000, '\n');
        if (choice.length() > 1)
        {
            cout << "Please enter 's' to start or 'q' to quit." << endl;
        }
        else if (newChoice[0] == 's' || newChoice[0] == 'q')
        {
            setStartChoice(newChoice[0]);
            return newChoice[0];
        }
        else
        {
            cout << "Please enter 's' to start or 'q' to quit." << endl;
        }
    }
}

//Prompts user for menu input to start or quit, using
//getMenuChoice(). Quits if user input is 'q'. Returns a bool of true (s) or false (q).
bool Menu::startCheck()
{
    if (getStartChoice() == 'q')
    {
        return false;
    }
    else
    {
        return true;
    }
}

//Displays a line of '~' characters, 90 characters long.
void Menu::displayLine()
{
    for (int i = 0; i < 90; i++)
    {
        cout << '~';
    }
    cout << endl;
}

//Asks user to press any key and/or ENTER/RETURN to continue.
void Menu::displayContinue()
{
    std::string anyKey;
    cout << "Press any key and/or ENTER/RETURN to continue. " << endl;
    getline(cin, anyKey);
}