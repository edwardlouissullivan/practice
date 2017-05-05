// CHALLENGE: Given two strings, write a method to decide 
// if one is a permutation of the other.

// Define permutation: two strings that have the 
// same count of each character, not necessarily in
// the same order.

// Proposed solution: I will count the number of specific
// characters (basically a histogram) in the first string
// using a hash table (unordered_map in C++ standard lib)
// and then I will traverse the second string and 
// decrement the values in the histogram from the first
// string. If every value in the histogram is 0 after
// traversing the second string, then I will know 
// that the strings are permutations of each other
// This algorithm will run in time O(n) where n
// is the length of the length of the longest string.

#include <string>
#include <iostream>
#include <assert.h>
#include <unordered_map>

using namespace std;

typedef std::unordered_map<char,int> char_to_int_map;

bool is_permutation(const string& str1, const string& str2){

    char_to_int_map char_counts;

    // Quit immediately if the two strings have
    // different lengths
    if (str1.length() != str2.length()){
        return false;
    }

    // Create histogram of characters in the first string
    for(char c : str1){
        if (char_counts.count(c) == 0){
            // If the char is not yet in out hash table
            char_counts.insert({{c, 1}});
        }
        else{
            // If the char is already in our hash table,
            // just increment the value
            char_counts.at(c) += 1;
        }
    }
    
    // Subtract characters in second string from
    // histogram of first string. Quit early if 
    // we find a char in the second string not
    // present in the histgram of the first string,
    // or if we go negative.
    for(char c : str2){
        if (char_counts.count(c) == 0){
            return false;
        }
        else {
            char_counts.at(c) -= 1;
            if (char_counts.at(c) < 0){
                return false;
            }
        }
    }

    return true;
    
}

void test_is_permutation(){

    // Test two strings that are NOT permutations 
    // because they have different lengths but
    // cover the same set of letters
    string str1 = "aa";
    string str2 = "aaaa";
    bool result = is_permutation(str1, str2);
    bool expected_result = false;
    assert (result == expected_result);

    result = is_permutation(str2, str1); // reverse order
    expected_result = false;
    assert (result == expected_result);
    

    // Test two strings that are NOT permutations
    // because they have the same lengths and the same
    // set of distinct letters, but different counts of
    // some letters
    str1 = "aaba";
    str2 = "abba";
    result = is_permutation(str1, str2);
    expected_result = false;
    assert (result == expected_result);

    result = is_permutation(str2, str1); // reverse order
    expected_result = false;
    assert (result == expected_result);

    // Test two strings that ARE VALID permutations
    str1 = "baba";
    str2 = "abba";
    result = is_permutation(str1, str2);
    expected_result = true;
    assert (result == expected_result);

    result = is_permutation(str2, str1); // reverse order
    expected_result = true;
    assert (result == expected_result);
    
    return;
}


int main(){

    test_is_permutation();
    cout << "ALL TESTS PASSED" << endl;

    return 0;
}




