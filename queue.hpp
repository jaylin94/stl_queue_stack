#ifndef QUEUE_HPP
#define QUEUE_HPP
#include <iostream>
#include <queue>

//Generates random number, and runs main simulation for the buffer
double generateRandom(int key);
void runQueueSim(int rounds, int addChance, int removeChance, std::queue<double> &rQueue);

//Created but not required for Lab9
double calcAverage(std::queue<double> &rQueue);

#endif
