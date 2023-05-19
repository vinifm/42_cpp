# Module 00
Contents: Namespaces, classes, member functions, stdio streams, initialization lists, static, and some other basic stuff.

## Encapsulation
Encapsulation is the bundling of data and methods into programmable units (such as a class). It lets you restrict access to some components of an object, so users cannot directly access state values for all of the variables of a particular object, this is referred to as *information hiding*.

### Getters and setters methods.
Getters (accessors) and setters (mutators) are class functions that act as an intermediate interface to respectively fetch and manipulate the state of an object. This lets you control *how* data is accessed or manipulated, by enforcing validation checks or restrictions, for example. They also improve maintainability, since any future change in internal class representation may be handled by changing getter and setter functions instead of the code that uses them.

Getters are usually declared as const member functions, which guarantees they will not modify the state of the object on which it is called, therefore providing read-only access to data.

Further reading: [Encapsulation in OOP: Definition and Examples](https://scoutapm.com/blog/what-is-encapsulation#h_93840447845461638888736229)

## [Parametric manipulators](https://cplusplus.com/reference/iomanip/)

Stream manipulators that take parameters to modify the behaviour of the input/output streams.
- `/*undefined*/ setw (int n)`: Sets the field width to be used on output operations.

# Module 01
Memory allocation, pointers to members, references, switch statement.

## Orthodox Canonical Class Form
The Orthodox Canonical Form consists of:
- Default constructor.
- Copy constructor: a constructor which creates a new object by initializing it with an object of the same class, which has been created previously. If a copy constructor is not defined in a class, the compiler itself defines one. If the class has pointer variables and has some dynamic memory allocations, then it is a must to have a copy constructor. Its parameter is a reference to an object of the same class declared as const to ensure it will not modify the object being copied. [Source: tutorialspoint](https://www.tutorialspoint.com/cplusplus/cpp_copy_constructor.htm)
- Assignment operator: assigns the values of an object to a pre-existing one, overloading its values. ([Copy Constructor vs Assignment Operator in C++](https://www.geeksforgeeks.org/copy-constructor-vs-assignment-operator-in-c/))
- Destructor.
