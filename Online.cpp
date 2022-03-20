#include "Online.h"
using namespace std;

//CONSTRUCTORI
Online::Online(){
    this->web = "";
    this->nr_viz = 0;
    this->discount = 0;
}

Online::Online(string web, int nr_viz, float discount){
    this->web = web;
    this->nr_viz = nr_viz;
    this->discount = discount;
}

Online::Online(const Online &o){
    this->web = o.web;
    this->nr_viz = o.nr_viz;
    this->discount = o.discount;
}

//GETTERI
string Online::get_web(){
    return web;
}

int Online::get_nr_viz(){
    return nr_viz;
}

float Online::get_discount(){
    return discount;
}

//ATRIBUIRE
Online Online::operator=(const Online &o){
    static_cast<Farmacie&>(*this) = static_cast<Farmacie>(o);
    this->web = o.web;
    this->nr_viz = o.nr_viz;
    this->discount = o.discount;

    return *this;
}

//INPUT/OUTPUT
istream& operator>>(istream &in, Online &o){
    in>>static_cast<Farmacie&>(o); //upcasting
    try{
        cout<<"Introduceti adresa web: ";
        in>>o.web;
        cout<<"Introduceti numarul de vizitatori: ";
        in>>o.nr_viz;
        if(o.nr_viz < 0)
            throw -1;
        cout<<"Introduceti discount-ul: ";
        in>>o.discount;
        if(o.discount < 0)
            throw "Ati introdus o valoare ilegala.";
        cout<<"\n";

        return in;
    } catch (int x){
        cout<<"Ati introdus o valoare ilegala. ";
        throw;
        
    } catch (const char* s){
        cout<<s;
        throw;
        
    }
    
}

ostream& operator<<(ostream &out, Online &o){
    o.output(out,o);
    return out;
}

void Online::output(ostream &out, Online &o){
    out<<"Nume farmacie online: "<<o.get_nume()<<"\n";
    out<<"Profit lunar: \n"; o.afis_profituri(); out<<"\n";
    out<<"Numar angajati: "<<o.get_nr_ang()<<"\n";
    out<<"Adresa web: "<<o.get_web()<<"\n";
    out<<"Numar de vizitatori: "<<o.get_nr_viz()<<"\n";
    out<<"Discount-ul: "<<o.get_discount()<<"\n\n";
}

//DESTRUCTOR
Online::~Online(){
    this->web.clear();
    
}