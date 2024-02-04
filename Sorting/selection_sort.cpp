/**
 * Selection Sort -> basically divides the vector into two parts 
 *  left to right subvector sorted one and right to left unsorted 
 * basically pushing the sorted boundary to the right 
 * 
 * time complexity -> O(n2)
 * Space -> only O(1) variable size
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<cassert>

template <typename T>
std::vector<T> selection_sort(const std::vector<T> &arr,int len){
    std::vector<T> temp_array (arr.begin(),arr.end());

    for (int i=0;i<len;i++){
        int min = i;
        for (int j = i+1;j<len;j++){
            if ( temp_array[j] < temp_array[min]){
                min = j;
            }
        }
        /*IF any elemnt less then elemnt at min index is found then only 
            min != i will be true */
        if (min != i ){
            std::swap(temp_array[min],temp_array[i]);
        }
    }

    return temp_array;

}


int main(){
    std::vector<int> vector4 = {1, 9, 11, 546, 26, 65, 212, 14};
    int vector4size = vector4.size();
    std::vector<int> result_test4;
    result_test4 = selection_sort(vector4, vector4size);
    assert(std::is_sorted(result_test4.begin(), result_test4.end()));
    std::cout << "Passed" << std::endl;
}