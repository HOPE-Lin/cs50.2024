from cs50 import get_int
t = get_int("Height: ")
if t > 8 and t < 0:
    print("")
for p in range(t):
    s = t - p
    for _ in range(s):
        print("", end = "");
    for _ in rang(s, t , 1):
        print("#", end = "")
    print()


