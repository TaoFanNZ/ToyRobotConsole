/*------------------------------------------------------------------------

	Name			: ToyRobot.h

	Author			: Tao Fan

	Language		: C++

	Date			: 04 June 2022

-----------------------------------------------------------------------------*/
#pragma once
#include <string>
using namespace std;

enum Face {
	NORTH,
	SOUTH,
	EAST,
	WEST
};

// corresponding strings for Face, must be consistent with Face as a convention
static const string Face_STR[] = { "NORTH", "SOUTH", "EAST", "WEST" };

// command status is used as return type to decouple output string from functionalities
enum CmdStatus {
	MOVE_SUCCESS,
	MOVE_NOT_PLACED,
	MOVE_FAIL,
	MOVE_WRONG_FACE,
	LEFT_SUCCESS,
	LEFT_NOT_PLACED,
	RIGHT_SUCESS,
	RIGHT_NOT_PLACED,
	PLACE_FAIL,
	PLACE_SUCCESS
};

// All strings are grouped here for multi language support if necessary
// corresponding strings for CmdStatus, must be consistent with CmdStatus as a convention
static const string STR_CmdStatus[] =
{
	"\tMoving succeeded.\n",
	"\tThe toy robot is not placed and cannot move.\n",
	"\tMoving failed because it will fall.\n",
	"\tWrong face used.\n",
	"\tTurning left succeeded.\n",
	"\tThe toy robot is not placed so cannot turn left.\n",
	"\tTurning right succeeded.\n",
	"\tThe toy robot is not placed so cannot turn right.\n",
	"\tPlacing failed because the position is out of table top.\n",
	"\tPlacing succeeded.\n"
};
static const string STR_REPROT_OUTPUT = "\tOutput: ";
static const string STR_REPORT_NOT_PLACED = "\tThe toy robot is not placed so no report printed.\n";

static const string STR_COMMAND_MOVE = "MOVE";
static const string STR_COMMAND_LEFT = "LEFT";
static const string STR_COMMAND_RIGHT = "RIGHT";
static const string STR_COMMAND_REPORT = "REPORT";
static const string STR_COMMAND_PLACE = "PLACE";
static const string STR_INSTRUCTION_PLACE = " 0,0,NORTH (* only one blank space after PLACE)";
static const string STR_INSTRUCTION_START = "Please use the command with the right format:";

class TableTop
{
private:
	int m_length;
	int m_width;

public:
	TableTop(int t_length, int t_width) : m_length(t_length), m_width(t_width) {}
	bool InTableTop(int t_x, int t_y)
	{
		if (t_x >= 0 && t_x < m_width && t_y >= 0 && t_y < m_length) return true;
		else return false;
	}

};

class ToyRobot
{
private:
	TableTop& m_tabletop; //use reference to avoid memory exchange
	int m_posx = 0;
	int m_posy = 0;
	bool m_placed = false;
	Face m_face = Face::EAST;
	
	bool ParsePlace(string t_place, int& t_posx, int& t_posy, Face& t_face); //Parse position and face from the input string 
	
public:
	ToyRobot(TableTop& t_tabletop) : m_tabletop(t_tabletop) {}
	bool Placed() { return m_placed; }  // for ut
	
	//return CmdStatus so that it can be transferred to string easily
	//Why not just return a string? to restrict someone in future to return a undefined string
	CmdStatus Place(int t_x, int t_y, Face t_face);
	CmdStatus Move();
	CmdStatus Right();
	CmdStatus Left();
	string Report();
	
	//return string so that the instruction can decouple from UI
	string GetInstruction();

	//use string as input and output so that it can decouple from UI
	string Execute(string input);
};




