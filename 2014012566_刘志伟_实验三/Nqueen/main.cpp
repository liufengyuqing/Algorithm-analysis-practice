#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

 int check(int k);
 int a[100];
 void Nqueen(int m)
 {

     int k=1;//�к� �ӵ�һ�п�ʼ
     int count=0;//��¼��
     a[k]=1;//��һ�еĵ�һ�п�ʼ
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
                 cout<<"��"<<count<<"�ֽ⣺";
                 for(int i=1;i<=m;i++)
                 {
                    cout<<a[i]<<" ";
                 }
                 cout<<endl;

             }
             k--;//����
             a[k]++;
         }
     }


 }

 int check(int k)
 {
     for( int i=1;i<k;i++) //����k����ǰ��ĵ�1~~k-1�н����ж�
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
    cout<<"N�ʺ��������"<<endl;
    cout<<"������N��";
    cin>>n;
    Nqueen(n);
    cout<<endl;
    cout<<"���ֵ�λ����Ŵ���ڼ��У����ִ�����һ�еĵڼ��У�����"<<endl;
}
