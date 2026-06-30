#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;

    cout << "=====================================\n";
    cout << " PROGRAM DIJKSTRA (SINGLE PATH)\n";
    cout << "=====================================\n";

    cout << "Masukkan jumlah node : ";
    cin >> n;

    cout << "Masukkan jumlah edge : ";
    cin >> m;

    vector< vector< pair<int,int> > > graph(n + 1);

    cout << "\nMasukkan data edge (asal tujuan bobot)\n";

    for(int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        graph[u].push_back(make_pair(v, w));
        graph[v].push_back(make_pair(u, w)); //hapus jika graph berarah
    }

    int start, tujuan;

    cout << "\nMasukkan node awal : ";
    cin >> start;

    cout << "Masukkan node tujuan : ";
    cin >> tujuan;

    vector<int> dist(n + 1, INT_MAX);
    vector<int> parent(n + 1, -1);

    priority_queue< pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;

    dist[start] = 0;
    pq.push(make_pair(0, start));

    while(!pq.empty())
    {
        int jarak = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if(jarak > dist[node])
            continue;

        for(int i = 0; i < graph[node].size(); i++)
        {
            int next = graph[node][i].first;
            int weight = graph[node][i].second;

            if(dist[node] + weight < dist[next])
            {
                dist[next] = dist[node] + weight;
                parent[next] = node;
                pq.push(make_pair(dist[next], next));
            }
        }
    }

    if(dist[tujuan] == INT_MAX)
    {
        cout << "\nTidak ada jalur.\n";
        return 0;
    }

    vector<int> path;

    int current = tujuan;

    while(current != -1)
    {
        path.push_back(current);
        current = parent[current];
    }

    reverse(path.begin(), path.end());

    cout << "\n=====================================\n";
    cout << "Shortest distance from node "
         << start << " to node "
         << tujuan << " = "
         << dist[tujuan] << endl;

    cout << "Path : ";

    for(int i = 0; i < path.size(); i++)
    {
        cout << path[i];

        if(i != path.size() - 1)
            cout << " -> ";
    }

    cout << endl;
    cout << "=====================================\n";

    return 0;
}
