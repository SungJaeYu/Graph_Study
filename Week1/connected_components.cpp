#include <iostream>
#include <vector>

using std::vector;
using std::pair;

void explore(vector<vector<int> > &adj, vector<bool> &visit, int x){
	visit[x] = true;
	for(int i = 0; i < adj[x].size(); ++i){
		int w = adj[x][i];
		if(!visit[w])
			explore(adj, visit, w);
	}
}

int number_of_components(vector<vector<int> > &adj, vector<bool> &visit) {
  int res = 0;
  for(int i = 0; i < adj.size(); ++i){
	  if(!visit[i]){
		  res++;
		  explore(adj, visit, i);
	  }
  }
  return res;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<bool> visit(n);
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << number_of_components(adj, visit);
}
