// { dg-options "-std=c++1z" }

template <typename T, typename U>
concept bool C () {
  return requires (T const & tref, U u) {
    {u(tref)} -> T &; // { dg-error "cannot virtualize.*because operand.*is not a.*possibly cv-qualified.*or a reference or pointer to" }
  };
}

any C c;
