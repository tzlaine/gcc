// { dg-options "-std=c++1z" }

template <typename T>
concept bool C () {
  return requires (T t) {
    {t()} -> T &; // { dg-error "more than one constraint defines a type for the expression" }
    {t()} -> T &;
  };
}

any C c; // { dg-error "ISO C\\\+\\\+ forbids declaration of.*with no type" }
