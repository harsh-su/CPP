#include<iostream>
#include<cassert>
#include<algorithm>
#include<vector>

/*
median of median is an approximate median selection aglorithm frequtnly used as a good pivot for an exact selection algorithm most commoly quicksort -
->O(n) time 
quicksort -> slects kth smallest element of an initally unsorted array 

good linking for studying why its imp
-> https://rcoh.me/posts/linear-time-median-finding/
*/

void print_arr(const std::vector<int> &m){
    int n = m.size();
    for (int i=0;i<n;i++){
        std::cout << m[i] << " "; 
    }
    std::cout << std::endl;
}

int median_of_medians(const std::vector<int> &arr , const int& idx){
    int pivot  = 0;
    std::vector<int> a(arr.begin(),arr.end());
    std::vector<int> m;

    int sz = a.size();
    for (int i =0;i<sz;i+=5){
        std::sort(a.begin()+i,a.begin()+std::min(sz,i+5));
        int mid  = (i+std::min(sz,i+5))/2;
        m.push_back(a[mid]);
    }

    int m_sz = int(m.size());
    if(m_sz <= 5){
        std::sort(m.begin(),m.end());
        pivot = m[(m_sz -1)/2];

    }else {
        pivot = median_of_medians(m,idx);
    }

    std::vector<int> low ;
    std::vector<int> high;

    for(int i=0;i<sz;i++){
        if (a[i]<pivot){
            low.push_back(a[i]);
        }else if (a[i] > pivot){
            high.push_back(a[i]);
        }
    }

    int k = int(low.size());
    if (idx < k) {
        return median_of_medians(low,idx);

    }else if (idx > k) {
        return median_of_medians(high,idx-k-1);
    }else {
        return pivot;
    }
}

int main(){
    std::vector<int> A{5,3,6,4,2,8,3,8,34,0};
	int kth = 4;
    //finding the kth smallesst elemnt 
    std::cout << median_of_medians(A,kth) << std::endl ; 

}