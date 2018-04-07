/   Runtime:3ms/
//  main.cpp
//  E118PascalTriangle
//
//  Created by MA YADI on 2018/1/10.
//  Copyright © 2018年 MA YADI. All rights reserved.
//

#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> vres;
        if(numRows==0)
            return vres;
        
        vector<int> vrow1;
        vrow1.push_back(1);
        vres.push_back(vrow1);
        if(numRows==1)
            return vres;
        
        for(int i=1; i<=numRows-1; i++){
            vector<int> vrow;
            vrow.push_back(1);
            for(int j=1; j<i; j++){
                vrow.push_back(vres[i-1].at(j-1)+vres[i-1].at(j));
            }
            vrow.push_back(1);
            vres.push_back(vrow);
        }
        
        return vres;
    }
    
    void printVector(vector<vector<int>> v,int n) {
        for (int i = 0; i < n; i++) {
            vector<int> a = v.at(i);
            for (int j = 0; j < a.size()-1; j++) {
                cout << a.at(j) << " ";
            }
            cout << a.at(a.size()-1) << endl;
        }
        return;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    vector<vector<int>> v;
    string line;
    while(getline(cin, line)){
        int m = stringToInteger(line);
        v = s.generate(m);
        int n = v.size();
        s.printVector(v, n);
    }
    return 0;
}

