#include "solution.h"

void Graph::BFS(int root, std::map <int, int> &distance, std::map <int, std::vector <int>> &path) {
  std::map <int, int> marks;
  std::map <int, int> pred;
  std::queue<int> q;

  if (edge_map_.empty())
    return;

  for (auto it = edge_map_.begin(); it != edge_map_.end(); it++) {
    pred[it->first] = -1;
    distance[it->first] = INT32_MAX;
  }

  q.push(root);
  marks[root] = 1;
  distance[root] = 0;

  while (!q.empty()) {
    int cur = q.front();
    q.pop();

    for (auto &n : edge_map_[cur]) {
      if (!marks[n]) {
        marks[n] = 1;
        distance[n] = distance[cur] + 1;
        pred[n] = cur;
        q.push(n);
      }
    }
  }

  for (unsigned int i = 0; i < pred.size(); i++) {
    int current = i;
    while (current != 0) {
      path[i].push_back(current);
      current = pred[current];
    }
    
    path[i].push_back(current);
  }

}