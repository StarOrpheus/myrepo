import json
import httplib

class Module:

    def __init__(self):
        self.name = 'taskCounter'
        self.description = 'show how many tasks user solved'
        self.help = 'Uses:\npython3 cfhelpher.py taskCounter Handle\n*Hint: you can add -v to increase verbosity level'

    def execute(self, args):

        vlvl = 0 #verbosity level
        if args[0] == '-v':
            vlvl = 1
            tasks = []
            handle = args[1]
        else:
            handle = args[0]

        r = httplib.get('http://codeforces.com/api/user.status', params={'handle' : handle})

        info = json.loads(r)

        if(info['status'] != 'OK'):
            print('Fail :c\n{}'.format(info['comment']))
            return

        info = info['result']
        
        count = 0

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

