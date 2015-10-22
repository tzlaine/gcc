// { dg-options "-std=c++1z" }

template <typename T>
concept bool C () {
  return requires (T const & tref, T && t_rvalue_ref) {
    {T()};

    {T(tref)};
    {T(t_rvalue_ref)};

    {T(1)};
    {T(1.0, 1)};

    {~T()};
  };
}

any C c;
