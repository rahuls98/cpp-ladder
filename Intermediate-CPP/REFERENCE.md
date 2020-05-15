### Pointer
<a href="./pointers_and_references.cpp">Reference 1</a> | <a href="./pointer_example.cpp">Reference 2</a>
- A pointer is a variable whose value is an address, i.e., the actual value of a pointer type is an address of memory. While dealing with pointers, the two important operators to be considered are:
  - <strong>&</strong> : the address operator
  - <strong>\*</strong> : the dereferencing (indirection) operator
- Consider the statement: int \*ptr = &var ;<br>
Here, the variable <strong>ptr</strong> is a pointer, which holds the address of the variable <strong>var</strong> as its value. Deferencing a pointer using \* allows access to the memory location and the corresponding value specified by this address.

<hr>

### Reference
<a href="./pointers_and_references.cpp">Reference 1</a> | <a href="./pass_by_reference.cpp">Reference 2</a>
- A reference variable is an alias, i.e., another name for an already existing variable. The variable can therefore be referenced using either the variable name or the reference name.
- Consider the statement: int &ref = var ; <br>
Here, the variable <strong>ref</strong> is an alias of the variable <strong>var</strong>, both of which holds the same value.
- Unlike pointers, references cannot be changed to refer to other objects after their initialization.

<hr>

### Dynamic memory allocation (DMA)
<a href="./dynamic_memory.cpp">Reference</a>
- Programs may require space according to runtime behaviour. Dynamic allocation of memory can help account for the following cases:
    - size of space required depends on input to program
    - to avoid allocation of very large memory area that may not be required
- The <strong>heap</strong> is used for allocating storage at run-time.
- Two important operators in the context of DMA are:
    - <strong>new</strong> : used to create required memory block, returning the address of the same.
    - <strong>delete</strong> : free the memory location in the heap, removing
    exclusivity from current code.
- Consider the statement: int \*ptr = new int ; <br>
Here the pointer <strong>ptr</strong> holds the address of the newly created block of memory, which is allocated at runtime from the heap. The pointer can now be dereferenced to set the value at the memory location.
- This allocated heap space must also be released at the end of the program using the <strong>delete</strong> operator. This removes the pointer's reference to the memory location and thereby, the exclusive rights of the program to the same. However, the value at the memory location may still be intact, and the memory location can still be referenced using the address (depending on the Operating System).

<hr>

### Assert
<a href="./assert.cpp">Reference</a>
- Assertions are used to check assumptions in the code by making use of logical operations. For example, it can be used to check if the value of a variable is as expected after the execution of a particular code snippet which modifies the variable.
- An assert is a preprocessor macro that is used to evaluate a conditional expression. If the **assert()** argument results in a 0 (false), then the output is implementation-specific diagnostic information on the standard error output and std::abort is called.
- If the argument evaluates to 0 (false), then the expression, sourcecode filename, and line number are sent to the standard error, and then abort() function is called.
- The C++ header <cassert> contains the assert functionality. The assert functionality is mostly used to check if the parameters passed to a function are valid, to check the return value of a function or to check the array bounds among other things.
- Assertions are checked at runtime. They make debugging efficient, but care should be taken on not to include assertions in the release build of the application. Using **NDEBUG** macro in a program disables all calls to assert. [#define NDEBUG]