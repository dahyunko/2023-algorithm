n, k = map(int ,input( ).split())
a =0
for i in range(1, n+1):
    if n % i == 0:
        a = a+1
        if a == k:
            print(i)
            break
if a<k:
    print(0)
