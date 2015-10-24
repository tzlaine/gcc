// { dg-options "-std=c++1z" }

template <typename T>
concept bool C () {
    return requires (T t) {
    {t[0]} -> double;
  };
}

class class_scope
{
  any C c; // { dg-error "the first use of 'any .*' must be a declaration at namespace scope|ISO C++ forbids declaration of.*with no type" }
};

void function_scope ()
{
  any C c; // { dg-error "the first use of 'any .*' must be a declaration at namespace scope|ISO C++ forbids declaration of.*with no type" }
}
