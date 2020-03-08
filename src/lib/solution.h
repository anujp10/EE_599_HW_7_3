#ifndef TEMPLATE_SOLUTION_H
#define TEMPLATE_SOLUTION_H

#include <unordered_set>
#include <string>
#include <vector>
#include <map>
#include <queue>

class Graph {
public:
  Graph(std::map<int, std::unordered_set<int>> &vertices) : edge_map_(vertices) {}
  std::map <int, std::unordered_set<int>> edge_map_;

  void BFS(int root, std::map <int, int> &distance, std::map <int, std::vector <int>> &path);
};

#endif