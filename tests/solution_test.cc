#include "src/lib/solution.h"
#include "gtest/gtest.h"
#include <vector>

TEST(BFSShould, BFSReturn) {
  std::map<int, std::unordered_set<int>> vertices = {{0, {1, 2, 5}},
                                                       {1, {0, 2, 3}},
                                                       {2, {0, 1, 3}},
                                                       {3, {1, 2, 4, 6}},
                                                       {4, {3}},
                                                       {5, {0}},
                                                       {6, {3}}};
  std::map<int, int> actual;
  std::map<int, std::vector<int>> path;
  Graph g(vertices);
  g.BFS(0, actual, path);
  std::map<int, int> expected = {{0, 0}, {1, 1}, {2, 1}, {3, 2}, {4, 3}, {5, 1}, {6, 3}};
  EXPECT_EQ(expected, actual);
}

TEST(BFSShould_1, BFSReturn_1) {
  std::map<int, std::unordered_set<int>> vertices = {{0, {1, 2, 5}},
                                                       {1, {0, 2, 3}},
                                                       {2, {0, 1, 3}},
                                                       {3, {1, 2, 4, 6}},
                                                       {4, {3}},
                                                       {5, {0}},
                                                       {6, {3}}};
  std::map<int, int> distance;
  std::map<int, std::vector<int>> actual;
  Graph g(vertices);
  g.BFS(0, distance, actual);
  std::map<int, std::vector<int>> expected =  {{0, {0}}, 
                                              {1, {1, 0}}, 
                                              {2, {2, 0}}, 
                                              {3, {3, 1, 0}}, 
                                              {4, {4, 3, 1, 0}}, 
                                              {5, {5, 0}}, 
                                              {6, {6, 3, 1, 0}}};
  EXPECT_EQ(expected, actual);
}

TEST(BFSShould_2, BFSReturn_2) {
  std::map<int, std::unordered_set<int>> vertices;
  std::map<int, int> actual;
  std::map<int, std::vector<int>> path;
  Graph g(vertices);
  g.BFS(0, actual, path);
  std::map<int, int> expected;
  EXPECT_EQ(expected, actual);
}

TEST(BFSShould_3, BFSReturn_3) {
  std::map<int, std::unordered_set<int>> vertices;
  std::map<int, int> distance;
  std::map<int, std::vector<int>> actual;
  Graph g(vertices);
  g.BFS(0, distance, actual);
  std::map<int, std::vector<int>> expected;
  EXPECT_EQ(expected, actual);
}