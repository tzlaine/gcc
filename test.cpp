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

template <typename T>
auto get_fn ()
{
    return [](T & t) { return t; };
}

#if 1
template <typename T, typename U>
concept bool Addable () {
    return requires (T t, T const & tref, U u, wrapper<T> wt, T * tptr, int * intptr) {
#if 0 // Unary ops
        {!t} -> T;
        {~t} -> T;
        {-tref} -> T;
        {+tref} -> T;
        {&t} -> T const *;
        {*t} -> T;
        {*tptr} -> T; // weird; should this tautology result in an implcit conversion op?
        {*intptr} -> T;
        {++t} -> T &;
        {tref++} -> T &;
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
        {t << t} -> T;
        {0 << t} -> T;
        {t >> t} -> T;
        {0 >> t} -> T;
        {t |  t} -> T;
        {0 |  t} -> T;
        {t ^  t} -> T;
        {0 ^  t} -> T;
        {t &  t} -> T;
        {0 &  t} -> T;
        {t && t} -> T;
        {0 && t} -> T;
        {t || t} -> T;
        {0 || t} -> T;
        {t +  t} -> T;
        {0 +  t} -> T;
        {t -  t} -> T;
        {0 -  t} -> T;
        {t *  t} -> T;
        {0 *  t} -> T;
        {t /  t} -> T;
        {0 /  t} -> T;
        {t %  t} -> T;
        {0 %  t} -> T;
        {t && t} -> bool;
        {0 && t} -> bool;
        {t || t} -> bool;
        {0 || t} -> bool;
        {t ,  t} -> T &;
        {0 ,  t} -> T &;
        {t[0]} -> T &;
        {t <  t} -> bool;
        {0 <  t} -> bool;
        {t <= t} -> bool;
        {0 <= t} -> bool;
        {t >  t} -> bool;
        {0 >  t} -> bool;
        {t >= t} -> bool;
        {0 >= t} -> bool;
        {t == t} -> bool;
        {0 == t} -> bool;
        {t != t} -> bool;
        {0 != t} -> bool;
#endif
#if 1 // Calls to regular member functions, free functions, and call operators.
//        {u(tref)} -> T &; // not virtualizable
//        {get_fn<T>()()} -> T &; // not virtualizable

        {foo(tref)} -> T &;
        {t()} -> T &;
        {t.foo()} -> T &;
        {tref()} -> T &;
        {tref.foo()} -> T &;
#endif
#if 0
//        {wt[u]} -> T &;
//        {tref[u]} -> T &;
//        {t[u]} -> T &;
//        {u[t]} -> T &;
//        {tref = 1} -> T &;

        //{T()} -> T; // Should not work, and doesn't, but it crashes!

        {T()};
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
