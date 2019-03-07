tmp=input().split()
N = int(tmp[0])
K = int(tmp[1])
if K == 1:
    tmp=input().split()
    print(max([int(num) for num in tmp]))
elif K == N:
    tmp=input().split()
    A = [int(num) for num in tmp]
    answer=1
    for num in A:
        answer = answer*num
    print(answer)
else:
    tmp=input().split()
    A = [int(num) for num in tmp]
    A.sort(key=abs)
    print(A)
