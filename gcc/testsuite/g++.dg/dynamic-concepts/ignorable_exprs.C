// { dg-options "-std=c++1z" }

#include <typeinfo>

template <typename T>
concept bool C () {
    return requires (T t, T * tptr) {
    {(int*)&t};
    {reinterpret_cast<int*>(&t)};
    {const_cast<const T>(t)};
    {static_cast<int*>(&t)};
    {dynamic_cast<int*>(&t)};
    {typeid(t)};
    {alignof(T)};
    {new T};
    {new T[2]};
    {delete tptr};
    {delete [] tptr};
  };
}

any C c;
