#include <bits/stdc++.h>
using namespace std;
#define V 4

// implementation of traveling Salesman Problem
int travllingSalesmanProblem(int graph[][V], int s)
{
    // store all vertex apart from source vertex
    // сохранить всю вершину отдельно от исходной вершины
    vector<int> vertex;
    for (int i = 0; i < V; i++)
        if (i != s)
            vertex.push_back(i);

    // store minimum weight Hamiltonian Cycle.
    // сохранить минимальный вес гамильтонова цикла.
    int min_path = INT_MAX;
    do {

        // store current Path weight(cost)
        // сохранить текущий вес пути (стоимость)
        int current_pathweight = 0;

        // compute current path weight
        // вычисляем вес текущего пути
        int k = s;
        for (int i = 0; i < vertex.size(); i++) {
            current_pathweight += graph[k][vertex[i]];
            k = vertex[i];
        }
        current_pathweight += graph[k][s];

        // update minimum
        // обновить минимум
        min_path = min(min_path, current_pathweight);

    } while (next_permutation(vertex.begin(), vertex.end()));

    return min_path;
}
int main()
{
    // matrix representation of graph
    // матричное представление графа
    int graph[][V] = { { 0, 10, 15, 20 },
                       { 10, 0, 35, 25 },
                       { 15, 35, 0, 30 },
                       { 20, 25, 30, 0 } };
    int s = 0;
    cout <<"The cost of the tour is  "<<  travllingSalesmanProblem(graph, s) << endl;
    return 0;
}
