// { dg-options "-std=c++1z" }

template <typename T, typename U>
concept bool C () {
  return requires (T t, U u) {
    {u >>= t} -> int; // { dg-error "cannot virtualize operator>>= from a non-member of prototype template parameter" }
  };
}

any C c;
