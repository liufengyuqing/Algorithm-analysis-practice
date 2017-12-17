#include<queue>
#include<iostream>
using namespace std;

//��ʾ������λ�õĽṹ��
struct Position
{
    int row;
    int col;
};

//��֧�޽��㷨
bool FindPath(Position start,Position finish,int& PathLen,Position *&path,int **grid,int m,int n)
{
    //�ҵ���̲���·�����򷵻��棬���򷵻ؼ�

    //�����յ���ͬ�����ò���
    if((start.row==finish.row) && start.col==finish.col)
    {
        PathLen=0;
        return true;
    }


    //���÷����ƶ�����ֵ�������ϡ�������
    Position offset[4];
    offset[0].row=0;
    offset[0].col=1;	//��
    offset[1].row=1;
    offset[1].col=0;	//��
    offset[2].row=0;
    offset[2].col=-1;	//��
    offset[3].row=-1;
    offset[3].col=0;	//��

    //���ڵķ�����
    int NumNeighBlo=4;
    Position here,nbr;
    //���õ�ǰ���񣬼�������λ
    here.row=start.row;
    here.col=start.col;
    //����0��1���ڱ�ʾ����Ŀ��źͷ������ʾ��룺2-0 3-1
    grid[start.row][start.col]=0;

    //����ʽ��������ǿɴ����ڷ���
    queue<Position> q_FindPath;

    do
    {
        for(int i=0; i<NumNeighBlo; i++)
        {
            //�ﵽ�ĸ�����
            nbr.row=here.row+offset[i].row;
            nbr.col=here.col+offset[i].col;
            if(grid[nbr.row][nbr.col]==-1)
            {
                //�÷���δ���
                grid[nbr.row][nbr.col]=grid[here.row][here.col]+1;
                if((nbr.row==finish.row)&&(nbr.col==finish.col))
                    break;
                //������ھ����
                q_FindPath.push(nbr);
            }
        }
        //�Ƿ񵽴�Ŀ��λ��finish
        if((nbr.row==finish.row)&&(nbr.col==finish.col))
            break;

        //��������Ƿ�Ϊ��
        if(q_FindPath.empty())return false;	//�޽�
        //���ʶ���Ԫ�س���
        here=q_FindPath.front();
        q_FindPath.pop();


    }
    while(true);

    //������̲���·��
    PathLen=grid[finish.row][finish.col];
    path=new Position[PathLen];	//·��

    //��Ŀ��λ��finish��ʼ����ʼλ�û���
    here=finish;
    for(int j=PathLen-1; j>=0; j--)
    {
        path[j]=here;
        //��ǰ��λ��
        for (int i = 0; i <=NumNeighBlo; i++)
        {
            nbr.row=here.row+offset[i].row;
            nbr.col=here.col+offset[i].col;
            if(grid[nbr.row][nbr.col]==j)	//�����2������ǰ��λ��
                break;
        }
        here=nbr;
    }

    return true;
}

int main()
{
    cout<<"---------��֧�޽編֮��������--------"<<endl;
    int path_len;
    int m,n;
    Position *path;
    Position start,finish;
    cout<<"��һ��m*n�������ϣ���ֱ�����m��n"<<endl;
    cin>>m>>n;

    //�������̸�
    int **grid = new int*[m+2];
    for(int i=0; i < m+2; i++)
    {
        grid[i] = new int[n+2];
    }
//��ʼ�����̸�
    for(int i=1; i <= m; i++)
    {
        for(int j=1; j <=n; j++)
        {
            grid[i][j]=-1;
        }
    }
       //���÷������е�Χǽ
    for(int i=0; i<=n+1; i++)
        grid[0][i]=grid[m+1][i]=-2;//���µ�Χǽ

    for(int i=0; i<=m+1; i++)
        grid[i][0]=grid[i][n+1]=-2;//���ҵ�Χǽ

    cout<<"��ʼ�����̸�ͼ�Χǽ"<<endl;
    cout<<"--------------- ----------------"<<endl;
    for(int i=0; i < m+2; i++)
    {
        for(int j=0; j <n+2; j++)
        {
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
     cout<<"-------------------------------"<<endl;




    cout<<"�������Ѿ�ռ�ݵ�λ�ã��������꣩,�����Ѿ����ߣ���-3��ʾ"<<endl;
    cout<<"��������� ������ < "<<m<<" ����������< "<<n<<" �����������Ϊ(0,0)����������"<<endl;


    //����Ѿ����ߵ����̸�
    while(true)
    {
        int ci,cj;
        cin>>ci>>cj;
        if(ci>m||cj>n)
        {
            cout<<"����Ƿ�����������";
            cout<<"������ < "<<m<<" ����������< "<<n<<" �����������Ϊ(0,0)����������"<<endl;
            continue;
        }else if(ci==0||cj==0){
             break;
        }else{
            grid[ci][cj]=-3;
        }

    }


    //����ǰ�����̸�
    cout<<"����ǰ�����̸�"<<endl;
    cout<<"-------------------------------"<<endl;
    for(int i=0; i < m+2; i++)
    {
        for(int j=0; j <n+2; j++)
        {
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
     cout<<"-------------------------------"<<endl;


    cout<<"���������λ������"<<endl;
    cin>>start.row>>start.col;
    cout<<"�������յ�λ������"<<endl;
    cin>>finish.row>>finish.col;

    if(FindPath(start,finish,path_len,path,grid,m,n))
    {
        cout<<"���ߺ�����̸�"<<endl;
        cout<<"-------------------------------"<<endl;
        for(int i=0; i <= m+1; i++)
        {
            for(int j=0; j <=n+1; j++)
            {
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<"-------------------------------"<<endl;
        cout<<"-2 ����Χǽ"<<endl;
        cout<<"-3 �����Ѿ�ռ�ݵĵ�"<<endl;
        cout<<"-1 ����û�в��ߵĵ�"<<endl;


        cout<<"-------------------------------"<<endl;
        cout<<"$ ����Χǽ"<<endl;
        cout<<"# �����Ѿ�ռ�ݵĵ�"<<endl;
        cout<<"* ������·��"<<endl;
        cout<<"= ����û�в��ߵĵ�"<<endl;
        cout<<"-------------------------------"<<endl;

        for(int i=0; i <= m+1; i++)
        {
            for(int j=0; j <=n+1; j++)
            {
                if(grid[i][j]==-2)
                {
                    cout << "$ ";
                }
                else if(grid[i][j]==-3)
                {
                    cout << "# ";
                }
                else
                {
                    int r;
                    for(r = 0; r < path_len; r++)
                    {
                        if(i==path[r].row && j==path[r].col)
                        {
                            cout << "* ";
                            break;
                        }
                        if(i == start.row && j == start.col)
                        {
                            cout << "* ";
                            break;
                        }
                    }
                    if(r == path_len)
                        cout << "= ";
                }
            }
            cout << endl;
        }
        cout<<"-------------------------------"<<endl;
        cout<<"·������ͳ���"<<endl;
        cout<<endl;
        cout<<"("<<start.row<<","<<start.col<<")"<<" ";
        for(int i=0; i<path_len; i++)
        {
            cout<<"("<<path[i].row<<","<<path[i].col<<")"<<" ";
        }
          cout<<endl;
          cout<<endl;
          cout<<"·�����ȣ�"<<path_len+1<<endl;

          cout<<endl;

          cout<<"�������"<<endl;
    }else
    {
        cout<<"û���ҵ�·��"<<endl;
    }
    return 0;
}
