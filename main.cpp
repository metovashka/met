#include <iostream>
#include <string>
#include "Hash.h"

using namespace std;


int main() {

    Table T(10, 90);
    Rec r;

    r.num=333;
    r.fio="Ivanov";
    T.Add(r);
    r.num=331;
    r.fio="Kuznecov";
    T.Add(r);
    r.num=332;
    r.fio="Sidorov";
    T.Add(r);
    r.num=335;
    r.fio="Petrov";
    T.Add(r);
    r.num=632;
    r.fio="Semenov";
    T.Add(r);
    r.num=777;
    r.fio="Yakovlev";
    T.Add(r);
    r.num=893;
    r.fio="Semtnov";
    T.Add(r);
    r.num=453;
    r.fio="Syttnov";
    T.Add(r);
    r.num=202;
    r.fio="Stepanov";
    T.Add(r);
    r.num=203;
    r.fio="Stgrtnov";
    T.Add(r);
    r.num=205;
    r.fio="Stgrtnov";
    T.Add(r);
    r.num=216;
    r.fio="Stegfnov";
    T.Add(r);
    r.num=516;
    r.fio="Sthgfhffnov";
    T.Add(r);
    r.num=783;
    r.fio="Syttnov";
    T.Add(r);
    r.num=402;
    r.fio="Stepanov";
    T.Add(r);
    r.num=343;
    r.fio="Stgrtnov";
    T.Add(r);
    r.num=125;
    r.fio="Stgrtnov";
    T.Add(r);
    r.num=876;
    r.fio="Stegfnov";
    T.Add(r);
    r.num=986;
    r.fio="Sthgfhffnov";
    T.Add(r);
    r.num=333;
    r.fio = "Ivernov";
    T.Add(r);

    for (int i(333); i<339; i++) {
        r.num=i;
        r.fio[0]++;
        T.Add(r);
    }

    r.num=769;
    r.fio="Deferfr";
    T.Add(r);
    T.Del(r);
    r.num=333;
    r.fio = "Ivernov";
    T.Del(r);
    r.num=333;
    r.fio="Ivanov";
    T.Del(r);
    T.Add(r);
    r.num=986;
    r.fio="Sthgfhffnov";
    T.Add(r);
    r.num=333;
    r.fio = "Ivernov";
    T.Add(r);
    r.num=986;
    r.fio="Sthgfhffnov";
    T.Add(r);
    r.num=333;
    r.fio = "Ivernov";
    T.Add(r);

    T.print();

    return 0;
}