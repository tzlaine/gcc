template <typename T>
struct id
{
    using type = T;
};

template <typename T>
concept bool True () {
    return true;
}

#if 1
template <typename T>
concept bool Addable () {
    return requires (T const & t, T t2) {
        typename id<T>;
        requires true;
        {t} -> auto;
        {t} -> True;
        {t + t} -> T;
        {t + t} noexcept;
    };
}
#else
template <typename T>
concept bool Addable =
    requires (T const & t) {
    {t + t} -> T;
};
#endif


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

#if 1
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

struct my_type {};

auto constrained_fn (Addable value)
{
    return value + value;
}

#if 0
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
    int i = 0;
    constrained_fn(i);

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
