#include<iostream>
#include<queue>
using namespace std;

#define LT(a,b) (a<b)

struct node{
    int num;
    node* next;

    node():num(0),next(nullptr){}
};

struct head{
    int edg;
    bool visited;
    node* first;
    head* next;

    head():edg(0),visited(false),first(nullptr),next(nullptr){}
};

class graph{
public:
    int n,m;
    head* g;

    graph(){
        cin>>n>>m;
        g = new head[n+1];
        for(int i=1;i<=m;i++){
            int u,v;
            cin>>u>>v;
            if(g[u].first == nullptr){
                g[u].visited = false;
                g[u].first = new node;
                g[u].first->num = v;
                g[u].edg = 1;
            }else{
                node* p = g[u].first;
                while(p->next!= nullptr){
                    p = p->next;
                }
                p->next = new node;
                p->next->num = v;
                g[u].edg+=1;
            }
        }
    }

    void clear(){
        for (int i = 1; i <= n; i++) {
            g[i].visited = false;
        }
        cout<<endl;
    }

    void sort(){
        node *p, *q;
        bool swapped;
        for(int i = 1;i <= n; i++){
            if(g[i].edg == 0 || g[i].edg == 1) continue;
            g[0].first = g[i].first;
            while(true){
                p = g[0].first;
                swapped = false;
                while(p->next != nullptr){
                    q = p->next;
                    if(LT(q->num,p->num)){
                        swap(p->num,q->num);
                        swapped = true;
                    }
                    p = q;
                }
                if(!swapped) break;
            }
        }
    }

    void dfs(int u){
        cout<<u<<" ";
        g[u].visited = true;
        node* p = g[u].first;
        while(p != nullptr){
            if(!g[p->num].visited){
                dfs(p->num);
            }
            p = p->next;
        }
    }

    void bfs(int u){
        queue<int> Q;
        node* p;
        Q.push(u);
        g[u].visited = true;
        while(!Q.empty()){
            int v = Q.front();
            Q.pop();
            cout<<v<<" ";
            p = g[v].first;
            while(p!= nullptr){
                if(!g[p->num].visited){
                    Q.push(p->num);
                    g[p->num].visited = true;
                }
                p = p->next;
            }
        }
    }
};

int main(){
    graph* g = new graph();
    g->sort();
    g->dfs(1);
    g->clear();
    g->bfs(1);
    delete g;
    return 0;
}
