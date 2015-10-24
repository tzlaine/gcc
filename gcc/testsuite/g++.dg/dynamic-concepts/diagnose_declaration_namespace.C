// { dg-options "-std=c++1z" }

namespace one {

  template <typename T>
  concept bool C () {
    return requires (T t) {
      {t[0]} -> double;
    };
  }

}

any C;

namespace two {
  any C;
}

namespace one { namespace three {
  any C;
} }

namespace one {
  any C;
}
