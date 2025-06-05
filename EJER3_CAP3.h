#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

void constantTime() { int a=5,b=a+10; cout<<"O(1): "<<b<<'\n'; }

bool binarySearch(const vector<int>& v,int t) {
    int l=0,r=(int)v.size()-1;
    while(l<=r) {
        int m=(l+r)/2;
        if(v[m]==t) return true;
        else if(v[m]<t) l=m+1; else r=m-1;
    }
    return false;
}

bool hasDivisor(int n) {
    for(int i=2;i<=sqrt(n);i++) if(n%i==0) return true;
    return false;
}

int sumArray(const vector<int>& v) {
    int s=0; for(int x:v) s+=x; return s;
}

void sortArray(vector<int>& v) { sort(v.begin(),v.end()); }

void printPairs(const vector<int>& v) {
    cout<<"O(n^2) pairs:\n";
    for(int i=0;i<(int)v.size();i++)
        for(int j=0;j<(int)v.size();j++)
            cout<<"("<<v[i]<<","<<v[j]<<") ";
    cout<<'\n';
}

void printTriplets(const vector<int>& v) {
    cout<<"O(n^3) triplets:\n";
    for(int i=0;i<(int)v.size();i++)
        for(int j=0;j<(int)v.size();j++)
            for(int k=0;k<(int)v.size();k++)
                cout<<"("<<v[i]<<","<<v[j]<<","<<v[k]<<") ";
    cout<<'\n';
}

void printSubsets(const vector<int>& v,int i=0,vector<int> s={}) {
    if(i==(int)v.size()) {
        cout<<"{";
        for(int j=0;j<(int)s.size();j++) cout<<s[j]<<(j+1==(int)s.size()?"":" ");
        cout<<"}\n";
        return;
    }
    printSubsets(v,i+1,s);
    s.push_back(v[i]);
    printSubsets(v,i+1,s);
}

void printPermutations(vector<int>& v,int start=0) {
    if(start==(int)v.size()-1) {
        cout<<"{";
        for(int i=0;i<(int)v.size();i++) cout<<v[i]<<(i+1==(int)v.size()?"":" ");
        cout<<"}\n";
        return;
    }
    for(int i=start;i<(int)v.size();i++) {
        swap(v[start],v[i]);
        printPermutations(v,start+1);
        swap(v[start],v[i]);
    }
}

int main() {
    vector<int> arr={1,2,3,4};

    constantTime();

    cout<<"O(log n) binary search 3: "<<(binarySearch(arr,3)?"Found":"Not Found")<<'\n';

    cout<<"O(sqrt n) divisor of 29: "<<(hasDivisor(29)?"Yes":"No")<<'\n';

    cout<<"O(n) sum array: "<<sumArray(arr)<<'\n';

    vector<int> toSort={4,3,1,2};
    sortArray(toSort);
    cout<<"O(n log n) sorted: ";
    for(int x:toSort) cout<<x<<' ';
    cout<<'\n';

    printPairs({1,2,3});
    printTriplets({1,2,3});

    cout<<"O(2^n) subsets:\n";
    printSubsets({1,2,3});

    cout<<"O(n!) permutations:\n";
    vector<int> perm={1,2,3};
    printPermutations(perm);

    return 0;
}

