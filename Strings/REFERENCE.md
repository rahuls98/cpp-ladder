### Element access
- __at__ : accesses the specified character with bounds checking.
- __front__: reference to the first character, equivalent to operator[](0)
- __back__: reference to the last character, equivalent to operator[](size() - 1)
- __data__: pointer to an array that contains a null-terminated sequence of characters (i.e., a C-string) representing the current value of the string object.
- **c_str**: pointer to a null-terminated character array with data equivalent to those stored in the string.