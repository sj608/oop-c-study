# oop-c-study
This is my personal repository to store example code for learning oop method using C

# Abstract Data Types and Information Hiding
Abstract data types often do not reveal its representation to the user. Abstract data types stisfy the good programming principles of information hiding and dive and conquer. information such as the representation of data item is given only to the one with a need to know. As a result, programming tasks of implementation and usage are cleanly separated.

## Set as an example

- Set.h
   - set of elements
   - operations
      - add, find, drop
   - generic pointer void* is used throughout
      - impossible to discover what a set looks like
      - permits to pass virtually anythikng
      - sacrificing type security in the interest of information hiding
- New.h
   - set is a pointer not a type defined by typedef
   - new() accepts a descriptor like set and possibley more arguments and returns a pointer to a new data item
   - delete() accepts a pointer originally produced by new() and recycles the associated resources
- Object.h
   - differ() compares objects, returns true if not equal, false if equal

refert to the [set.h](oop-c/src/set.h), [new.h](oop-c/src/new.h) header file

- main.c with headers included and skeleton structure compiles but fails to link since source functions are not defined.
- Abstract data types and the memory manager must be implemented
- if an object stores no information and if every object belongs to at most one set
   - represent each object and each set as small, unique, positive integer value used as indices into an array heap[]
- if an object is a member of a set
   - its array element contains the integer value representing the set
- Object points to the set containing them