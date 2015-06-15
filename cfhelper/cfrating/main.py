import requests
import sys
import time
import json
import os

nickname = sys.argv[1]

if(nickname == '-h'):
	print('Uses:\ncfhelper cfrating NICKNAME\nwhere NICKNAME is your Cadeforces handle')
	sys.exit()

r = requests.get('http://codeforces.com/api/user.info', params={'handles':nickname})

tq = json.loads(r.text)

#voot

if(tq["status"] == 'FAILED'):
	print('Fail: {}'.format(tq['comment']))
	sys.exit()

s = tq["result"][0]['rating']

print('Current rating is: {}'.format(s))

x = input("Wait for changes in rating?(y/n)")

if(x == 'n'):
	sys.exit()

while True:
	r = requests.get('http://codeforces.com/api/user.info', params={'handles':nickname})

	d = r.text[r.text.find('"rating"'):r.text.find('"maxRank"')-1]
	d = int(d[d.find(':')+1:])

	if s != d:
		print('Rank changed to {}'.format(d))
		os.system('play --no-show-progress --null --channels 1 synth %s sine %f' % ( 1, 300))
		break
		
	time.sleep(5)
