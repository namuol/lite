#define CLAMP(a,b,x) ( (x) < (a) ? (a) : ((x) > (b) ? (b) : (x)) )

template <typename T, typename R>
inline R round(T val)
{
    return (R)(val + 0.5f);
}
