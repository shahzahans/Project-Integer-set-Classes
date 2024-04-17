[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/SJn7A7DR)
# Integer Set Operations using Class

In this assignment you are expected to implement the methods of the class `IntegerSet`. These methods represent several operations on sets.

## Goal
The goal of the programming assignment is to implement the methods of the class `IntegerSet`, additionally you are expected to write the appropriate header comments to each one of the methods (refer to the previous lab for examples). Once you have *correctly* implemented them you will pass the 25 tests that are given to you in the main file.

This lab will help you practice the following topics:
* Working with tests
* Working with multiple source code files
* Working with arrays
* Working with classes
  * Constructors
  * Methods
  * const Methods
  * const Return types

## The `IntegerSet` class

### Data Members
`_set` an array of `bool`. The number of elements of this array is set to the constant `U`. `U` stands for *universe* and its value is 10. All sets in your program will have the same universe!

### Methods
* `IntegerSet();` this is the constructor of the class, initializes the set to empty set.
* `const IntegerSet& Assign(const IntegerSet& rhs);` assigns the elements of `rhs` to the caller of the method.
* `bool AddElement(unsigned short element);` adds the `element` to the set. If it was not possible to add it returns false.
* `bool Belongs(unsigned short element);` returns true if `element` is in the set, false otherwise.
* `const IntegerSet Intersection(const IntegerSet& rhs)const;` performs the intersection operation between `this` and `rhs`, returns the result of the intersection.
* `const IntegerSet Union(const IntegerSet& rhs)const;` performs the union operation between `this` and `rhs`, returns the result of the intersection.
* `const IntegerSet Complement()const;` performs the complement operation. It **does not** modify this, instead it returns a new object that represents the `this`'s complement.
* `bool Equals(const IntegerSet& rhs)const;` returns true when `this` elements are the same as `rhs` elements.
* `size_t Size()const;` returns the number of elements in the set. **REMEMBER** this is not the same as the number of elements of the array!
* `void Write(ostream& output)const;` writes the set elements to `output` stream. If there are no element, the output stream will receive the empty string. If there are one or more elements they will be output separated by spaces.
* `size_t Read(istream& input);` reads the elements of the set from the `input` stream. It returns the number of elements that were actually read.
* `string ToString()const;` returns a string representation of the set. For example: `{0, 1, 7}`.
* `void Clear();` makes the set an empty set.

## An example run

```c++
IntegerSet a;
cout << a.AddElement(3) << endl;    // prints true
cout << a.AddElement(1) << endl;    // prints true
cout << a.AddElement(10) << endl;   // prints false
cout << a.Size() << endl;           // prints 2
cout << a.ToString() << endl;       // prints {1, 3}
a.Write(cout) << endl;              // prints 1 3 
                                    // there is a space after the three
IntegerSet b, c;
b.AddElement(4);
b.AddElement(1);

c.Assign(a.Intersection(b));
cout << c.ToString() << endl;       // prints {1}
c.Assign(a.Union(b));
cout << c.ToString() << endl;       // prints {1, 3, 4}

```
## Files you are given

- `main.cpp` this file contains the `main` and `Test` functions. **DO NOT** modify this file in any way. The `main` function will execute 25 tests on the operations that you are requested to implement.
- `integer_set.h` this file contains the declaration of the `IntegerSet` class. **DO NOT** modify this file in any way.
- `integer_set.cpp` on this file you will work. In this file you will write the implementation of all the methods declared in `integer_set.h`. You may add helper functions, but you _must_ implement the methods that are declared in the header file as they are.
- `CMakeLists.txt` this file contains the instructions for the compiler on how to build your program. **DO NOT** modify this file in any way.

## Possible Steps
The first recommended step is to write the function headers in `integer_set.cpp` and create the stub for each function. For example if the declaration of a method is:
```c++
IntegerSet Complement()const;
```
Then the function stub on its CPP file would be:

```c++
IntegerSet IntegerSet::Complement()const;{
    return IntegerSet();
}
```
Make sure your returning-value functions return an "impossible" number, this way you would guarantee that if a function has not been implemented you don't pass the test associated with the function by chance. Once you have done the stubs, the program should compile and you should be able to start implementing the requested functions.


