#include <set>
#include <string>
#include <iostream>
#include <assert.h>

using namespace std;

typedef std::set <char> charset;

bool all_chars_unique(string& str){

    std::pair<std::set<char>::iterator, bool> insert_ret;
    charset chars_found;

    bool are_all_unique = true;
    for (char c: str){
        insert_ret = chars_found.insert(c);
        if (insert_ret.second == false){
            are_all_unique = false;
            break;
        }
    }
    
    return are_all_unique; 
}

bool all_chars_unique_no_extra_space(string& str){

    bool all_unique = true;
    for (int i = 0; i < str.length() && all_unique == true; i++){
        for (int j = i + 1; j < str.length() && all_unique == true; j++){
            if (str[j] == str[i]){
                all_unique = false;
            }
        } 
    }
    
    return all_unique; 
}

void test_all_chars_unique(){

    string test1 = "This is not unique";
    assert (all_chars_unique(test1) == false);

    string test2 = "Unique!";
    assert (all_chars_unique(test2) == true);

    return;
}

void test_all_chars_unique_no_extra_space(){

    string test1 = "This is not unique";
    assert (all_chars_unique_no_extra_space(test1) == false);

    string test2 = "Unique!";
    assert (all_chars_unique_no_extra_space(test2) == true);

    return;
}

int main(){

    test_all_chars_unique();
    cout << "ALL TESTS PASSED" << endl;
    return 0;
}

