// { dg-options "-std=c++1z" }

template <typename T>
concept bool C () {
  return requires (T t, T const & tref, T && t_rvalue_ref) {
    {t =   t} -> T &;
    {t =   t_rvalue_ref} -> T &;
    {t +=  t} -> T &;
    {t -=  tref} -> T &;
    {t *=  t} -> T &;
    {t /=  t} -> T &;
    {t %=  t} -> T &;
    {t <<= t} -> T &;
    {t >>= t} -> T &;
    {t |=  t} -> T &;
    {t ^=  t} -> T &;
    {t &=  t} -> T &;

    {t << t} -> T;
    {0 << t} -> T;
    {t >> t} -> T;
    {0 >> t} -> T;
    {t |  t} -> T;
    {0 |  t} -> T;
    {t ^  t} -> T;
    {0 ^  t} -> T;
    {tref &  tref} -> T;
    {0 &  t} -> T;
    {t +  t} -> T;
    {0 +  t} -> T;
    {t -  t_rvalue_ref} -> T;
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
  };
}

any C c;
