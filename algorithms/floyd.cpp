#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<int>> dist;
const int INF = 1e9;

void printSolution()
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                cout << "INF" << " ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
} 

void floyd(){
    int i, j, k;
 
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (dist[k][j] != INF && dist[i][k] != INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
 
    printSolution();
}
 

int main()
{
    cin >> n;
    
    floyd();

    return 0;
}

