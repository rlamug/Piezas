/**
 * Unit Tests for Piezas
 **/

#include <gtest/gtest.h>
#include "Piezas.h"

class PiezasTest : public ::testing::Test {
 protected:
  PiezasTest() {}             // constructor runs before each test
  virtual ~PiezasTest() {}    // destructor cleans up after tests
  virtual void SetUp() {}     // sets up before each test (after constructor)
  virtual void TearDown() {}  // clean up after each test, (before destructor)
};

// Sanity check
TEST(PiezasTest, sanityCheck) { ASSERT_TRUE(true); }
/*** reset ***/
TEST(PiezasTest, reset) {
  Piezas piezas;
  for (int row = 0; row < BOARD_ROWS; row++) {
    for (int column = 0; column < BOARD_COLS; column++) {
      piezas.board[row][column] = X;
    }
  }
  piezas.reset();
  ASSERT_EQ(board[0][0], 'Blank');
}