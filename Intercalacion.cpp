#include <bits/stdc++.h>
#include <sys/time.h>
//Libreria chrono para c++11
#include <chrono>
using namespace std;

///--- GENERAR ARRAY

void generateArray(int arr[], int num)
{
    srand(time(NULL));

    for(int a=0; a<num; a++)
    {
        arr[a] = 1 + rand() % (num);
    }
}

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}


///--- MERGE SORT

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{

    if (l < r)
    {
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

///-----INSERTION SORT
void inter_Sort(int A[],int p,int q,int r)
{
    int B[r];
    for (int i=p;i<=q;i++)
    {
        B[i]=A[i];
    }
    for (int j=q;j<=r;j++)
    {
        B[r+q-j]=A[j];
    }
    int i=p;
    int j=r;
    for (int k=p;k<=r;k++)
    {
        if(B[i]<=B[j])
        {
            A[k]=B[i];
            i++;
        }
        else{
            A[k]=B[j];
            j--;
        }
    }
}
///---MEDIR TIEMPO

int getTime_inter(int arr[],int n,int mitad,int num)
{
    auto start = std::chrono::high_resolution_clock::now();

    inter_Sort(arr,n,mitad,num);

    auto finish = std::chrono::high_resolution_clock::now();
    int Ftime=std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count();
    return Ftime;


}

int getTime_merge(int arr[],int l , int n)
{
    auto start = std::chrono::high_resolution_clock::now();

    mergeSort(arr,l,n);

    auto finish = std::chrono::high_resolution_clock::now();
    int Ftime=std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count();
    return Ftime;


}

int main()
{
    int num=100;

    int arr[num];
    int mitad=num/2;

    for (int i=0;i<num;i++)
    {
        if(i>=mitad)
        {
            arr[i]=i-mitad;

        }
        else
        {
            arr[i]=i+mitad;
        }
    }
    cout<<getTime_inter(arr,0,mitad,num);


    return 0;

}



