// { dg-options "-std=c++1z" }

template <typename T>
concept bool C () {
  return requires (T t) {
      {*&t} -> T; // { dg-error "cannot virtualize.*because operand.*is a subexpression" }
  };
}

any C c; // { dg-error "ISO C\\\+\\\+ forbids declaration of.*with no type" }
