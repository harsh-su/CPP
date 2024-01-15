/**
 * @file
 * @brief Given a linked list L[0,....,n] of n numbers, find the middle node.
 *
 * @details The technique utilized in this implementation is the ["Floyd's
 * tortoise and
 * hare"](https://en.wikipedia.org/wiki/Cycle_detection#Floyd's_tortoise_and_hare)
 * approach. This technique uses two pointers that iterate through the list at
 * different 'speeds' in order to solve problems. In this implementation, for
 * every iteration the slow pointer advances one node while the fast pointer
 * advances two nodes. The result of this is that since the fast pointer moves
 * twice as fast as the slow pointer, when the fast pointer reaches the end of
 * the list the slow pointer will be pointing to the middle node of the list.
 *
 * Here are some example lists you can use to see how the algorithm works
 * A = [1,2,3,4,5]
 * B = [1,2,3,4,5,6]
 * print median(A) #should be 39
 * print median(B) #should be 4
 *
 * @author [Benjamin Weiss](https://github.com/weiss-ben)
 * @see median_search.cpp
 */

#include<cassert>
#include<iostream>

struct Listnode {
    int val{0};
    Listnode * next{nullptr};
    Listnode() = default;
    explicit Listnode(int x) : val(x) {}
    Listnode(int x,Listnode * next) : val(x),next(next){}
    
}