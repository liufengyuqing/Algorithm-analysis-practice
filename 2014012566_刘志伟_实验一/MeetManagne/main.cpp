#include <iostream>

using namespace std;
/*
输入数据举例：

 5

1 1 23

2 12 28

3 25 35

4 27 80

5 36 50



*/

struct meeting
{
    int num;
    int start;
    int ending;
    int flag=0;
};

void sort(meeting a[],int n)
{

    for(int i=0; i<n; i++)
    {
        int min=a[i].ending;
        meeting temp;
        int index=i;
        for(int j=i+1; j<n; j++)
        {
            if(a[j].ending<min)
            {
                min=a[j].ending;
                index=j;
            }

        }
        temp=a[i];
        a[i]=a[index];
        a[index]=temp;

    }

    /*
       for(int i=0; i<n; i++)
        {
            //int min=a[i].ending;
            for(int j=i+1;j<n;j++)
            {
                if(a[j].ending<a[i].ending)
                {
                    meeting temp;
                    temp=a[i];
                    a[i]=a[j];
                    a[j]=temp;
                }
            }
        }

    */


}

int selector(meeting b[],int n)//贪心算法
{
    int t=0;
    int k=0;
    for(int i=0; i<n; i++)
    {
        if(b[i].flag==0)
        {
            b[i].flag=1;
            k=i;
            cout<<"第"<<++t<<"会场召开的会议为："<<endl;
            cout<<b[i].num<<" "<<b[i].start<<" "<<b[i].ending<<endl;
            for(int j=i+1; j<n; j++)
            {
                if(b[j].start>=b[k].ending&&b[j].flag!=1)
                {
                    b[j].flag=1;
                    k=j;
                    cout<<b[j].num<<" "<<b[j].start<<" "<<b[j].ending<<endl;
                }
            }

        }

    }
    cout<<endl;
    return t;

}





int main()
{
    int n;
    cout<<"请输入需要召开的会议数量：";
    cin>>n;
    meeting *meet=new meeting[n];
    cout<<"请依次输入"<<n<<"场会议的编号，开始时间，结束时间："<<endl;

    for(int i=0; i<n; i++)
    {
        cin>>meet[i].num>>meet[i].start>>meet[i].ending;
    }

    sort(meet,n);

    cout<<"按照会议结束时间排序后的会议序列："<<endl;
    cout<<endl;

    for(int i=0; i<n; i++)
    {
        cout<<meet[i].num<<" "<<meet[i].start<<" "<<meet[i].ending<<endl;
    }
    cout<<endl;

    cout << "共需要"<<selector(meet,n)<<"个会场" << endl;
    return 0;
}
