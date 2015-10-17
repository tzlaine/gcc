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

template <typename T>
struct wrapper
{
    T t;
};

#if 1
template <typename T, typename U>
concept bool Addable () {
    return requires (T t, T & tref, U u, wrapper<T> wt) {
#if 0 // Unary ops
        {!t} -> T;
        {~t} -> T;
        {-t} -> T;
        {+t} -> T;
        {&t} -> T const *;
        {*t} -> T;
        {*t3} -> T;
        {*i} -> T;
        {++t} -> T &;
        {t++} -> T &;
        {--t} -> T &;
        {t--} -> T &;
#endif
#if 0 // Mutating binary ops
        {t =   t} -> T &;
        {t +=  t} -> T &;
        {t -=  t} -> T &;
        {t *=  t} -> T &;
        {t /=  t} -> T &;
        {t %=  t} -> T &;
        {t <<= t} -> T &;
        {t >>= t} -> T &;
        {t |=  t} -> T &;
        {t ^=  t} -> T &;
        {t &=  t} -> T &;
#endif
#if 0 // Non-mutating binary ops
        {t << t} -> bool;
        {t >> t} -> bool;
        {t |  t} -> bool;
        {t ^  t} -> bool;
        {t &  t} -> bool;
        {t && t} -> bool;
        {t || t} -> bool;
        {t +  t} -> bool;
        {t -  t} -> bool;
        {t *  t} -> bool;
        {t /  t} -> bool;
        {t %  t} -> bool;
        {t && t} -> bool;
        {t || t} -> bool;
        {t ,  t} -> T &;
        {t[0]} -> T &;
        {t <  t} -> bool;
        {t <= t} -> bool;
        {t >  t} -> bool;
        {t >= t} -> bool;
        {t == t} -> bool;
        {t != t} -> bool;
#endif
#if 1
//        {wt[u]} -> T &;
//        {tref[u]} -> T &;
//        {t[u]} -> T &;
//        {u[t]} -> T &;
        {tref = 1} -> T &;
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

#if 0
auto constrained_fn (Addable value)
{
    return value + value;
}
#endif

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
