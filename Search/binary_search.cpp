#include<algorithm>
#include<iostream>
#include<vector>

int binary_search(const std::vector<int> &arr,int val){
    int low = 0;
    int high  = arr.size()-1;

    while (low<=high)
    {
        int m = low + (high-low)/2;
        if (val == arr[m]){
            return m;
        }
        else if (val <  arr[m]){
            high =m-1;
        }else {
            low = m+1;
        }
    }
    return -1;
}

//  * Worst-case time complexity	O(log n)
//  * Best-case time complexity	O(1)
//  * Average time complexity	    O(log n)
//  * Worst-case space complexity  0(1)




int main(){

}