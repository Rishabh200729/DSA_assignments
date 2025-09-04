#include <stdio.h>
#include <stdlib.h>

// 1) Menu Driven Array Operations
int arr[100], n=0;

void create() {
    printf("Enter number of elements: ");
    scanf("%d",&n);
    printf("Enter elements: ");
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
}
void display() {
    for(int i=0;i<n;i++) printf("%d ",arr[i]);
    printf("\n");
}
void insert() {
    int pos,val;
    printf("Enter position and value: ");
    scanf("%d%d",&pos,&val);
    for(int i=n;i>pos;i--) arr[i]=arr[i-1];
    arr[pos]=val; n++;
}
void delete() {
    int pos;
    printf("Enter position: ");
    scanf("%d",&pos);
    for(int i=pos;i<n-1;i++) arr[i]=arr[i+1];
    n--;
}
void linearSearch() {
    int x,f=0;
    printf("Enter element to search: ");
    scanf("%d",&x);
    for(int i=0;i<n;i++) if(arr[i]==x){printf("Found at %d\n",i); f=1;}
    if(!f) printf("Not found\n");
}

// 2) Remove Duplicates
void removeDuplicates() {
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;) {
            if(arr[i]==arr[j]) {
                for(int k=j;k<n-1;k++) arr[k]=arr[k+1];
                n--;
            } else j++;
        }
    }
}

// 3) Predict Output
void predictOutput() {
    int i;
    int arr2[5]={1};
    for(i=0;i<5;i++) printf("%d",arr2[i]);
    printf("\n");
}

// 4a) Reverse Array
void reverseArray() {
    for(int i=0;i<n/2;i++) {
        int t=arr[i]; arr[i]=arr[n-i-1]; arr[n-i-1]=t;
    }
}

// 4b) Matrix Multiplication
void matrixMultiply() {
    int a[10][10],b[10][10],c[10][10],r1,c1,r2,c2;
    printf("Enter rows and cols of matrix A: ");
    scanf("%d%d",&r1,&c1);
    printf("Enter rows and cols of matrix B: ");
    scanf("%d%d",&r2,&c2);
    if(c1!=r2){printf("Not possible\n"); return;}
    printf("Enter A:\n");
    for(int i=0;i<r1;i++) for(int j=0;j<c1;j++) scanf("%d",&a[i][j]);
    printf("Enter B:\n");
    for(int i=0;i<r2;i++) for(int j=0;j<c2;j++) scanf("%d",&b[i][j]);
    for(int i=0;i<r1;i++) for(int j=0;j<c2;j++){c[i][j]=0; for(int k=0;k<c1;k++) c[i][j]+=a[i][k]*b[k][j];}
    printf("Result:\n");
    for(int i=0;i<r1;i++){for(int j=0;j<c2;j++) printf("%d ",c[i][j]); printf("\n");}
}

// 4c) Transpose
void transposeMatrix() {
    int a[10][10],t[10][10],r,c;
    printf("Enter rows and cols: ");
    scanf("%d%d",&r,&c);
    printf("Enter matrix:\n");
    for(int i=0;i<r;i++) for(int j=0;j<c;j++) scanf("%d",&a[i][j]);
    for(int i=0;i<r;i++) for(int j=0;j<c;j++) t[j][i]=a[i][j];
    printf("Transpose:\n");
    for(int i=0;i<c;i++){for(int j=0;j<r;j++) printf("%d ",t[i][j]); printf("\n");}
}

// 5) Sum of Rows and Columns
void sumRowsCols() {
    int a[10][10],r,c;
    printf("Enter rows and cols: ");
    scanf("%d%d",&r,&c);
    printf("Enter matrix:\n");
    for(int i=0;i<r;i++) for(int j=0;j<c;j++) scanf("%d",&a[i][j]);
    for(int i=0;i<r;i++){int sum=0; for(int j=0;j<c;j++) sum+=a[i][j]; printf("Row %d sum=%d\n",i,sum);}
    for(int j=0;j<c;j++){int sum=0; for(int i=0;i<r;i++) sum+=a[i][j]; printf("Col %d sum=%d\n",j,sum);}
}

int main() {
    int ch;
    while(1) {
        printf("\n1.CREATE\n2.DISPLAY\n3.INSERT\n4.DELETE\n5.LINEAR SEARCH\n6.REMOVE DUPLICATES\n7.PREDICT OUTPUT\n8.REVERSE ARRAY\n9.MATRIX MULTIPLY\n10.TRANSPOSE\n11.ROW/COL SUM\n12.EXIT\n");
        scanf("%d",&ch);
        switch(ch) {
            case 1:create();break;
            case 2:display();break;
            case 3:insert();break;
            case 4:delete();break;
            case 5:linearSearch();break;
            case 6:removeDuplicates();break;
            case 7:predictOutput();break;
            case 8:reverseArray();break;
            case 9:matrixMultiply();break;
            case 10:transposeMatrix();break;
            case 11:sumRowsCols();break;
            case 12:exit(0);
        }
    }
    return 0;
}
