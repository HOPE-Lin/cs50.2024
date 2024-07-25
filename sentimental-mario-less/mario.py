from cs50 import get_int
t = get_int("Height: ")
while t > 8 or t < 0:
    t = get_int("Height: ")

for p in range(1, t + 1, 1):
    s = t - p
    for _ in range(s):
        print(" ", end = "");
    for _ in range(s, t , 1):
        print("#", end = "")
    print()


