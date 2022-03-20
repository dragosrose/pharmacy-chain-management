#pragma once

#include "Farmacie.h"
#include "Online.h"
#include <iostream>
#include <vector>
using namespace std;

template <class Tip>
class GestionareFarmacii{
    private:
        vector <Tip> v;
        static int index;
        static const int id;
    public:
        GestionareFarmacii();
        GestionareFarmacii(vector<Tip> v, int index);
        GestionareFarmacii(const GestionareFarmacii<Tip>& g);
        ~GestionareFarmacii();
        void operator+= (const Tip &t);
        void display_lant();
};

template <class Tip> int GestionareFarmacii<Tip>::index = 0;
//template <> int const GestionareFarmacii<Online>::id = 11;
template <> int const GestionareFarmacii<Farmacie>::id = 10;

// CONSTRUCTORI
template <class Tip>
GestionareFarmacii<Tip>::GestionareFarmacii(){
    index = 0;
}

template <class Tip>
GestionareFarmacii<Tip>::GestionareFarmacii(vector<Tip> v, int index){
    this->v = v;
    this->index = index;
}

template <class Tip>
GestionareFarmacii<Tip>::GestionareFarmacii(const GestionareFarmacii<Tip>& g){
    v = g.v;
    index = g.index;
}

//DESTRUCTOR
template <class Tip>
GestionareFarmacii<Tip>::~GestionareFarmacii(){
    v.clear();
}

//AICI ADAUGAM FARMACIILE IN LANT
template <class Tip>
void GestionareFarmacii <Tip>::operator +=(const Tip &t){
    v.push_back(t);
    index++;
}


//AFISAM LANTUL DE FARMACII
template <class Tip>
void GestionareFarmacii <Tip>::display_lant(){
    if(id == 11)
        cout<<"Lant farmacii online: \n";
    else if(id == 10)
        cout<<"Lant farmacii fizice: \n";
    
    cout<<"Numarul de farmacii: "<<index<<"\n";
    cout<<"Acestea sunt urmatoarele farmacii de gestionat: \n\n";
    
    for(int i=0; i<v.size(); i++){
        cout<<"Farmacia nr: "<<i+1<<":\n" << v[i];
    }

    
}

/* SPECIALIZARE - CERINTA SUPLIMENTARA*/
template <>
class GestionareFarmacii<Online> {
    private:
        vector <Online> v;
        static int index;
        static const int id = 11;
    public:
        GestionareFarmacii() = default;
        GestionareFarmacii(vector <Online> v, int index);
        GestionareFarmacii(const GestionareFarmacii<Online>& go);

        void operator+=(Online &o){
            v.push_back(o);
            index++;
        }

        //ADUNAM TOTI VIZITATORII DIN TOATE FARMACIILE
        int afis(){
            int s=0;
            for(int i=0; i<v.size(); i++){
                s+= v[i].get_nr_viz();
            }

            return s;
        }
        ~GestionareFarmacii();


};


int GestionareFarmacii<Online>::index = 0;

GestionareFarmacii<Online>::GestionareFarmacii(vector <Online> v, int index){
    this->v = v;
    this->index = index;
}

GestionareFarmacii<Online>::GestionareFarmacii(const GestionareFarmacii<Online>& go){
    v = go.v;
    index = go.index;
}

GestionareFarmacii<Online>::~GestionareFarmacii(){
    v.clear();
}





