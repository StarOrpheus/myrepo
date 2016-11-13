import math
from ewclid import solve

config = (
	math.sqrt(5),	# Double to calc
	781,			# Deep of calculations 
)

a = []

def go(n, x):
	if(n == 0):
		return
	k = math.floor(x)
	a.append(k)
	x = 1.0 / (x - k)
	go(n-1, x)

go(config[1], config[0])

p = [1]
p.append(a[0])
q = [0, 1] # -1th and 0t

for i in range(1, config[1]-1):
	p.append(a[i] * p[-1] + p[-2])
	q.append(a[i] * q[-1] + q[-2])

# ans = solve(p[-1], q[-1])

print(p[-1], ' ', q[-1])
print(p[-1] / q[-1])
print(config[0])