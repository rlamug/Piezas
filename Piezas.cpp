#include "Piezas.h"
#include <vector>
/** CLASS Piezas
 * Class for representing a Piezas vertical board, which is roughly based
 * on the game "Connect Four" where pieces are placed in a column and
 * fall to the bottom of the column, or on top of other pieces already in
 * that column. For an illustration of the board, see:
 *  https://en.wikipedia.org/wiki/Connect_Four
 *
 * Board coordinates [row,col] should match with:
 * [2,0][2,1][2,2][2,3]
 * [1,0][1,1][1,2][1,3]
 * [0,0][0,1][0,2][0,3]
 * So that a piece dropped in column 2 should take [0,2] and the next one
 * dropped in column 2 should take [1,2].
 **/

/**
 * Constructor sets an empty board (default 3 rows, 4 columns) and
 * specifies it is X's turn first
 **/
Piezas::Piezas() {
  turn = X;
  for (int row = 0; row < BOARD_ROWS; row++) {
    for (int column = 0; column < BOARD_COLS; column++) {
      board[row][column] = Blank;
    }
  }
}

/**
 * Resets each board location to the Blank Piece value, with a board of the
 * same size as previously specified
 **/
void Piezas::reset() {
  for (int row = 0; row < BOARD_ROWS; row++) {
    for (int column = 0; column < BOARD_COLS; column++) {
      board[row][column] = Blank;
    }
  }
}

/**
 * Places a piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. dropPiece does
 * NOT allow to place a piece in a location where a column is full.
 * In that case, placePiece returns Piece Blank value
 * Out of bounds coordinates return the Piece Invalid value
 * Trying to drop a piece where it cannot be placed loses the player's turn
 **/
Piece Piezas::dropPiece(int column) {
  // Toggle turn
  if (turn == X) {
    turn = O;
  } else {
    turn = X;
  }
  // Placing piece in out of bounds coordinates
  if (column >= BOARD_COLS || column < 0) {
    return Invalid;
  }
  // Checks each row within the column to see if it's blank
  for (int row = 0; row < BOARD_ROWS; row++) {
    // Found open spot to place piece
    if (board[row][column] == Blank) {
      board[row][column] = turn;
      return turn;
    }
  }
  // Column is full
  return Blank;
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
 **/
Piece Piezas::pieceAt(int row, int column) {
  // Out of bounds coordinates
  if (row >= BOARD_ROWS || row < 0 || column >= BOARD_COLS || column < 0) {
    return Invalid;
  } else {
    return board[row][column];
  }
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won ("tie").
 * For a game to be over, all locations on the board must be filled with X's
 * and O's (i.e. no remaining Blank spaces). The winner is which player has
 * the most adjacent pieces in a single line. Lines can go either vertically
 * or horizontally. If both X's and O's have the same max number of pieces in a
 * line, it is a tie.
 **/
Piece Piezas::gameState() {
  int currentPiece;
  int nextPiece;
  int xScore = 0;
  int oScore = 0;
  // Check if board is filled
  for (int row = 0; row < BOARD_ROWS; row++) {
    for (int column = 0; column < BOARD_COLS; column++) {
      // Game isn't over
      if (board[row][column] == Blank) {
        return Invalid;
      }
    }
  }
  // Check adjacent pieces in each row
  for (int row = 0; row < BOARD_ROWS; row++) {
    for (int column = 0; column < (BOARD_COLS - 1); column++) {
      currentPiece = pieceAt(row, column);
      nextPiece = pieceAt(row, column + 1);
      // Update score
      if (currentPiece == pieceAt(row, column)) {
        if (currentPiece == X) {
          xScore += 1;
        } else {
          oScore += 1;
        }
      }
    }
  }
  // Check adjacent pieces in each column
  for (int column = 0; column < BOARD_COLS; column++) {
    for (int row = 0; row < (BOARD_ROWS - 1); row++) {
      int currentPiece = pieceAt(row, column);
      int nextPiece = pieceAt(row + 1, column);
      // Update score
      if (currentPiece == pieceAt(row, column)) {
        if (currentPiece == X) {
          xScore += 1;
        } else {
          oScore += 1;
        }
      }
    }
  }
  // X won
  if (xScore > oScore) {
    return X;
  }
  // O won
  else if (xScore < oScore) {
    return O;
  }
  // Tie
  else {
    return Blank;
  }
}