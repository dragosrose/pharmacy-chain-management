#include <iostream>
#include <vector>
#include "Farmacie.h"
#include "Online.h"
#include "GestionareFarmacii.h"
using namespace std;


int main()
{
    GestionareFarmacii <Farmacie> v;
    GestionareFarmacii <Online> x;

    int opt = 0; int N; 
    while(opt < 5){
        cout<<"Alege una dintre urmatoarele optiuni: \n";
        cout<<"1. Input pentru lantul de farmacii fizice\n";
        cout<<"2. Input pentru lantul de farmacii online\n";
        cout<<"3. Afisare informatii lant farmacii fizice\n";
        cout<<"4. Afisare numar total de vizitatori lant farmacii online\n";
        cout<<"5. Iesiti din program.\n";
        cout<<"Introduce aici optiunea ta: "; cin>>opt;
        cout<<"\n\n";
        
        switch(opt){
            case 1:
                {cout<<"Introduceti numarul de farmacii fizice: "; cin>>N;
                if(N < 1){
                    goto input_nou;
                    input_nou:
                        cout<<"Input incorect. Introduceti din nou numarul de farmacii fizice: "; cin>>N;
                        if(N < 1)
                            goto input_nou;
                }
                Farmacie* a = new Farmacie[N];

                //Afisez un lant de farmacii fizice
                for(int i=0; i<N; i++){
                    cout<<"Farmacia numarul: "<<i+1<<"\n";
                    cin>>a[i];
                    v+=a[i];
                }

                delete[] a;
                break;}
            case 2:
                {cout<<"Introduceti numarul de farmacii online: "; cin>>N;
                if(N<1){
                    goto input_nou_2;
                    input_nou_2:
                        cout<<"Input incorect. Introduceti din nou numarul de farmacii online: "; cin>>N;
                        if(N < 1)
                            goto input_nou;
                }

                Online* b = new Online[N];

                for(int i=0; i<N; i++){
                    cout<<"Farmacia numarul: "<<i+1<<"\n";
                    cin>>b[i];
                    x+=b[i];
                }

                delete[] b;
                break;}
            case 3:
                v.display_lant(); cout<<"\n";
                break;
            case 4:
                cout<<"\n\nNumarul total de vizitatori este: "<<x.afis(); // Cerinta suplimentare: afisam numarul total de vizitatori
                break;
            default:
                cout<<"Ati iesit din program.\n";
                break;
        }
            


    }    
        
    
    return 0;

}