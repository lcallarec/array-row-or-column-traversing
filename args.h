#define DEFAULT_COLUMNS 1000000
#define DEFAULT_ROWS 1000

struct arguments
{
  int rows;
  int columns;
};

void set_args(int argc, char *argv[], struct arguments *arguments);
