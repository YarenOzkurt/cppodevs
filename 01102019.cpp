#include <iostream>

using namespace std;

void printArr(int arr[],int n)
{
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int * sortin(int dizi[]){
  int temp;
  for(int i=0;i<10;i++)
    for(int j=0;j<10;j++)
      if(dizi[i] < dizi[j]){
        temp = dizi[i];
        dizi[i] = dizi[j];
        dizi[j] = temp;
      }
return dizi;
}

float ort(int arr[])
{
    float ort=0.0;
    float sum=0;
    for(int i=0;i<10;i++)
     {
         sum+=arr[i];
     }
    ort = sum/10;
    return ort;
}

int maxVal(int arr[])
{
    //int max;
    int temp=arr[0];
    for(int i = 0; i <10; i++)
    {
        if(temp<arr[i])
         {
             temp=arr[i];
         }
    }
    return temp;
}

int minVal(int arr[])
{
    //int max;
    int temp=arr[0];
    for(int i = 0; i <10; i++)
    {
        if(temp>arr[i])
         {
             temp=arr[i];
         }
    }
    return temp;
}

int middle(int arr[])
{
    int middle;
    //printArr(arr);
    sortin(arr);
    //printArr(arr);
    middle=arr[5];
   
    return middle;
}
void grafikCiz(int arr[],int n){
  for(int i=0;i<n;i++){
    for(int j=0;j<arr[i];j++)
    {
      cout<<"*";
    }
    cout<<endl;
  }
}
int * minmaxBul(int dizi[]){
  int *m = new int[2];
  m[0] = minVal(dizi);
  m[1] = maxVal(dizi);

  return m;
}

int main()
{
    int arr[]={1,2,3,40,5,6,7,8,9,10};
    //printArr(arr);
    // cout<<"ilk deger: "<<arr[0]<<endl;
    // cout<<"son deger: "<<arr[9]<<endl;
    // cout<<"Ortalama: "<<ort(arr)<<endl;
    // cout<<"max deger : "<<maxVal(arr)<<endl;
    // cout<<"min deger : "<<minVal(arr)<<endl;
    // cout<<"orta deger : "<<middle(arr)<<endl;
    //printArr(arr);
//    grafikCiz(arr,10);
    printArr(minmaxBul(arr),2);
    return 0;

    
}