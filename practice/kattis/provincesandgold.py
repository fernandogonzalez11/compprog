g, s, c = [int(x) for x in input().split()]

budget = g*3 + s*2 + c*1

vict = [("Province", 8), ("Duchy", 5), ("Estate", 2)]
trea = [("Gold", 6), ("Silver", 3), ("Copper", 0)]

for v in vict:
    if v[1] <= budget:
        print(v[0], end=' or ')
        break

for t in trea:
    if t[1] <= budget:
        print(t[0])
        break