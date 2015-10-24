// { dg-options "-std=c++1z" }

template <typename T, typename U>
concept bool C () {
  return requires (T t, U u) {
    {t[u]} -> double;
  };
}

using type = any C<int>; // { dg-error "the first use of.*must be a declaration" }

int func (any C<int>) // { dg-error "the first use of.*must be a declaration|ISO C\\\+\\\+ forbids declaration of.*with no type" }
{
  return 42;
}
