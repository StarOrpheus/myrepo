import math

def solve(a, b):	# a/b
	
	config = [a, b]

	ans = []

	def ewc(a=config[0], b=config[1]):
		if(a == 0):
			return b;
		if(b == 0):
			return a;

		if(a < b):
			swap(a, b)

		ans.append(int(a / b))
		a = a % b
		ewc(b, a)

	ewc()
	
	return ans