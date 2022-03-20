#pragma once

#include <iostream>
using namespace std;
class Farmacie{
    private:
        string nume;
        int nr_ang;
        double profituri[12];
        string luni[12] = {"Ianuarie: ", "Februarie: ", "Martie: ", "Aprilie: ",
"Mai: ", "Iunie: ", "Iulie: ", "August: ", "Septembrie: ", "Octombrie: ",
"Noiembrie: ", "Decembrie: "};
    public:
        Farmacie();
        Farmacie(string nume, double* p, int nr_ang);
        Farmacie(const Farmacie &f);

        string get_nume();
        int get_nr_ang();
        void afis_profituri();

        virtual void output(ostream &out, Farmacie &f);
        
        Farmacie operator=(const Farmacie &f);

        friend istream& operator>>(istream &in, Farmacie &f);
        friend ostream& operator<<(ostream &out, Farmacie &f);


        ~Farmacie();
};

