#include "pch.h"
#include "CppUnitTest.h"
#include "..\ToyRobotConsole\ToyRobot.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ToyRobotTest
{
	TEST_CLASS(TableTopTest)
	{
	public:
		TEST_METHOD(TestInTable1)
		{
			TableTop table(5,5);
			Assert::IsFalse(table.InTableTop(5,5));			
		}
		TEST_METHOD(TestInTable2)
		{
			TableTop table(5, 5);
			Assert::IsFalse(table.InTableTop(4, 5));
		}
		TEST_METHOD(TestInTable3)
		{
			TableTop table(5, 5);
			Assert::IsFalse(table.InTableTop(3, 5));
		}
		TEST_METHOD(TestInTable4)
		{
			TableTop table(5, 5);
			Assert::IsFalse(table.InTableTop(2, 5));
		}
		TEST_METHOD(TestInTable5)
		{
			TableTop table(5, 5);
			Assert::IsFalse(table.InTableTop(1, 5));
		}
		TEST_METHOD(TestInTable6)
		{
			TableTop table(5, 5);
			Assert::IsFalse(table.InTableTop(0, 5));
		}
		TEST_METHOD(TestInTable7)
		{
			TableTop table(5, 5);
			Assert::IsFalse(table.InTableTop(5, 4));
		}
		TEST_METHOD(TestInTable8)
		{
			TableTop table(5, 5);
			Assert::IsFalse(table.InTableTop(5, 3));
		}
		TEST_METHOD(TestInTable9)
		{
			TableTop table(5, 5);
			Assert::IsFalse(table.InTableTop(5, 2));
		}
		TEST_METHOD(TestInTable10)
		{
			TableTop table(5, 5);
			Assert::IsFalse(table.InTableTop(5, 1));
		}
		TEST_METHOD(TestInTable11)
		{
			TableTop table(5, 5);
			Assert::IsFalse(table.InTableTop(5, 0));
		}

		TEST_METHOD(TestInTable12)
		{
			TableTop table(5, 5);
			Assert::IsTrue(table.InTableTop(4, 4));
		}
		TEST_METHOD(TestInTable13)
		{
			TableTop table(5, 5);
			Assert::IsTrue(table.InTableTop(4, 3));
		}
		TEST_METHOD(TestInTable14)
		{
			TableTop table(5, 5);
			Assert::IsTrue(table.InTableTop(4, 2));
		}
		TEST_METHOD(TestInTable15)
		{
			TableTop table(5, 5);
			Assert::IsTrue(table.InTableTop(4, 1));
		}

		TEST_METHOD(TestInTable16)
		{
			TableTop table(5, 5);
			Assert::IsTrue(table.InTableTop(4, 0));
		}
		TEST_METHOD(TestInTable17)
		{
			TableTop table(5, 5);
			Assert::IsTrue(table.InTableTop(3, 4));
		}
		TEST_METHOD(TestInTable18)
		{
			TableTop table(5, 5);
			Assert::IsTrue(table.InTableTop(2, 4));
		}
		TEST_METHOD(TestInTable19)
		{
			TableTop table(5, 5);
			Assert::IsTrue(table.InTableTop(1, 4));
		}

		TEST_METHOD(TestInTable20)
		{
			TableTop table(5, 5);
			Assert::IsTrue(table.InTableTop(0, 4));
		}
		TEST_METHOD(TestInTable21)
		{
			TableTop table(5, 5);
			Assert::IsTrue(table.InTableTop(0, 0));
		}
		TEST_METHOD(TestInTable23)
		{
			TableTop table(5, 5);
			Assert::IsTrue(table.InTableTop(3, 0));
		}

		TEST_METHOD(TestInTable24)
		{
			TableTop table(5, 5);
			Assert::IsTrue(table.InTableTop(2, 0));
		}
		TEST_METHOD(TestInTable25)
		{
			TableTop table(5, 5);
			Assert::IsTrue(table.InTableTop(1, 0));
		}
		TEST_METHOD(TestInTable26)
		{
			TableTop table(5, 5);
			Assert::IsTrue(table.InTableTop(0, 1));
		}
		TEST_METHOD(TestInTable27)
		{
			TableTop table(5, 5);
			Assert::IsTrue(table.InTableTop(0, 2));
		}

		TEST_METHOD(TestInTable28)
		{
			TableTop table(5, 5);
			Assert::IsTrue(table.InTableTop(0, 3));
		}
		TEST_METHOD(TestInTable29)
		{
			TableTop table(5, 5);
			Assert::IsFalse(table.InTableTop(0, -1));
		}
		TEST_METHOD(TestInTable30)
		{
			TableTop table(5, 5);
			Assert::IsFalse(table.InTableTop(1, -1));
		}
		TEST_METHOD(TestInTable31)
		{
			TableTop table(5, 5);
			Assert::IsFalse(table.InTableTop(2, -1));
		}
		TEST_METHOD(TestInTable32)
		{
			TableTop table(5, 5);
			Assert::IsFalse(table.InTableTop(3, -1));
		}
		TEST_METHOD(TestInTable33)
		{
			TableTop table(5, 5);
			Assert::IsFalse(table.InTableTop(4, -1));
		}
		TEST_METHOD(TestInTable34)
		{
			TableTop table(5, 5);
			Assert::IsFalse(table.InTableTop(5, -1));
		}
		TEST_METHOD(TestInTable35)
		{
			TableTop table(5, 5);
			Assert::IsFalse(table.InTableTop(-1, 0));
		}
		TEST_METHOD(TestInTable36)
		{
			TableTop table(5, 5);
			Assert::IsFalse(table.InTableTop(-1, 1));
		}
		TEST_METHOD(TestInTable37)
		{
			TableTop table(5, 5);
			Assert::IsFalse(table.InTableTop(-1, 2));
		}
		TEST_METHOD(TestInTable38)
		{
			TableTop table(5, 5);
			Assert::IsFalse(table.InTableTop(-1, 3));
		}
		TEST_METHOD(TestInTable39)
		{
			TableTop table(5, 5);
			Assert::IsFalse(table.InTableTop(-1, 4));
		}
		TEST_METHOD(TestInTable40)
		{
			TableTop table(5, 5);
			Assert::IsFalse(table.InTableTop(-1, 5));
		}
		TEST_METHOD(TestInTable41)
		{
			TableTop table(5, 5);
			Assert::IsFalse(table.InTableTop(-1, -1));
		}
	
		TEST_METHOD(TestInTable42)
		{
			TableTop table(5, 5);
			Assert::IsFalse(table.InTableTop(-80, -6));
		}

	};

	TEST_CLASS(ToyRobotTest)
	{
	public:
		TEST_METHOD(TestPlace1)
		{
			TableTop table(5, 5);
			ToyRobot robot(table);
			robot.Place(5, 5, Face::EAST);
			Assert::IsFalse(robot.Placed());
		}
		
		TEST_METHOD(TestPlace2)
		{
			TableTop table(5, 5);
			ToyRobot robot(table);
			robot.Place(5, 0, EAST);
			Assert::IsFalse(robot.Placed());
		}
		TEST_METHOD(TestPlace3)
		{
			TableTop table(5, 5);
			ToyRobot robot(table);
			robot.Place(0, 5, EAST);
			Assert::IsFalse(robot.Placed());
		}

		TEST_METHOD(TestPlace4)
		{
			TableTop table(5, 5);
			ToyRobot robot(table);
			robot.Place(-1, 0, EAST);
			Assert::IsFalse(robot.Placed());
		}
		TEST_METHOD(TestPlace5)
		{
			TableTop table(5, 5);
			ToyRobot robot(table);
			robot.Place(0, -1, EAST);
			Assert::IsFalse(robot.Placed());
		}

		TEST_METHOD(TestPlace6)
		{
			TableTop table(5, 5);
			ToyRobot robot(table);
			robot.Place(-1, -1, EAST);
			Assert::IsFalse(robot.Placed());
		}

		TEST_METHOD(TestPlace7)
		{
			TableTop table(5, 5);
			ToyRobot robot(table);
			robot.Place(0, 0, EAST);
			Assert::IsTrue(robot.Placed());
		}

		TEST_METHOD(TestPlace8)
		{
			TableTop table(5, 5);
			ToyRobot robot(table);
			robot.Place(4, 4, EAST);
			Assert::IsTrue(robot.Placed());
		}

		TEST_METHOD(TestPlace9)
		{
			TableTop table(5, 5);
			ToyRobot robot(table);
			robot.Place(4, 0, EAST);
			Assert::IsTrue(robot.Placed());
		}

		TEST_METHOD(TestPlace10)
		{
			TableTop table(5, 5);
			ToyRobot robot(table);
			robot.Place(0, 4, EAST);
			Assert::IsTrue(robot.Placed());
		}

		//test right, left and move
		TEST_METHOD(TestMove1)
		{
			TableTop table(5, 5);
			ToyRobot robot(table);
			robot.Place(0, 0, EAST);
			robot.Right();
			Assert::IsTrue(robot.Move() == CmdStatus::MOVE_FAIL);
		}
	
		TEST_METHOD(TestMove2)
		{
			TableTop table(5, 5);
			ToyRobot robot(table);
			robot.Place(0, 0, EAST);
			robot.Left();
			Assert::IsTrue(robot.Move() == CmdStatus::MOVE_SUCCESS);
		}
		TEST_METHOD(TestMove3)
		{
			TableTop table(5, 5);
			ToyRobot robot(table);
			robot.Place(0, 0, NORTH);
			robot.Left();
			Assert::IsTrue(robot.Move() == CmdStatus::MOVE_FAIL);
		}
		TEST_METHOD(TestMove4)
		{
			TableTop table(5, 5);
			ToyRobot robot(table);
			robot.Place(0, 0, NORTH);
			robot.Right();
			Assert::IsTrue(robot.Move() == CmdStatus::MOVE_SUCCESS);
		}
		TEST_METHOD(TestMove5)
		{
			TableTop table(5, 5);
			ToyRobot robot(table);
			robot.Place(4, 4, SOUTH);
			robot.Right();
			Assert::IsTrue(robot.Move() == CmdStatus::MOVE_SUCCESS);
		}
		TEST_METHOD(TestMove6)
		{
			TableTop table(5, 5);
			ToyRobot robot(table);
			robot.Place(4, 4, SOUTH);
			robot.Left();
			Assert::IsTrue(robot.Move() == CmdStatus::MOVE_FAIL);
		}

		//test rigth bottom corner
		TEST_METHOD(TestMove7)
		{
			TableTop table(5, 5);
			ToyRobot robot(table);
			robot.Place(4, 0, EAST);
			Assert::IsTrue(robot.Move() == CmdStatus::MOVE_FAIL);
		}
		TEST_METHOD(TestMove8)
		{
			TableTop table(5, 5);
			ToyRobot robot(table);
			robot.Place(4, 0, SOUTH);
			Assert::IsTrue(robot.Move() == CmdStatus::MOVE_FAIL);
		}
		TEST_METHOD(TestMove9)
		{
			TableTop table(5, 5);
			ToyRobot robot(table);
			robot.Place(4, 0, WEST);
			Assert::IsTrue(robot.Move() == CmdStatus::MOVE_SUCCESS);
		}
		TEST_METHOD(TestMove10)
		{
			TableTop table(5, 5);
			ToyRobot robot(table);
			robot.Place(4, 0, NORTH);
			//Assert::IsTrue(robot.Move() == CmdStatus::MOVE_SUCCESS);
		}

		//test left top corner
		TEST_METHOD(TestMove11)
		{
			TableTop table(5, 5);
			ToyRobot robot(table);
			robot.Place(0, 4, EAST);
			Assert::IsTrue(robot.Move() == CmdStatus::MOVE_SUCCESS);
		}
		TEST_METHOD(TestMove12)
		{
			TableTop table(5, 5);
			ToyRobot robot(table);
			robot.Place(0, 4, SOUTH);
			Assert::IsTrue(robot.Move() == CmdStatus::MOVE_SUCCESS);
		}
		TEST_METHOD(TestMove13)
		{
			TableTop table(5, 5);
			ToyRobot robot(table);
			robot.Place(0, 4, WEST);
			Assert::IsTrue(robot.Move() == CmdStatus::MOVE_FAIL);
		}
		TEST_METHOD(TestMove14)
		{
			TableTop table(5, 5);
			ToyRobot robot(table);
			robot.Place(0, 4, NORTH);
			Assert::IsTrue(robot.Move() == CmdStatus::MOVE_FAIL);
		}

		//test top right corner
		TEST_METHOD(TestMove15)
		{
			TableTop table(5, 5);
			ToyRobot robot(table);
			robot.Place(4, 4, EAST);
			Assert::IsTrue(robot.Move() == CmdStatus::MOVE_FAIL);
		}
		TEST_METHOD(TestMove16)
		{
			TableTop table(5, 5);
			ToyRobot robot(table);
			robot.Place(4, 4, SOUTH);
			Assert::IsTrue(robot.Move() == CmdStatus::MOVE_SUCCESS);
		}
		TEST_METHOD(TestMove17)
		{
			TableTop table(5, 5);
			ToyRobot robot(table);
			robot.Place(4, 4, WEST);
			Assert::IsTrue(robot.Move() == CmdStatus::MOVE_SUCCESS);
		}
		TEST_METHOD(TestMove18)
		{
			TableTop table(5, 5);
			ToyRobot robot(table);
			robot.Place(4, 4, NORTH);
			Assert::IsTrue(robot.Move() == CmdStatus::MOVE_FAIL);
		}

		//test bottom left corner
		TEST_METHOD(TestMove19)
		{
			TableTop table(5, 5);
			ToyRobot robot(table);
			robot.Place(0, 0, EAST);
			Assert::IsTrue(robot.Move() == CmdStatus::MOVE_SUCCESS);
		}
		TEST_METHOD(TestMove20)
		{
			TableTop table(5, 5);
			ToyRobot robot(table);
			robot.Place(0, 0, SOUTH);
			Assert::IsTrue(robot.Move() == CmdStatus::MOVE_FAIL);
		}
		TEST_METHOD(TestMove21)
		{
			TableTop table(5, 5);
			ToyRobot robot(table);
			robot.Place(0, 0, WEST);
			Assert::IsTrue(robot.Move() == CmdStatus::MOVE_FAIL);
		}
		TEST_METHOD(TestMove22)
		{
			TableTop table(5, 5);
			ToyRobot robot(table);
			robot.Place(0, 0, NORTH);
			Assert::IsTrue(robot.Move() == CmdStatus::MOVE_SUCCESS);
		}

		//test not placed
		TEST_METHOD(TestNotPlaced1)
		{
			TableTop table(5, 5);
			ToyRobot robot(table);
			Assert::IsTrue(robot.Move() == CmdStatus::MOVE_NOT_PLACED);
		}
		TEST_METHOD(TestNotPlaced2)
		{
			TableTop table(5, 5);
			ToyRobot robot(table);
			Assert::IsTrue(robot.Left() == CmdStatus::LEFT_NOT_PLACED);
		}
		TEST_METHOD(TestNotPlaced3)
		{
			TableTop table(5, 5);
			ToyRobot robot(table);
			Assert::IsTrue(robot.Right() == CmdStatus::RIGHT_NOT_PLACED);
		}
		TEST_METHOD(TestNotPlaced4)
		{
			TableTop table(5, 5);
			ToyRobot robot(table);
			Assert::IsTrue(robot.Report() == STR_REPORT_NOT_PLACED);
		}

		TEST_METHOD(TestParsePlace1)
		{
			TableTop table(5, 5);
			ToyRobot robot(table);
			Assert::IsTrue(robot.Execute("Place 0,0,North") == STR_CmdStatus[PLACE_SUCCESS]);
		}
		TEST_METHOD(TestParsePlace2)
		{
			TableTop table(5, 5);
			ToyRobot robot(table);
			Assert::IsTrue(robot.Execute("Place x,0,North") == robot.GetInstruction());
		}
		TEST_METHOD(TestParsePlace3)
		{
			TableTop table(5, 5);
			ToyRobot robot(table);
			Assert::IsTrue(robot.Execute("Place 0,0,Nor") == robot.GetInstruction());
		}
		TEST_METHOD(TestParsePlace4)
		{
			TableTop table(5, 5);
			ToyRobot robot(table);
			Assert::IsTrue(robot.Execute("Place 5,5,North") == STR_CmdStatus[PLACE_FAIL]);
		}
		TEST_METHOD(TestParsePlace5)
		{
			TableTop table(5, 5);
			ToyRobot robot(table);
			Assert::IsTrue(robot.Execute("Place 0,x,east") == robot.GetInstruction());
		}
		TEST_METHOD(TestParsePlace6)
		{
			TableTop table(5, 5);
			ToyRobot robot(table);
			Assert::IsTrue(robot.Execute("Place 3,4,west") == STR_CmdStatus[PLACE_SUCCESS]);
		}
		TEST_METHOD(TestParsePlace7)
		{
			TableTop table(5, 5);
			ToyRobot robot(table);
			Assert::IsTrue(robot.Execute("Place 2,1,sOUth") == STR_CmdStatus[PLACE_SUCCESS]);
		}
		TEST_METHOD(TestParsePlace8)
		{
			TableTop table(5, 5);
			ToyRobot robot(table);
			Assert::IsTrue(robot.Execute("Place -1,0,North") == STR_CmdStatus[PLACE_FAIL]);
		}
		TEST_METHOD(TestParsePlace9)
		{
			TableTop table(5, 5);
			ToyRobot robot(table);
			Assert::IsTrue(robot.Execute("Place 3,4xy,North") == robot.GetInstruction());
		}
	
		TEST_METHOD(TestParsePlace10)
		{
			TableTop table(5, 5);
			ToyRobot robot(table);
			Assert::IsTrue(robot.Execute("Place 3 4,North") == robot.GetInstruction());
		}
		TEST_METHOD(TestParsePlace11)
		{
			TableTop table(5, 5);
			ToyRobot robot(table);
			Assert::IsTrue(robot.Execute("Place 3 4 North") == robot.GetInstruction());
		}
		TEST_METHOD(TestParsePlace12)
		{
			TableTop table(5, 5);
			ToyRobot robot(table);
			Assert::IsTrue(robot.Execute("Place 3g,4,North") == robot.GetInstruction());
		}
		TEST_METHOD(TestParsePlace13)
		{
			TableTop table(5, 5);
			ToyRobot robot(table);
			Assert::IsTrue(robot.Execute("Place 3,4,,North") == robot.GetInstruction());
		}
		TEST_METHOD(TestParsePlace14)
		{
			TableTop table(5, 5);
			ToyRobot robot(table);
			Assert::IsTrue(robot.Execute("PLAce 2,3, North") == robot.GetInstruction()); //because of the blank space
		}
		TEST_METHOD(TestParsePlace15)
		{
			TableTop table(5, 5);
			ToyRobot robot(table);
			Assert::IsTrue(robot.Execute("Place 3 ,4,North") == robot.GetInstruction());
		}
		TEST_METHOD(TestParsePlace16)
		{
			TableTop table(5, 5);
			ToyRobot robot(table);
			Assert::IsTrue(robot.Execute("Place 3,4 ,North") == robot.GetInstruction());
		}
		TEST_METHOD(TestParsePlace17)
		{
			TableTop table(5, 5);
			ToyRobot robot(table);
			Assert::IsTrue(robot.Execute("Place 4") == robot.GetInstruction());
		}
		TEST_METHOD(TestParsePlace18)
		{
			TableTop table(5, 5);
			ToyRobot robot(table);
			Assert::IsTrue(robot.Execute("Place 3,4xy,North") == robot.GetInstruction());
		}
	};

}
