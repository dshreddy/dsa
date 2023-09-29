#include <bits/stdc++.h>
using namespace std;

// helps to solve range queries with sqrt n complexity
// also known as Moo's algorithm

template <class T>
class sqDecompose{
public:
    vector<T> v;
    vector<T> a;
    int k;
    sqDecompose(vector<T> vec){
        int n = vec.size();
        k = sqrt(n) + 1;
        v.resize(n);
        a.resize(k);
        for(int i = 0; i < n; i++){
            v[i] = vec[i];
            a[i/k] += vec[i];
        }
    }

    // TC : O(sqrt(n))
    bool update(int j, T val){
        int b = j / k;
        a[b] -= v[j];
        a[b] += val;
        v[j] = val;
        return 1;
    }

    // TC : O(sqrt(n))
    T sumRange(int l, int r){
        // sum in range [l,..,r], inclusive
        T ans = 0;
        for(int i = l; i <= r;){
            if(i % k == 0 && i + k - 1 <= r){
                ans += a[i/k];
                i += k;
            }
            else{
                ans += v[i];
                i++;
            }
        }
        return ans;
    }
};

int main(){
	
	vector<int> v = {1,1,1,4,4,5,6};
	int n = v.size();
	sqDecompose<int> model(v);
    
	cout << "Values without update are : \n";
    cout << model.sumRange(0,2) << '\n';

	model.update(0, 5);
	model.update(1, 6);

	cout << "Updated values are : \n";
    cout << model.sumRange(0,2) << '\n';
}