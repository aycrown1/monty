### Stacks and Queues
**Stacks** in Data Structures is a linear type of data structure that follows the *LIFO (Last In First Out) principle* and allows insertion and deletion operations from one end of the stack data structure, that is top.

**Queues** is also a linear structure that follows a *FIFO (First In First Out)* order for storing the elements and uses two ends front and rear for insertion and deletion.

<blockquote> The difference between stacks and queues is how they are removed. In a stack, we remove the item most recently added; in a queue, we remove the item least recently added.
There are many ways to implement a queue data structure, but we are going to do it using a linked list.</blockquote>

The insertion of an element into the stack is called `push` operation, and the deletion of an element from the stack is called `pop` operation. In stack, we always keep track of the last element present in the list with a pointer called `top`.


### The Monty language
**Monty 0.98** is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

<h4>Monty byte code files</h4>

Files containing Monty byte codes usually have the `.m` extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line.

1. `push()`
- Description: Pushes an element onto the stack.
- Usage: `push <int>`
- where `<int>` is an integer.
- Error: 
  - If `<int>` is not an integer or if no argument is given to `push`, it prints the error message `L<line_number>: usage: push integer`, followed by a new line, and exits with the status `EXIT_FAILURE`.

2. `pall()`
 - Description: Prints all the values on the stack, starting from the top of the stack.
- Usage: `pall`
- Note: If the stack is empty, it does not print anything.

- Example for push and pall opcodes:
    ```shell
    $ cat push.m
     push 10
     push 20
     push 30
     pall
    $ ./monty push.m
     30
     20
     10
    $
    ```
- Explanation:
  - `push 10`: Pushes the value 10 onto the stack.
  - `push 20`: Pushes the value 20 onto the stack.
  - `push 30`: Pushes the value 30 onto the stack.
  - `pall`: Prints all the values on the stack from top to bottom. The stack contains 30, 20, and 10, so they will be printed in that order.
        
3. `pint()`
- Description: Prints the value at the top of the stack.
- Usage: `pint`
- Error: If the stack is empty, it prints the error message `L<line_number>: can't pint, stack empty`, followed by a new line, and exits with the status `EXIT_FAILURE`.
- Example for pint opcode:
     ```shell
     $ cat pint.m
       push 10
       push 20
       push 30
       pint
     $ ./monty pint.m
     30
     $
     ```
- Explanation:
  - `push 10`: pushes the value 10 onto the stack.
  - `push 20`: Pushes the value 20 onto the stack.
  - `push 30`: Pushes the value 30 onto the stack.
  - `pint` prints the value at the top of the stack, which is 30.

4. `swap()`
- Description: Swaps the top two elements of the stack.
- Usage: `swap`
- Error: If the stack contains less than two elements, it prints the error message `L<line_number>: can't swap, stack too short`, followed by a new line, and exits with the status `EXIT_FAILURE`.
   Example for swap opcode:
     ```shell
     $ cat swap.m
     push 10
     push 20
     push 30
     swap
     pall
    $ ./monty swap.m
    20
    30
    10
    $
    ```
- Explanation:
  - `push 10`: pushes the value 10 onto the stack.
  - `push 20`: pushes the value 20 onto the stack.
  - `push 30`: pushes the value 30 onto the stack.
  - `swap`: swaps the top two elements of the stack.
  - Initially, the stack is `[30, 20]`. After executing the `swap` instruction, the top two elements are swapped, resulting in the stack becoming `[20, 30]`.

5. `pop()`
- Description: Removes the top element of the stack.
- Usage: `pop`
- Error: If the stack is empty, it prints the error message `L<line_number>: can't pop an empty stack`, followed by a new line, and exits with the status `EXIT_FAILURE`.
   Example:
     ```shell
     $ cat pop.m
     push 10
     push 20
     push 30
     pop
     pall
     $ ./monty pop.m
     20
     10
     $
     ```
- Explanation:
  - `push 10` pushes the value 10 onto the stack.
  - `push 20` pushes the value 20 onto the stack.
  - `pop` removes the top element of the stack.
  - Initially, the stack is `[10, 20]`. After executing the `pop` instruction, the top element, which is 20, is removed from the stack.

6. `add()`
- Description: Adds the top two elements of the stack.
- Usage: `add`
- Error: If the stack contains less than two elements, it prints the error message `L<line_number>: can't add, stack too short`, followed by a new line, and exits with the status `EXIT_FAILURE`.
   Example:
     ```shell
     $ cat add.m
     push 10
     push 20
     push 30
     add
     $ ./monty add.m
     50
     10
     $
     ```
- Explanation:
  - `push 10`: pushes the value 10 onto the stack.
  - `push 20`: pushes the value 20 onto the stack.
  - `add`: adds the top two elements of the stack. Initially, the stack is `[10, 20]`. After executing the `add` instruction, the top two elements, 10 and 20, are added together, resulting in the stack becoming `[30]`.

