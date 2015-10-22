// { dg-options "-std=c++1z" }

template <typename T>
concept bool C () {
  return requires (T t) {
    {t = 0 + 1} -> int; // { dg-error "cannot virtualize.*because operand.*is a subexpression" }
  };
}

any C c;
