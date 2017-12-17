#include <iostream>

using namespace std;

void beibao(int n,int w,int wei[],int v[])
{
    int c[100][100];

    for(int i=0; i<=w; i++)
    {
        c[0][i]=0;//初始化第0行
    }
    for(int j=1; j<=n; j++)
    {
        c[j][0]=0;//初始化第0列
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=w; j++)
        {
            if(j<wei[i])
            {
                c[i][j]=c[i-1][j];
            }
            else
            {
                int temp=c[i-1][j-wei[i]]+v[i];
                if(c[i-1][j]>temp)
                {
                    c[i][j]=c[i-1][j];
                }
                else
                {
                    c[i][j]=temp;
                }

            }
        }
    }

    int j=w;
    int x[n];
    for(int i=n; i>0; i--)
    {
        if(c[i][j]>c[i-1][j])
        {
            x[i]=1;
            j-=wei[i];
        }
        else
        {
            x[i]=0;
        }

    }
    cout<<"要装入的物品依次是：（1代表装0，代表不装）"<<endl;
    for(int i=1; i<=n; i++)
    {
        cout<<x[i]<<" ";
    }
}


int main()
{
    int n,w;
    cout<<"请输入物品的个数n: "<<endl;
    cin >>n;
    cout<<"请输入背包的容量w："<<endl;
    cin>>w;
    int wei[n],v[n];
    cout <<"请输入"<<n<<"个物品的重量"<< endl;

    for(int i=1; i<=n; i++)
    {
        cin>>wei[i];
    }

    cout <<"请输入"<<n<<"个物品的价值"<< endl;
    for(int i=1; i<=n; i++)
    {
        cin>>v[i];
    }
    beibao(n,w,wei,v);

    return 0;
}
