// { dg-options "-std=c++1z" }

template <typename T, typename U>
concept bool C () {
    return requires (T t, U u) {
    {u(t)} -> T &;
  };
}

any C<int> c; // { dg-error "cannot virtualize.*because operand.*is not a.*possibly cv-qualified.*or a reference to|ISO C\\\+\\\+ forbids declaration of.*with no type" }
