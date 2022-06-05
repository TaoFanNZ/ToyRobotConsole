// ToyRobotConsole.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <string>
#include <iostream>
#include "ToyRobot.h"
using namespace std;

int main()
{
	TableTop table(5,5); //set the table top as 5x5
	ToyRobot robot(table);
	cout << robot.GetInstruction();

	bool quit = false;
	while (!quit)
	{
		string input;
		getline(cin, input, '\n');
		if (input == "quit") quit = true; //quit the program 
		else cout << robot.Execute(input); //print the return string of the function Execute
	}
}
