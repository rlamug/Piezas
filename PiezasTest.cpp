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
  ASSERT_EQ(piezas.dropPiece(0), 'O');
}
// Drops piece at row 0 column 0 three 
TEST(PiezasTest, dropPieceThirddMove) {
  Piezas piezas;
  piezas.dropPiece(0);
  piezas.dropPiece(0);
  ASSERT_EQ(piezas.dropPiece(0), 'X');
}
// Drops piece at full column 
TEST(PiezasTest, dropPieceFourthMove) {
  Piezas piezas;
  piezas.dropPiece(0);
  piezas.dropPiece(0);
  piezas.dropPiece(0);
  ASSERT_EQ(piezas.dropPiece(0), ' ');
}
// Drops piece out of bounds greater than amount of columns
TEST(PiezasTest, dropPieceOutOfBoundsGreater) {
  Piezas piezas;
  ASSERT_EQ(piezas.dropPiece(4), '?');
}
// Drops piece out of bounds in negative
TEST(PiezasTest, dropPieceOutOfBoundsLess) {
  Piezas piezas;
  ASSERT_EQ(piezas.dropPiece(-1), '?');
}
/*** pieceAt Tests ***/
// Gets empty board piece
TEST(PiezasTest, pieceAtEmpty) {
  Piezas piezas;
  ASSERT_EQ(piezas.pieceAt(0,0), ' ');
}
// Gets first moves piece
TEST(PiezasTest, pieceAtFirstMove) {
  Piezas piezas;
  piezas.dropPiece(0)
  ASSERT_EQ(piezas.pieceAt(0,0), 'X');
}
// Gets second moves piece
TEST(PiezasTest, ) {
  Piezas piezas;
  piezas.dropPiece(0);
  piezas.dropPiece(0);
  ASSERT_EQ(piezas.pieceAt(1, 0), 'O');
}
// Gets out of bounds piece negative
TEST(PiezasTest, ) {
  Piezas piezas;
  ASSERT_EQ(piezas.pieceAt(-1, -1), '?');
}
// Gets out of bounds piece positive
TEST(PiezasTest, ) {
  Piezas piezas;
  ASSERT_EQ(piezas.pieceAt(3, 4), '?');
}