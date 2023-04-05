# CAiml
CAiml is an object-oriented programming language that looks like C++ added the new elements injections and mindtables.

# The Language Goals

Before we jump into things, let’s first define a wish list for CAiml Programming Language:

    It should be beginner-friendly.
        When I say beginners, I mean people who don’t have a lot of technical knowledge or at least software development knowledge, but might want to understand what a programming language is and how to use it.

    Its syntax should be as light and easy to use as possible.
        Considering C++’s reputation as the best programming language for beginners, let’s take some of its syntax and modify it to our needs a bit.

    It should support very basic types - a number and a string.
        Whether a number is u64 / i64, u32 / i32 etc. is not that important to beginners. So, let’s hide implementation details about the size of the number from our users.

    It should to be “partially” statically typed.
    
 # The aim
The aim was for it to be implementable by a program that was about 20 pages
long. It has a fairly conventional syntax which should be easy to
understand by anyone familiar with BCPL, ML, C, Modula-3 or Java.
Like BCPL, it is typeless but has a more restrictive syntax in order
not to give adhoc recursive descent parsers an unfair advantage over
table driven compilers. Unlike BCPL the reserved words 'do' and 'then'
are not optional, and semicolons used to separate declarations and
commands are also mandatory.

The language allows both static and local variables and vectors, it
allows both pointers and indirection, it has variadic recursive
functions and routines and all these quantites can be passed as
arguments, returned as results, or assigned to variables. Strings use
backslack ('\') as the escape character and are zero terminated (as in
C), and there is an output mechanism similar to printf in C. It also
has a function (sys(n,...)) that allows dynamic control of the
interpreter.

A typical VSPL program is the following:

static count, isprime[1000]

let start() = valof
{ for i = 2 to 999 do isprime[i] := true; // Until proved otherwise.
  count := 0;
  for p = 2 to 999 do if isprime[p] do
  { let i = p*p;
    while i<=999 do { isprime[i] := false; i := i+p };
    out(p)
  };
  resultis 0
}
 
let out(n) be
{ if count mod 10 = 0 do printf("\n");
  printf(" %3d", n);
  count := count+1
}
