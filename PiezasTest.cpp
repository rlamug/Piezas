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
TEST(PiezasTest, resetFilled) {
  Piezas piezas;
  piezas.dropPiece(0);
  ASSERT_EQ(piezas.pieceAt(0, 0), 'X');
}
TEST(PiezasTest, resetDropped) {
  Piezas piezas;
  piezas.dropPiece(0);
  piezas.reset();
  ASSERT_EQ(piezas.pieceAt(0, 0), ' ');
}