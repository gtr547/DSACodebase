// Given two sorted arrays arr1 and arr2 of size n and m, find the intersection of both the arrays

#include <bits/stdc++.h>
using namespace std;

// void common(vector<int>& arr1, vector<int>& arr2){
//     int n = arr1.size(), m = arr2.size();

//     list<int> result;

//     // check if an element has already been matched, avoids duplicates.
//     int visited[m] = {0};


//     // iterate over the elements of the first array(arr1)
//     for (int i = 0; i < n; i++)
//     {
//         // for each elem in arr1, check all the elements of arr2
//         for (int j = 0; j < m; j++)
//         {
//             // if both the arrays has an matching element, and its not been added to the result list 
//             if (arr1[i] == arr2[j] && visited[j] == 0)
//             {
//                 // adds to the result and updates the visited array
//                 result.push_back(arr1[i]);
//                 visited[j] = 1;
//                 break;
//             }
//             // since both the arrays are sorted if arr2[j] becomes greater than arr1[i], no need to check for further 
//             if(arr2[j] > arr1[i]) break;
            
//         }
        
//     }
    

//     for (auto i : result)
//     {
//         cout<<" "<<i;
//     }

// }


// optimal approach 
void common(vector<int>& arr1, vector<int>& arr2){
    int n = arr1.size(), m = arr2.size();

    list<int> result;

    int i = 0, j = 0;

    while (i<n && j<m)
    {
        if (arr1[i]==arr2[j])
        {
            if (result.empty() || result.back()!=arr1[i])
            {
                result.push_back(arr1[i]);

            }
            i++;
            j++;
        }
        else if (arr1[i]<arr2[j])
        {
            i++;
        }
        else if (arr1[i]>arr2[j])
        {
            j++;
        }
    }
    
    

    for (auto i : result)
    {
        cout<<" "<<i;
    }

}

int main() {
    // Write your code here
    vector<int> arr1;
    vector<int> arr2;
    
    int n = 0;

    while (true)
    {
        cin>>n;

        if(n != -1){
            arr1.push_back(n);
        }
        else break;
    }

    n = 0;

    while (true)
    {
        cin>>n;
        
        if (n!=-1)
        {
            arr2.push_back(n);
        }
        else break;        
    }


    common(arr1, arr2);
    
    
    return 0;
}