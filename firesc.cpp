#include <bits/stdc++.h>

using namespace std;

class Graph
{
    long long int V;    // No. of vertices
 
    // Pointer to an array containing adjacency lists
    list<long long int> *adj;
 
    // A function used by DFS
    void DFSUtil(long long int v, bool visited[],long long int &captains){
    	visited[v] = true;
    	
    	captains++;
    	for(auto i = adj[v].begin(); i!= adj[v].end(); ++i){
    		if(!visited[*i]){    			
    			DFSUtil(*i, visited,captains);
    		}
    	}    	
    };

public:
	
    Graph(long long int V){
    	this->V = V;
    	adj = new list<long long int>[V];
    
    };   // Constructor

    void addEdge(long long int v, long long int w){
    	adj[v].push_back(w);
    	adj[w].push_back(v);
    };
    void connectedComponents(){
	    // Mark all the vertices as not visited
	    bool *visited = new bool[V];
	    for(long long int v = 0; v < V; v++)
	        visited[v] = false;
		long long int count = 0;
		long long int nComp = 0;	 
		long long int captains = 1;
	    for (auto v=0; v<V; v++){
	        if (visited[v] == false)
	        {	nComp = 0;
	            
	            DFSUtil(v, visited, nComp);
	            captains =((captains%1000000007)*(nComp%1000000007))%1000000007;	            
	 			count = ((count%1000000007) + 1)%1000000007;	            
	        }
	    }
	    cout<<count<<" "<<captains<<endl;
	}
};

int main(int argc, char const *argv[])
{
	int t,n,m,x,y;
	cin>>t;
	while(t--){
		cin>>n>>m;
		Graph g(n);
		//vector< vector<int> >matrix;
		//matrix.resize(n, vector<int>(n));
		for (int i = 0; i < m; ++i)
		{
			cin>>x>>y;
			//matrix[x-1][y-1] = matrix[y-1][x-1] = 1;
			g.addEdge(x-1,y-1);
		}
		g.connectedComponents();

		/*
		for(int i =0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				cout<<matrix[i][j]<<" ";
			}cout<<endl;
		}
		*/
		/*
		//std::vector<int> count(n) ;
		for(int i =0; i < n; ++i){
			for(int j = i; j < n; ++j){
				if(!matrix[i][j]){
					//no edge
					continue;
				}
				else{
					//cout<<"i"<<i+1<<"j"<<j+1;
					count[i]++;
					i=j;				
				}
			}
			cout<<count[i]<<"c"<<endl;
		}
		*/
	}
	return 0;
}