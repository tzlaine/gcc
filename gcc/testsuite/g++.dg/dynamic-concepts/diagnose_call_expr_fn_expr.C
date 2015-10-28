// { dg-options "-std=c++1z" }

template <typename T>
auto get_fn ()
{
    return [](T & t) { return t; };
}

template <typename T>
concept bool C () {
  return requires (T t) {
    {get_fn<T>()()} -> T &; // { dg-error "cannot virtualize.*because the function being called.*is a subexpression" }
  };
}

any C c; // { dg-error "ISO C\\\+\\\+ forbids declaration of.*with no type" }
