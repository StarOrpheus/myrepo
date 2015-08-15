import httplib
import json


class Module:

    def __init__(self):
        self.name = 'userInfo'
        self.description = 'show information about user'
        self.help = 'Uses:\npython3 cfhelpher.py userinfo NICKNAME args1 args2 args3...\nWhere arguments(args) are rank, handle, city, country, firstName and etc.'

    def execute(self, args):
        nickname = args[0]

        r = httplib.get("http://codeforces.com/api/user.info", params={'handles':nickname})

        r = json.loads(r)

        if(r["status"] == "FAILED"):
            print("Failed: {}".format(r["comment"]))
            return

        info = r['result'][0]

        # print(info)

        for arg in args[1:]:
            print(info[arg])