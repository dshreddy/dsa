#include<bits/stdc++.h>
using namespace std;

class HashSet
{
private:
    int size = 991;
    vector<int> arr[991];
    int hash(int key) { return key%size; }
public:

    HashSet() { }

    void add(int key)
    {
        int index = hash(key);

        for(int i=0; i<arr[index].size(); i++) if(arr[index][i]==key) return;
        arr[index].push_back(key);
    }

    bool contains(int key)
    {
        int index = hash(key);

        for(int i=0; i<arr[index].size(); i++) if(arr[index][i]==key) return true;
        return false;
    }

    void remove(int key)
    {
        int index = hash(key);

        for(int i=0; i<arr[index].size(); i++) 
        {
            if(arr[index][i]==key) 
            {
                arr[index].erase(arr[index].begin()+i);
                return;
            }
        }
    }
};

int main()
{
    HashSet s;

    s.add(1);
    s.add(2);
    s.add(3);

    cout<<s.contains(1)<<endl;
    cout<<s.contains(4)<<endl;

    s.remove(1);
    cout<<s.contains(1)<<endl;
}