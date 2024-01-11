/*
-> for ordered list
a jump search or block search refers to a search algorithm for ordered lists. It works by first checking all items Lkm, where k ∈ N k\in \mathbb {N} and m is the block size, until an item is found that is larger than the search key. To find the exact position of the search key in the list a linear search is performed on the sublist L[(k-1)m, km].

The optimal value of m is √n, where n is the length of the list L. Because both steps of the algorithm look at, at most, √n items the algorithm runs in O(√n) time. This is better than a linear search, but worse than a binary search. The advantage over the latter is that a jump search only needs to jump backwards once, while a binary can jump backwards up to log n times. This can be important if jumping backwards takes significantly more time than jumping forward.

The algorithm can be modified by performing multiple levels of jump search on the sublists, before finally performing the linear search. For a k-level jump search the optimum block size ml for the l th level (counting from 1) is n(k-l)/k. The modified algorithm will perform k backward jumps and runs in O(kn1/(k+1)) time.

finding the index of x 
time -> O(√n) 
*/

#include<iostream>
#include<cmath>
#include<algorithm>


int jump_search(int arr[],int x,int n){
    //finding block size to be jumped 
    int step  = std::sqrt(n);

    //finding blk where element is present 
    int prev = 0;
    while(arr[std::min(step,n)-1] < x ){
        prev = step;
        step += std::sqrt(n);
        if (prev >= n)
        {
            return -1;
        }
    }
    //doing linear search on blk 
    while (arr[prev] < x)
    {
        prev++;
        if (prev == std::min(step,n)){
            return -1;
        }        
    }

    if (arr[prev] == x){
        return prev;
    }

    return -1;
    
}

int main() {
    int arr[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610};
    int x = 1;
    int n = sizeof(arr) / sizeof(arr[0]);

    // Find the index of 'x' using Jump Search
    int index = jump_search(arr, x, n);

    // Print the index where 'x' is located
    std::cout << "\nNumber " << x << " is at index " << index << "\n";
    return 0;
}
 