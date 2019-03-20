#include <argp.h>
#include "args.h"

static struct argp_option options[] =
    {
        {"rows", 'r', "ROWS", 0, "Number of rows"},
        {"columns", 'c', "COLUMNS", 0, "Number of columns"},
        {0}};

static error_t parse_opt(int key, char *arg, struct argp_state *state)
{
  struct arguments *arguments = state->input;

  switch (key)
  {
  case 'r':
    arguments->rows = atof(arg);
    break;
  case 'c':
    arguments->columns = atof(arg);
    break;
  default:
    return ARGP_ERR_UNKNOWN;
  }
  return 0;
}

static char doc[] = "traverse -- A program to compare row-major or column major array traversal.";

static struct argp argp = {options, parse_opt, "", doc};

void set_args(int argc, char *argv[], struct arguments *arguments) {

  arguments->rows = DEFAULT_COLUMNS;
  arguments->columns = DEFAULT_ROWS;

  argp_parse(&argp, argc, argv, 0, 0, &arguments);
}
