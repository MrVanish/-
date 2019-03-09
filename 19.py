N = int(input())
A = [int(tmp) for tmp in input().rstrip().split(' ')]
ans = 0
for i in range(N):
    for ii in range(i,N):
        if A[i] > A[ii]:
            ans+=1
print(ans)
