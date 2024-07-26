from cs50 import get_string

s = get_string("Text: ")
t = len(s)
a = 0
b = 0
c = 0
for i in range(t):
    if s[i].isalpha:
        a += 1
    elif s[i].isspace():
        b += 1
    elif s[i] in [. ]
