with open("hack.txt", "w") as f:
    n = 100000
    f.write(f"{n} {2 * n}\n")
    for i in range(1, n + 1):
        f.write(f"join {i + 1} {i}\n");

    for i in range(n):
        f.write(f"get 1\n");