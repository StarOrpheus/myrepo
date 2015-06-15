import requests
import time
import os



os.system('play --no-show-progress --null --channels 1 synth %s sine %f' % ( 1, 300))
r = requests.get('http://codeforces.com/api/user.info', params={'handles':'Jyree'})

s = r.text
s = s[s.find('"rating"'):s.find('"maxRank"')-1]
s = int(s[s.find(':')+1:])

print(s)

while True:
	r = requests.get('http://codeforces.com/api/user.info', params={'handles':'Jyree'})

	d = r.text[r.text.find('"rating"'):r.text.find('"maxRank"')-1]
	d = int(d[d.find(':')+1:])

	if s != d:
		print(d)
		os.system('play --no-show-progress --null --channels 1 synth %s sine %f' % ( 1, 300))
		break
		
	time.sleep(5)
