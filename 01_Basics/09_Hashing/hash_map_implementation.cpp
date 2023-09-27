#include<bits/stdc++.h>
using namespace std;

class MyHashMap
{
private:

    int size = 991;

    vector<pair<int,int> > arr[991];

    int hash(int key) { return key%size; }

public:

    MyHashMap() {}

    void put(int key, int val)
    {
        int index = hash(key);

        for(int i=0; i<arr[index].size(); i++)
        {
            if(arr[index][i].first == key)
            {
                arr[index][i].second = val;
                return;
            }
        }

        pair<int,int> p = make_pair(key,val);
        arr[index].push_back(p);
    }

    int get(int key)
    {
        int index = hash(key);

        for(int i=0; i<arr[index].size(); i++)
        {
            if(arr[index][i].first == key)
            {
                return arr[index][i].second;
            }
        }
        return -1;
    }

    void remove(int key)
    {
        int index = hash(key);

        for(int i=0; i<arr[index].size(); i++)
        {
            if(arr[index][i].first == key)
            {
                arr[index].erase(arr[index].begin()+i);
            }
        }
    }
};

int main()
{
    MyHashMap m;
    m.put(1,2);
    m.put(1,3);
    cout<<m.get(1)<<endl;
    m.remove(1);
    cout<<m.get(1)<<endl;
    //SUGGESTED PROBLEMS https://leetcode.com/problems/design-hashmap/
}
