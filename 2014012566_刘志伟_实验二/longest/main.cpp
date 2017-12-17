#include <iostream>
#include<string.h>
//最长公共子序咧


using namespace std;

void LCS(string str1,string str2)
{
   int str1_len=str1.length();
   int str2_len=str2.length();
   int a[100][100];
   //a[100][100]=memset(a,0,sizeof(a));//³õÊ¼»¯Êý×é0
   for(int i=1;i<=str1_len;i++)
   {
       for(int j=1;j<=str2_len;j++)
       {
          if(str1[i-1]==str2[j-1])
          {
              a[i][j]=a[i-1][j-1]+1;
          }
          else if(a[i][j-1]>=a[i-1][j])
          {
              a[i][j]=a[i][j-1];
          }
          else
          {
               a[i][j]=a[i-1][j];
          }

       }

   }
   for(int i=0;i<=str1_len;i++)
   {
       for(int j=0;j<=str2_len;j++)
       {
           cout<<a[i][j]<<" ";
       }
       cout<<endl;
   }

   int i ,j;
   for(i=str1_len,j=str2_len;i>=1&&j>=1;)
   {
       if(str1[i-1]==str2[j-1])
       {
           cout<<str1[i-1]<<" ";
           i--;
           j--;
       }
       else
       {
           if(a[i][j]>=a[i][j-1])
           {
               j--;
           }
           else
           {
               i--;
           }

       }
   }


}


int main()
{
   string str1="BDCABA";
   string str2="ABCBDAB";
   LCS(str2,str1);
return 0;
}
