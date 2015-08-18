import httplib
import time
import json
import os

class Module:

	def __init__(self):
		self.name = "cfrating"
		self.description = "show user's rating"
		self.help = 'Uses:\npython3 cfhelpher.py cfrating NICKNAME\nwhere NICKNAME is your Cadeforces handle'

	def execute(self, args):

		nickname = args[0]

		response = httplib.get('http://codeforces.com/api/user.info', params={'handles':nickname})

		userinfo = json.loads(response)

		#voot

		if(userinfo["status"] == 'FAILED'):
			print('Fail: {}'.format(userinfo['comment']))
			return

		rating = userinfo["result"][0]['rating']

		print('Current rating is: {}'.format(rating))

		x = input("Wait for changes in rating?(y/n)")

		if(x == 'n'):
			return

		while True:
			r = httplib.get('http://codeforces.com/api/user.info', params={'handles':nickname})
			r = json.loads(r)
			d = r["result"][0]['rating']

			if rating != d:
				print('Rank changed to {}'.format(d))
				os.system('play --no-show-progress --null --channels 1 synth %s sine %f' % ( 1, 300))
				break

			time.sleep(5)
