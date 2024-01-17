/**
 * @file
 * @brief Implementation of [Saddleback Algorithm](https://www.geeksforgeeks.org/saddleback-search-algorithm-in-a-2d-array) for 2D arrays.
 *
 * @details
 * Saddleback Algorithm is an algorithm that searches 2D array in linear time,
 * i.e, O(m + n), where m is number of rows and n is number of columns of 2D array. Also, each row and
 * column of the matrix should be sorted beforehand for this algorithm to work.
 *
 * sorting a 2D array is done with complexity of O( n*logn )
 * @author [Hashir Niazi](https://github.com/HashirGJ8842)
 */

#include<iostream>
#include<vector>

/**
 * This function implements [Saddleback Algorithm](https://www.geeksforgeeks.org/saddleback-search-algorithm-in-a-2d-array),
 * on a sorted 2D array, and finds the location of the element needed to search
 * @param matrix 2D matrix which is sorted on the basis of rows and columns
 * @param element element to be searched
 * @return An std::pair of with row and column populated within it, if the
 * element is present.
 * @return An std::pair with (0, 0), if the element is not present.
 * @Timecomplexity -> O (m+n)
 */

std::pair<int ,int> saddleback_search(std::vector<std::vector<int>> input_mat,int element){
    int left_index = 0;
    int right_index = input_mat[0].size()-1;

    while(left_index < input_mat[0].size()){
        if (element == input_mat[left_index][right_index]){
            return std::make_pair(left_index+1,right_index+1);
        } else if (element > input_mat[left_index][right_index]){
            ++left_index;
        } else if (element < input_mat[left_index][right_index]){
            if (!right_index){
                break;
            }else {
                --right_index;
            }
        }
    }
    return std::make_pair(0,0);
}

int main(){
     std::vector<std::vector<int>> matrix = {{1, 10, 100, 1000, 10000},
                                            {2, 20, 200, 2000, 20000},
                                            {3, 30, 300, 3000, 30000},
                                            {4, 40, 400, 4000, 40000},
                                            {5, 50, 500, 5000, 50000}};
    std::pair<int,int> ans1 = saddleback_search(matrix,300);
    std::cout << ans1.first << " " << ans1.second <<std::endl;

}