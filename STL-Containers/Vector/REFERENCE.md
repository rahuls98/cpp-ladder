### Member functions
- __assign__: assigns values to the container [<a href="./memberFunctions.cpp">Reference</a>]

<hr>

### Element access
<a href="./elementAccess.cpp">Reference</a>
- __at__ : accesses the specified character with bounds checking and returns a reference to the same.
- __front__: reference to the first character, equivalent to operator[](0).
- __back__: reference to the last character, equivalent to operator[](size() - 1).

<hr>

### Iterators
<a href="./iterators.cpp">Reference</a>
- __begin__: returns a mutable or constant iterator.
- __cbegin__:returns a constant iterator (immutable).
- __end__, __cend__: returns an iterator to the character following the last character of the string. This character acts as a placeholder, attempting to access it results in undefined behavior.
- __rbegin__: returns a mutable or constant reverse iterator.
- __crbegin__:returns a constant reverse iterator (immutable).
- __rend__, __crend__: returns a reverse iterator to the character following the last character of the reversed string. It corresponds to the character preceding the first character of the non-reversed string. This character acts as a placeholder, attempting to access it results in undefined behavior.