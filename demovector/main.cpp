#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <set>
using namespace std;
void testRbegin(vector<int> vec)
{
    cout<<*vec.rbegin()<<endl;
}
template<class T>
void show(T* p)
{
    for(size_t i=0;i<p->size();++i)
    {
        cout<<p->at(i)<<endl;
    }
}
void test1()
{
    vector<int>* p=new vector<int>({12,23,34});

    show<vector<int>>(p);
    std::reverse(p->begin(),p->end());
    cout<<"***********"<<endl;
    show<vector<int>>(p);

    list<int>* l=new list<int>(p->begin(),p->end());

    string a[]={"dsada","dsada"};
}

void test2()
{
    std::set<int> s;
    s.insert(123);
    s.insert(13);
    s.insert(12123);
    s.insert(1232);
    s.insert(123);
    std::set<int>::key_compare k=s.key_comp();
    cout<<k(1,2)<<endl;
}
void test3()
{
    string str="213";
    cout<<std::stod(str)+2<<endl;
    cout<<std::to_string(123)+"sda"<<endl;
}

int main()
{
//    test3();
    cout<<5/2<<endl;
    string str="sdadas";
    str.substr()
    return 0;
}

