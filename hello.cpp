#include <iostream>

using namespace std;

int ortHesapla(int a, int b){
    int ort;
    if(a>100 || b>100)
    {
            ort = 101;
    }
    else 
    {
        ort = int(a+b)/2;
        cout<< "Ortalamaniz: "<< ort<<"\n"<<endl;
    }

    return ort;
}

void harfHesapla(int a, int b){
    int ort = ortHesapla(a,b);
    char harf;

        if(ort<44){
            harf = 'F';
            
        }
        else if (ort>=45 && ort<=59){
            harf = 'D';
        }
        else if (ort>= 60 && ort<=74){
            harf = 'C';
        }
        else if (ort>= 75 && ort<=89){
            harf = 'B';
        }
        else if (ort>= 90 && ort<=100){
            harf = 'A';
        }
        else {
            cout<< "0-100 arasi not giriniz!!"<<endl;
        }
    
    //return harf;
}

bool palindrom(int a)
{
    bool flag;
    int yuzbin = int(a/100000);
    a=a-(yuzbin*100000);
    int onbin = int(a/10000);
    a=a-(onbin*10000);
    int bin = int(a/1000);
    a=a-(bin*1000);
    int yuz = int(a/100);
    a=a-(yuz*100);
    int on = int(a/10);
    a=a-(on*10);
    int bir = a;
    
    if(bir==yuzbin && on==onbin && yuz==bin)
        flag=true;
    else 
        flag=false;

    return flag;
}
int main(){
    int num;
    // int a,b;
    // cout<<"Vize notunu giriniz: ";
    // cin>>a;
    // cout<<"Final notunu giriniz: ";
    // cin>>b;
    // // int ort = ortHesapla(a,b);

    // // cout<< "Ortalamaniz: "<< ort<<"\n";
    // //char harf = harfHesapla(a,b);
    // harfHesapla(a,b);
    //cout<< "Harfli notunuz: "<< harf;
    cout<<"Numaranizi giriniz ";
    cin>>num;
    if (palindrom(num))
        cout<<"Numaraniz palindromdur";
    else
        cout<<"Numaraniz palindrom degildir";
    return 0;
}