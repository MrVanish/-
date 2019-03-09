import itertools
X = input().rstrip()
XArr = [char for char in X]
XArr = list(itertools.permutations(XArr))
XArr2 = []
for pair in XArr:
    tmp = ''
    for num in pair:
        tmp += num
    XArr2.append(int(tmp))
XArr2.sort()
sw = False
for num in XArr2:
    if num > int(X):
        print(num)
        sw = True
        break
if sw!=True:
    print("-1")
