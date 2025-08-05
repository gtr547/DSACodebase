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
int cntStud(vector<int>& arr, int pages, int k){
    
    int stud = 1, studpageCnt = 0;

    for (int  i = 0; i < arr.size(); i++)
    {
        if(stud > k) return stud;

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
// int bookAllocation(vector<int>& arr, int k){

    // if (arr.size() < k)
    // {
    //     return -1;
    // }
    

//     int low = *max_element(arr.begin(), arr.end());
//     int high = accumulate(arr.begin(), arr.end(), 0);

//     for (int i = low; i <= high; i++)
//     {
//         if(cntStud(arr, i) == k) return i;
//     }
//     return -1;
// }

int bookAllocation(vector<int>& arr, int k){

     if (arr.size() < k) return -1;
    
    
    int low = *max_element(arr.begin(), arr.end());    
    int high = accumulate(arr.begin(), arr.end(), 0);
    
    // Insted of using STL function to find the "low" and "high", we can use a loop 
    // for(int book: arr){
    //     low = max(low, book);
    //     high += book;
    // }

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        
        if (cntStud(arr, mid, k) > k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }

    }
    return low ;
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


// note: This problem is similar to problems like "Painters Partition" ,"Minimum Page Alloacation" and "Split Array Largest Sum". So the same solution can be used.