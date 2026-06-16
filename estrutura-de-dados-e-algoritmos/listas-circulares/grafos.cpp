#include <vector>
#include <queue>
#include <stack>
#include <iostream>

using namespace std;

class Grafo {
private:
    int V;
    // Cada vértice tem uma lista (vector) de vizinhos
    vector<vector<int>> adj; // adj[u] = lista de vértices adj.a, u
    
public:
    Grafo(int v) : V(v), adj(v) {};

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // Grafo não-direcionado
    }

    // BFS - usa FILA -> explora em largura (caminho mínimo)
    void bfs(int inicio) {
        vector<bool> visited(V, false);
        vector<int> dist(V, -1);
        queue<int> fila;    // <- aqui entra a FILA!
        
        visited[inicio] = true;
        dist[inicio]    = 0;
        fila.push(inicio);

        while (!fila.empty()) {
            int u = fila.front(); fila.pop();
            cout << u << "dist=" << dist[u] << ") ";
            for (int v : adj[u]) {
                if(!visited[v]) {
                    visited[v] = true;
                    dist[v]    = dist[u] + 1;
                    fila.push(v);   // enfileira vizinho não visitado
                }
            }
        }
    }

    // DFS iterativo - use PILHA -> explora em profundidade
    void dfs(int inicio) {
        vector<bool> visited(V, false);
        stack<int> pilha;       //<- aqui entra a PILHA

        while (pilha.empty()) {
            int u = pilha.top(); pilha.pop();
            if (!visited[u]) {
                visited[u] = true;
                cout << u << " ";
                for (int v : adj[u]) pilha.push(v);
            }
        }
    }
};