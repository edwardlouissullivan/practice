

class Node(object):

    def __init__(self, v, n=None):
        self.next = n
        self.value = v

def remove_duplicates(linked_list):

    cur_node = linked_list
    prev_node = cur_node
    visited = set()
    while cur_node is not None:
        if cur_node.value in visited:
            # If we have already seen the current
            # node's value, then skip it
            prev_node.next = cur_node.next
        else:
            # Otherwise, add it's value to the
            # set of seen values
            visited.add(cur_node.value)
            prev_node = cur_node
        cur_node = cur_node.next
    return

def test_remove_duplicates():
    # Very cursory test, not suitable for production

    n1 = Node(18)
    n2 = Node(2, n1)
    n3 = Node(3, n2)
    n4 = Node(2, n3)
    n5 = Node(3, n4)
    n6 = Node(5, n5)
    n6 = Node(1, n6)

    remove_duplicates(n6)

    print n6.next.next.next.next.value
    assert n6.next.next.next.next.value == 18


def main():
    test_remove_duplicates()
    print "ALL TESTS PASSED"

if __name__ == "__main__":
    main()
