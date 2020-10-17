// Implementation of kruskal's Algorithm
#include<bits/stdc++.h>
#define v 9
using namespace std;
int arr[v];

bool cmp(pair<int,int> x,pair<int,int> y){
    return x.second<y.second;
}

int find(int x){
    if(arr[x]==-1)
        return x;
    return find(arr[x]);
}

bool mkmst(int x,int y)
{
    /* for(auto a:arr)
    {
        cout<<a<<endl;
    }
 */
   

    int a,b;
    
    a=find(x);
    b=find(y);

    if(a==x&&b==y){
        arr[x]=y;
        return true;
    }
    else if(a!=b){
        

        arr[a]=b;
        
        return true;
    
    return false;
    
}

void printmst(vector<pair<int,int>> lst)
{
    cout<<"size = "<<lst.size()<<endl;
    vector<pair<int,int>>::iterator itr;
    cout<<"EDGES"<<"\t"<<"WEIGHT"<<endl;
    int i,j;
    
    for(itr=lst.begin();itr!=lst.end();itr++)
    {
          

        if(itr->first%10==itr->first)
        {
            i=0;
            j=itr->first;
            if(mkmst(i,j)){
                cout<<i<<" - "<<j<<"\t"<<itr->second<<endl;
            }
            else{
                continue;
            }
            
        }
        else
        {
            
            i=itr->first/10;
            j=itr->first%10; 
            if(mkmst(i,j)){
                cout<<i<<" - "<<j<<"\t"<<itr->second<<endl;

            }
            else{
                continue;
            }
            
            
        }
           
    }
}

// main calling function for kruskals algorithm

void krus(int g[v][v])
{
    vector<pair<int,int>> set;
    map<int,int> lst;
    
    for(int i=0;i<v;i++)
    {
        for(int j=i+1;j<v;j++)
        {
            if(g[i][j])
            {
                
                lst.insert({10*i+j,g[i][j]});
                
            }
        }
    }
    

    for(auto a:lst)
    {
        set.push_back(a);
    }
    
    sort(set.begin(),set.end(),cmp);
    
    printmst(set);  
}

// driver function 

int main()
{
    int graph[v][v] = { {0,4,0,0,0,0,0,8,0},
                        {4,0,8,0,0,0,0,11,0},
                        {0,8,0,7,0,4,0,0,2},
                        {0,0,7,0,9,14,0,0,0},
                        {0,0,0,9,0,10,0,0,0},
                        {0,0,4,14,10,0,2,0,0},
                        {0,0,0,0,0,2,0,1,6},
                        {8,11,0,0,0,0,1,0,7},
                        {0,0,2,0,0,0,6,7,0} };
    memset(arr,-1,sizeof(int)*v);
    krus(graph);

    return 0;
}
