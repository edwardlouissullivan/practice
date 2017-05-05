
#include <string>
#include <assert.h>
#include <iostream>
using namespace std;

void reverse(char* str){
    // First, get the length of the string, excluding the null
    int len = 0;
    while(*(str + len) != '\0'){
        len++;
    }

    // Then swap characters from the beginning and end,
    // working toward the center
    char * start = str;
    char * end = str + len - 1;
    while (start < end){
        char start_char = *start;
        char end_char = *end;
        *start = end_char;
        *end = start_char;
        start++;
        end--;
    }

    return;
}

void reverse(string& str){
 
    int j = str.length() - 1;
    int i = 0;
    while(i < j){
        char start_char = str[i];
        char end_char = str[j];
        str[i] = end_char;
        str[j] = start_char;
        i++;
        j--;
    }   
    return;
}

void test_reverse_cstr(){

    char test1[] = "12345 ABCDE";
    reverse(test1);
    assert (strcmp(test1, "EDCBA 54321") == 0);

    return;
}

void test_reverse_libstr(){

    string test1= "12345 ABCDE";
    reverse(test1);
    assert (test1 == "EDCBA 54321");

    return;
}

int main(){

    test_reverse_cstr();
    test_reverse_libstr();

    cout << "ALL TESTS PASSED" << endl;

    return 0;
}





