// { dg-options "-std=c++1z" }

template <typename T>
concept bool C () {
  return requires {
    {T()} -> T; // { dg-error "cannot virtualize a constructor with a return type" }
  };
}

any C c;
