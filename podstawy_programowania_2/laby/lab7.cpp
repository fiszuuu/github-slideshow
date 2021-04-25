#include <set>
#include <vector>
#include <iostream>
using namespace std;

class relation{
    class pair{
    public:
        int x;
        int y;
//        bool operator<(const pair&other)const;
        pair(int _x, int _y):x(_x),y(_y){}
    };
public:
    vector<pair> pairs;
    /*
     * czy zawiera parę (x,y)?
     */
    bool has_pair(int x,int y)const;
    /*
     * dodaje parę
     * para musi być unikalna (nie może pojawiac sie kilka razy)
     */
    void add(int x,int y);
    /*
     * zwraca dziedzine relacji (iksy)
     */
    set<int> get_domain()const;
    /*
     * zwraca przeciwdziedzine relacji (igreki)
     */
    set<int> get_range()const;

    /*
     * czy relacja jest zwrotna?
     */

    bool is_reflexive()const;
    /*
     * czy relacja jest symetryczna?
     */
    bool is_symmetric()const;
    /*
     * czy jest przechodnia
     */
    bool is_transitive()const;
    /*
     * czy jest relacją równowazności
     */
    bool is_equivalence()const;
    /*
     *  czy jest antysymetryczna
     *  https://en.wikipedia.org/wiki/Antisymmetric_relation
     */
    bool is_antisymmetric()const;
    /*
     * Czy jest relacją częściowego porządkująca
     * https://en.wikipedia.org/wiki/Partially_ordered_set#Formal_definition
     */
    bool is_partial_order()const;
    /*
     * czy jest spójna
     * https://en.wikipedia.org/wiki/Connex_relation
     */
    bool is_connex()const;
    /*
     * czy jest relacja całkowitego porządku
     * https://en.wikipedia.org/wiki/Total_order
     */
    bool is_total_order()const;
    /*
     * Zapisuje relację w formacie dot
     * https://graphviz.org/
     */
    void to_dot(std::ostream&os)const;
};

bool relation::has_pair(int x,int y)const{
    for (int i = 0; i<pairs.size(); ++i)
    {
        if (pairs[i].x == x && pairs[i].y == y)
            return true;
    }
    return false;
}
void relation::add(int x,int y){
    if (!this->has_pair(x, y))
    {
        pair pair_to_add (x, y);
        pairs.push_back(pair_to_add);
    }
}
set<int> relation::get_domain()const{
    set<int> r;
    for (int i=0; i<pairs.size(); ++i)
    {
        r.insert(pairs[i].x);
    }
    return r;
}
set<int> relation::get_range()const{
    set<int> r;
    for (int i=0; i<pairs.size(); ++i)
    {
        r.insert(pairs[i].y);
    }
    return r;
}
bool relation::is_reflexive()const{
    set <int> domain = this->get_domain();
    for(auto x: domain)
    {
        if (!this->has_pair(x, x))
            return false;
    }

    return true;
}
bool relation::is_symmetric()const{
    for (int i=0; i < pairs.size(); ++i)
    {
        if (!this->has_pair(pairs[i].y, pairs[i].x))
            return false;
    }
    return true;
}
bool relation::is_transitive()const{
    set <int> range = this->get_range();
    for (int i=0; i<pairs.size(); ++i)
    {
        for(auto y: range)
            {
            if (this->has_pair(pairs[i].y, y))
                if (!this->has_pair(pairs[i].x, y))
                    return false;
            }
            /*
            else
                return false;*/
    }
    return true;
}
bool relation::is_equivalence()const{
    return this->is_symmetric() && this->is_transitive() && this->is_reflexive();
}
bool relation::is_antisymmetric()const{
    for (int i=0; i < pairs.size(); ++i)
    {
        if (!has_pair(pairs[i].y, pairs[i].x))
            return false; //wyjade mi się ze trzeba wyrzucać reflective 
    }
    return true;
}
bool relation::is_partial_order()const{
    return this->is_reflexive() && this->is_transitive() && this->is_antisymmetric();
}
bool relation::is_connex()const{
    set <int> domain = this->get_domain();
    set <int> range = this->get_range();
    for (auto x: domain)
    {
        for (auto y: range)
        {
            if (!has_pair(x, y))
                return false;
        }
    }
    return true;
}
void relation::to_dot(std::ostream&os)const{
    os<<"digraph g{\n";
    for(auto&e:pairs){
        os<<e.x<<" -> "<<e.y<<";"<<endl;
    }
    os<<"}\n";
}
bool relation::is_total_order()const{
    return this->is_antisymmetric() && this->is_transitive() && this->is_reflexive() && this->is_connex();
}
// TESTY
void info(const relation&r){
    cout<<"is_reflexive: "      <<r.is_reflexive()<<endl;
    cout<<"is_symmetric: "      <<r.is_symmetric()<<endl;
    cout<<"is_transitive: "     <<r.is_transitive()<<endl;
    cout<<"is_equivalence: "    <<r.is_equivalence()<<endl;
    cout<<"is_antisymmetric: "  <<r.is_antisymmetric()<<endl;
    cout<<"is_partial_order: "  <<r.is_partial_order()<<endl;
    cout<<"is_connex: "         <<r.is_connex()<<endl;
    cout<<"is_total_order: "    <<r.is_total_order()<<endl;

}
void test_relation_1(){
    relation r;
    int n=50;
    for(int x=0;x<n;x++){
        for(int y=0;y<n;y++){
            if(x%7==y%7)r.add(x,y);
        }
    }
    info(r);
}


void test_relation_2(){
    relation r;
    int n=50;
    for(int x=0;x<n;x++){
        for(int y=1;y<n;y++){
            if(x%y==0)r.add(x,y);
        }
    }
    info(r);
}
void test_relation_3(){
    relation r;
    int n=50;
    for(int x=0;x<n;x++){
        for(int y=0;y<n;y++){
            if(x<=y)r.add(x,y);
        }
    }
    info(r);
}

void test_relation_4(){
    relation r;
    int n=20;
    for(int x=-n;x<n;x++){
        for(int y=-n;y<n;y++){
            if(x*x<=y*y)r.add(x,y);
        }
    }
    info(r);
}

void test_relation_5(){
    relation r;
    int n=2;
    for(int x=-n;x<n;x++){
        for(int y=-n;y<n;y++){
            if(x*x<=y*y)r.add(x,y);
        }
    }
    info(r);
    r.to_dot(cout);
}

void test_relation_6(){
    relation r;
    int n=5;
    for(int x=0;x<n;x++)r.add(x,x);
    for(int x=0;x<n-3;x++){
        for(int y=1;y<n;y++){
            if(x<y+2)r.add(x,y);
        }
    }
    info(r);
    r.to_dot(cout);
}

int main ()
{
    test_relation_1();
    test_relation_2();
    test_relation_3();
    test_relation_4();
    test_relation_5();
    test_relation_6();
    return 0;
}