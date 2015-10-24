// { dg-options "-std=c++1z" }

template <typename T>
concept bool C () {
    return requires (T t) {
    {t[0]} -> double;
  };
}

any C;
