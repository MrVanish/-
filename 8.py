import sys
# Теперь проходит проверку с "ababa" ,должно пройти ,но не понятно ,чо по времени и памяти
S = input().rstrip()
max = len(S)

if max == 1:
    print(-1)
    sys.exit(0)
    
if len(set(S)) == 1:
    print(-1)
    sys.exit(0)

if S != str(S[::-1]):
    print(max)
    sys.exit(0)

for i in range(len(S)):
    max -= 1
    if S[i] == S[max]:
        print(max)
        sys.exit(0)


        
