/**
 * @file
 * @brief Implementation of the [Sublist Search
 * Algorithm](https://www.geeksforgeeks.org/sublist-search-search-a-linked-list-in-another-list)
 * @details
 *
 * ### Algorithm
 *
 *  * Sublist search is used to detect a presence of one list in another list.
 *  * Suppose we have a single-node list (let's say the first list), and we
 *  want to ensure that the list is present in another list (let's say the
 * second list), then we can perform the sublist search to find it.
 *
 *  * For instance, the first list contains these elements: 23 -> 30 -> 41,
 *  and the second list contains these elements: 10 -> 15 -> 23 -> 30 -> 41
 *  -> 49. At a glance, we see that the first list presents in the second list.
 *
 * ### Working
 *
 *  * The sublist search algorithm works by comparing the first element
 *  of the first list with the first element of the second list.
 *  * If the two values don't match, it goes to the next element of the
 *  second list. It does this until the two values match.
 * 
 * checks for consequent elemnt in the list 
 *
 * @author [Nitin Sharma](https://github.com/foo290)
 */

#include<cassert>
#include <iostream>
#include<vector>


struct ListNode {
    int val{0};
    ListNode *next{nullptr};

    // Default constructor
    ListNode() = default;

    // Constructor with a single integer argument
    explicit ListNode(int x) : val(x) {}

    // Constructor with two arguments
    ListNode(int x, ListNode *next) : val(x), next(next) {}

    // Constructor to generate linked list from an array
    ListNode(const std::vector<int> &values) {
        ListNode *current = this; // Use 'this' pointer to keep track of the current node

        for (int value : values) {
					current->val = value; // Set the value of the current node
					if (!current->next && value != values.back()) {
							current->next = new ListNode(); // Create a new node if not the last element
					}
					current = current->next; // Move to the next node
        }
    }
};

// Helper function to print the linked list
void printLinkedList(ListNode *head) {
    while (head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

bool sublist_search(ListNode* sublist, ListNode*mainlist){
	if (sublist == nullptr || mainlist == nullptr){
		return false;
	}
	ListNode*targetptr = sublist;
	while (mainlist!= nullptr){
		ListNode*mainptr = mainlist;
		while (targetptr !=nullptr)
		{
			if (mainptr == nullptr){
				return false;
			} else if (mainptr->val == targetptr->val){
				targetptr = targetptr->next;
				mainptr = mainptr->next;
			} else{
				break;
			}
		}

		if (targetptr == nullptr){
			return true; //Means sublist has found 
		}

		targetptr = sublist; 
		mainlist = mainlist->next;

	}

	return false;

}




int main() {
    // Example usage: Creating a linked list from an array
    std::vector<int> mainlistData = { 2, 5, 6, 7, 8};  ///< Main list in which sublist is to be searched
    std::vector<int> sublistData = {6, 7};  ///< Sublist to be searched

    ListNode* main_ll = new ListNode(mainlistData);
    ListNode* sub_ll = new ListNode(sublistData);

    bool exists = sublist_search(sub_ll,main_ll);

    if (exists) {
        std::cout << "[TRUE] - sublist found in main list\n";
    } else {
        std::cout << "[FALSE] - sublist NOT found in main list\n";
    }
    return 0;
}


