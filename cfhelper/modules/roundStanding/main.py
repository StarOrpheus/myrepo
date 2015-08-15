import httplib
import json

class Module:
    def __init__(self):
        self.name = 'roundStanding'
        self.description = 'show user\' standing in round'
        self.help = 'Uses:\npython3 cfhelpher.py roundStanding NICKNAME ROUNDID\nwhere NICKNAME is your Cadeforces, ROUNDID is id of the round handle'

    def execute(self, args):
        nickname    = args[0]
        rid         = args[1]

        response = httplib.get('http://codeforces.com/api/contest.standings', params={'contestId':rid, 'handles':nickname})

        response = json.loads(response)

        if(response['status'] == 'FAILED'):
            print('Fail: {}'.format(response['comment']))
            return

        result      = response["result"]
        problems    = result['problems']
        rows        = result['rows']

        for i in range(len(problems)):
            print(rid, problems[i]["index"],' ', problems[i]['name'], '\t[', rows[0]["problemResults"][i]['points'], "\\", problems[i]["points"], ']', sep='')

        print('Hacks: +{}/-{}'.format(rows[0]['successfulHackCount'], rows[0]['unsuccessfulHackCount']))

        print('-'*10)

        print('Points summary - {}, rank - {}'.format(rows[0]['points'], rows[0]['rank']))