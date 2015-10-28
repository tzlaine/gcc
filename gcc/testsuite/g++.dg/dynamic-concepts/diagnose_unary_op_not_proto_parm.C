// { dg-options "-std=c++1z" }

template <typename T>
struct id
{
    using type = T;
};

template <typename T>
concept bool C () {
    return requires (id<T> idt) {
      {+idt} -> T; // { dg-error "cannot virtualize.*because operand.*is not a.*possibly cv-qualified.*or a reference to" }
  };
}

any C c; // { dg-error "ISO C\\\+\\\+ forbids declaration of.*with no type" }
