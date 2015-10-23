// { dg-options "-std=c++1z" }

template <typename T>
concept bool C () {
  return requires (int i) {
    {i} -> T; // { dg-error "cannot virtualize expression.*because it does not use prototype parameter" }
  };
}

any C c;
