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
#include <queue>
#include <string>
#include <iomanip>
#include "queue.hpp"
using std::cin;
using std::cout;
using std::endl;
using std::queue;
using std::string;

//Runs the queue simulation. Takes 3 integers for rounds, addChance, removeChance, and a reference
//to a queue of doubles as parameters.
void runQueueSim(int rounds, int addChance, int removeChance, queue<double> &rQueue)
{
    int percentage;
    double buffLength = 0.0;
    double buffAvgCurrentRound = 0.0;
    double buffAvgPrevRound = 0.0;
    double roundCount = 1.0;

    //Simulates queue for number of rounds validated in menu
    while (rounds > 0)
    {
        //Generates random number to see if number will be appended in queue
        percentage = generateRandom(2);
        if (percentage <= addChance)
        {
            rQueue.push(generateRandom(1));
            buffLength++;
        }
        //Generates random number to see if a number will be removed from queue
        percentage = generateRandom(2);
        if (percentage <= removeChance && rQueue.empty() == false)
        {
            rQueue.pop();
            //Decrements buffer length only if it is greater than 0
            if (buffLength != 0)
            {
                buffLength--;
            }
        }
        //Calculates average length of the buffer based on formula given
        buffAvgCurrentRound = ((buffAvgPrevRound * (roundCount - 1)) + buffLength) / roundCount;
        //Sets previous round average to the current round's average
        buffAvgPrevRound = buffAvgCurrentRound;
        roundCount++;
        rounds--;
    }

    //Outputs all values in the queue, or message if there are no values
    if (rQueue.empty() == false)
    {
        cout << "Values in the buffer: ";
        while (rQueue.empty() == false)
        {
            cout << rQueue.front() << " ";
            rQueue.pop();
        }
        cout << endl;
    }
    else if (rQueue.empty() == true)
    {
        cout << "There are no values in the buffer. " << endl;
    }

    //Displays buffer length and average length of the buffer
    cout << "Buffer length: " << buffLength << endl;
    cout << "Average length of the buffer: " << std::setprecision(2) << buffAvgCurrentRound << endl;
}

//Generates a random number, takes an integer as a parameter to select the range of the random number generated.
//1 for 1 - 1000, 2 for 1 - 100, 3 for 0.
double generateRandom(int key)
{
    double N;
    if (key == 1)
    {
        N = (rand() % 1000) + 1;
        return N;
    }
    else if (key == 2)
    {
        N = (rand() % 100) + 1;
        return N;
    }
    else if (key == 3)
    {
        return 0;
    }
}

//Not required for lab 9. Takes a reference to a queue of doubles as a parameter
double calcAverage(queue<double> &rQueue)
{
    double average = 0.0;
    double sum = 0.0;
    double size = rQueue.size();
    string noElements = "No elements in queue. ";

    //If there are no elements in the queue, return 0.0
    if (rQueue.empty() == true)
    {
        cout << noElements << endl;
        return 0.0;
    }

    while (rQueue.empty() == false)
    {
        sum += rQueue.front();
        rQueue.pop();
    }

    average = sum / size;

    return average;
}