#include <iostream>

using namespace std;

class dijkstra
{
  int b[50][50];
  int d[50];
  int m[50];
  int pre[20];
  int V,E,s;
  
  public:
    dijkstra()
    {
       cout << "\nEnter the number of Vertices: ";
       cin >> V;
       
       for(int i=1;i<=V;i++)
          for(int j=0;j<=V;j++)
             b[i][j]=999;
       for(int i=1;i<=V;i++)
           d[i]=999;
       for(int i=1;i<=V;i++)
           m[i]=-1;
       for(int i=1;i<=V;i++)
           pre[i]=-1;
                                                                                                                           
    }
    void InputGraph();
    void Display();
    void Algo();
    void DisplayOutput();
};

void dijkstra::InputGraph()
{
   cout << "\nEnter the number of Edges: ";
   cin >> E;
   
   int v1,v2,w;
   
   for(int i=0;i<E;i++)
   {
     cout << "\nEnter vertex1, vertex2 and corresponding distance: ";
     cin >> v1 >> v2 >> w;
     b[v1][v2]=w;
   }
}

void dijkstra::Display()
{  cout<<"\nMatrix showing the corresponding distance between any 2 vertices:\n";
   for(int i=1;i<=V;i++)
   {
     for(int j=1;j<=V;j++)
         cout << b[i][j] << " \t ";
     cout << endl;
   }
}

void dijkstra::Algo()
{
   cout << "\nEnter source vertex: ";
   cin >> s;
   
   for(int i=1;i<=V;i++)
   {
      d[i]=b[s][i];
      m[i]=0;
   }
   for(int i=1;i<=V;i++)
     pre[i]=s;
   d[s]=0;
   m[s]=1;
   pre[s]=-1;
   
   int min=999;
   int u,w;
   
   for(int i=2;i<=V;i++)
   {
    min=999;
      for(int j=1;j<=V;j++)
      {
         if(d[j]<min && m[j]==0)
         {
            min=d[j];
            u=j;
         }
      }

      m[u]=1;
      
      for(int j=1;j<=V;j++)
      {
        if(b[u][j]!=0)
            w=j;
        if(m[w]==0)
        {
           if(d[w]>d[u]+b[u][w])
           {
              d[w]=d[u]+b[u][w];
              pre[w]=u;
           }
        }
        
      }
      
 
   }
}

void dijkstra::DisplayOutput()
{
  for(int i=1;i<=V;i++)
  {
    cout << endl;
    cout << " Vertex: " << i <<endl<< "\t Distance: " << d[i] << "  Path: ";
    int j=i;
    while(pre[j]!=-1)
    {
       cout << j << "<----";
       j=pre[j];  
    }
    cout << s << endl;
  }
  
}

int main()
{
   dijkstra obj;
   obj.InputGraph();
   obj.Display();
   obj.Algo();
   obj.DisplayOutput();
}
