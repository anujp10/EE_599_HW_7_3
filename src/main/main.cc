#include <iostream>
#include "src/lib/solution.h"

int main()
{
    std::map<int, std::unordered_set<int>> vertices = {{0, {1, 2, 5}},
                                                       {1, {0, 2, 3}},
                                                       {2, {0, 1, 3}},
                                                       {3, {1, 2, 4, 6}},
                                                       {4, {3}},
                                                       {5, {0}},
                                                       {6, {3}}};

    Graph g(vertices);
    std::map<int, int> distance;
    std::map<int, std::vector<int>> path;

    g.BFS(0, distance, path);

    std::cout << "Distance map" << std::endl;
    for (auto it = distance.begin(); it != distance.end(); it++)
    {
        std::cout << "(" << it->first <<", " << it->second << ") ";
    }
    std::cout << std::endl;

    std::cout << "Path map" << std::endl;
    for (unsigned int i = 0; i < path.size(); i++)
    {
        std::cout << i << ": ";
        for (auto it = path[i].rbegin(); it != path[i].rend(); it++)
        {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }

    return EXIT_SUCCESS;
}