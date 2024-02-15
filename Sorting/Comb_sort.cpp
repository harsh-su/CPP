/**
 * Working form Bubble sort the COMB_SORT improves on bubble sort by 
 * eliminating the turtules that are the small values at the end of the list * which pose problem for bubble sort 
 (* 
 * in bubble sort the gap for comparing values is 1 but for comb sort 
 * it decreasing  sequncntially (for each iteration of outer loop) by a      * factor -> shrink factor 
 * worst case -> O(n*n)
 * best case -> O On*logn)
 *  
*/

#include<algorithm>
#include<cassert>
#include<iostream>
#include<vector>

/*finding the nxt gap by shrinking the current gap by shrink factor of 1.3 */
int findnxtgap(int gap){
    gap = (gap *10) /13;
    return std::max(1,gap);
}

void combsort( std::vector<int> &arr , int l ,int r){
    int gap = r;
    bool swapped = true ; //for intializing the loop

    while (gap !=1 || swapped)
    {
        gap = findnxtgap(gap);
        swapped =false;
        //
        for (int i=0;i<=r-gap;i++){
            if (arr[i] > arr[i+gap]){
                std::swap(arr[i],arr[i+gap]);
                swapped=true;
            }
        }
    }
    

}


int main(){
    std::vector<int> arr1 = {34, 56, 6, 23, 76, 34, 76, 343, 4, 76};
    combsort(arr1, 0, 9);
    assert(std::is_sorted(std::begin(arr1),std::end(arr1)));
    std::cout << "Test 1 passed\n";
}