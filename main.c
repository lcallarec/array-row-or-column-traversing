#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_SIZE 1000000
#define ROWS 1000

void by_row(int **data);
void by_column(int **data);

int main(int argc, char *argv[])
{

  setbuf(stdout, NULL);
  if (argc == 1 || strcmp(argv[1], "--row") == -1 || strcmp(argv[1], "--col") == -1)
  {
    printf("Please run with either --row or --col\n");
    return 1;
  }

  printf("Allocating a %d x %d array of integers...\n", ARRAY_SIZE, ROWS);
  int **data = malloc(ROWS * sizeof(*data));
  for (int i = 0; i < ROWS; ++i)
  {
    data[i] = malloc(ARRAY_SIZE * sizeof(*(data[i])));
  }

  printf("Filling array with 0 values\n");
  for (int i = 0; i < ROWS; ++i)
  {
    memset(data[i], 0, ARRAY_SIZE * sizeof(int));
  }

  clock_t time;
  time = clock();

  if (strcmp(argv[1], "--row") == 0)
  {
    printf("Running with row traversal\n");
    by_row(data);
  }
  else
  {
    printf("Running with column traversal\n");
    by_column(data);
  }

  double elapsed = ((double)time) / CLOCKS_PER_SEC;

  printf("Time elapsed : %f seconds\n", elapsed);

  printf("(Cleaning up allocated memory...)\n");
  for (int i = 0; i < ROWS; ++i)
  {
    free(data[i]);
  }
  free(data);

  return 0;
}

void by_row(int **data)
{
  for (int i = 0; i < ROWS; ++i)
  {
    for (int j = 0; j < ARRAY_SIZE; ++j)
    {
      int read = data[i][j];
    }
  }
}

void by_column(int **data)
{
  for (int i = 0; i < ARRAY_SIZE; ++i)
  {
    for (int j = 0; j < ROWS; ++j)
    {
      int read = data[j][i];
    }
  }
}
