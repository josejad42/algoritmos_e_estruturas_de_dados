#include<iostream>
#include<queue>
#include<stack>

using namespace std;

class Graph{
    public:
    int **matrix;
    int numEdge;
    int *mark;
    int n;

    Graph(int nv){
        n = nv;
        matrix = new int*[n];
        for (int i = 0; i < n; i++) {
            matrix[i] = new int[n];
            for (int j = 0; j < n; j++) {
                matrix[i][j] = 0;
            }
        }

        mark = new int[n];
        for(int i = 0; i<n; i++){
            mark[i] = 0;
        }
        numEdge = 0;
    }

    ~Graph() {
        for (int i = 0; i<n; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
        delete[] mark;
    }

    int nv(){
        return n;
    }

    int e(){
        return numEdge;
    }

    int first(int v){
        for(int i = 0; i<n; i++){
            if(matrix[v][i]) return i;
        }
        return n;
    }

    int next(int v, int w){
        for(int i = w+1; i<n; i++){
            if(matrix[v][i]) return i;
        }
        return n;
    }

    void setEdge(int i, int j, int wt){
        if(matrix[i][j] == 0) numEdge++;
        matrix[i][j] = wt;
    } 

    void delEdge(int i, int j){
        if(matrix[i][j]) numEdge--;
        matrix[i][j] = 0;
    }

    int weight(int i, int j){
        return matrix[i][j];
    }

    bool isEdge(int i, int j){
        if(matrix[i][j]) return true;
        return false;
    }

    void setMark(int i, int val){
        mark[i] = val;
    }

    int getMark(int i){
        return mark[i];
    }

    void graphTraverse(){
        for(int i = 0; i<n; i++){
            if(getMark(i) == 0) BFS(i);
        }
    }

    void DFS(int v){
        cout << v << " ";
        setMark(v, 1);
        int w = first(v);
        while(w<n){
            if(getMark(w) == 0) DFS(w);
            w = next(v, w);
        }
    }

    void topological(int v, stack<int> s){
        setMark(v, 1);
        int w = first(v);
        while(w<n){
            if(getMark(w) == 0) topological(w, s);
            w = next(v, w);
        }
        s.push(v);
    }

    void BFS(int start){
        queue<int> Q;
        Q.push(start);
        setMark(start, 1);
        while(!Q.empty()){
            int v = Q.front();
            Q.pop();
            cout << v << " ";
            int w = first(v);
            while (w < n){
                if(getMark(w) == 0){
                    setMark(w, 1);
                    Q.push(w);
                }
                w = next(v, w);
            }
        }
    }

};


int main(){
    Graph grafo(5);
    grafo.setEdge(0, 4, 1);
    grafo.setEdge(0, 1, 1);
    grafo.setEdge(1, 3, 1); 
    grafo.setEdge(2, 4, 1);
    grafo.setEdge(3, 2, 1);
    grafo.setEdge(4, 1, 1);
    
    return 0;
}