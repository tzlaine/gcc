template <typename T>
struct id
{
    using type = T;
};

template <typename T>
concept bool True () {
    return true;
}

int foo(int) { return 0; }

#if 1
template <typename T>
concept bool Addable () {
    return requires (T const & t, T t2, T* t3, int* i) {
        typename id<T>;
        requires true;
//        {t} -> auto;
//        {t} -> True;
//        {foo(*t3)} -> T;
//        {*-t2} -> bool;
//        {t2} -> T;
//        {t + t} -> T;
//        {t + t} noexcept;
#if 0 // Unary ops
        {!t2} -> T;
        {~t2} -> T;
        {-t2} -> T;
        {+t2} -> T;
        {&t2} -> T const*;
        {*t2} -> T;
        {*t3} -> T;
        {*i} -> T;
#endif
#if 0 // Binary ops
        {t2 << t2} -> bool;
        {t2 >> t2} -> bool;
        {t2 |  t2} -> bool;
        {t2 ^  t2} -> bool;
        {t2 &  t2} -> bool;
        {t2 && t2} -> bool;
        {t2 || t2} -> bool;
        {t2 + t2} -> bool;
        {t2 - t2} -> bool;
        {t2 * t2} -> bool;
        {t2 / t2} -> bool;
        {t2 && t2} -> bool;
        {t2 || t2} -> bool;
#endif
#if 0 // Comparison binary ops
        {t2 <  t2} -> bool;
        {t2 <= t2} -> bool;
        {t2 >  t2} -> bool;
        {t2 >= t2} -> bool;
        {t2 == t2} -> bool;
        {t2 != t2} -> bool;
#endif
    };
}
#else
template <typename T>
concept bool Addable =
    requires (T const & t) {
    {t + t} -> T;
};
#endif


#if 0
template <typename T>
concept bool UsedConcept () {
    return requires (T const & t) {
        typename id<T>;
    };
}

template <typename T>
concept bool ConceptUser () {
    return requires (T const & t) {
//        requires UsedConcept<T>() && sizeof(int) > 1u;
//        {UsedConcept<T>()};
        {t + t} -> UsedConcept;
    };
}

any ConceptUser;
#endif

// TODO: Be able to deal with this case.
template <typename T>
concept bool NestedParams () {
    return requires (T const & t) {
        {t};
        requires requires (T t) { // Note that the type of "t" just changed.
            {t};
        };
    };
}

struct my_type
{
    bool operator*() const { return true; }
    my_type operator-() const { return *this; }
};

auto constrained_fn (Addable value)
{
    return value + value;
}

#if 1
any Addable;
#endif

#if 0
any Addable;
#endif

#if 0
any Foo;
#endif

int main ()
{
#if 0
    int i = 0;
    constrained_fn(i);
#endif

#if 0
    my_type mt = {};
    constrained_fn(mt);
#endif

#if 0
    int any = 0;
#endif

#if 0
    int concept = 0;
#endif

    return 0;
}
