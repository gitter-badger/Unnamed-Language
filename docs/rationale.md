## Version 1.1.0 ##
The standard GNU versioning scheme will be applied.

# General Note #
The sections are divided into different topics. Each topic starts with possible cases/uses. Then we choose one and give a reason. At the end a result is stated.  
The result is in a grammar specification. All characters are terminals except for <:enclosed:> lexemes. These are non-terminals. Any point in the topic may be interjected with the "tangent"s. Tangents refer to another topic in order to clarify what is later used in the current topic.

## Entry Point ##

1. ```label:```
2. Start from the beginning of a file (from the top to the bottom).
3. Use a standard function e.g.: ```int main(int argc, char *argv[]){}```
4. Use a cyclic dependency graph.

3 seems like a goal. It defines an entry point.  
Reason: 3 defines a function as the start of the program. The label is too assembly-esque and resembles a goto. Neither is it callable, only goto-able. This will yield problems when attempting to call the entry point for recursion. The start of the file is not really useful as it does not allow us exactly differentiate function declarations from actual running code. I think this makes people understand the code less. A cyclic dependency graph is very versatile (computations based on what is used); however, it does not look like something that is simple to manage. If it is complicated for a computer to parse: it is also complicated for humans to understand and reason about it.

We add the requirement that each file can have its own enter function and the compiler can compile with respect to running a certain enter function.
Reason: Sometimes it is useful to have 2 different enter functions so either can be run. They can be declared in the same project without copying a lot of the code.

Next Topic:
```
function
  How do we declare functions?
end
```

Result: Entry point
```
(:) enter
{
  <:code:>
}
```

## Function Declaration ##
Should we allow free functions?
Let's say yes.
Reason: It is too much work to have to define an entire class for functions.

Types of function declaration:  

1. C-decl: ```<:return_type:> <:name:> ( <:arguments:> ) [ ] { <:statements:> }```
2. C-style: ```<:return_type:> <:name:> ( <:arguments:> ) { }```
3. Java-style: ```public class <:Name:> { public static <:return_type:> <:name:> ( <:arguments:> ) throws <:exception_list:> { <:statements:> } }```
4. Haskell-style: ``` <:name:> :: <:type:> -> <:type:> \n <:name:> <:arguments:> = <:code:>  ```
5. Lisp-style: ```(<:name:> <:arguments:>)```
6. Matlab-style: ```function [ <:return_names:> ] = <:function_name:> ( <:arguments:> ) <:code:> end```
7. Python-style: def <:name:> ( <:argument_list:> ) <:indent:> <:code:> <:unindent:>
8. Javascript-style: ```function <:name:> ( <:arguments:> ) { <:code:> }```

Tangent: See `Variable/Type Declaration` for choice of type within the function signature.

```
() -> () function
() function
void() function

(32s a, char b)(64s c) function  // Note: '(' in the beginning is required to give the LL(1) parser information that it is a function.
(32s q, 8u c):(64u e) function // Return args on the left.
((:) b):(30u a) function // Returning a b void function

(ptr (:) b):(18u a) function // Returning a b, a pointer to a void function.
(ptr (->) b)->(32s a) function // Returning a b, a pointer to a void function, using arrows
```

Why use arrows when typing is cheaper using ':'? The function declaration will have to start with a '('.  
What if we want a variable of - say - a class to be assigned functions?  
Use function pointers. This means declarations starting with `(` are static functions that are unassignable.  
Reason: Having a collected signature of functions is very clean and useful. It makes the language terser and is also easily parsable.

Result: Function Signature
```
( <:type:> <:result_name:>, <:arguments:> : <:type:> <:argument_name:>, <:arguments:> ) <:function_name:>
{ <:code:> }
```
Example:
```
(64u factorial, 32s error_code : 32u to_calculate) computeRawFactorial
{
  64u factorial(to_calculate);
  to_calculate -= 1;
  while (to_calculate > 1)
  {
    factorial *= to_calculate
    to_calculate -= 1;
  }
  return factorial: factorial;
}
```

## Variable/Type Declaration ##
Tangent: See `Plain Old Data (POD) Types` for declaring PODs.

The style that is desired must be easy to parse. For consistency, types must avoid cdecl.  
Type reads from left-to-right.  
1. ```const int *const variable;```  
2. ```variable is const ptr const int```  
3. ```const ptr const int variable```  
4. ```variable: const ptr const int```  
5. ```variable: int = 100```  

```
struct Something
{
  beta: String;
  delta: int[];
  x: const int;
  y: float = 20.0;
  z: char;
};
```

```
struct Something
{
  String    beta;
  int[]     delta;
  const int x;
  float     y;
  char      z;
};
```

We go with 3. The reason is that this is LL(1) parsable (a predictive parser).  
The FIRST(statement) is different for each production.

