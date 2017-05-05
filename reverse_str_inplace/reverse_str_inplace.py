

# Strings are immutable in python, so it's not 
# even really possible to reverse a string in place,
# unless it is represented as an array...

def reverse_str(string):

    array = list(string)
    i = 0;
    j = len(string) - 1;

    while i < j:
        # i_char = string[i]
        # j_char = string[j]
        array[i], array[j] = array[j], array[i]
        i += 1
        j -= 1

    result = ''.join(array)
    
    return result

def test_reverse_str_inplace():

    test_case_1 = "ABCDE"
    result = reverse_str(test_case_1)
    expected_result = "EDCBA"
    assert result == expected_result

def main():
    
    test_reverse_str_inplace()
    print "ALL TESTS PASSED"

if __name__ == "__main__":
    main()
