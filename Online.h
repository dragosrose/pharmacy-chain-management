#pragma once

#include "Farmacie.h"
#include<iostream>
#include<string>
using namespace std;

class Online: public Farmacie{
    private:
        string web;
        int nr_viz;
        float discount;
    public:
        Online();
        Online(string web, int nr_viz, float discount);
        Online(const Online &o);

        string get_web();
        int get_nr_viz();
        float get_discount();

        virtual void output(ostream &out, Online &o);

        Online operator=(const Online &o);

        friend istream& operator>>(istream &in, Online &o);
        friend ostream& operator<<(ostream &out, Online &o);
        ~Online();
        
};