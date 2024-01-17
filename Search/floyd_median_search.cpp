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

//definition for singly-linked list 

struct ListNode {
    int val{0};
    ListNode * next{nullptr};
    ListNode() = default;
    explicit ListNode(int x) : val(x) {}
    ListNode(int x,ListNode * next) : val(x),next(next){}

};

//functiont o seach for the median of linked list 
ListNode* middleNode(ListNode* head){
    if (!head){
        return nullptr;
    }

    ListNode* fastptr = nullptr;
    ListNode* slowptr = fastptr = head;

    while(fastptr->next && fastptr->next->next){

        std::cout << slowptr->val << fastptr->val << std::endl;
        slowptr = slowptr->next;
        fastptr = fastptr->next->next;
    }

    return (fastptr->next) ? slowptr->next :slowptr;
}

static void test() {
    auto* head1 = new ListNode;
    head1->val = 1;

    ListNode* temp = head1;
    for (int i = 2; i < 6; ++i) {
        // Allocate next
        auto* temp1 = new ListNode;
        temp1->val = i;

        // Advance
        temp->next = temp1;
        temp = temp1;
    }
    temp->next = nullptr;

    ListNode* median = middleNode(head1);
    assert(3 == median->val);  // 3 is the value of the median node.
    std::cout << "test case:1 passed\n";

    // Test case # 2
    auto* head2 = new ListNode;
    head2->val = 1;

    ListNode* temp2 = head2;
    for (int i = 2; i < 7; ++i) {
        // Allocate next
        auto* temp3 = new ListNode;
        temp3->val = i;

        // Advance
        temp2->next = temp3;
        temp2 = temp3;
    }
    temp2->next = nullptr;

    ListNode* median1 = middleNode(head2);
    assert(4 == median1->val);  // 4 is the value of the median node.
    std::cout << "test case:2 passed\n";

    delete head1;
    delete temp;

    delete head2;
    delete temp2;

    std::cout << "--All tests passed--\n";
}

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main() {
    test();  // run self-test implementations
    return 0;
}