# Tower of Hanoi - Jack Vento
## The Program

The program is a text-based version of the puzzle The Tower of Hanoi. It features both stack-based and recursive solutions.

There are three possible command line arguments:
* -n x: sets the number of disks to x (default: x = 5 if not specified)
* -s: print using the stack implementation
* -r: print using the recursive implementation

Run the program using `./tower <arguments>` after compiling. Either -s or -r are required (or both) with -n optionally supplied.

## Makefile
* `make` and `make all` will compile the program to an executable named "*tower*".
* `make clean` removes all compiler-generated files.
* `infer` is also an optional featured command, which the program passes.
