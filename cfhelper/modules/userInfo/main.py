import httplib
import json
import datetime

class Module:

    def __init__(self):
        self.name = 'userInfo'
        self.description = 'Show information about user'
        self.help = 'Uses:\npython3 cfhelpher.py userinfo NICKNAME'

    def execute(self, args):
        nickname = args[0]

        r = httplib.get("http://codeforces.com/api/user.info", params={'handles':nickname})

        r = json.loads(r)

        if(r["status"] == "FAILED"):
            print("Failed: {}".format(r["comment"]))
            return

        info = r['result'][0]

        # print(info)

        for key, val in info.items():
            if(key != 'registrationTimeSeconds' and key != 'lastOnlineTimeSeconds'):
                print('{}: {}'.format(key, val))
                continue
            print('{}: {}'.format(key, datetime.datetime.fromtimestamp(val).strftime('%d.%m.%Y %H:%M:%S')))
