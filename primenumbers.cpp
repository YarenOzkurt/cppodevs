#include <iostream>
#include <math.h>

using namespace std;
//Bir sayinin asal olup olmadigini kontrol etmek icin
bool isPrime(int n){
  bool flag=true;
  if(n==1&&n==0)
  {
      flag=false;
  }
  else{
    for(int i=2;i<=sqrt(n);i++){
    if(n%i==0){
      flag=false;
    }
  }
  }

  return flag;
}
//aralarinda 2 fark olan asal sayilar
void listPrime(int a,int b)
{   int temp;
    for(int i=a;i<b;i++)
    {
        
        if(isPrime(i) && isPrime(i+2)) 
          cout<<i+2<<"-"<<i<<"=2"<<endl;

    }
}
int main()
{
    int a,b;
    cout<<"iki sayi  giriniz: "<<endl;
    cin>>a;
    cin>>b;
    listPrime(a,b);

}