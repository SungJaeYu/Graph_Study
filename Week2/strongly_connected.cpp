#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>

using std::vector;
using std::stack;

vector<bool> visited;

void ordering(vector<vector<int> > adj, stack<int> &order, int v){
	visited[v] = true;
	vector<int>::iterator i;
	for(i = adj[v].begin(); i != adj[v].end(); ++i){
		if(!visited[*i])
			ordering(adj, order, *i);
	}
	order.push(v);
}


void dfs_util(vector<vector<int> > adj, int v){
	visited[v] = true;
	vector<int>::iterator i;
	for(i = adj[v].begin(); i != adj[v].end(); ++i){
		if(!visited[*i])
			dfs_util(adj, *i);
	}
}

void transpos(vector<vector<int> > adj, vector<vector<int> > &adj_T){
	for(int v = 0; v < adj.size(); ++v){
		vector<int>::iterator i;
		for(i = adj[v].begin(); i != adj[v].end(); ++i){
			adj_T[*i].push_back(v);
		}
	}
	return;
}

int number_of_strongly_connected_components(vector<vector<int> > adj) {
  int result = 0;
  stack<int> order;
  for(int i = 0; i < adj.size(); ++i){
	  if(visited[i] == false)
		ordering(adj, order, i);
  }

  for(int i = 0; i < adj.size(); ++i)
	  visited[i] = false;
  
  vector<vector<int> > adj_T(adj.size(), vector<int>());
  transpos(adj, adj_T);

  while(order.empty() == false){
	  int v = order.top();
	  order.pop();

	  if(visited[v] == false){
		  dfs_util(adj_T, v);
		  result++;
	  }
  }
  return result;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  visited.resize(n);
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  std::cout << number_of_strongly_connected_components(adj);
}
