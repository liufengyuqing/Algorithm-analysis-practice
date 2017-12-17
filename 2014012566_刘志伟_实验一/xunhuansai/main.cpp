#include <iostream>

using namespace std;

void Round_Robin_Calender(int k,int **a)
{
    int n=1;
    for(int i=1; i<=k; i++) n*=2;

    for(int i=1; i<=n; i++)  a[1][i]=i;
    int m=1;
    for(int s=1; s<=k; s++)
    {
        n/=2;
        for(int t=1; t<=n; t++)
            for(int i=m+1; i<=2*m; i++)
                for(int j=m+1; j<=2*m; j++)
                {
                    a[i][j+(t-1)*m*2]=a[i-m][j+(t-1)*m*2-m];
                    a[i][j+(t-1)*m*2-m]=a[i-m][j+(t-1)*m*2];
                }
        m*=2;
    }

}

void output(int **a,int n)
{

	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}




int main()
{
    int k,n1=1;
    cout<<"ÇëÊäÈëKÖµ£º";
    cin>>k;
    for(int i=1; i<=k; i++) n1*=2;
    //cout<<k1;
    int **a=new int *[n1+1];
    for(int i=0; i<=n1; i++)
    {
        a[i]=new int[n1+1];
    }

    Round_Robin_Calender(k,a);
    output(a,n1);

    for(int i=0; i<n1; i++)
        delete []a[i];
        delete []a;

    return 0;
}
