#include "Farmacie.h"
#include <string>
#include <iomanip>
using namespace std;



//CONSTRUCTORI
Farmacie::Farmacie(){
    this->nume = "";
    for(int i=0; i<12; i++)
        this->profituri[i] = 0;
}

Farmacie::Farmacie(string nume, double* p, int nr_ang){
    this->nume = nume;
    for(int i=0; i<12; i++)
        this->profituri[i] = p[i];
    this->nr_ang = nr_ang;
}

Farmacie::Farmacie(const Farmacie &f){
    this->nume = f.nume;
    for(int i=0; i<12; i++)
        this->profituri[i] = f.profituri[i];
    this->nr_ang = f.nr_ang;
}

//GETTERI       
string Farmacie::get_nume(){
    return nume;
}

int Farmacie::get_nr_ang(){
    return nr_ang;
}

void Farmacie::afis_profituri(){
    for(int i=0; i<12; i++){
        cout<<luni[i]<<profituri[i]<<"\n";
    }
}

//ATRIBUIRE
Farmacie Farmacie::operator=(const Farmacie &f){
    this->nume = f.nume;
    for(int i=0; i<12; i++)
        this->profituri[i] = f.profituri[i];
    this->nr_ang = f.nr_ang;

    return *this;
}

//INPUT/OUTPUT
istream& operator>>(istream &in, Farmacie &f){
    try{
        cout<<"Introduceti numele farmaciei: ";
        getline(in>>ws, f.nume);
        cout<<"Introduceti profitul lunar: \n";
    
        for(int i=0; i<12; i++){
            cout<<f.luni[i]; in>>f.profituri[i];
            if(f.profituri[i] < 0){
                cout<<"Introduceti o valoare noua: \n";
                i--;
            }

        }

        cout<<"Introduceti numarul de angajati: ";
        in>>f.nr_ang;
        if(f.nr_ang < 1)
            throw "Ati introdus o valoare ilegala. \n";
        cout<<"\n";
        return in;
    } catch (const char* s){
        cout<<s<<"\n";
        throw;
        
    }
    
    
}

ostream& operator<<(ostream &out, Farmacie &f){
    
    f.output(out,f);
    return out;
}

void Farmacie::output(ostream &out, Farmacie &f){
    out<<"Numele farmaciei: "<< f.nume<<"\n";
    out<<"Profit lunar: \n";
    for(int i=0; i<12; i++){
        out<<f.luni[i]<<f.profituri[i]<<"\n";
    }
    out<<"Numar angajati: "<<f.nr_ang<<"\n\n";
}

//DESTRUCTOR
Farmacie::~Farmacie(){
    nume.clear();
    for(int i=0; i<12; i++)
        profituri[i] = 0;
}
