/*------------------------------------------------------------------------

	Name			: ToyRobot.cpp

	Author			: Tao Fan

	Language		: C++

	Date			: 04 June 2022
	
-----------------------------------------------------------------------------*/
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <algorithm>
#include "ToyRobot.h"
using namespace std;

//Parse position and face from the input string
bool ToyRobot::ParsePlace(string t_place, int& t_posx, int& t_posy, Face& t_face)
{
	bool found = false;
	string pstr = t_place;
	//find the orientation, and remove it from the string
	for (int i = Face::NORTH; i <= Face::WEST; i++)
	{
		if (t_place.find(Face_STR[i]) != string::npos)
		{
			found = true;
			t_face = static_cast<Face>(i);
			pstr = t_place.substr(0, t_place.size() - Face_STR[i].length());
			break;
		}
	}

	if (found)
	{ //parse number string like 3,3,
		std::stringstream ss(pstr);
		ss.exceptions(ios::failbit); //set exception in case they are not numbers
		try
		{
			int j;
			ss >> j; // get the first number, if it is not number the exception will be caught.
			t_posx = j;
			if (ss.peek() == ',') //ignore the first comma
				ss.ignore();
			else return false; //No comma is not right format

			ss >> j; // get the second number
			t_posy = j;
			if (ss.peek() == ',') // ignore the second comma, if it is not number the exception will be caught.
				ss.ignore();
			else return false; // No comma is not right format

			if (ss.peek() == EOF) return true; // make sure the string format is like "3,3,east", not "3,3abcd,east"
			else return false;
		}
		catch (...)
		{ //if numbers are not right, which means the format is not like 3,3,
			return false;
		}
	}
	else return false; //no Face value in the string
}

CmdStatus  ToyRobot::Place(int t_x, int t_y, Face t_face)
{
	if (m_tabletop.InTableTop(t_x, t_y))
	{
		m_placed = true;
		m_face = t_face;
		m_posx = t_x;
		m_posy = t_y;
		return PLACE_SUCCESS;
	}
	else return PLACE_FAIL;
}
CmdStatus  ToyRobot::Move()
{
	//(0,0) is at the right bottom corner
	if (!m_placed) return MOVE_NOT_PLACED;
	switch (m_face)
	{
	case Face::EAST:
		if (m_tabletop.InTableTop(m_posx + 1, m_posy))
		{
			m_posx += 1;
			return MOVE_SUCCESS;
		}
		else return MOVE_FAIL;
	case Face::WEST:
		if (m_tabletop.InTableTop(m_posx - 1, m_posy))
		{
			m_posx -= 1;
			return MOVE_SUCCESS;
		}
		else return MOVE_FAIL;
	case Face::NORTH:
		if (m_tabletop.InTableTop(m_posx, m_posy + 1))
		{
			m_posy += 1;
			return MOVE_SUCCESS;
		}
		else return MOVE_FAIL;
	case Face::SOUTH:
		if (m_tabletop.InTableTop(m_posx, m_posy - 1))
		{
			m_posy -= 1;
			return MOVE_SUCCESS;
		}
		else return MOVE_FAIL;
	default:
		return MOVE_WRONG_FACE; //impossible value, but keep it in case
	}
}
CmdStatus  ToyRobot::Right()
{
	if (!m_placed) return RIGHT_NOT_PLACED;
	switch (m_face)
	{
	case Face::EAST:
		m_face = Face::SOUTH;
		break;
	case Face::WEST:
		m_face = Face::NORTH;
		break;
	case Face::NORTH:
		m_face = Face::EAST;
		break;
	case Face::SOUTH:
		m_face = Face::WEST;
		break;
	}
	return RIGHT_SUCESS;
}

CmdStatus  ToyRobot::Left()
{
	if (!m_placed) return LEFT_NOT_PLACED;
	switch (m_face)
	{
	case Face::EAST:
		m_face = Face::NORTH;
		break;
	case Face::WEST:
		m_face = Face::SOUTH;
		break;
	case Face::NORTH:
		m_face = Face::WEST;
		break;
	case Face::SOUTH:
		m_face = Face::EAST;
		break;
	}
	return LEFT_SUCCESS;
}

string  ToyRobot::Report()
{
	if (!m_placed) return STR_REPORT_NOT_PLACED;
	string output = STR_REPROT_OUTPUT;
	stringstream ss;
	ss << m_posx;
	output += ss.str();
	output += ",";
	ss.str("");
	ss << m_posy;
	output += ss.str();
	output += ",";
	output += Face_STR[m_face];
	output += "\n";
	return output;
}

string  ToyRobot::GetInstruction()
{
	string instruction = "==============================================\n" +
		STR_INSTRUCTION_START + "\n" + 
		STR_COMMAND_PLACE + STR_INSTRUCTION_PLACE + "\n" +
		STR_COMMAND_LEFT + "\n" +
		STR_COMMAND_RIGHT + "\n" +
		STR_COMMAND_MOVE + "\n" +
		STR_COMMAND_REPORT + "\n" +
		"==============================================\n";
	return instruction;
}

string ToyRobot::Execute(string input)
{
	vector<string> args;
	transform(input.begin(), input.end(), input.begin(), ::toupper); //convert input string to upper case
	istringstream iss(input);
	for (string in; iss >> in; ) //for "Place 3,3,East", "Place" is the first arg, "3,3,East" is the second one.
		args.push_back(in); //push arguments into the vector

	size_t len = args.size(); //the number of arguments

	if (len == 1)
	{
		if (args[0] == STR_COMMAND_MOVE) return STR_CmdStatus[Move()]; //return the string of status the function Move returns.
		else if (args[0] == STR_COMMAND_RIGHT) return STR_CmdStatus[Right()]; //return the string of status the function Right returns.
		else if (args[0] == STR_COMMAND_LEFT)  return  STR_CmdStatus[Left()]; //return the string of status the function Left returns.
		else if (args[0] == STR_COMMAND_REPORT) return  Report();//return the string of report.
		else return GetInstruction(); // show instruction if input is not in right format
	}
	else if (len == 2)
	{
		if (args[0] == STR_COMMAND_PLACE) //if it is Place command
		{
			int posx, posy;
			Face face;
			if (ParsePlace(args[1], posx, posy, face)) //parse the string and get the postion and the face
				return STR_CmdStatus[Place(posx, posy, face)]; //return the string of status that the function PLACE returns.
			else return GetInstruction(); //show instruction if PLACE command is not in right format
		}
		else return GetInstruction(); //show instruction if there are more arguments but the command is not PLACE.
	}
	else return GetInstruction(); // show instruction if there are 3 or more arguments
}