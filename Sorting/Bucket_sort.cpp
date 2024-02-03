/**
 * Bucket sort assumes that the input is drawn from a uniform distribution.
 * Bucket sort can be exceptionally fast because of the way elements are 
 * assigned to buckets, typically using an array where the index is the 
 * value.This means that more auxiliary memory is required for the buckets 
 * at the cost of running time than more comparison sorts.
 * The average time complexity for Bucket Sort is O(n + k). The worst time 
 * complexity is O(n²) and space complexity for Bucket Sort is O(n+k).
 * 
 * Information taken from (https://medium.com/karuna-sehgal/an-introduction-to-bucket-sort-62aa5325d124)
*/


#include<iostream>
#include<algorithm>
#include<vector>

template <typename T>
void bucket_sort(std::vector<T> &arr, int n){
    
    std::vector<std::vector<T>> bucket(n) ;
    for (int i=0;i<int(n);i++){
        int bucket_index = n * arr[i];
        bucket[bucket_index].push_back(arr[i]);
    }

    for (int i=0;i<n;i++) std::sort(bucket[i].begin(),bucket[i].end());

    int index = 0;
    for(int i=0;i<int(n);i++){
        for (int j=0;j<bucket[i].size();j++){
            arr[index++]= bucket[i][j];
        }
    }
}

int main() {
    std::vector<float> arr = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    int n = arr.size();
    bucket_sort(arr, n);

    std::cout << "Sorted array is \n";
    for (int i = 0; i < n; i++) std::cout << arr[i] << " ";
    std::cout << std::endl;
    return 0;
}