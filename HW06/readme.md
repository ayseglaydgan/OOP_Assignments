# Explanation

## Why Most of Implementations are in Header Files?

My implementations are on the header file because, when using templates, It requires to do like this.\
With standard separate header file and implementation file style. It gives errors.

## File Structure

There are class files with implementations and a main file as a source files.\
Also there is a makefile and this readme.md file.\

Lastly there is a testResults.txt file. This file contains sample run.\
If you command `make output` it will generate same output as output.txt.

## Problem Approach

First of all, I create a Node class to represent every node in a list.\
Then I create a Iterator that keeps that uses this node class.\

Iterator class applies required iterator methods and overloads required operators.\
And inherits base random access iterator class.\
Because of that, std::sort, std::find, std::for_each functions are usable.\
Also there is a const iterator that does the same thing but not allowed to change the value.

Iterable.h contains general iterable class. It implemented by using iterator and const iterator as expected.\
Also even it has virtual functions, it implements them for simpler use.

GTUVector, GTUSet, GTUArray implements iterable class and adds their unique functions.\
Also they implements a list template to initialize values like this: `GTUVector<int> vec = {1,2,3,4,5};`.

## Tests

I tested all functions as `int` and `string`.

Also I tested functions that throws error with throwing error.

All errors are handled.
