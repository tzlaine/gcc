// { dg-options "-std=c++1z" }

int known_fn (int t) { return t; }

float known_overload (float t) { return t; }
int known_overload (int t) { return t; }

template <typename T>
T known_template_fn (T t) { return t; }

template <typename T>
concept bool C () {
  return requires (T t, T const & tref, T && t_rvalue_ref) {
    {known_fn(t)} -> T;
    {known_overload(t)} -> T;
    {known_template_fn(t)} -> T;

    {unknown_fn(t)} -> T &;
    {unknown_fn(tref)} -> T &;
    {unknown_fn(t_rvalue_ref)} -> T &;

    {t()} -> T &;
    {t.foo()} -> T &;

    {tref()} -> T &;
    {tref.foo()} -> T &;

    {t_rvalue_ref()} -> T &;
    {t_rvalue_ref.foo()} -> T &;
  };
}

any C c;
