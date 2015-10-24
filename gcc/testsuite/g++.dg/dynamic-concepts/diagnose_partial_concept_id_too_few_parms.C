// { dg-options "-std=c++1z" }

template <typename T, typename U>
concept bool C () {
    return requires (T t, U u) {
    {t[u]} -> double;
  };
}

any C<> c; // { dg-fatal "expected a concept-name or partial-concept-id" }
