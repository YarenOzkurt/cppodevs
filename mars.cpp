#include <iostream>
#include <fstream>
#include <string>
#include <locale>
#include <clocale>

using namespace std;
// void printArr(int arr[],int a)
// {
//     for(int i=0;i<a;i++)
//     {
//         cout<<arr[i]<<' ';
//     }
// }

// void printArrString(string arr[])
// {
//     for(int i=0;i<sizeof(arr);i++)
//     {
//         cout<<arr[i]<<' ';
//     }
// }

void countingLetters(string mars)
{
    setlocale(LC_ALL, "Turkish");

    int sizeOfText = mars.length();
    int countA=0;
    int countB=0;
    int countC=0;
    int countCh=0;
    int countD=0;
    int countE=0;
    int countF=0;
    int countG=0;
    int countGh=0;
    int countH=0;
    int countI=0;
    int countIe=0;
    int countK=0;
    int countL=0;
    int countM=0;
    int countN=0;
    int CountO=0;
    int CountOe=0;
    int countP=0;
    int countR=0;
    int countS=0;
    int countSh=0;
    int countT=0;
    int countU=0;
    int countUe=0;
    int countV=0;
    int countY=0;
    int countZ=0;
    int countEmpty=0;
    int countSP=0;
    cout<<sizeOfText<<" sizeoftext "<<endl;
    for(int i = 0; i < sizeOfText; i++)
     {
        if(mars[i]==char(65)||mars[i]==char(97))
            countA++;
        else if(mars[i]=='b'||mars[i]=='B')
            countB++;
        else if(mars[i]=='c'||mars[i]=='C')
            countC++;
        else if(mars[i]==char(128)||mars[i]==char(135))      
            countCh++;
        else if (mars[i]=='d'||mars[i]=='D')
            countD++;
        else if(mars[i]=='e'||mars[i]=='E')
            countE++;
        else if(mars[i]=='f'||mars[i]=='F')
            countF++;
        else if(mars[i]=='g'||mars[i]=='G')
            countG++;
        else if(mars[i]==char(166)||mars[i]==char(167))
            countGh++;
        else if(mars[i]=='h'||mars[i]=='H')
            countH++;
        else if(mars[i]== 'I'||mars[i]==char(213))
            countI++;
        else if(mars[i]=='i'||mars[i]=='I')
            countIe++;
        else if(mars[i]=='k'||mars[i]=='K')
            countK++;
        else if(mars[i]=='l'||mars[i]=='L')      
            countL++;
        else if (mars[i]=='m'||mars[i]=='M')
            countM++;
        else if(mars[i]=='n'||mars[i]=='N')
            countN++;
        else if(mars[i]=='o'||mars[i]=='O')
            CountO++;
        else if(mars[i]== char(153) ||mars[i]== char(148))
            CountOe++;
        else if(mars[i]=='p'||mars[i]=='P')
            countP++;
        else if(mars[i]=='r'||mars[i]=='R')
            countR++;
        else if(mars[i]== 's'||mars[i]=='S')
            countS++;
        else if(mars[i]==char(158)||mars[i]==char(159))
            countSh++;
        else if(mars[i]== 't'||mars[i]=='T')
            countT++;
        else if(mars[i]=='u'||mars[i]=='U')
            countU++;
        else if(mars[i]==char(154)||mars[i]==char(129))
            countUe++;
        else if(mars[i]=='v'||mars[i]=='V')      
            countV++;
        else if (mars[i]=='y'||mars[i]=='Y')
            countY++;
        else if(mars[i]=='z'||mars[i]=='Z')
            countZ++;
        else if(mars[i]==' ')
            countEmpty++;
        else
            countSP++;
     }
     
    int alphabet[]={countA,countB,countC,countCh,countD,countE,countF,countG,countGh,countH,countI,countIe,countK,countL,countM,countN,CountO,CountOe,countP,countR,countS,countSh,countT,countU,countUe,countV,countY,countZ,countEmpty,countSP};
    for(int a=0;a<30;a++)
    {
        cout<<alphabet[a]<<" ";
    }

}


int main() 
{
    setlocale(LC_ALL, "Turkish"); 

    string s;
    string mars;

    ifstream infile;
    infile.open("file1.txt");

    while(!infile.eof())
    {
    infile>>s;
    mars=mars+s;    
    //cout<<s<<endl;
    }
    //cout<<mars;
    countingLetters(mars);
    //cout<<mars<<endl;


}