#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    map<string, vector<string> > graph;

    // Membuat graph sesuai gambar
    graph["Cibinong"].push_back("Cileubeut");
    graph["Cileubeut"].push_back("Tanah Sareal");
    graph["Tanah Sareal"].push_back("Bogor Tengah");
    graph["Bogor Tengah"].push_back("Tajur");

    graph["Cibinong"].push_back("Bogor Utara");
    graph["Bogor Utara"].push_back("Baranangsiang");
    graph["Baranangsiang"].push_back("Tajur");

    string awal = "Cibinong";
    string tujuan = "Tajur";

    queue<string> q;
    map<string, bool> visited;
    map<string, string> parent;

    q.push(awal);
    visited[awal] = true;

    // BFS mencari jalur terpendek
    while (!q.empty())
    {
        string sekarang = q.front();
        q.pop();

        for (int i = 0; i < graph[sekarang].size(); i++)
        {
            string tetangga = graph[sekarang][i];

            if (!visited[tetangga])
            {
                visited[tetangga] = true;
                parent[tetangga] = sekarang;
                q.push(tetangga);
            }
        }
    }

    // Cek apakah tujuan ditemukan
    if (!visited[tujuan])
    {
        cout << "Jalur tidak ditemukan!" << endl;
        return 0;
    }

    // Menyusun jalur
    vector<string> path;
    string current = tujuan;

    while (current != awal)
    {
        path.push_back(current);
        current = parent[current];
    }

    path.push_back(awal);

    reverse(path.begin(), path.end());

    cout << "Jalur Terpendek Wildan dari Cibinong ke Tajur :" << endl;

    for (int i = 0; i < path.size(); i++)
    {
        cout << path[i];

        if (i < path.size() - 1)
        {
            cout << " -> ";
        }
    }

    cout << endl;
    cout << "Jumlah langkah : " << path.size() - 1 << endl;

    return 0;
}
