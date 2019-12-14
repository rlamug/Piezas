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
/*** dropPiece Tests ***/
// Drops piece at row 0 column 0
TEST(PiezasTest, dropPieceFirstMove) {
  Piezas piezas;
  ASSERT_EQ(piezas.dropPiece(0), 'X');
}
// Drops piece at row 0 column 0 twice 
TEST(PiezasTest, dropPieceSecondMove) {
  Piezas piezas;
  piezas.dropPiece(0);
  piezas.dropPiece(0);
  ASSERT_EQ(piezas.dropPiece(0), 'O');
}
// Drops piece at row 0 column 0 twice 
TEST(PiezasTest, dropPieceThirddMove) {
  Piezas piezas;
  piezas.dropPiece(0);
  piezas.dropPiece(0);
  piezas.dropPiece(0);
  ASSERT_EQ(piezas.dropPiece(0), 'X');
}
// Drops piece at row 0 column 0 twice 
TEST(PiezasTest, dropPieceFourthMove) {
  Piezas piezas;
  piezas.dropPiece(0);
  piezas.dropPiece(0);
  piezas.dropPiece(0);
  ASSERT_EQ(piezas.dropPiece(0), '?');
}