/* PROMPT: Implement an algorithm to find the kth to last element of a singly linked list.

*/

#include <assert.h>
#include <iostream>
using namespace std;

struct node_t {
    int value;
    const node_t * next;

    node_t(int v) : value(v), next(nullptr) {};
    node_t(int v, const node_t * n): value(v), next(n) {};
};

node_t * find_kth_last_element(const node_t *& head, int k){

    const node_t * cur = head;
    const node_t * kth = nullptr;

    // Traverse the list with a pointer to the end, and
    // keep a second pointer that is k
    // element behind the first pointer
    if (k == 0)
        kth = cur;
    for (int i = 0; cur != nullptr && cur->next != nullptr; i++){
        if (i == k)
            kth = head;
        if (i >= k)
            kth = kth->next; 
        cur = cur->next;
    }
    
    // If the second pointer (kth) is null, that
    // means that the linked list wast not at
    // least k elements long
    return (node_t *) kth;
}

void test_find_kth_last_element(){
    node_t n1(1);
    node_t n2(2, &n1);   
    node_t n3(3, &n2);   
    node_t n4(4, &n3);   
    node_t n5(5, &n4);   
    node_t n6(6, &n5);   
    const node_t * head = (const node_t *) &n6;

    node_t * result = find_kth_last_element(head, 2);
    node_t * expected_result = &n3;

    assert (result == expected_result);
}

int main(){
    test_find_kth_last_element();
    cout << "ALL TESTS PASSED" << endl;
    return 0;
}


