// { dg-options "-std=c++1z" }

template <typename T, typename U>
concept bool C () {
    return requires (T t, U u) {
    {t[u]} -> double;
  };
}

any C<int, double> c; // { dg-error "expected a concept-name or partial-concept-id|specializing member.*requires.*syntax" }
