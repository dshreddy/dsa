#include <bits/stdc++.h>
using namespace std;

// for range update and point query

template<class T>
class SegmentTree{
public:
	/*
		Note : follows 0 based indexing
	*/

	int n;
	vector<T> a;

	SegmentTree() : n(0){}
	SegmentTree(int sz) : a(4 * n, 0), n(sz){}
	SegmentTree(const vector<T> &v){
		this->n = v.size();
		a.resize(4 * n, 0);
		build(1, 0, n - 1, v);
	}

	// TC : O(n log(n))
	void build(int p, int l, int r, const vector<T> &v){
		if(l == r){
			a[p] = v[l];
		}
		else{
			int m = (l + r) / 2;
			build(2 * p, l, m, v);
			build(2 * p + 1, m + 1, r, v);
			a[p] = 0;
		}
		return;
	}

	// TC : O(log n)
	T find_val_at(int p, int l, int r, int pos){
		if(l == r) {
			return a[p];
		}
		else{
			int m = (l + r) / 2;
			if(pos <= m){
				return a[p] + find_val_at(2 * p, l, m, pos);
			}
			else{
				return a[p] + find_val_at(2 * p + 1, m + 1, r, pos);
			}
		}
	}
	T find_val_at(int pos){
		return find_val_at(1, 0, n - 1, pos);
	}

	// TC : O(log n)
	void update(int p, int l, int r, int x, int y, T val){
		if(y < l || x > r){
			return;
		}
		else if(l >= x && y >= r){
			a[p] += val;
		}
		else if(l == r) return;
		else{
			int m = (l + r) / 2;
			update(2 * p, l, m, x, y, val);
			update(2 * p + 1, m + 1, r, x, y, val);
		}
	}

	void update_in_range(int l, int r, T val){
		return update(1, 0, n - 1, l, r, val);
	}
};

int main(){
	
	vector<int> v = {1,2,3,4,4,5,6};
	int n = v.size();
	SegmentTree<int> tree(v);

	cout << "Values without update : \n";
	for(int i = 0; i < n; i++){
		cout << tree.find_val_at(i) << ' ';
	}
	cout << '\n';

	tree.update_in_range(0, 3, 4);
	cout << "Update values are : \n";
	for(int i = 0; i < n; i++){
		cout << tree.find_val_at(i) << ' ';
	}
	cout << '\n';
}