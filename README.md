# Array row or column traversing

Which method is faster, if we traverse lots of rows containing thousands of values ?

## Compile

Check `argp` headers are installed and accessible via your `INCLUDE_PATH`. 

* On Linux : should be nothing to install, `argp` header file should already be in your include path. 

* On macOS:

`brew install argp-standalone`

```bash
make
```

## Run

```bash
Usage: traverse [OPTION...] 
traverse -- A program to compare row-major or column major array traversal.

  -c, --columns=COLUMNS      Number of columns
  -r, --rows=ROWS            Number of rows
  -?, --help                 Give this help list
      --usage                Give a short usage message
```

Exemple of use :
```bash
./traverse -r 1000 -c 500 
Allocating a 500 x 1000 array of integers (0.24MB)
Filling array with 0 values
Row traversal tooks    0.004401 s
Column traversal tooks 0.005625 s
(Now cleaning up allocated memory...)
```
