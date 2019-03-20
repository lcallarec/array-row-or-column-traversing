#include "traverse.h"

void by_row(int **data, int rows, int columns)
{
  for (int row = 0; row < rows; ++row)
  {
    for (int col = 0; col < columns; ++col)
    {
      int read = data[row][col];
    }
  }
}

void by_column(int **data, int rows, int columns)
{
  for (int col = 0; col < columns; ++col)
  {
    for (int row = 0; row < rows; ++row)
    {
      int read = data[row][col];
    }
  }
}
