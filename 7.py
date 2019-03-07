import math
tmp=input().split()
print('NO' if math.fabs(int(tmp[2]) - int(tmp[4])) == math.fabs(int(tmp[3]) - int(tmp[5])) else 'YES')

