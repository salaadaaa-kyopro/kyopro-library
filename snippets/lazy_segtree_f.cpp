template<typename T>
struct F{
    T a,b;
    F(T a, T b):a(a),b(b){}
};
template<typename T>
T mapping(F<T> f, T x){
    return f.a*x + f.b;
}
template<typename T>
T composition(F<T> f, F<T> g){
    return F<T>(f.a*g.a, f.a*g.b + f.b);
}
