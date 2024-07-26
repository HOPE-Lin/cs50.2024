from cs50 import get_string

s = get_string("Text: ")
t = len(s)
a = 0
b = 0
c = 0
for i in range(t):
    if s[i].isalpha():
        a += 1
    elif s[i].isspace():
        b += 1
    elif s[i] in ['.', '?',]:
       c += 1
g = 0.0588 * (a / b) * 100 - 0.296 * (c / b) * 100 - 15.8
if g > 16:
    print("Grade 16+")
elif g < 1:
    print("Before Grade 1")
else:
    print(f"Grade {g}")

