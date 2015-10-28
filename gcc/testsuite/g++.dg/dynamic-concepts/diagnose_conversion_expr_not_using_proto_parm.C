// { dg-options "-std=c++1z" }

template <typename T>
concept bool C () {
  return requires (int i) {
    {i} -> T; // { dg-error "cannot virtualize expression.*because it does not use prototype parameter" }
  };
}

any C c; // { dg-error "ISO C\\\+\\\+ forbids declaration of.*with no type" }
