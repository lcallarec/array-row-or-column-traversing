#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <argp.h>

#include "traverse.c"
#include "args.c"

int main(int argc, char *argv[])
{

  setbuf(stdout, NULL);
  struct arguments arguments;

  set_args(argc, argv, &arguments);

  argp_parse(&argp, argc, argv, 0, 0, &arguments);

  printf("Allocating a %d x %d array of integers (%2.2fMB)\n", arguments.columns, arguments.rows, ((float)arguments.columns * arguments.rows * sizeof(int)) / 8 / 1024 / 1024);
  int **data = malloc(arguments.rows * sizeof(*data));
  for (int i = 0; i < arguments.rows; ++i)
  {
    data[i] = malloc(arguments.columns * sizeof(*(data[i])));
  }

  printf("Filling array with 0 values\n");
  for (int i = 0; i < arguments.rows; ++i)
  {
    memset(data[i], 0, arguments.columns * sizeof(int));
  }
  
  clock_t time;

  printf("Running with row traversal...");
  time = clock();
  by_row(data, arguments.rows, arguments.columns);
  printf("\rRow traversal tooks    %fs\n", (double)time / CLOCKS_PER_SEC);

  printf("Running with column traversal...");
  time = clock();
  by_column(data, arguments.rows, arguments.columns);
  printf("\rColumn traversal tooks %fs\n", (double)time / CLOCKS_PER_SEC);

  printf("(Now cleaning up allocated memory...)\n");
  for (int i = 0; i < arguments.rows; ++i)
  {
    free(data[i]);
  }
  free(data);

  return 0;
}


