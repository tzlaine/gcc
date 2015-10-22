// { dg-options "-std=c++1z" }

template <typename T>
concept bool C () {
  return requires (T t) {
    {+t}; // { dg-error "no return type could be deduced for this expression constraint; did you forget the '->'" }
  };
}

any C c;
