#include <iostream>
#include <vector>

using std::vector;
using std::pair;

vector<bool> visited;
vector<bool> recStack;
bool flag = false;

bool iscyclic_util(vector<vector<int> > &adj, int v){
	if(visited[v] == false){
		visited[v] = true;
		recStack[v] = true;

		vector<int>::iterator i;
		for(i = adj[v].begin(); i != adj[v].end(); ++i){
			if(!visited[*i] && iscyclic_util(adj, *i))
				return true;
			else if(recStack[*i])
				return true;
		}
	}
	recStack[v] = false;
	return false;
}

int acyclic(vector<vector<int> > &adj) {
	for(int i = 0; i < adj.size(); i++){
		if(iscyclic_util(adj, i))
			return true;
	}
	return 0;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  visited.resize(n, 0);
  recStack.resize(n, 0);
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  std::cout << acyclic(adj);
}
