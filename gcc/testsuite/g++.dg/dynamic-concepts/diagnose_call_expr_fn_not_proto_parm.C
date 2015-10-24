// { dg-options "-std=c++1z" }

template <typename T, typename U>
concept bool C () {
    return requires (T t, U u) {
    {u(t)} -> T &; // { dg-error "cannot virtualize.*because operand.*is not a.*possibly cv-qualified.*or a reference to" }
  };
}

any C<int> c;
