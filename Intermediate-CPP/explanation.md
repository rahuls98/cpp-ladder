## Pointer
- A pointer is a variable whose value is an address, i.e., the actual value of a pointer type is an address of memory. While dealing with pointers, the two important operators to be considered are:
  - <strong>&</strong> : the address operator
  - <strong>\*</strong> : the dereferencing (indirection) operator
- Consider the statement: int \*ptr = &var ;<br>
Here, the variable <strong>ptr</strong> is a pointer, which holds the address of the variable <strong>var</strong> as its value. Deferencing a pointer using \* allows access to the memory location and the corresponding value specified by this address.

[Reference program - pointers_and_references.cpp]

## Reference
- A reference variable is an alias, i.e., another name for an already existing variable. The variable can therefore be referenced using either the variable name or the reference name.
- Consider the statement: int &ref = var ; <br>
Here, the variable <strong>ref</strong> is an alias of the variable <strong>var</strong>, both of which holds the same value.
- Unlike pointers, references cannot be changed to refer to other objects after their initialization.

[Reference program - pointers_and_references.cpp]
[Reference program - pass_by_reference.cpp]

## Dynamic memory allocation (DMA)
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

[Reference program - dynamic_memory.cpp]
