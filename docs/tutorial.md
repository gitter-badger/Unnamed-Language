# Tutorial #
This document will contain a tutorial-esque reference. It acts as both a reference for the language in addition to being a tutorial.

## Organization ##
* Introduction
  * Compilers
* Basics of The Unnamed Language (TUL)
  * Structure of a program
  * Variables and types
  * Constants
  * Operators
  * Basic Input/Output

* Program structure
  * Control Structures
  * Functions
  * Overloads and templates
  * Name visibility

* Compound data types
  * Arrays
  * Character sequences
  * Pointers
  * Dynamic Memory
  * Data structures
  * Other data types

* Classes
  * Classes (I)
  * Classes (II)
  * Special members
  * Friendship and inheritance
  * Polymorphism

* Other language features
  * Type conversions
  * Exceptions
  * Preprocessor directives

* TUL Standard Library
  * Input/Output with files

### Introduction: Compilers ###
TODO

### Structure of a program ###
Any Unnamed Language program can be written in one or more files. Each program has to have a function called "enter". This is where the program starts. The program always computes from top to bottom, from left-to-right in code. Here is an example containing these fundamental components:
```
// A basic program
public (:) enter
{
  system.out << "Hello World!";
}
```
```
Hello World!
```

The first pane shows the code. The second pane shows the ouput to the console or terminal (emulator).

We'll read from left-to-right top-to-bottom and explain what everything means.
1. `//` means the start of a _comment_. A comment is a piece of text that the compiler ignores. It is not considered code. Its sole purpose is to aid you: the programmer. The comment stops when a new line is encountered.
2. `public` means that the following entry is visible to all observers. This will make more sense when we get into classes. For now consider it as a necessary start of any _declaration_.
3. `(:)` means the type declaration (also called a signature) of a function. The '(' indicates a function. The ':' separates return values and input parameters. The closing ')' notifies the compiler that the signature is finished.
4. `enter` is the name of the function. All functions declared and defined in this manner need a name. The name is used later on. The name `enter` denotes the entry point of the program. It is a special function.

### Variables and types ###
```
// A basic program containing a variable
public (:) enter
{
  8u name_for_this_variable('h');
  system.out << "Hello World!";
}
```
```
Hello World!
```

The line that is added is `8u name_for_this_variable('h');`. This line is known as a declaration. A declaration always has this form.
1. `8u` denotes the type of the declaration. In this case it stands for "8 bits of an unsigned integer". This means that the type is going to guarantee 8 bits of information. In addition, it guarantees that operations on this data are unsigned (an integer that is positive), a natural number including 0.
2. `name_for_this_variable` denotes the actual name with which you will refer to this variable. This can be anything lowercase with underscores.
3. `('h')` denotes an initialization value for the variable. In this case it is 'h'. It could just as well be `104` without the single quotation marks.

What can this variable do? What can it be used for? The variable can be manipulated and printed.
```
// A basic program containing a variable
public (:) enter
{
  8u name_for_this_variable('h');
  system.out << name_for_this_variable;
}
```
```
h
```

See how we removed the string literal and replaced it with just the name. This will cause the system to print the variable that we have intialized it with.

The following list is a complete list of _all_ basic types in the entire language:
* @u
* @s

You can replace the @ with any positive integer number. The "u" stands for the variable being unsigned, whereas the "s" denotes that the variable will use signed semantics (negative integers allows).

### Operators ###
Variables are quite boring without being able to perform operations during runtime.
```
// A basic program containing a variable
public (:) enter
{
  8u name_for_this_variable(104);
  name_for_this_variable += 1;
  system.out << name_for_this_variable;
}
```
```
i
```

  * Basic Input/Output
### Constants ###


















