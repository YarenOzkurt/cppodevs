#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

/*******************************
330056 Yaren Ozkurt 1. ogretim

Bu kod vs code ile yazilip g++ ile derlenmistir
burada calismamasi benim sucum degildir...

********************************/



// fonk. tanımlamaları BURAYA
// global değişken kullanmayın!

int sizeOF(int arr[]) //Verilen dizinin boyutunu bulmak icin
{
  int size=0;
    for(int i=0;i<100;i++)
    {
      if(arr[i]!=-1)//-1 arrayin son elemani bu elemani bulana kadar say
        size++;
      else
      i=100; //bulmussan for dongusunden cik          
    }
return size;//boyutu dondur
}

int * findDuplicate(int arr[])//ayni degerden birden fazla var mi
{
      
    int num = sizeOF(arr);//dzinin boyutu kadar kosacak 
    for(int i=0; i<num; i++)
    {
        for(int j=i+1; j<num; j++)//bir sonraki degerden baslayarak karsilastirmaya basla
        {            
            if(arr[i] == arr[j])//cift deger bulundu mu
            {
              for(int k=j; k<num; k++)//j deki degerin yerine bi sonraki degeri ekleyerek sil
                {
                    arr[k] = arr[k + 1];//k yerine bir sonraki deger
                }   
                num--;//dizinin boyutunu bir eksilt
                j--;//deger silinmisse degerlerin indisi kaymistir j yi arttirmaya gerek yok
            }
        }
    }
  return arr;//yeni olusturulan diziyi dondur
}


bool kiyasla(int dizi1[],int dizi2[])
{
  // KODLAR BURAYA
  //bool flag=true;
  int n=sizeOF(dizi1);
  int m=sizeOF(dizi2);//2 dizinin boyutunu hesapla
  
  sort(dizi1,dizi1+n);
  sort(dizi2,dizi2+m);//bu iki degeri sirala
  
  if(n!=m)
  {
    return false;
  }//eger boyutlari farkliysa esit degildir
  
  for(int i = 0; i <= n; i++)
  {
    if(dizi1[i] != dizi2[i])//siralanmis dizide sirayla kontrol yapildiginda farkli deger varsa false
    {
      return false;
    }
  }
  return true;//hepsi ayniysa true dondur
}

bool kiyasla2(int dizi1[],int dizi2[]){
  // KODLAR BURAYA, Bonus için
  int n=sizeOF(dizi1);
  int m=sizeOF(dizi2);
  sort(dizi1,dizi1+n);
  sort(dizi2,dizi2+m);//ustteki kismin aynisi

  findDuplicate(dizi1);//cift degerleri bul ve sil
  findDuplicate(dizi2);//yeni ugrasilacak degerler bu 2 diziden cikacak

  bool flag = kiyasla(dizi1, dizi2);//fonksiyondan donen degeri kaydetmek icin

  //ayni fonksiyonu tekrar yazmaya gerek yok cogul degerler silinince geriye kalanlar karsilastirilir.
  
  return flag;
}


int main() {
  // main() içerisine kod eklemeyin, burası olabildiğince sade olsun
  int dizi1[] = {23,11,25,2,25,26,12,45,98,98,-1};
  int dizi2[] = {45,2,25,25,26,11,12,23,98,99,-1};
  // int dizi1[] = {25,30,40,35,-1};
  // int dizi2[] = {25,30,35,40,41,-1};
  //cout<<sizeOF(dizi1);
  cout <<"Dizilerin eşitlik durumu: "<<kiyasla(dizi1,dizi2)<<endl;
  
  // // Bonus +1 puan
  // // Dizileri küme gibi düşünfüğünüzde yani tekrarlı elemanları çıkarıp teke düşürtdüğünüzde ve karşılaştırdığınızda aynı ise bu kümeler eştir.
  cout <<"Dizilerin eşlik (denklik) durumu: "<<kiyasla2(dizi1,dizi2)<<endl;
}