7. `nop()`
- Description: No operation. Does nothing.
   Note: Based on the provided instruction `nop`, the `nop` opcode doesn't perform any operation. It is a no-operation instruction used for alignment or placeholder purposes. Therefore, executing the `nop` instruction will not affect the stack or produce any output. It simply moves to the next instruction without performing any action.

8. `sub()`
- Description: Subtracts the top element of the stack from the second top element of the stack.
- Usage: `sub`
- Error: If the stack contains less than two elements, it prints the error message `L<line_number>: can't sub, stack too short`, followed by a new line, and exits with the status `EXIT_FAILURE`.
   Example:
     ```shell
     $ cat sub.m
     push 10
     push 20
     push 30
     sub
     $ ./monty sub.m
     -10
     10
     $
     ```
- Explanation:
  - `push 20`: pushes the value 20 onto the stack.
  - `push 10`: pushes the value 10 onto the stack.
  - `sub`: subtracts the top element of the stack from the second top element.
  - Initially, the stack is `[30, 20, 10]`. After executing the `sub` instruction, the top element (30) is subtracted from the second top element (20), resulting in the stack becoming `[-10]`.

9. `op_div()`
- Description: Divides the second top element of the stack by the top element of the stack.
- Usage: `div`
- Error:
  - If the stack contains less than two elements, it prints the error message `L<line_number>: can't div, stack too short`, followed by a new line, and exits with the status `EXIT_FAILURE`.
  - If the top element of the stack is 0, it prints the error message `L<line_number>: division by zero`, followed by a new line, and exits with the status `EXIT_FAILURE`.
  
     Example:
    ```shell
     $ cat div.m
     push 10
     push 20
     push 40
     div
     $ ./monty div.m
     0
     10
     $ cat div2.m
     push 10
     push 20
     push 40
     swap
     div
     $ ./monty div2.m
     2
     10
     $
     ```
- Explanation:
In the first file `div.m`:
  - `push 10`: pushes the value 10 onto the stack.
  - `push 20`: pushes the value 20 onto the stack.
  - `push 40`: pushes the value 40 onto the stack.
  - `div`: divides the second top element of the stack by the top element.
  - Initially, the stack is `[40, 20, 10]`. After executing the `div` instruction, the second top element (20) is divided by the top element (40), resulting in the stack becoming `[0.5]`, but since the data storage variable in the doubly linked list is an int type, so the output in the stack will be [0].

     In the second file `div2.m`:
 
  - `push 10`: pushes the value 10 onto the stack.
  - `push 20`: pushes the value 20 onto the stack.
  - `push 40`: pushes the value 40 onto the stack.
  - `swap`: Swaps the top two elements of the stack.
    After swapping, the stack becomes: [20, 40, 10].
  - `div`: Divides the second top element (40) by the top element (20).
    The result is 40 divided by 20, which is 2.
    The top element (20) is removed, and the second top element (40) is updated with the result.
    Stack: [2, 10]
  - `pall`: Prints all the values on the stack.
    The stack contains two elements: 2 and 10.


10. `mul()`
 - Description: Multiplies the second top element of the stack with the top element of the stack.
 - Usage: `mul`
 - Error: If the stack contains less than two elements, it prints the error message `L<line_number>: can't mul, stack too short`, followed by a new line, and exits with the status `EXIT_FAILURE`.
  
     Example:
     ```shell
     $ cat mul.m
     push 10
     push 20
     push 30
     mul
     pall
     $ ./monty mul.m
     600
     10
     $
     ```
  - `push 10`: Pushes the value 10 onto the stack.
    Stack: [10]
  - `push 20`: Pushes the value 20 onto the stack.
    Stack: [20, 10]
  - `push 30`: Pushes the value 30 onto the stack.
    Stack: [30, 20, 10]
  - `mul`: Multiplies the second top element (20) with the top element (30) and replaces them with the result.
    Result: 20 * 30 = 600
    Stack: [600, 10]
  - `pall`: Prints all the values on the stack, starting from the top.
    The stack contains two elements: 600 and 10.


