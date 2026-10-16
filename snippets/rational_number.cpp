#include <bits/stdc++.h>

using namespace std;

struct Rational{
    // p/q
    long long p,q;
    Rational(long long p, long long q):p(p),q(q){
        assert(q==0);
        long long g = gcd(abs(p),abs(q));
        this->p /= g; this->q /= g;
    }
    Rational(long long n):p(n),q(1){}
    
    long double val() const {
        return (long double)p/q;
    }
    Rational operator-() const {
        return Rational(-(this->p), this->q);
    }
    Rational inv() const {
        return Rational(q,p);
    }
    Rational operator*(const Rational& other) const {
        return Rational(this->p*other.p, this->q*other.q);
    }
    Rational operator/(const Rational& other) const {
        return (*this * other.inv());
    }
    Rational operator+(const Rational& other) const {
        return Rational(this->p*other.q + other.p*this->q, this->q*other.q);
    }
    Rational operator-(const Rational& other) const {
        return *this + (-other);
    }
    bool operator==(const Rational& other) const {
        return this->p == other.p && this->q == other.q;
    }
    bool operator<(const Rational& other) const {
        return this->p * other.q < this->q * other.p;
    }
    bool operator>(const Rational& other) const {
        return other < *this;
    }
    bool operator<=(const Rational& other) const {
        return *this == other || *this < other;
    }
    bool operator>=(const Rational& other) const {
        return other <= *this;
    }
    
    operator long double() const {
        return val();
    }
    long double operator+(const long double& other) const {
        return val() + other;
    }
    long double operator-(const long double& other) const {
        return val() - other;
    }
    long double operator*(const long double& other) const {
        return val() * other;
    }
    long double operator/(const long double& other) const {
        return val() / other;
    }
    
    bool operator<(const long long& other) const {
        return *this < Rational(other);
    }
    bool operator>(const long long& other) const {
        return *this > Rational(other);
    }
    bool operator<=(const long long& other) const {
        return *this < other || *this == Rational(other);
    }
    bool operator>=(const long long& other) const {
        return *this > other || *this == Rational(other);
    }
    bool operator<(const long double& other) const {
        return val() < other;
    }
    bool operator>(const long double& other) const {
        return val() > other;
    }
    bool operator<=(const long double& other) const {
        return val() <= other;
    }
    bool operator>=(const long double& other) const {
        return val() >= other;
    }
};
Rational operator+(long long& n, Rational& r){
    return Rational(n) + r;
}
Rational operator-(long long& n, Rational& r){
    return Rational(n) - r;
}
Rational operator*(long long& n, Rational& r){
    return Rational(n) * r;
}
Rational operator/(long long& n, Rational& r){
    return Rational(n) / r;
}
long double operator+(long double& r, Rational& q){
    return r + q.val();
}
long double operator-(long double& r, Rational& q){
    return r - q.val();
}
long double operator*(long double& r, Rational& q){
    return r * q.val();
}
long double operator/(long double& r, Rational& q){
    return r / q.val();
}
bool operator<(long long& n, Rational& r){
    return r > n;
}
bool operator>(long long& n, Rational& r){
    return r < n;
}
bool operator<=(long long& n, Rational& r){
    return r >= n;
}
bool operator>=(long long& n, Rational& r){
    return r <= n;
}
bool operator<(long double& r, Rational& q){
    return q > r;
}
bool operator>(long double& r, Rational& q){
    return q < r;
}
bool operator<=(long double& r, Rational& q){
    return q >= r;
}
bool operator>=(long double& r, Rational& q){
    return q <= r;
}
