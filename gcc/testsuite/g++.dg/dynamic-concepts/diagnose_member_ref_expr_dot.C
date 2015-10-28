// { dg-options "-std=c++1z" }

template <typename T>
concept bool C () {
    return requires (T t, int T::* non_fn_member) {
    {t.*non_fn_member} -> T; // { dg-error "cannot virtualize use of pointer-to-member in" }
  };
}

any C c; // { dg-error "ISO C\\\+\\\+ forbids declaration of.*with no type" }
