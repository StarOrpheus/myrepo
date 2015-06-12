import requests
import time
import os



os.system('play --no-show-progress --null --channels 1 synth %s sine %f' % ( 1, 300))
r = requests.get('http://codeforces.com/api/user.info', params={'handles':'Jyree'})

s = r.text
p1 = s.find('"rating"')
p2 = s.find('"maxRank"')
s = s[p1:p2-1]
p1 = s.find(':')
s = int(s[p1+1:])

print(s)

while True:
	r = requests.get('http://codeforces.com/api/user.info', params={'handles':'Jyree'})
	
	d = r.text
	p1 = d.find('"rating"')
	p2 = d.find('"maxRank"')
	d = d[p1:p2-1]
	p1 = d.find(':')
	d = int(d[p1+1:])

	if s != d:
		print(d)
		os.system('play --no-show-progress --null --channels 1 synth %s sine %f' % ( 1, 300))
		break
		
	time.sleep(5)
