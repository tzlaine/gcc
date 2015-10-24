// { dg-options "-std=c++1z" }

template <typename T>
concept bool C () {
  return requires (T t) {
    {t[0]} -> double;
  };
}

any C;

any C function_1 (any C c)
{}

auto function_2 (any C c) -> const any C
{}

auto function_3 (any C c)
{
  return c;
}
