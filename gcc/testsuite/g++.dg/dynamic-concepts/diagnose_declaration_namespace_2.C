// { dg-options "-std=c++1z" }

namespace one {

  template <typename T>
  concept bool C () {
    return requires (T t) {
      {t[0]} -> double;
    };
  }

}

namespace two {
  any ::one::C; // { dg-error "the first use of.*must be a declaration in the same namespace as|from definition of|declaration does not declare anything" }
}

namespace one { namespace three {
  any ::one::C; // { dg-error "the first use of.*must be a declaration in the same namespace as|from definition of|declaration does not declare anything" }
} }
