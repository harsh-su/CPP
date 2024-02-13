/**
 * To sort an array with 0 ,1 and 2 in a single passs 
 * time complexity -> O(n)
 * 
*/

#include<algorithm>
#include<cassert>
#include<iostream>
#include<vector>

template <typename T>
std::vector<T> dnfsort(const std::vector<T> &in_arr){
    std::vector<T> arr(in_arr);
    int lo = 0;
    int hi = arr.size()-1;
    int mid =0;
    
    /*iterating through all elements */
    while (mid <= hi)
    {   
        switch (arr[mid])
        {
        case 0:
            std::swap(arr[lo++],arr[mid++]);
            break;
        case 1:
            mid++;
            break;
        case 2:
            std::swap(arr[mid],arr[hi--]);
            break;
        }
    }

    return arr;
    
}

int main(){
     std::vector<int> array2 = {1, 0, 0, 1, 1, 0, 2, 1};
    std::cout << "Test 2... ";
    std::vector<int> arr2 = dnfsort(array2);
    assert(std::is_sorted(std::begin(arr2), std::end(arr2)));
    std::cout << "passed" << std::endl;
}