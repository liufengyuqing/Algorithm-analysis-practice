#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

 int check(int k);
 int a[100];
 void Nqueen(int m)
 {

     int k=1;//行号 从第一行开始
     int count=0;//记录解
     a[k]=1;//第一行的第一列开始
     while(k>0)
     {
         if(k<=m&&a[k]<=m)
         {
             if(check(k)==0)
             {
                 a[k]++;
             }else
             {
                 k++;
                 a[k]=1;
             }
         }else
         {
             if(k>m)
             {
                 count++;
                 cout<<"第"<<count<<"种解：";
                 for(int i=1;i<=m;i++)
                 {
                    cout<<a[i]<<" ";
                 }
                 cout<<endl;

             }
             k--;//回溯
             a[k]++;
         }
     }


 }

 int check(int k)
 {
     for( int i=1;i<k;i++) //将第k行与前面的第1~~k-1行进行判断
     {
         if((a[i]==a[k])||(a[i]-a[k]==k-i)||(a[i]-a[k]==i-k))
         {
            return 0;
         }
     }
     return 1;
 }






int main()
{
    int n=0;
    cout<<"N皇后问题求解"<<endl;
    cout<<"请输入N：";
    cin>>n;
    Nqueen(n);
    cout<<endl;
    cout<<"数字的位置序号代表第几行，数字代表那一行的第几列！！！"<<endl;
}
