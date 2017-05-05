/* 
PROMPT: Write code to remove duplicates from an unsorted linked list.
*/

#include <iostream>
#include <set>
using namespace std;

struct node_t {
        const node_t * next;
        int value;
        node_t(int v, const node_t * n): next(n), value(v) {};
        node_t(int v): value(v), next(nullptr) {};
};


void remove_duplicates(node_t *& head){
    /* General strategy:
        - Create a set of values seen
        - Traverse the linked list and for each node:
            - If it's value is already in the set
                -Remove that node from the linked list
            - Else: add it's value to the set of seen values
        - Return void 
    */
    set<int> values_seen;
    node_t * cur_node = head;
    node_t * prev_node = head;
    while (cur_node != nullptr){
        if (values_seen.count(cur_node->value) > 0) {
            // Value is already in the linked list
            // Remove this node from the linked list
            prev_node->next = cur_node->next;   
        }
        else {
            values_seen.insert(cur_node->value);
            prev_node = cur_node;
        }
        cur_node = (node_t *) cur_node->next;
    }
       
    return;
}

void print_linked_list(node_t * head){

    while(head != nullptr){
        if (head->next != nullptr)
            cout << head->value << "<-";
        else
            cout << head->value << endl;
        head = (node_t *) head->next;
    }

    return;
}


void test_remove_duplicates(){

    // Create a sample linked list:
    // 1->3->4->3->2->1
    // Expected result:
    // 1->3->4->2;
    node_t n1(1);
    node_t n2(2, &n1);
    node_t n3(3, &n2);
    node_t n4(4, &n3);
    node_t n5(3, &n4);
    node_t n6(1, &n5);
    node_t * linked_list = &n6;

    print_linked_list(linked_list);
    remove_duplicates(linked_list);
    print_linked_list(linked_list);

    return;
}

int main(){
    test_remove_duplicates();
    cout << "ALL TESTS PASSED" << endl;
    return 0;
}


