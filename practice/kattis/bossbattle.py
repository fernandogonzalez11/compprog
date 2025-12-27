n = int(input())

yo = 0
he = -2 % n

def cond():
    return he == yo or he == (yo+1)%n or he == (yo-1)%n

if cond():
    print(1)
    exit()

i = 1
while not cond():
    i += 1
    he = (he+1)%n
    yo = (yo+2)%n

print(i)