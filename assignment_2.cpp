#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

// 1. Binary Search
int binarySearch(vector<int>& arr, int key) {
    int l=0, r=arr.size()-1;
    while(l<=r) {
        int mid=(l+r)/2;
        if(arr[mid]==key) return mid;
        else if(arr[mid]<key) l=mid+1;
        else r=mid-1;
    }
    return -1;
}

// 2. Bubble Sort
void bubbleSort(vector<int>& arr) {
    int n=arr.size();
    for(int i=0;i<n-1;i++) {
        for(int j=0;j<n-i-1;j++) {
            if(arr[j]>arr[j+1]) swap(arr[j],arr[j+1]);
        }
    }
}

// 3. Missing number in sorted array
int findMissing(vector<int>& arr) {
    for(int i=0;i<arr.size()-1;i++) {
        if(arr[i+1]-arr[i]>1) return arr[i]+1;
    }
    return -1;
}

// 4. String programs
string concat(string a, string b){ return a+b; }
string reverseStr(string s){ reverse(s.begin(), s.end()); return s; }
string removeVowels(string s){
    string res="";
    for(char c: s){
        if(string("aeiouAEIOU").find(c)==string::npos) res+=c;
    }
    return res;
}
void sortStrings(vector<string>& v){ sort(v.begin(), v.end()); }
char toLowerChar(char c){ return tolower(c); }

// 5. Efficient matrix storage - example using diagonal matrix
class DiagonalMatrix {
    vector<int> diag;
public:
    DiagonalMatrix(int n){ diag.resize(n); }
    void set(int i,int j,int val){ if(i==j) diag[i]=val; }
    int get(int i,int j){ return (i==j)?diag[i]:0; }
};

// 6. Sparse matrix using triplet form
struct Triple{ int row,col,val; };
class SparseMatrix{
    int rows,cols;
    vector<Triple> data;
public:
    SparseMatrix(int r,int c):rows(r),cols(c){}
    void add(int r,int c,int v){ if(v!=0) data.push_back({r,c,v}); }
    void display(){
        for(auto &t:data) cout<<"("<<t.row<<","<<t.col<<","<<t.val<<") ";
        cout<<"\n";
    }
};

// 7. Count inversions
int countInversions(vector<int>& arr) {
    int n=arr.size(), inv=0;
    for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) if(arr[i]>arr[j]) inv++;
    return inv;
}

// 8. Count distinct elements
int countDistinct(vector<int>& arr) {
    set<int> s(arr.begin(),arr.end());
    return s.size();
}

int main(){
    // Example Runs
    vector<int> arr={64,34,25,12,22,11,90};
    bubbleSort(arr);
    cout<<"Bubble sorted: ";
    for(int x:arr) cout<<x<<" ";
    cout<<"\n";

    vector<int> arr2={1,2,3,5,6};
    cout<<"Missing number: "<<findMissing(arr2)<<"\n";

    string s="Hello";
    cout<<"Reversed: "<<reverseStr(s)<<"\n";
    cout<<"Without vowels: "<<removeVowels("beautiful")<<"\n";

    vector<string> v={"cat","apple","dog"};
    sortStrings(v);
    cout<<"Sorted strings: ";
    for(auto &st:v) cout<<st<<" ";
    cout<<"\n";

    vector<int> invArr={2,4,1,3,5};
    cout<<"Inversions: "<<countInversions(invArr)<<"\n";

    vector<int> dArr={1,2,2,3,4,4,5};
    cout<<"Distinct count: "<<countDistinct(dArr)<<"\n";

    return 0;
}
