//https://www.hackerrank.com/challenges/prettyprint/problem?isFullScreen=true
#include <iostream>
#include <iomanip> 
#include <unordered_map>
using namespace std;

/*
sample input 
1  
100.345 2006.008 2331.41592653498
*/

int main() {
	int T; cin >> T;
	cout << setiosflags(ios::uppercase);
	cout << setw(0xf) << internal;
	while(T--) 
    {
		double A; cin >> A;
		double B; cin >> B;
		double C; cin >> C;

		/* Enter your code here */
        
        cout <<hex<<left <<showbase<<nouppercase<<(long long)A<<endl;
        
        cout << setprecision(2) << setw(15) << right << showpos << fixed << setfill('_') << B << endl;
        
        cout<<setprecision(9)<<uppercase<<scientific<<noshowpos<<C<<endl;
	}
}
