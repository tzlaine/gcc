// { dg-options "-std=c++1z" }

template <typename T>
concept bool C = requires (T t) {
  {!t} -> T;
  {+t} -> T;
};

any C c;