Next, you should take a look at the `main` function and discern from there in what order you should implement the methods.

> Remember to make sure your code compiles.

## Expected Output
```
TEST PASSED (Constructor size set correctly                    ) Total Passed: 1
TEST PASSED (ToString on empty set                             ) Total Passed: 2
TEST PASSED (Equals on empty set                               ) Total Passed: 3
TEST PASSED (Adding 3 to set a, returned correct value         ) Total Passed: 4
TEST PASSED (A size is 3 after adding 3 elements               ) Total Passed: 5
TEST PASSED (A size is 3 after adding an existing element      ) Total Passed: 6
TEST PASSED (Adding invalid element to set a detected          ) Total Passed: 7
TEST PASSED (A size is 3 after adding invalid element          ) Total Passed: 8
TEST PASSED (ToString on set a                                 ) Total Passed: 9
TEST PASSED (2 does not belong to a                            ) Total Passed: 10
TEST PASSED (5 does belong to a                                ) Total Passed: 11
TEST PASSED (ToString after assigning a to b                   ) Total Passed: 12
TEST PASSED (ToString after b complement                       ) Total Passed: 13
TEST PASSED (ToString Intersection of disjoint sets            ) Total Passed: 14
TEST PASSED (ToString Intersection Result                      ) Total Passed: 15
TEST PASSED (ToString empty after Clear                        ) Total Passed: 16
TEST PASSED (ToString Union Result                             ) Total Passed: 17
TEST PASSED (Count after reading correct                       ) Total Passed: 18
TEST PASSED (Size after reading correct                        ) Total Passed: 19
TEST PASSED (ToString after reading correct                    ) Total Passed: 20
TEST PASSED (Count after reading correct (2)                   ) Total Passed: 21
TEST PASSED (Size after reading correct (2)                    ) Total Passed: 22
TEST PASSED (ToString after reading correct (2)                ) Total Passed: 23
TEST PASSED (Write empty set correct                           ) Total Passed: 24
TEST PASSED (Write non-empty set correct                       ) Total Passed: 25
```

## Grading
The number of test you need to pass is 25, if you pass them all then your _raw_ grade will be 100, this is assuming you don't get any deductions on good programming practices. If you pass 20 tests, then your _raw_ grade would be $20/25 * 100 = 80$.

## Deductions

* For each infraction on good programming practices there will be a deduction of 5 points
* If the program has a runtime error (the program crashes) there will be a deduction of 10 points
* If the program does not have comment headers there will be a deduction of 5 points
* If the program does not have comments on functions and appropriate additional comments there will be a deduction of 5 points
* If the program does not follow instructions, for instance if you did not implement any of the requested functions, there will be a deduction of 5 points per ignored instruction
* If the program does not compile, the grade will be zero.

NOTE: Remember to check the Canvas Page about Programming Practices and the course coding conventions.


## Academic Integrity

This programming assignment is to be done on an **individual** basis. At the same time, it is understood that learning from your peers is valid, and you are encouraged to talk among yourselves about programming in general and current assignments in particular.  Keep in mind, however, that each individual student must do the work in order to learn.

Hence, the following guidelines are established:
* Feel free to discuss any and all programming assignments but do not allow other students to look at or copy your code. Do not give any student an electronic or printed copy of any program you write for this class.
* Gaining the ability to properly analyze common programming errors is an important experience. Do not deprive a fellow student of his/her opportunity to practice problem-solving: control the urge to show them what to do by writing the code for them.
* If you’ve given the assignment a fair effort and still need help, see the instructor or a lab assistant.
* **If there is any evidence that a program or other written assignment was copied from another student (or from any source), neither student will receive any credit for it. This rule will be enforced: It is possible to fail the class for cheating on a programming assignment.**
* Protect yourself: Handle throw-away program listings carefully.
* Remember to read the Academic Integrity guidelines provided in the class syllabus.
* DO NOT copy code from any source, **ALL** the submitted code should be written by you (except the code that is given).
