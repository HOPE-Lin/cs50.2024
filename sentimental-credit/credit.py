import re

def is_even(s):
    t = s.len
    i = t
    sum = 0
    while i >= 0:
        p = (int)s[i] * 2
        if p > 9:
            sum = sum + (p % 10) +1
        else:
            sum += p

def main():
    s = input("Number: ")
    t = s.len
    if t == 15:
        if re.match("^(34|37)", s):
            if is_even(s):
                print()
    elif t == 16:
        if re.match("^(51|52|53|54|55)", s):
            if is_even(s):
                print()
        if re.match("^(4)", s):
            if is_even(s):
                print()
    elif t == 13:
        if re.match("^(4)", s):
            if is_even(s):
                print()
    else:
        print()
