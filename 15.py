N = int(input())
A = [int(tmp) for tmp in input().rstrip().split(' ')]
S = []
answer = 0
for number in A:
    if len(S) == 0 or S[-1] > number:
        S.append(number)
    else:
        if S[-1] == number:
            continue
        tmp = S.pop()
        while len(S) != 0 and S[-1] <= number:
            answer += S[-1] - tmp
            tmp = S.pop()
        answer += number - tmp
        S.append(number)
if len(S) != 0:
    tmp = S.pop()
    while len(S)!=0:
        answer += S[-1] - tmp
        tmp = S[-1]
        S.pop()
print(answer)

        
