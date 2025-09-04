#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 1) Binary Search & Linear Search
int binarySearch(int arr[], int n, int x) {
    int l=0, r=n-1;
    while(l<=r) {
        int mid=l+(r-l)/2;
        if(arr[mid]==x) return mid;
        if(arr[mid]<x) l=mid+1;
        else r=mid-1;
    }
    return -1;
}
int linearSearch(int arr[], int n, int x) {
    for(int i=0;i<n;i++) if(arr[i]==x) return i;
    return -1;
}

// 2) Bubble Sort
void bubbleSort(int arr[], int n) {
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(arr[j]>arr[j+1]) {
                int t=arr[j]; arr[j]=arr[j+1]; arr[j+1]=t;
            }
}

// 3) Missing Number in Sorted Array
int missingNumber(int arr[], int n) {
    for(int i=0;i<n-1;i++) {
        if(arr[i+1]!=arr[i]+1) return arr[i]+1;
    }
    return -1;
}

// 4a) Concatenate
void concat(char a[], char b[]) {
    strcat(a,b);
}
// 4b) Reverse
void reverse(char s[]) {
    int n=strlen(s);
    for(int i=0;i<n/2;i++) {
        char t=s[i]; s[i]=s[n-i-1]; s[n-i-1]=t;
    }
}
// 4c) Delete vowels
void delVowels(char s[]) {
    int i,j=0;
    for(i=0;s[i];i++) {
        if(strchr("aeiouAEIOU",s[i])==NULL) s[j++]=s[i];
    }
    s[j]='\0';
}
// 4d) Sort strings
void sortStrings(char arr[][100], int n) {
    for(int i=0;i<n-1;i++) {
        for(int j=i+1;j<n;j++) {
            if(strcmp(arr[i],arr[j])>0) {
                char t[100];
                strcpy(t,arr[i]); strcpy(arr[i],arr[j]); strcpy(arr[j],t);
            }
        }
    }
}
// 4e) Upper to Lower
void toLowercase(char s[]) {
    for(int i=0;s[i];i++) if(s[i]>='A' && s[i]<='Z') s[i]+=32;
}

// 5) Efficient Storage – Representations
// Diagonal, Tri-diagonal, Lower, Upper, Symmetric stored in 1D arrays
int diagIndex(int i,int j) { return (i==j)?i: -1; }
int triDiagIndex(int i,int j,int n) {
    if(abs(i-j)>1) return -1;
    return 2*i + (j-i+1);
}
int lowerTriIndex(int i,int j) {
    if(i>=j) return i*(i+1)/2+j;
    return -1;
}
int upperTriIndex(int i,int j,int n) {
    if(i<=j) return i*n - i*(i+1)/2 + (j-i);
    return -1;
}
int symIndex(int i,int j) {
    if(i>=j) return i*(i+1)/2+j;
    else return j*(j+1)/2+i;
}

// 6) Sparse Matrix using triplet
typedef struct { int row,col,val; } Element;
typedef struct { int m,n,num; Element *e; } Sparse;

Sparse createSparse(int m,int n,int num) {
    Sparse s; s.m=m; s.n=n; s.num=num;
    s.e=(Element*)malloc(num*sizeof(Element));
    return s;
}
Sparse transpose(Sparse s) {
    Sparse t=createSparse(s.n,s.m,s.num);
    int k=0;
    for(int i=0;i<s.n;i++) {
        for(int j=0;j<s.num;j++) {
            if(s.e[j].col==i) {
                t.e[k].row=s.e[j].col;
                t.e[k].col=s.e[j].row;
                t.e[k].val=s.e[j].val;
                k++;
            }
        }
    }
    return t;
}
Sparse addSparse(Sparse a, Sparse b) {
    Sparse c=createSparse(a.m,a.n,a.num+b.num);
    int i=0,j=0,k=0;
    while(i<a.num && j<b.num) {
        if(a.e[i].row<b.e[j].row || (a.e[i].row==b.e[j].row && a.e[i].col<b.e[j].col)) c.e[k++]=a.e[i++];
        else if(b.e[j].row<a.e[i].row || (b.e[j].row==a.e[i].row && b.e[j].col<a.e[i].col)) c.e[k++]=b.e[j++];
        else { c.e[k]=a.e[i]; c.e[k++].val=a.e[i++].val+b.e[j++].val; }
    }
    while(i<a.num) c.e[k++]=a.e[i++];
    while(j<b.num) c.e[k++]=b.e[j++];
    c.num=k; return c;
}
Sparse multiplySparse(Sparse a,Sparse b) {
    Sparse c=createSparse(a.m,b.n,a.num*b.num);
    int k=0;
    for(int i=0;i<a.num;i++) {
        for(int j=0;j<b.num;j++) {
            if(a.e[i].col==b.e[j].row) {
                c.e[k].row=a.e[i].row;
                c.e[k].col=b.e[j].col;
                c.e[k].val=a.e[i].val*b.e[j].val;
                k++;
            }
        }
    }
    c.num=k; return c;
}

// 7) Count Inversions
int merge(int arr[], int l, int m, int r) {
    int n1=m-l+1, n2=r-m;
    int L[n1],R[n2];
    for(int i=0;i<n1;i++) L[i]=arr[l+i];
    for(int j=0;j<n2;j++) R[j]=arr[m+1+j];
    int i=0,j=0,k=l,count=0;
    while(i<n1 && j<n2) {
        if(L[i]<=R[j]) arr[k++]=L[i++];
        else { arr[k++]=R[j++]; count+=n1-i; }
    }
    while(i<n1) arr[k++]=L[i++];
    while(j<n2) arr[k++]=R[j++];
    return count;
}
int mergeSort(int arr[], int l, int r) {
    int count=0;
    if(l<r) {
        int m=(l+r)/2;
        count+=mergeSort(arr,l,m);
        count+=mergeSort(arr,m+1,r);
        count+=merge(arr,l,m,r);
    }
    return count;
}

// 8) Count Distinct Elements
int countDistinct(int arr[], int n) {
    int c=0;
    for(int i=0;i<n;i++) {
        int f=0;
        for(int j=0;j<i;j++) if(arr[i]==arr[j]) { f=1; break; }
        if(!f) c++;
    }
    return c;
}

int main() {
    int arr[]={64,34,25,12,22,11,90}; int n=7;
    bubbleSort(arr,n);
    for(int i=0;i<n;i++) printf("%d ",arr[i]);
    return 0;
}
