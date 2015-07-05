import json
import requests
import sys

if(len(sys.argv) != 1 and sys.argv[1] == '-h'):
    print('Uses:\ncfhelper taskCounter\n*Hint: you can add -v to increase verbosity level')
    sys.exit(0)

handle = input('Input your handle: ')

r = requests.get('http://codeforces.com/api/user.status', params={'handle' : handle})

info = json.loads(r.text)

if(info['status'] != 'OK'):
    print('Fail :c\n{}'.format(info['comment']))
    sys.exit(0)

info = info['result']

count = 0

vlvl = 0 #verbosity level

if(len(sys.argv) != 1 and sys.argv[1] == '-v'):
    vlvl    = 1
    tasks   = []


for tr in info:
    if(tr['verdict'] == 'OK'):
        count += 1
        if(vlvl == 1):
            tasks.append([tr['problem']['contestId'], tr['problem']['index']])

if(vlvl == 1):
    tasks = sorted(tasks)
    for i in range(len(tasks)):
        if(i != 0 and tasks[i][0] != tasks[i-1][0]):
            print()
        print(tasks[i][0], tasks[i][1], sep='')
    print('-'*10)

print('Tasks solved: {}'.format(count))

