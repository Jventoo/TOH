# **Assignment 3 Design - Jack Vento**
## Stack.c
### Create
* Allocate stack on the heap and check that creation was successful. If not, return null. Continue otherwise.
* Assign capacity to the supplied size. 
* Assign top to 0. 
* Allocate an array (items) of supplied size on the heap and check that it succeeded. 
* Return null if unsuccessful, otherwise return a ptr to the stack.
### Delete
* Free and null the items array.
* Free and null the stack.
### Pop
* If the stack and the top are valid, decrement the top.
* Return reference to the new top if valid, else -1.
### Push
* If top = capacity, reallocate the items array to a larger capacity.
* Set top to be supplied value and post increment top.
### Empty
* Return true if top = 0, else return false.
### Peek
* If not empty, return items[top - 1]. If empty, return null.
## Tower.c
### Stack
Parameters: n (number of disks), begin char (start peg), final char (target peg), helper char (other peg)
* Print stack header
* Create stacks for begin, final, and helper using specified parameter chars.
* if n is even:
    * Swap final and helper to ensure proper movement direction (clockwise = even, counterclockwise = odd).
* Calculate number of moves (moves = 2<sup>n</sup> - 1)
* Push disks largest to smallest onto the begin stack (for moves -> 1).
* Following movement algorithm developed with help from [this animation at TOH.info](http://towersofhanoi.info/Animate.aspx).
* for i <= moves
    * if i % 3 == 0 (facilitate movement of the rest of begin's disks by moving from helper): Move disk from helper to final.
    * if i % 3 == 1 (simply move to the goal peg): Move disk from begin to final.
    * if i % 3 == 2 (move to the helper peg to get at the larger disks under the current disk): Move disk from begin to helper.
    * Increment the count for all 3 cases.
* Print the number of moves from count.
#### Moving The Disks (src to dest through helper function):
    * Pop a disk from both our src (disk1) and dest (disk2) pegs.
    * When src is empty (result of src pop was 0), push disk2 onto src.
    * When dest is empty (result of dest pop was 0), push disk1 onto dest.
    * If neither are empty, move the smaller disk to the peg with the larger disk (This will be two pushes; one to replace the pop and the other to push the smaller disk.)
    * Print the movement for each case through single line helper.
### Recursion
Parameters: n (number of disks), count (pointer to integer from main to track moves), begin char (start peg), final char (target peg), helper char (other peg)
* Base case: n = 1 -> Print, increment moves, print num moves, and return
* Else
    * Recursion(n - 1, begin, helper, final)
    * Print moving disk message. Increment moves
    * Recursion(n - 1, helper, final, begin)
### Main
* Declare bools (run_stack, run_recurs) and size (n) to track each command line argument.
* Check if there are less than 1 command-line arguments supplied or no run preference, print an error and return if so.
* while there are options to parse
    * Set bool statuses for each argument.
    * Set size if n supplied
* if run_stack
    * Stack()
* if run_recurs
    * Print recursion header (can't do it in the function like the stack implementation)
    * Declare count to track moves
    * Recursion()
    * Print number of moves from count