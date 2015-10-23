// { dg-options "-std=c++1z" }

template <typename T>
concept bool C () {
  return requires (T t) {
    {const_cast<const T>(t)} -> T; // { dg-error "cannot virtualize the conversion from expression.*to \\\(possibly cv-qualified\\\) prototype parameter" }
  };
}

any C c;
