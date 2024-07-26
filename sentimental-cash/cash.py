from cs50 import get_float
t = get_float("Change: ")
while t < 0:
    t = get_float("Change: ")
p = 0
while t >= 0.25:
    t -= 0.25
    p += 1
while t >= 0.10:
    t -= 0.10
    p += 1
while t >= 0.05:
    round(t - 0.05, 2)
    p += 1
while t >= 0.01:
    round(t - 0.01, 2)
    p += 1
print(f"{p}")
