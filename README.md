# Dynamic Array in C++

A generic **Dynamic Array implementation in C++** built from scratch using **Templates and Dynamic Memory Allocation**.

This project demonstrates how a dynamic array can be implemented manually without relying on `std::vector`.

## Overview

The `clsDynamicArray<T>` class manages a dynamically allocated array and provides operations for:

- Accessing elements
- Updating elements
- Resizing
- Inserting
- Deleting
- Searching
- Reversing
- Clearing
- Checking size and emptiness

The class uses C++ templates, allowing it to work with different data types.

## Template Support

The class is defined as:

```cpp
template <class T>
class clsDynamicArray
