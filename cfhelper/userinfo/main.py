import requests
import sys
import json

nickname = sys.argv[1]

if(nickname == '-h'):
    print('Uses:\ncfhelper userinfo NICKNAME args1 args2 args3...\nWhere arguments(args) are rank, handle, city, country, firstName and etc.')
    sys.exit()

r = requests.get("http://codeforces.com/api/user.info", params={'handles':nickname})

r = json.loads(r.text)

if(r["status"] == "FAILED"):
    print("Failed: {}".format(r["comment"]))
    sys.exit()

info = r['result'][0]

# print(info)

for i in range(2, len(sys.argv)):
    print(info[sys.argv[i]])