// { dg-options "-std=c++1z" }

template <typename T>
struct id
{
    using type = T;
};

template <typename T>
concept bool C () {
  return requires (id<T> idt) {
      {idt &= 0} -> int; // { dg-error "cannot virtualize operator&= from a non-member of prototype template parameter" }
  };
}

any C c; // { dg-error "ISO C\\\+\\\+ forbids declaration of.*with no type" }