## Plain Old Data (POD) Types ##
Specifying a signed integer:  
`<:denary:>`s:
```
32s
64s
100s
10s
9s
50s
47s
```

Specifying an unsigned integer:  
`<:denary:>u`:
```
32u
64u
100u
10u
9u
50u
47u
```

Why not use u32 instead? The lexer will be able to pick this up faster? Suppose:
```
2000000000s // 2 Signed Gigabit
s2000000000 // 2 Signed Gigabit
```
No. This will remove allowing u3 as a variable name. This is not a problem. What is a problem is that it is inconsistent. x3 may be a variable name but not u3. Therefore; the suffix is preferred.

Specifying a pointer type:
ptr <type>
```
ptr 32u
ptr ptr ptr 8u
```

Specifying a reference type:
ref <type>
```
ref 32u
ref ptr 9u
```

Reason: satisfies the portability goal as well as being easy to code.

Result:
```
<:number:><:type_of_int:>
```
Note that the lexer will perform this operation.

## Variables and True Functions ##
```
32s a = 1000;
ptr (:) enter_a // This is a variable. It has to be assigned to be called correctly
(:) enter_b // This is NOT a variable; but an actual function
```
enter_a can be overwritten. It is mutable. It is not a true function. It is a function pointer.

## Operators ##
Should we allow operator overloading?
1. Liberal
2. Conservative
3. Restricted

Liberal: can define any new operator.  
Conservative (C++): can overload any operator.  
Restricted (Java): no operator overloading/creation.  

So what shall we choose?  
Use cases of operators.  
```
  1 + 2;
  3 * 5;
  9 - 3;
  4 / 2;
  400 % 3;
  1 << 3;
  1000 >> 3;
  ==, !=, >=, <=, >, <
  ||, &&, !, ~, |, &
  , . ->
```

Use case of a conservative model:
```
  vec1: Vector(1, 3, -2);
  vec2: Vector(10, -5, 4);
  vec3: Vector = vec1 + vec2;
  vec4: Vector = vec1.add(vec2);
```

Seems like a strong case for allowing at least conservative operator overloading, right?

How will the syntax be for overloading?
```
(Vec3 result : cref Vec3 lhs, cref Vec3 rhs : pure) +
{
  Vec3 temp;
  temp.set(x: lhs.x + rhs.x, y: lhs.y + rhs.y, z: lhs.z + rhs.z);
  return result: temp;
}
```

## Overloading new/del? ##
In C++ one has the ability to overload operators delete and new. This may improve memory handling on some specific systems. It allows the programmer to overload the operators and optimize the entire program from a single point. On one hand that appears nice and it already fits with the current overloading method. However, it does introduce "hidden" operations. This is already quite so with constructors and destructors and goes somewhat against the language being human-friendly.

## Expressions ##
There are multiple forms of expressing general expressions.
LISP uses the prefix style; whilst a lot of popular languages use infix style. In this language infix will be used to evaluate binary (and unary) operations.

An addition to expressions come from Haskell (and some other languages): the if-else construct can be embedded in an expression. The ternary operator from C/C++ is removed.

Reason: the if-else is much easier to read yet terse. It is not too small compared to the ternary operator ?: in C/C++/Java which can be missed by the eye. It removes another construct from the language; hence, making it simpler.

## Current Language Status ##
The following code is to be a single file of code. It should abide by the specification given above.

Main.ul:
```
private ptr (64u result : 32u of : pure) compute_factorial;

public static (:) enter
{
  ptr Main main = new Main;
  defer del main; // Calls the constructor when exiting the scope.
  print(data: "Hello, world!");
  print(escape: lib::NEWLINE);
}

private static (64u result : 32u of : const pure) computeFactorial
{
  64u x = of;
  of -= 1;
  while (of > 1)
  {
    x *= of;
    of -= 1;
  }
  return result: x;
}

public (:: pure) Main // Constructor
{
  compute_factorial = computeFactorial;
}

public (:: pure) ~Main // Destructor, no type signature
{
  64u result: result = compute_factorial(of = 10);
  print(data: result);
}
```

Should output
> Hello, world!  
> 3628800

## Tokenization Complexity ##
I've been toying with the idea of prepending a "." or ":" in front of every keyword.
This makes it explicit that we're actually using a keyword:
```
(:) Filename
{

}

(: ptr Filename this)

(:) enter
{
  :600u x = 100;
  :32u a = 300;
  :if (a > 50)
  {
    :do (a > 100)
    {
      :while (a > 120)
      {
        --a;
      }
    }
  }
  :for
  Filename file;
  file.enter()
}
```
Doesn't look too bad... but I don't think this'll be "it".

I can implement the current machine as a simple regex matcher. It will just need
to match the top, and if it fails just go downwards... i'd rather just have
a fully formed mealy machine...































.
