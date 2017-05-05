


def all_chars_unique(string):

    chars_found = set()
    all_unique = True
    for c in string:
        if c in chars_found:
            all_unique = False
            break
        else:
            chars_found.add(c)
    return all_unique

def test_all_chars_unique():

    test1 = "This is no unique"
    assert all_chars_unique(test1) == False

    test2 = "Unique!"
    assert all_chars_unique(test2) == True


def main():
    
    test_all_chars_unique()
    print "ALL TESTS PASSED"


if __name__ == "__main__":
    main()



