## Pointer
A pointer is a variable whose value is an address, i.e., the actual value of a pointer type is an address of memory. While dealing with pointers, the two important operators to be considered are:
- & : the address operator
- \* : the dereferencing (indirection) operator

Consider the statement: int \*ptr = &var ;<br>
Here, the variable <strong>ptr</strong> is a pointer, which holds the address of the variable <strong>var</strong> as its value. Deferencing a pointer using \* allows access to the memory location and the corresponding value specified by this address.

## Reference
A reference variable is an alias, i.e., another name for an already existing variable. The variable can therefore be referenced using either the variable name or the reference name.<br><br>
Consider the statement: int &ref = var ; <br>
Here, the variable <strong>ref</strong> is an alias of the variable <strong>var</strong>, both of which holds the same value.<br><br>
Unlike pointers, references cannot be changed to refer to other objects after their initialization.

[Reference program - pointers_and_references.cpp]
