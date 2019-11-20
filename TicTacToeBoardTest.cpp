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
  ASSERT_EQ(ticTac.toggleTurn(), X);
}

TEST(toggleTurn, oTurn)
{
  TicTacToeBoard ticTac;
  ASSERT_EQ(ticTac.toggleTurn(), O);
}

/* EXAMPLE TEST FORMAT
TEST(TicTacToeBoardTest, unitTestName)
{
	ASSERT_TRUE(true);
}
*/
