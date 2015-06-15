import json
import requests
import datetime

r = requests.get('http://codeforces.com/api/contest.list', params={'gym' : 'false'})

s = r.text[26:-3]
s = list(s.split('},{'))

ph = '"phase":'
ph = len(ph)

for contest in s:
    if(contest[contest.find('"phase":') + ph + 1:contest.find(',"frozen"')-1] == 'BEFORE'):
        contest = '{' + contest + '}'
        contest = json.loads(contest)
        print(contest["name"], 'starts at ',
              datetime.datetime.fromtimestamp(
            int(contest["startTimeSeconds"])
        ).strftime('%d-%m-%Y %H:%M:%S'))