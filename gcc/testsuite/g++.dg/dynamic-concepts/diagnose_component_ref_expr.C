// { dg-options "-std=c++1z" }

template <typename T>
concept bool C () {
  return requires (T t) {
    {t.non_fn_member} -> T &; // { dg-error "cannot virtualize use of non-function member in" }
  };
}

any C c; // { dg-error "ISO C\\\+\\\+ forbids declaration of.*with no type" }
