/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"

class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(toggleTurn, xTurn)
{
  TicTacToeBoard ticTac;
	ticTac.toggleTurn();
  ASSERT_EQ(ticTac.toggleTurn(), X);
}

TEST(toggleTurn, oTurn)
{
  TicTacToeBoard ticTac;
  ASSERT_EQ(ticTac.toggleTurn(), O);
}
TEST(getPiece, invalid)
{
	TicTacToeBoard ticTac;
	ASSERT_EQ(ticTac.getPiece(-9, 7), Invalid);
}

TEST(getPiece, empty)
{
	TicTacToeBoard ticTac;
	ASSERT_EQ(ticTac.getPiece(0, 0), Blank);
}

TEST(getPiece, valid)
{
	TicTacToeBoard ticTac;
	ticTac.placePiece(0, 0);
	ASSERT_EQ(ticTac.getPiece(0, 0), X);
}

TEST(placePiece, Invalid)
{
	TicTacToeBoard ticTac;
	ASSERT_EQ(ticTac.placePiece(-8, 9), Invalid);
}

TEST(placePiece, valid)
{
	TicTacToeBoard ticTac;
	ASSERT_EQ(ticTac.placePiece(1, 2), X);
}

TEST(placePiece, validO)
{
	TicTacToeBoard ticTac;
	ticTac.placePiece(1, 2);
	ASSERT_EQ(ticTac.placePiece(1, 1), O);
}

TEST(getWinner, xWinsColumn)
{
	TicTacToeBoard ticTac;
	ticTac.placePiece(1, 0);
	ticTac.placePiece(2, 1);
	ticTac.placePiece(2, 0);
	ticTac.placePiece(2, 2);
	ticTac.placePiece(0, 0);
	ASSERT_EQ(ticTac.getWinner(), X);
}

TEST(getWinner, xWinsRow)
{
	TicTacToeBoard ticTac;
	ticTac.placePiece(0, 0);
	ticTac.placePiece(2, 0);
	ticTac.placePiece(0, 1);
	ticTac.placePiece(2, 2);
	ticTac.placePiece(0, 2);
	ASSERT_EQ(ticTac.getWinner(), X);
}

TEST(getWinner, oWinsRow)
{
	TicTacToeBoard ticTac;
	ticTac.placePiece(1, 2);
	ticTac.placePiece(0, 0);
	ticTac.placePiece(2, 2);
	ticTac.placePiece(0, 1);
	ticTac.placePiece(1, 1);
	ticTac.placePiece(0, 2);
	ASSERT_EQ(ticTac.getWinner(), O);
}

TEST(getWinner, oWinsColumn)
{
	TicTacToeBoard ticTac;
	ticTac.placePiece(1, 0);
	ticTac.placePiece(0, 0);
	ticTac.placePiece(1, 1);
	ticTac.placePiece(0, 1);
	ticTac.placePiece(2, 1);
	ticTac.placePiece(0, 2);
	ASSERT_EQ(ticTac.getWinner(), O);
}

TEST(getWinner, xDiagonal)
{
	TicTacToeBoard ticTac;
	ticTac.placePiece(0, 0);
	ticTac.placePiece(1, 0);
	ticTac.placePiece(1, 1);
	ticTac.placePiece(0, 1);
	ticTac.placePiece(2, 2);
	ASSERT_EQ(ticTac.getWinner(), X);
}

TEST(getWinner, xDiagonal2)
{
	TicTacToeBoard ticTac;
	ticTac.placePiece(0, 2);
	ticTac.placePiece(1, 0);
	ticTac.placePiece(1, 1);
	ticTac.placePiece(0, 1);
	ticTac.placePiece(2, 0);
	ASSERT_EQ(ticTac.getWinner(), X);
}

TEST(getWinner, invalidWinner)
{
	TicTacToeBoard ticTac;
	ticTac.placePiece(0, 2);
	ticTac.placePiece(1, 0);
	ticTac.placePiece(1, 1);
	ticTac.placePiece(0, 1);
	ticTac.placePiece(2, 1);
	ASSERT_EQ(ticTac.getWinner(), Invalid);
}

TEST(getWinner, blankWinner)
{
	TicTacToeBoard ticTac;
	ticTac.placePiece(0, 0);
	ticTac.placePiece(2, 2);
	ticTac.placePiece(1, 1);
	ticTac.placePiece(2, 0);
	ticTac.placePiece(0, 2);
	ticTac.placePiece(0, 1);
	ticTac.placePiece(1, 2);
	ticTac.placePiece(1, 0);
	ticTac.placePiece(2, 1);
	ASSERT_EQ(ticTac.getWinner(), Blank);
}



/* EXAMPLE TEST FORMAT
TEST(TicTacToeBoardTest, unitTestName)
{
	ASSERT_TRUE(true);
}
*/
