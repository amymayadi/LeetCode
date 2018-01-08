#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v;
        for(int i = 0; i<numRows; i++) {
            vector<int> line;
            if(i == 0)
                line.push_back(1);
            else {
                line.push_back(1); // first col
                for(int j = 1; j < i; j++) {
                    line.push_back(v[i-1][j-1] + v[i-1][j]);
                } //for
                line.push_back(1); // last col
            } //else
        v.push_back(line);
        }
    return v;
    }
//    void generate(int row) {
//        int a[5][5] = {{0}};
//        for(int i = 0; i < 5; i++) {
//            for(int j = 0; j < 5; j++) {
//                a[i][0] = 1;
//                a[i][i] = 1;
//                if(i >= 2 && j > 0 && j < i) {
//                    a[i][j] = a[i-1][j-1] + a[i-1][j];
//                }
//            }
//        }
//        for(int l = 0; l < 5; l++) {
//            for(int m = 0; m < l; m++) {
//                if(a[l][m] != 0)
//                    cout << a[l][m] << ",";
//            }
//                cout << a[l][l] << endl;
//        }
//    }

    void printTriangle(vector< vector<int> > pt)
    {
        cout << "[" << endl;
        for(int i=0; i<(int)pt.size(); i++){
            for(int space=(pt.size()-i-1); space>=0; space--){
                cout << " ";
            }
            cout << "[";
            for(int j=0; j<(int)pt[i].size(); j++){
                cout << pt[i][j];
                if(j<(int)pt[i].size()-1){
                    cout << ",";
                }
            }
            cout << "]";
            if(i<(int)pt.size()-1){
                cout << ",";
            }
            cout << endl;
        }
        cout << "]" << endl;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main()
{
    string line;
    while(getline(cin,line)){
        int n = stringToInteger(line);
        vector<vector<int>> v;
        v = Solution().generate(n);
        Solution().printTriangle(v);
    }
    return 0;
}
