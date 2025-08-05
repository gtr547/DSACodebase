// Given an array ‘arr of integer numbers, ‘ar[i]’ represents the number of pages in the ‘i-th’ book. 
// There are a ‘m’ number of students, and the task is to allocate all the books to the students.
// Allocate books in such a way that:

//     Each student gets at least one book.
//     Each book should be allocated to only one student.
//     Book allocation should be in a contiguous manner.

// You have to allocate the book to ‘m’ students such that the maximum number of pages assigned to a student is minimum. 
// If the allocation of books is not possible. return -1


#include <bits/stdc++.h>
using namespace std;

// helper function
int cntStud(vector<int>& arr, int pages){
    int n = arr.size();
    int stud = 1, studpageCnt = 0;

    for (int  i = 0; i < n; i++)
    {
        if(studpageCnt + arr[i] <= pages){
            studpageCnt += arr[i];
        }
        else
        {
            stud ++;
            studpageCnt = arr[i];
        }
    }
    return stud;
    
}

// naive approach using linear search - O((sum - max + 1)*N)
int bookAllocation(vector<int>& arr, int k){

    if (arr.size() < k)
    {
        return -1;
    }
    

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);

    for (int i = low; i <= high; i++)
    {
        if(cntStud(arr, i) == k) return i;
    }
    return -1;
}

int main() {
    // Write your code here
    vector<int> arr;
    
    int n = 0;

    while (true)
    {
        cin>>n;

        if(n != -1){
            arr.push_back(n);
        }
        else break;
    }
    
    int k = 0;
    cin>>k;
    
    cout<<bookAllocation(arr, k);

    return 0;
}