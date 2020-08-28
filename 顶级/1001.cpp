#include<iostream>
#include "vector"
#include "algorithm"
using namespace std;
int m,n;
int MAX = 9999999;

struct Edge{
    int u,v,w,c;
};

vector<int>root;
vector<int>root_size;


bool cmp(Edge& e1,Edge& e2){
    return e1.w < e2.w;
}

int find_root(int u){
    while(root[u] != u){
        u = root[u];
    }
    return u;
}

void connect(int u,int v){
    if(root_size[u] < root_size[v]){
        root_size[v] += root_size[u];
        root[u] = v;
    }else{
        root_size[u] += root_size[v];
        root[v] = u;
    }
}


void minTree(vector<Edge> usedEdges,vector<Edge> brokenEdges){
    sort(brokenEdges.begin(),brokenEdges.end(),cmp);
    vector<int>costs = vector<int>(n+1,0);
    int max_val = 0;
    for(int i=1;i<=n;i++){
        for(int k=1;k<=n;k++){
            root[k] = k;
            root_size[k] = 1;
        }
        int part_nums = n-1;
        for(Edge e : usedEdges){
            if(e.u == i || e.v == i){
                continue;
            }
            int parent_u = find_root(e.u);
            int parent_v = find_root(e.v);
            if(parent_u != parent_v){
                connect(parent_v,parent_u);
                part_nums -= 1;
            }
        }
        for(Edge e : brokenEdges){
            if(e.u == i || e.v == i){
                continue;
            }
            int parent_u = find_root(e.u);
            int parent_v = find_root(e.v);
            if(parent_u != parent_v){
                connect(parent_v,parent_u);
                costs[i] += e.w;
                part_nums -= 1;
            }
        }
        if(part_nums > 1){
            costs[i] = MAX;
        }
        max_val = max(costs[i],max_val);
    }
    if(max_val > 0){
        bool flag = true;
        for(int i=1;i<=n;i++){
            if(costs[i] == max_val){
                if(flag){
                    flag = false;
                    cout<<i;
                }else{
                    cout<<" "<<i;
                }

            }
        }
    }else{
        cout<<0;
    }
}










int main(){
//    n =4;
//    m = 5;
//    int arr[] = {1,2,1,1,1,3,1,1,2,3,1,0,2,4,1,1,3,4,1,0};
    cin>>n>>m;
    root = vector<int>(n+1,0);
    root_size = vector<int>(n+1,1);
    vector<Edge> usedEdges;
    vector<Edge> brokenEdges;
    for(int i=0;i<m;i++){
        Edge edge =  Edge();
//        edge.u = arr[i*4];
//        edge.v = arr[i*4+1];
//        edge.w = arr[i*4+2];
//        edge.c = arr[i*4+3];
        cin>>edge.u>>edge.v>>edge.w>>edge.c;
        if(edge.c == 0){
            brokenEdges.push_back(edge);
        }else{
            usedEdges.push_back(edge);
        }
    }
    minTree(usedEdges,brokenEdges);

}