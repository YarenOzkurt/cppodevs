/*
 return_type function_name(parameters)
 {
     ...
     body of function
    ....
}

void geri veri dondurmeyen fonksiyonlar return yok
2 turlu tanimlama
protoyip tanimlama>>yapacagi is tanimlandigi yerde yazilmak zorunda degildir
direkt tanimlama

deger ile cagirma call by value verinin icerigi degismezCall by Value
This method copies the actual value of an argument into the formal parameter of the function. In this case, changes made to the parameter inside the function have no effect on the argument.
pointer ile cagirma call by pointer verinin icerigi degismez
This method copies the address of an argument into the formal parameter. Inside the function, the address is used to access the actual argument used in the call. This means that changes made to the parameter affect the argument.
call by reference ikisi arasi
This method copies the reference of an argument into the formal parameter. Inside the function, the reference is used to access the actual argument used in the call. This means that changes made to the parameter affect the argument.

  1. değişken tanımlama
  2. tür dönüşümü
  3. if else merdiveni
  4. takas(swap) fonksiyonu
    call by value, call by pointer
  5. cout<<setw, setprecision, fixed
  6. öğrenci numarasının palindrome olup olmadığının kontrolü, döngü kullanmadan
*/

// 1. ----------------------------
/*
// basit girdi çıktı, tür dönüşümü, if else merdiveni
#include <iostream>
#include <iomanip> 
using namespace std;
int main() {
  int as=15,fn=16;
  //  cin>>as>>fn;
  float ort = (as + fn)/2.;
  char harf;
  if(ort>0 && ort<39){
    harf='F';
  }
  else if(ort<45){
    harf='D';
  }
  else if(ort<65){
    harf='C';
  }
  else if(ort<85){
    harf='B';
  }
  else if(ort<=100){
    harf='A';
  }
  else{
    harf='E';
  }
  cout<<setw(10)<<"AS"<<setw(10)<<"FN"<<setw(12)<<"Ort"<<setw(8)<<"Harf"<<endl;
  cout <<setw(10)<<as<<setw(10)<<fn<<setw(12)<<fixed<<setprecision(2)<<ort<<setw(8)<<harf<<endl;
}
*/
// 2. ------------------------------------

// öğrenci numarasının palindrom kontrolü
// koşul operatörü, döngüler, operatörler
#include <iostream>
#include <iomanip> 
using namespace std;
// sabit (6) haneli palindrom testi
int palindromTest1(int n){
  int b,o,y,bn,ob,yb;
  b = n%10; n /= 10;
  o = n%10; n /= 10;
  y = n%10; n /= 10;
  bn= n%10; n /= 10;
  ob= n%10; n /= 10;
  yb= n%10; n /= 10;
  if(b==yb && o==ob && y==bn)
    return 1;
  else
    return 0;
}
// değişken haneli palindrom testi
int palindromTest2(int n){
  int k,t=0,ydk=n;
  while(n>0)
  {
    k = n%10;
    n /= 10;
    t=t*10+k; 
  }
  return (ydk==t)?1:0;
}
//called by value
void swap(int a, int b)
{
    int temp;
    temp=a;
    a=b;
    b=temp;
}
//called by pointer
void swap2(int *a, int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void swap3(int &a, int &b)
{
        int temp;
    temp=a;
    a=b;
    b=temp;
}

void printer(int num, int as, int fn,float ort,char harf)
{
      int w[] = {9,9,5,8,8};
  cout<<setw(w[0])<<"No";
  cout<<setw(w[1])<<"AS";
  cout<<setw(w[2])<<"FN";
  cout<<setw(w[3])<<"Ort";
  cout<<setw(w[4])<<"Harf"<<endl;
  
  cout<<setw(w[0])<<num;
  cout<<setw(w[1])<<as;
  cout<<setw(w[2])<<fn;
  cout<<setw(w[3])<<fixed<<setprecision(2)<<ort;
  cout<<setw(w[4])<<harf<<endl;
}
int main() {
  int as=15,fn=16,num=25525;
  //  cin>>as>>fn;
  float ort = (as + fn)/2.;
  char harf;
  if(ort>0 && ort<39){
    harf='F';
  }
  else if(ort<45){
    harf='D';
  }
  else if(ort<65){
    harf='C';
  }
  else if(ort<85){
    harf='B';
  }
  else if(ort<=100){
    harf='A';
  }
  else{
    harf='E';
  }
  int w[] = {9,9,5,8,8};
    
  cout<<"Numara palindrom mu? : "<<palindromTest2(num)<<endl;
  cout<<"Call by value"<<endl;
  swap(as,fn);
    printer(num,as,fn,ort,harf);
  cout<<"Call by pointer"<<endl;
  swap2(&as,&fn);
  printer(num,as,fn,ort,harf);
    cout<<"Call by reference"<<endl;
  swap3(as,fn);
  printer(num,as,fn,ort,harf);
}
/*ODEEEEEVVVVV arasinav ve final notu var
araliktaki asal sayilari bulucaz aralarinda 2 fark olan asal sayi ciftlerini bulun
*/