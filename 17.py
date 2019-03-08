N = int(input())

NArr = []

for i in range(N):
    NArr.append(int(input()))

if (1021 in NArr) & (1031 in NArr) & (1033 in NArr):
    print('YES')

elif (1052651 in NArr) & (1033 in NArr):
    print('YES')

elif (1065023 in NArr) & (1021 in NArr):
    print('YES')

elif (1054693 in NArr) & (1031 in NArr):
    print('YES')

elif(1087388483 in NArr) :
    print('YES')
    
else:
    print('NO')
