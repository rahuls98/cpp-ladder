### Element access 
<a href="./elementAccess.cpp">Reference</a>
- __at__ : accesses the specified character with bounds checking and returns a reference to the same.
- __front__: reference to the first character, equivalent to operator[](0).
- __back__: reference to the last character, equivalent to operator[](size() - 1).
- __data__: pointer to an array that contains a null-terminated sequence of characters (i.e., a C-string) representing the current value of the string object.
- **c_str**: pointer to a null-terminated character array with data equivalent to those stored in the string.

<hr>

### Iterators
<a href="./iterators.cpp">Reference</a>
- __begin__: returns a mutable or constant iterator.
- __cbegin__:returns a constant iterator (immutable).
- __end__, __cend__: returns an iterator to the character following the last character of the string. This character acts as a placeholder, attempting to access it results in undefined behavior.
- __rbegin__: returns a mutable or constant reverse iterator. [<a href="./palindrome.cpp">Reference</a>]
- __crbegin__:returns a constant reverse iterator (immutable).
- __rend__, __crend__: returns a reverse iterator to the character following the last character of the reversed string. It corresponds to the character preceding the first character of the non-reversed string. This character acts as a placeholder, attempting to access it results in undefined behavior.

<hr>

### Capacity
<a href="./capacity.cpp">Reference</a>
- **max_size**: returns the maximum number of elements the string is able to hold due to system or library implementation limitations.
- __size__: returns the number of CharT elements in the string.
- __length__: returns the number of CharT elements in the string.
- __empty__: checks whether string is empty.

<hr>

### Operations
<a href="./operations.cpp">Reference</a>
- __clear__: removes all characters from the string. Equivalent to erase(begin(), end())
- __erase__: removes specified characters from the string. Takes in the starting position and number of charcaters from there to be deleted.
- __pop_back__: removes the last character.
- __push_back__: appends a character to the end.
- __replace__: replaces specified portion of a string.
- __insert__: used to insert characters into a string. [<a href="./insert.cpp">Operation reference</a>]

<hr>
