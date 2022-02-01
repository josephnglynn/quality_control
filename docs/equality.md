# Equality

## Outline
These functions relate to checking equality of checking two variables of unknown types: ```a``` and ```b``` with their respective types ```( A and B )``` where ```(( A == B ) || ( A != B))```.

## Type C
Optionally you may supply a type ```C``` where ```( C == A ) || ( C == B )```. When given, it will cast the type which is not equal to ```C``` to ```C```. 
E.G: 
```cpp
int8_t a = 10;
uint64_t b = 10;

// By providing uint64_t as C, a will be cast to an uint64_t before checking for equality
quality_control::check_equal<uint64_t>(a, b);
```

## Definitions

Note: All global namespace functions are just wrappers around namespaced functions.

The functions in namespace ```quality_control::*``` are :
```c++
quality_control::check_equal<C>(a, b); // The C is only needed if casting is needed
quality_control::check_equal(a, b);

quality_control::assert_equal<C>(a, b); // The C is only needed if casting is needed
quality_control::assert_equal(a, b);
```

The functions in global namespace are :
```c++
CHECK_EQUAL(a, b)
ASSERT_EQUAL<C>(a, b)
```
