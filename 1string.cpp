#include <iostream>
#include <cstring>
#include <string>
using namespace std;

char * sorter(char arr[],int size)
{
    
    char temp;
    for(int i=0;i<size;i++)
    for(int j=0;j<size;j++)
      if(arr[i] < arr[j]){
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    return arr;
}



void printer(char arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<' ';
    }
}


int main() 
{
    char arr[10];
     int size=sizeof(arr);
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }

    printer(arr,size);
    sorter(arr,size);
    cout<<endl;
    printer(arr,size);
    int orta=10/2;
    cout<<endl<<arr[orta];
    //dinamik dizi al sirala ortadaki elemani yazdir.

  return 0;
}
