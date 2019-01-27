#include <vector>
#include <iostream>


using namespace std;
template <typename T>
using matrix = std::vector<vector<int>>;

matrix
makeMatrix(int n, int m){
    return matrix(n, vector<int> (m));
}

void printMatrix(const matrix M){
    int row = M.size();
    for (int i = 0; i < row;++i){
        for(auto j:M.at(i))
            cout << j << " ";
        cout << endl;
    }
}

matrix
matrix_chain_order(const vector<int> p){
    int n = p.size() - 1;
    matrix m = makeMatrix(n + 1, n + 1);
    matrix s = makeMatrix(n, n);// just use the [1:n-1 , 2:n]
    
    int q;

    for (int l = 2; l <= n; ++l)
        for (int i = 1; i <= n - l+1;++i){
            int j = i + l - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k < j;++k){
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if(q<m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    

}

int main(){
    vector<int> p{30, 35, 15, 5, 10, 20, 25};
    matrix m = makeMatrix(n + 1, n + 1);
    printMatrix(m);
    return 0;
}