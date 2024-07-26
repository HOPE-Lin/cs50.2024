import re

def is_even(s):
    t = len(s)
    i = t - 1
    j = t - 2
    sum = 0
    while i >= 0:
        p = int(s[i]) * 2
        if p > 9:
            sum = sum + (p % 10) +1
        else:
            sum += p
        i -= 2
    while j >= 0:
        p = int(s[j])
        sum += p
    if sum % 10 == 0:
        return True
    else:
        return False

def main():
    s = input("Number: ")
    t = len(s)
    if t == 15:
        if re.match("^(34|37)", s):
            if is_even(s):
                print("AMEX")
    elif t == 16:
        if re.match("^(51|52|53|54|55)", s):
            if is_even(s):
                print("MASTERCARD")
        if re.match("^(4)", s):
            if is_even(s):
                print("VISA")
    elif t == 13:
        if re.match("^(4)", s):
            if is_even(s):
                print("VISA")
    else:
        print("INVALID")

main()
