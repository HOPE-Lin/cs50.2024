from cs50 import get_int
t = get_int("Height :")
while t <= 0 or t > 8:
    t = get_int("Height:")
for p in range(1, t + 1, 1):
    s = t - p
    for _ in range(s):
        print(" ", end="")
    for _ in range(p):
        print("#", end="")
    print("  ", end="")
    for _ in range(p):
        print("#", end="")
    print()
