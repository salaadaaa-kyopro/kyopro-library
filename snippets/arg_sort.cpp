#include <numeric>
#include <cmath>
using namespace std;

struct dir_vec{
    public:
    long long x,y;
    int half;
    dir_vec():x(0),y(0),half(-1){}
    dir_vec(long long x, long long y):x(x),y(y){
        if(x==0){
            this->x=0; this->y=(y>0 ? 1 : -1);
            this->half=y<0;
            return;
        }
        if(y==0){
            this->y=0; this->x=(x>0 ? 1 : -1);
            this->half=x<0;
            return;
        }
        long long g = gcd(abs(x),abs(y));
        this->half = y<0;
        this->x=x/g; this->y=y/g;
    }
    bool operator==(const dir_vec& other) const { return (this->x==other.x && this->y==other.y && this->half==other.half); }
    bool operator!=(const dir_vec& other) const { return !(*this==other); }
    bool operator<(const dir_vec& other) const {
        if(this->half<other.half) return true;
        if(this->half>other.half) return false;
        return (this->x*other.y - this->y*other.x > 0);
    }
    bool operator>(const dir_vec& other) const { return other<*this; }
    bool operator<=(const dir_vec& other) const { return !(*this>other); }
    bool operator>=(const dir_vec& other) const { return other<=*this; }
};