11. `mod()`
 - Description: Computes the remainder of the division of the second top element of

 the stack by the top element of the stack.
 - Usage: `mod`
 - Error:
   - If the stack contains less than two elements, it prints the error message `L<line_number>: can't mod, stack too short`, followed by a new line, and exits with the status `EXIT_FAILURE`.
   - If the top element of the stack is 0, it prints the error message `L<line_number>: division by zero`, followed by a new line, and exits with the status `EXIT_FAILURE`.
     Example:
     ```shell
     $ cat mod.m
     push 10
     push 20
     push 30
     mod
     pall
     $ ./monty mod.m
     20
     10
     $
  - Explanation:
  - `push 10`: Pushes the value 10 onto the stack.
    Stack: [10]
  - `push 20`: Pushes the value 20 onto the stack.
    Stack: [20, 10]
  - `push 30`: Pushes the value 30 onto the stack.
    Stack: [30, 20, 10]
  - `mod`: Computes the remainder of the division of the second top element (20) by the top element (30) of the stack.
    The remainder of 20 divided by 30 is 20.
    The top element is replaced with the result (20).
    Stack: [20, 10]
 - `pall`: Prints all the values on the stack.
    The values 20 and 20 are printed, starting from the top of the stack.
    Output: 20 10


12. `pchar()`
 - Description: Prints the character at the top of the stack.
 - Usage: `pchar`
 - Error:
   - If the value at the top of the stack is not in the ASCII table, it prints the error message `L<line_number>: can't pchar, value out of range`, followed by a new line, and exits with the status `EXIT_FAILURE`.
   - If the stack is empty, it prints the error message `L<line_number>: can't pchar, stack empty`, followed by a new line, and exits with the status `EXIT_FAILURE`.
   
     Example:
     ```shell
     $ cat pchar.m
     push 65
     pchar
     $ ./monty pchar.m
     A
     $
     ```
  - Explanation:
  - `push 65`: Pushes the value 65 onto the stack.
    Stack: [65]
  - `pchar`: Prints the character corresponding to the ASCII value 65.
    The ASCII value 65 represents the character 'A'.
    The character 'A' is printed.
    Stack: [65]

Therefore, after executing the given instructions, the character 'A' will be printed.


13. `pstr()`
 - Description: Prints the string starting from the top of the stack.
 - Usage: `pstr`
 - Note:
   - The integer stored in each element of the stack is treated as the ASCII value of the character to be printed.
   - The string stops when either the stack is empty, the value of the element is 0, or the value of the element is not in the ASCII table.
     Example:
     ```shell
     push 111
     push 108
     push 108
     push 101
     push 72
     pstr
     ```
  Explanation:
  - `push 111`: Pushes the value 111 onto the stack.
    Stack: [111]
  - `push 108`: Pushes the value 108 onto the stack.
    Stack: [108, 111]
  - `push 108`: Pushes the value 108 onto the stack.
    Stack: [108, 108, 111]
  - `push 101`: Pushes the value 101 onto the stack.
    Stack: [101, 108, 108, 111]
  - `push 72`: Pushes the value 72 onto the stack.
    Stack: [72, 101, 108, 108, 111]
  - `pstr`: Prints the string starting from the top of the stack.
    The ASCII values 72, 101, 108, 108, 111, represent the characters 'H', 'e', 'l', 'l', 'o' respectively.

14. `rotl()`
 - Description: Rotates the stack to the top.
 - Usage: `rotl`
 - Note: The top element of the stack becomes the last one, and the second top element of the stack becomes the first one.

15. `rotr()`
 - Description: Rotates the stack to the bottom.
 - Usage: `rotr`
 - Note: The last element of the stack becomes the top element of the stack.

16. `stack()`
 - Description: Sets the format of the data to a stack (LIFO). This is the default behavior of the program.
 - Usage: `stack`

17. `queue()`
 - Description: Sets the format of the data to a queue (FIFO).
 - Usage: `queue`
 - Note:
   - When switching the mode from stack to queue, the top of the stack becomes the front of the queue, and the front of the queue becomes the top of the stack.

18. `void (*get_opcode(char *opcode))(stack_t **stack, unsigned int line_number)`
 - Description: Returns the function pointer associated with the given opcode.
 - Parameters:
   - `opcode`: String containing the opcode.
 - Returns: Function pointer corresponding to the opcode.
 - Note: The purpose of the `get_opcode` function is to map the given opcode string to the corresponding opcode function and return the function pointer. This allows dynamically selecting the correct `opcode` function based on the provided `opcode` string.

19. `void execute_instructions(FILE *file)`
 - Description: Executes the Monty instructions read from the file.
 - Parameters:
- `file`: Pointer to the file containing the Monty instructions.
- Note: This function is responsible for executing s read from a file. It takes a `FILE` pointer as an argument, which represents the file containing the Monty instructions. The function reads each line from the file, parses the opcode and its arguments, and executes the corresponding opcode function. It uses the opcode functions defined in the program to perform the desired operations on the stack or queue.

20. `int is_integer(char *str)`
 - Description: Checks if a string represents a valid integer.
 - Parameters:
   - `str`: String to be checked.
 - Returns: 1 if the string represents a valid integer, 0 otherwise.
    Note: This function is a utility function used to check if a string represents a valid integer. It takes a string as an argument and checks whether it can be converted to an integer using the `atoi` function. It returns 1 if the string is a valid integer, and 0 otherwise.
