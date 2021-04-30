#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>


using namespace std;

class Vector: public vector<double>{
public:
    Vector(int n=0);
    Vector&operator*=(double arg);
    Vector&operator+=(double arg);
    Vector operator+(double arg)const;
    Vector operator*(double arg)const;
    Vector&operator+=(const Vector&arg);
    Vector&operator-=(const Vector&arg);
    Vector&operator*=(const Vector&arg);
    Vector operator*(const Vector&arg)const;
    Vector operator+(const Vector&arg)const;
    Vector operator-(const Vector&arg)const;
    double operator|(const Vector&arg)const;
    double sum()const;
    double mean()const;
    double std()const;
    Vector apply(double (*f)(double))const;
    Vector operator^(double arg)const;
    static Vector zeros(int n);
    static Vector random(int n);
    static Vector range(double stop, double start=0, double step=1);
};


ostream&operator<<(ostream&os,const Vector&v);

/*
 * Czyta wektor ze strumienia is zapisany w powyższym formacie
 * [v_0, v_1,     v_last]
 */
istream&operator>>(istream&is, Vector&v);


Vector::Vector(int n): vector<double>(n > 0 ? n : 0){
}

Vector&Vector::operator*=(double arg){
    for(auto&e:*this)e*=arg;
    return *this;
}

Vector Vector::operator*(double arg)const{
    Vector ret(*this);
    ret*=arg;
    return ret;
}

Vector&Vector::operator+=(double arg){
    for (auto & e: *this) e+=arg;
    return *this;
}

Vector Vector::operator+(double arg)const{
    Vector ret(*this);
    ret+=arg;
    return ret;
}
Vector&Vector::operator*=(const Vector&arg){
    if(size()!=arg.size())throw "bad size";
    for(int i=0;i<size();i++)
        (*this)[i]*=arg[i];
    return *this;
}
Vector&Vector::operator+=(const Vector&arg){
    if (size() != arg.size())
        throw "bad size";
    for (int i =0; i < size(); ++i)
        (*this)[i]+=arg[i];
    return *this;
}

Vector&Vector::operator-=(const Vector&arg){
    if (size() != arg.size())
        throw "bad size";
    for (int i =0; i < size(); ++i)
        (*this)[i]-=arg[i];
    return *this;
}

Vector Vector::operator+(const Vector&arg)const{
    Vector ret(*this);
    ret += arg;
    return ret;
}

Vector Vector::operator-(const Vector&arg)const{
    Vector ret(*this);
    ret -= arg;
    return ret;
}

Vector Vector::operator*(const Vector&arg)const{
    Vector ret(*this);
    ret*=arg;
    return ret;
}
double Vector::operator|(const Vector&arg)const{
    double result = 0;
    Vector ilo(*this);
    ilo = (*this) * arg;
    result = ilo.sum();
    return result;
}

Vector Vector::zeros(int n){
    Vector v(n);
    for (int i =0; i < v.size(); ++i)
    {
        v[i] = 0;
    }
    return v;
}

Vector Vector::random(int n){
    Vector v(n);
    for (int i =0; i < v.size(); ++i)
    {
        v[i] = (double)rand()/RAND_MAX;
    }
    return v;
}


double Vector::sum()const{
    double sum = 0;
    for (int i =0 ; i < size(); ++i)
    {
        sum += (*this)[i];
    }
    return sum;
}

double Vector::mean()const{
    return sum()/size();
}

double Vector::std()const{
    double std=0;
    for (int i=0; i < size(); ++i)
    {
        std += ((*this)[i] - mean())*((*this)[i] - mean());
    }
    return sqrt(std/size());
}

Vector Vector::apply(double (*f)(double))const{
    Vector ret(*this);
    for (int i=0 ; i < ret.size(); ++i)
    {
        f(ret[i]);
    }
    return ret;
}

Vector Vector::operator^(double arg)const{
    Vector ret(*this);
    for (int i = 0; i < size(); ++i)
    {
        ret[i] = pow (ret[i], arg);
    }
    return ret;
}

Vector Vector::range(double stop, double start, double step){
    Vector ret(0);
    int value = start;
    while (value < stop)
    {
        ret.push_back(value);
        value += step;
    }
    return ret;
}


ostream&operator<<(ostream&os,const Vector&v){
    os<<"[";
    for(int i=0;i<v.size();i++){
        if(i!=0)os<<", ";
        os<<v[i];
    }
    os<<"]";
    return os;
}

istream&operator>>(istream&is, Vector&v){
    v.clear();
    string s;
    getline(is, s, ']'); // wczytaj do znaku ]
    // zamień (przecinki i nawiasy) , ] na spacje
    replace(s.begin(), s.end(), ',', ' ');
    replace(s.begin(), s.end(), '[', ' ');
    replace(s.begin(), s.end(), ']', ' ');
    istringstream iss(s);
    for(;;){
       // wczytaj liczby double i dodaj do wektora
       double d;
       iss >> d;
       if (!iss)
        break;
       v.push_back(d);
    }
    return is;
}

static void test_read_write(){
    Vector r = Vector::range(10);
    ostringstream oss;
    oss<<r;
    string repr = oss.str();
    cout<<repr<<endl;
    istringstream iss(repr);
    Vector v;
    iss>>v;
    v*=2;
    cout<<v;
}

static void test_add(){
    int n=10;
    Vector a = Vector::range(10);
    Vector b = Vector::range(10) * 5 + 2;
    Vector c = a + b;
    cout<<a<<endl;
    cout<<b<<endl;
    cout<<c<<endl;
    cout<<c[1]<<endl;
}
void test_dot(){
    int n=5;
    Vector a = Vector::range(n);
    Vector b = Vector::range(n) * 5 + 2;
    int dot = a|b;
    cout<<a<<endl;
    cout<<b<<endl;
    cout << dot << endl;
}
void test_pow(){
    int n = 3;
    Vector a = Vector::range(10);
    Vector b = a^n;
    cout<<a<<endl;
    cout<<b<<endl;
}
void test_apply(){

}
void test_stats(){
    
    Vector a = Vector::random(10);
    cout<<a<<endl;
    a+=-0.5;
    cout<<a<<endl;
    a*=20;
    cout<<a<<endl;
    a = a ^ 2;
    a *= -0.125;
    cout<<a<<endl;
    cout<<a.mean()<<endl;
    cout<<a.std()<<endl;
}
int main ()
{
    //test_read_write();
    //test_add();
    //test_dot();
    //test_pow();
    test_stats();
    return 0;
}