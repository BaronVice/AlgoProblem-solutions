#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    vector <vector<pair<int, int>>> office(n+1, vector<pair<int, int>>(m+1));

    for (int i = 0; i <= n; i++)
        office[i][0] = pair<int, int>(0, 0);
    for (int j = 0; j <= m; j++)
        office[0][j] = pair<int, int>(0, 0);

    int result = 4;
    string s;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        for (int j = 1; j <= m; j++)
            if (s[j-1] == '0'){
                pair <int, int> current_pair;

                if (office[i-1][j].first > office[i][j-1].second){
                    current_pair.first = office[i-1][j].first + 1;
                    current_pair.second = office[i-1][j].second;
                }
                else{
                    current_pair.first = office[i][j-1].first;
                    current_pair.second = office[i][j-1].second + 1;
                }


                if (office[i-1][j].first == 0)
                    current_pair.first = 1;
                if (office[i][j-1].first == 0)
                    current_pair.second = 1;

                // if(office[i-1][j].first + office[i-1][j].second > office[i][j-1].first + office[i][j-1].second){
                //     current_pair.first = (1 + office[i-1][j].first);
                //     current_pair.second = (max(1, office[i-1][j].second));
                // }
                // else{
                //     current_pair.first = (max(1, office[i][j-1].first));
                //     current_pair.second = (1 + office[i][j-1].second);
                // }


                
                result = max(result, 2 * current_pair.first + 2 * current_pair.second);

                office[i][j] = current_pair;
            }
            else
                office[i][j] = pair<int, int>(0, 0);
    }

    for (auto row : office){
        for (auto p : row){
            cout << '|' << p.first << ' ' << p.second << '|' << "     " ;
        }
        cout << '\n';
    }

    cout << result << '\n';

    return 0;
}