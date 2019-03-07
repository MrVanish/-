N=int(input())-1
A=input().split()
if len(A) == 2:
    print(int(A[0])*int(A[1]))
else:
    IntA=[int(num) for num in A]
    IntA.sort()
    maxOne = IntA[0]*IntA[1]
    maxSecond = IntA[N]*IntA[N-1]
    print(maxOne if maxOne > maxSecond else maxSecond)
