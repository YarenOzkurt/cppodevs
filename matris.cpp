#include <iostream>

using namespace std;

void matrisPrint(int matris[3][3])
{
    int i, j; 
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
       {
          cout<<matris[i][j]<<" ";
       }
        cout<<endl; 
    }        
}
void printArr(int arr[])
{
    for(int i=0;i<3;i++)
     cout<<arr[i]<<" ";
}

int main()
{
    int temp;
    int arr[3]={0,0,0};
    int matris[3][3] =  {{2, 5, 5},{4, 0, 3},{9, 1, 8}};  
    
    int matrisTrans[3][3];
        
    for(int i = 0; i < 3; ++i)  
    {  
        for(int j = 0; j < 3; ++j)  
        {
            matrisTrans[i][j]=matris[j][i];
        }
    }
    for(int k=0;k<3;k++)
    {
        for(int l=0;l<3;l++)
        {
            arr[k]+=matris[l][k];
        }
    }
    matrisPrint(matris);
    cout<<endl;
    matrisPrint(matrisTrans);
    cout<<endl;
    printArr(arr);
    cout<<endl;

  for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
      if(arr[i] < arr[j]){
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
        printArr(arr);

    return 0;
}