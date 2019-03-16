//
// Created by 1 on 10.03.2019.
//

#ifndef LAB_5_HASH_H
#define LAB_5_HASH_H

#include <string>
#include <iostream>

using namespace std;

struct Rec {
    string fio;
    unsigned int num;
    unsigned int status=0;
};

class Table {

private:
    Rec *arr;
    unsigned int koef,Max;
    double M=0,Q=0;

public:
    Table(unsigned int N, unsigned int k) {
        arr = new Rec[N];
        Max=N;
        if ((k!=0)&&(k<100))
            koef = k;
    }

    ~Table() {
        delete[] arr;
    }

    int Hash_1(int key) {
        return key%(Max);
    }

    int Hash_2(int index) {
        return (index+1)%(Max);
    }

    void Add(Rec r) {

        if(Q>=koef) {
            Rec p;
            Rec *k;
            k = new Rec[Max];
            for(int i=0; i<Max; i++) {
                if(arr[i].status==1) {
                    k[i].num=arr[i].num;
                    k[i].fio=arr[i].fio;
                    k[i].status=1;
                    arr[i].status=0;
                }
            }
            delete []arr;
            Max*=2;
            arr = new Rec[Max];
            M=0;Q=0;
            for(int i=0; i<Max; i++) {
                if(k[i].status==1) {
                    p.num=k[i].num;
                    p.fio=k[i].fio;
                    Add(p);
                }
            }
            delete []k;
        }

        int index=Hash_1(r.num);
        if (arr[index].status==0) {
            arr[index].status = 1;
        } else {
            while (arr[index].status != 0)
                index = Hash_2(index);
            arr[index].status=1;
        }
        arr[index].num=r.num;
        arr[index].fio=r.fio;
        M++;
        Q = M/Max*100;

    }

    int Search(Rec r) {
        int pos=-1;
        for (int i(0); i<Max; i++) {
            if ((arr[i].num==r.num) && (arr[i].fio==r.fio))
                pos=i;
        }
        if (pos==-1) {
            cout<<"Record is not found"<<endl;
        }
        return pos;
    }

    void Del(Rec r) {
        int pos=Search(r);
        Rec p;
        arr[pos].status=0;
        for (int i(pos+1); arr[i].status!=0; i++) {

                p.num = arr[i].num;
                p.fio = arr[i].fio;
                arr[i].status = 0;
                Add(p);
                M--;
                Q = M/Max*100;
                if (i==Max-1) {
                    i=-1;
                }
        }
    }

    void print() {
        for (int i(0); i<Max; i++ ) {
            if (arr[i].status==0) {
                cout<<i<<""<<endl;
            } else {
                cout <<i<<" "<< arr[i].num << " ";
                cout << arr[i].fio << endl;
            }
        }
    }
};

#endif //LAB_5_HASH_H
