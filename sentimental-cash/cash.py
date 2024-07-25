from cs50 import get_float
t = get_float
p = 0
while t >= 25:
    t -= 25
    p += 1
while t >= 10:
    t -= 10
    p += 1
while t >= 5:
    t -= 5
    p += 1
while t >= 1:
    t -= 1
    p += 1
    print(" ", p)
