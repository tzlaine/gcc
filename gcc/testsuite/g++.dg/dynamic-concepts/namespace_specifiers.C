// { dg-options "-std=c++1z" }

template <typename T>
concept bool C () {
  return requires (T t) {
    {t[0]} -> double;
  };
}

any ::C;

void function (any ::C c)
{}

namespace one {

  template <typename T>
  concept bool C1 () {
    return requires (T t) {
      {t[0]} -> double;
    };
  }

  any ::one::C1;

}

void function (any ::one::C1 c)
{}

namespace two {
  any one::C1 c;
  any ::one::C1 d;
}

namespace one { namespace three {
  any one::C1 c;
  any ::one::C1 d;
} }
