import json
import httplib
import datetime

class Module:
    def __init__(self):
        self.name = "contestlist"
        self.description = "show list of upcoming CodeForces rounds"
        self.help = 'Uses: python3 cfhelpher.py contestlist'

    def execute(self, args):
        response = httplib.get('http://codeforces.com/api/contest.list', params={'gym' : 'false'})

        contests = json.loads(response)['result']
        for contest in contests:
            if contest['phase'] == 'BEFORE':
                print(contest['name'])
                print(datetime.datetime.fromtimestamp(int(contest['startTimeSeconds'])).strftime('%d-%m-%Y %H:%M:%S'))
