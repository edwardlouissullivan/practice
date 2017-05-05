
import collections

def is_permutation(str1, str2):
    
    if len(str1) != len(str2):
        return False

    char_counts = collections.defaultdict(int)
    for char in str1:
        char_counts[char] += 1

    for char in str2:
        if char not in char_counts:
            return False    

        char_counts[char] -= 1
        if char_counts[char] < 0:
            return False

    return True

def test_is_permutation():

    # Test not permutation, different lengths
    s1 = "a"
    s2 = "aaa"
    assert is_permutation(s1, s2) == False
    assert is_permutation(s2, s1) == False
    
    # Test not permutation, same lenths, same
    # letters, different quantities
    s1 = "aaabb"
    s2 = "abbbb"
    assert is_permutation(s1, s2) == False
    assert is_permutation(s2, s1) == False

    # Test VALID permutation
    s1 = "aaabb"
    s2 = "abbaa"
    assert is_permutation(s1, s2) == True
    assert is_permutation(s2, s1) == True
    

def main():

    test_is_permutation()
    print "ALL TESTS PASSED"

if __name__ == "__main__":
    main()

