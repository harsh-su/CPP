/**
 * Binary insertion sort employs a
 * binary search to determine the correct location to insert new elements, and
 * therefore performs ⌈log2 n⌉ comparisons in the worst case. When each element
 * in the array is searched for and inserted this is O(n log n). The algorithm
 * as a whole still has a running time of O(n2) on average because of the series
 * of swaps required for each insertion
 * 
 * 
*/

#include<iostream>
#include<algorithm>
#include<cassert>
#include<vector>





template <class T>
int binary_search(std::vector<T> &arr, T val, int low, int high) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == val) {
            return mid;
        } else if (arr[mid] < val) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return low;
}

template<typename T>
void binary_insertion_sort(std::vector<T> &arr){
    int n = arr.size();

    for (int i =0;i<n;i++){
        T key = arr[i];
        int j = i -1;
        int location = binary_search(arr,key,0,j);
        while (j >=location)
        {
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = key;
        
    }
}

// /**
//  * @brief Self-test implementations
//  * @returns void
//  */
// static void test() {
//     /* descriptions of the following test */
//     /* 1st test:
//        [5, -3, -1, -2, 7] returns [-3, -2, -1, 5, 7] */
//     std::vector<int64_t> arr1({5, -3, -1, -2, 7});
//     std::cout << "1st test... ";
//     binary_insertion_sort(arr1);
//     assert(std::is_sorted(std::begin(arr1), std::end(arr1)));
//     std::cout << "passed" << std::endl;

//     /* 2nd test:
//        [12, 26, 15, 91, 32, 54, 41] returns [12, 15, 26, 32, 41, 54, 91] */
//     std::vector<int64_t> arr2({12, 26, 15, 91, 32, 54, 41});
//     std::cout << "2nd test... ";
//     binary_insertion_sort(arr2);
//     assert(std::is_sorted(std::begin(arr2), std::end(arr2)));
//     std::cout << "passed" << std::endl;

//     /* 3rd test:
//        [7.1, -2.5, -4.0, -2.1, 5.7] returns [-4.0, -2.5, -2.1, 5.7, 7.1] */
//     std::vector<float> arr3({7.1, -2.5, -4.0, -2.1, 5.7});
//     std::cout << "3rd test... ";
//     binary_insertion_sort(arr3);
//     assert(std::is_sorted(std::begin(arr3), std::end(arr3)));
//     std::cout << "passed" << std::endl;

//     /* 4th test:
//        [12.8, -3.7, -20.7, -7.1, 2.2] returns [-20.7, -7.1, -3.7, 2.2, 12.8] */
//     std::vector<float> arr4({12.8, -3.7, -20.7, -7.1, 2.2});
//     std::cout << "4th test... ";
//     binary_insertion_sort(arr4);
//     assert(std::is_sorted(std::begin(arr4), std::end(arr4)));
//     std::cout << "passed" << std::endl;
// }

/**
 * @brief Main function
 * @return 0 on exit.
 */

template <typename T>
void print_arr(const std::vector<T> &arr){
    for (const auto& item : arr){
        std::cout << item <<" ";
    }
    std::cout << std::endl;
}


int main() {
    std::vector<int64_t> arr1({5, -3, -1, -2, 7});
    std::cout << "1st test... ";
    binary_insertion_sort(arr1);
    print_arr(arr1);
    
}