import requests
import json
import sys

nickname    = sys.argv[1]
rid         = sys.argv[2]

if(len(sys.argv) != 3 or nickname == '-h'):
	print('Uses:\ncfhelper roundStanding NICKNAME ROUNDID\nwhere NICKNAME is your Cadeforces, ROUNDID is id of the round handle')
	sys.exit()

r = requests.get('http://codeforces.com/api/contest.standings', params={'contestId':rid, 'handles':nickname})

r = json.loads(r.text)

if(r['status'] == 'FAILED'):
    print('Fail: {}'.format(r['comment']))
    sys.exit()

r           = r["result"]
problems    = r['problems']
rows        = r['rows']



for i in range(len(problems)):
    print(rid, problems[i]["index"],' ', problems[i]['name'], '\t[', rows[0]["problemResults"][i]['points'], "\\", problems[i]["points"], ']', sep='')

print('Hacks: +{}/-{}'.format(rows[0]['successfulHackCount'], rows[0]['unsuccessfulHackCount']))

print('-'*10)

print('Points summary - {}, rank - {}'.format(rows[0]['points'], rows[0]['rank']))