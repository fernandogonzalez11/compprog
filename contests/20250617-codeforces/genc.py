tests = 10**4

n = 10**3
m = 10**2

s = ' '.join(["3" for _ in range(m)])
bigS = '\n'.join([s for _ in range(n)])
bigS = str(n) + " " + str(m) + "\n" + bigS + "\n"

# bigBigS = '\n'.join([(str(n) + " " + str(m) + "\n" + bigS) for _ in range(tests)])
# bigBigS = str(tests) + "\n" + bigBigS

with open("test.txt", "w") as f:
    f.write(f"{tests}\n")
    for _ in range(tests):
        f.write(bigS)