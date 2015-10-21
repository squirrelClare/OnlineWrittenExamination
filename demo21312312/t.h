#ifndef T_H
#define T_H
int x=33;
class T
{
public:
    T(){
        this->x=33;
    };
    T(int i);
    int get(){
        return T::x+7;
    };
};

#endif // T_H
