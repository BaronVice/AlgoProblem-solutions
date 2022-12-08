#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main(){

    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;

    vector<vector<int>> trees(500, vector<int>(500));

    for (int q = 0; q < t; q++){
        int n, m, counter = 0;
        cin >> n >> m;

        char el;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++){
                cin >> el;
                if (el == '*'){
                    trees[i][j] = 1;
                    counter++;
                }
                else{
                    trees[i][j] = 0;
                }

            }

        for (int required_size = 1; required_size <= min(n, m); required_size++){
            for (int i = required_size; i < n; i++){
                for (int j = required_size; j < m - required_size; j++){
                    if (trees[i][j] >= 1){
                        if (trees[i-1][j] >= required_size &&
                            trees[i][j-1] >= required_size &&
                            trees[i][j+1] >= required_size)
                        {
                            
                            counter++;
                            trees[i][j] = required_size + 1;
                        }
                    }
                }
            }
        }
        
        cout << counter << '\n';
        
    }

    return 0;
}