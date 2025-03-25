#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class graph{
public:
	int V ;
	vector<vector<pair<int, int>>>adjList
	
	Graph(int V) {
        this->V = V;
        adjList.resize(V);
    }
    void addedge(int u, int v, int weight){
    	adjList[u].pushback({v, wieght});
    	adjList[v].pushback({u, wieght});
    	}
    void display(){
    	cout<<"Adjacency Matrix:\n";
    	for (int i=0; i<v ; i++){
    		for(int j=0; j<v; j++){
    		 cout<<adjMatrix[i][j] << " ";}
    		 cout<<endl;
    		 }
    	}
    	
    bool isconnected(){
    	vector<bool> visited(v, False);
    	queue <int> q;
    	q.push(0);
    	visited[0]=true;
    	
    	
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
                for (auto &neighbor : adjList[node]) {
                if (!visited[neighbor.first]) {
                    visited[neighbor.first] = true;
                    q.push(neighbor.first);
                }
            }
        }

        for (int i = 0; i < V; i++) {
            if (!visited[i]) return false;
        }
        return true;
    }
    void primsMST() {
        vector<int> parent(V, -1);
        vector<int> key(V, INT_MAX);
        vector<bool> inMST(V, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        key[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            inMST[u] = true;

            for (int v = 0; v < V; v++) {
                if (adjMatrix[u][v] != 0 && !inMST[v] && adjMatrix[u][v] < key[v]) {
                    key[v] = adjMatrix[u][v];
                    pq.push({key[v], v});
                    parent[v] = u;
                }
            }
        }

        cout << "Prim's MST: \n";
        for (int i = 1; i < V; i++) {
            cout << parent[i] << " - " << i << " with weight " << key[i] << endl;
        }
    }
        void kruskalsMST() {
        vector<pair<int, pair<int, int>>> edges;
        for (int u = 0; u < V; u++) {
            for (int v = u + 1; v < V; v++) {
                if (adjMatrix[u][v] != 0) {
                    edges.push_back({adjMatrix[u][v], {u, v}});
                }
            }
        }

        sort(edges.begin(), edges.end());

        vector<int> parent(V), rank(V, 0);
        for (int i = 0; i < V; i++) parent[i] = i;

        auto find = [&](int u) {
            if (parent[u] != u) parent[u] = find(parent[u]);
            return parent[u];
        };

        auto unionSets = [&](int u, int v) {
            int root_u = find(u);
            int root_v = find(v);
            if (root_u != root_v) {
                if (rank[root_u] > rank[root_v]) {
                    parent[root_v] = root_u;
                } else if (rank[root_u] < rank[root_v]) {
                    parent[root_u] = root_v;
                } else {
                    parent[root_v] = root_u;
                    rank[root_u]++;
                }
            }
        };

        cout << "Kruskal's MST: \n";
        for (auto &edge : edges) {
            int u = edge.second.first;
            int v = edge.second.second;
            int weight = edge.first;
            if (find(u) != find(v)) {
                cout << u << " - " << v << " with weight " << weight << endl;
                unionSets(u, v);
            }
        }
    }
}; 
int main (){
 	int V, v, u ,weight;
 	
 	cout<< "Enter the Number of Cities : ";
 	cin>>V;
 	Graph g(V);
 	
 	do{
 	cout<<"------------MENU------------"\n;
 	cout<<"1. Add Edge in Graph\n";
 	cout<<"2. Display Adjacent Matrix\n";
 	cout<<"3. is graph connected\n";
 	cout<<"4. Run Prism Algorithm\n";
 	cout<<"5. Run Kruskals Algorithm\n";
 	cout<<"6. Exit\n";
 	cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the cities (vertices) and weight of the flight (time/fuel): ";
            cin >> u >> v >> weight;
            g.addEdge(u, v, weight);
            break;
        case 2:
            g.displayAdjMatrix();
            break;
        case 3:
            if (g.isConnected()) {
                cout << "Graph is connected\n";
            } else {
                cout << "Graph is not connected\n";
            }
            break;
        case 4:
            g.primsMST();
            break;
        case 5:
            g.kruskalsMST();
            break;
        case 6:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice, try again.\n";
        }
    } while (choice != 6);

    return 0;
}
 	
 		
    	
    	
    	
    	
    
	
	
