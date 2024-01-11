#include<iostream>
#include<cassert>
#include<algorithm>
#include<vector>

/*
median of median is an approximate median selection aglorithm frequtnly used as a good qivot for an exact selection algorithm most commoly quicksort -
->O(n) time 
quicksort -> slects kth smallest element of an initally unsorted array 
*/

void print_arr(const std::vector<int> &m){
    int n = m.size();
    for (int i=0;i<n;i++){
        std::cout << m[i] <<std::endl; 
    }
}

int  median_of_median(const std::vector<int> &arr , const int& idx){
    int pivot  =0;
    std::vector<int> a(arr.begin(),arr.end());
    std::vector<int>m;

    int r = a.size();
    for (int i=0;i<r;i+=5){
        std::sort(a.begin()+i,a.begin()+std::min(r,i+5));
        int mid = (i+std::min(r,i+5))/2;
        m.push_back(a[mid]);
    }

    print_arr(m);

    int sz = int (m.size());
    if (sz <=5){
        std::sort(m.begin(),m.end());
        pivot = m[(sz -1) /2];
    }else {
        pivot  = median_of_median(m,idx);
    }

    std::vector<int> low ;
    std::vector<int> high;
    for(int i=0;i<r;i++){
        if(a[i] < pivot ){
            low.push_back(a[i]);
        }else if (a[i] > pivot){
            high.push_back(a[i]);
        }
    }
    int k = int(low.size());
    if (idx < k){
        return median_of_median(low,idx);
    }else if (idx > k) {
        return median_of_median(high,idx-k-1);
    }else{
        return pivot ;
    }
}

int main(){
    std::vector<int> A{25,21,98,100,76,22,43,60,89,87};
	int i = 3;
    median_of_median(A,6);

}