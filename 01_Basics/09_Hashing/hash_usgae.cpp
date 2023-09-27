#include<bits/stdc++.h>
using namespace std;

int main() {

    vector<string> names;

    names.push_back("alice");
    names.push_back("bad");
    names.push_back("collin");
    names.push_back("brad");
    names.push_back("dylan");
    names.push_back("kim");

    unordered_map<string, int> countMap;

    for (string& name: names) 
    {
        if(countMap.count(name) == 0) countMap[name] = 1;
        else countMap[name]++;
    }
    return 0;
    /*
    SUGGESTED PROBLEMS
    https://leetcode.com/problems/contains-duplicate/
    https://leetcode.com/problems/two-sum/
    https://leetcode.com/problems/lru-cache/
    */
}
