// { dg-options "-std=c++1z" }

template <typename T>
concept bool C () {
  return requires (T t, T const & tref, T * tptr, int * intptr, T && t_rvalue_ref) {
    {!t} -> T;
    {~t_rvalue_ref} -> T;
    {-tref} -> T;
    {+tref} -> T;
    {&t} -> T const *;
    {*t} -> T;
    {*tptr} -> T;
    {*intptr} -> T;
    {++t} -> T &;
    {tref++} -> T &;
    {--t} -> T &;
    {t--} -> T &;
  };
}

any C c;
