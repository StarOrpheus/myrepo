from sys import stdin, stdout, stderr, exit
import math
import re
from pprint import pprint

# "Your mom" - "My fat cock" 0:1

mp = dict()
matches = []
team_by_plname = dict()

outf = open('output.txt', 'w')
inf = open('input.txt', 'r')

class match:
    def __init__(self, *arg):
        self.teams = arg[0]
        self.count = arg[1]
        self.log = [[], []]

    def __str__(self):
        return str(self.teams) + " " + str(self.count) + str(self.log)


def new_match(s:str):   # "Benis" - "Kekis" 3:1
    matches.append(match(list(map( lambda s : s[1:-1], re.findall("\"[\w\ ]+\"", s) )), \
                            list(map(int, re.findall("\d+:\d+", s)[0].split(':')))))

def new_goal(s:str):
    t = re.findall('\d+\'', s)[0]
    s = s[:-len(t)-1]
    if(len(matches[-1].log[0]) < matches[-1].count[0]):
        matches[-1].log[0].append((s, t))
        team_by_plname[s] = matches[-1].teams[0]
    else:
        matches[-1].log[1].append((s, t))
        team_by_plname[s] = matches[-1].teams[1]

def total_goals_for_team(s:str):
    team = re.findall('\"[\w\ ]+\"', s)[0][1:-1]
    k = 0
    for m in matches:
        if(m.teams[0] == team):
            k += m.count[0]
        if(m.teams[1] == team):
            k += m.count[1]
    outf.write(str(k) + '\n')

def mean_goals_for_team(s:str):
    team = re.findall('\"[\w\ ]+\"', s)[0][1:-1]
    k = 0
    n = 0
    for m in matches:
        if(m.teams[0] == team):
            k += m.count[0]
            n += 1
        if(m.teams[1] == team):
            k += m.count[1]
            n += 1
    outf.write(str(k / n) + '\n')

def total_goals_by_player(s:str):
    name = s[len('Total goals by '):]
    k = 0
    for m in matches:
        for log in m.log:
            for rec in log:
                if(rec[0] == name):
                    k += 1
    outf.write(str(k) + '\n')

def mean_goals_by_player(s:str):
    name = s[len('Mean goals per game by '):]
    if(name in team_by_plname.keys()):
        team = team_by_plname[name]
        k = 0
        n = 0
        for m in matches:
            if(m.teams[0] == team or m.teams[1] == team):
                n += 1
                for rec in m.log[0 if (m.teams[0] == team) else 1]:
                    if(rec[0] == name):
                        k += 1
        outf.write(str(k/n) + '\n')
    else:
        outf.write('0\n')

def goals_on_min_by_pl(s:str):
    t = re.findall('\d+', s)[0]
    k = 0
    name = s[len('Goals on minute  by ') + len(t):]
    # print('#', name, file=stderr)
    t = t + '\''
    if(name in team_by_plname.keys()):
        team = team_by_plname[name]
        for m in matches:
            if(m.teams[0] == team or m.teams[1] == team):
                for rec in m.log[0 if (m.teams[0] == team) else 1]:
                    k += (rec == (name, t))
        outf.write(str(k) + '\n')
    else:
        outf.write('0\n')

def goal_on_first_tmin(s:str):
    t = re.findall('\d+', s)[0]
    k = 0
    name = s[len('Goals on first  minutes by ') + len(t):]
    # outf.write(t + ' first ' + name + ' ')
    if(name in team_by_plname.keys()):
        team = team_by_plname[name]
        for m in matches:
            if(team in m.teams):
                for rec in m.log[0 if (m.teams[0] == team) else 1]:
                    k += (rec[0] == name and int(rec[1][:-1]) <= int(t))
        outf.write(str(k) + '\n')
    else:
        outf.write('0\n')

def goal_on_last_tmin(s:str):
    t = re.findall('\d+', s)[0]
    k = 0
    name = s[len('Goals on last  minutes by ') + len(t):]
    # outf.write(t + ' last ' + name + ' ')
    if(name in team_by_plname.keys()):
        team = team_by_plname[name]
        for m in matches:
            if(team in m.teams):
                for rec in m.log[0 if (m.teams[0] == team) else 1]:
                    k += (rec[0] == name and int(rec[1][:-1]) >= 91-int(t))
        outf.write(str(k) + '\n')
    else:
        outf.write('0\n')

def score_open_team(s:str):
    team = s[len('Score opens by '):][1:-1]
    k = 0
    # outf.write(team + ' ')
    for m in matches:
        if(len(m.log[0]) == 0 and len(m.log[1]) == 0):
            continue
        if(len(m.log[0]) != 0 and len(m.log[1]) == 0):
            opener = m.teams[0]
        elif(len(m.log[0]) == 0 and len(m.log[1]) != 0):
            opener = m.teams[1]
        else:
            opener = m.teams[0] if (int(m.log[0][0][1][:-1]) < int(m.log[1][0][1][:-1])) else m.teams[1]

        k += (opener == team)
    outf.write(str(k) + '\n')

def score_open_player(s:str):
    name = s[len('Score opens by '):]
    k = 0
    # outf.write(name + ' ')
    for m in matches:
        if(len(m.log[0]) == 0 and len(m.log[1]) == 0):
            continue
        if(len(m.log[0]) != 0 and len(m.log[1]) == 0):
            opener = m.log[0][0][0]
        elif(len(m.log[0]) == 0 and len(m.log[1]) != 0):
            opener = m.log[1][0][0]
        else:
            opener = m.log[0][0][0] if (int(m.log[0][0][1][:-1]) < int(m.log[1][0][1][:-1])) else m.log[1][0][0]
        k += (name == opener)
    outf.write(str(k) + '\n')

def main():
    mp[re.compile('^\".+\" - \".+\" \d+:\d+$')] = new_match
    mp[re.compile('^[\w\ ]+ \d+\'$')] = new_goal
    mp[re.compile('^Total goals for \"[\w\ ]+\"$')] = total_goals_for_team
    mp[re.compile('^Mean goals per game for \"[\w\ ]+\"$')] = mean_goals_for_team
    mp[re.compile('^Total goals by [\w\ ]+$')] = total_goals_by_player
    mp[re.compile('^Mean goals per game by [\w\ ]+$')] = mean_goals_by_player
    mp[re.compile('^Goals on minute \d+ by [\w\ ]+$')] = goals_on_min_by_pl
    mp[re.compile('^Goals on first \d+ minutes by [\w\ ]+$')] = goal_on_first_tmin
    mp[re.compile('^Goals on last \d+ minutes by [\w\ ]+$')] = goal_on_last_tmin
    mp[re.compile('^Score opens by \"[\w\ ]+\"$')] = score_open_team
    mp[re.compile('^Score opens by [\w\ ]+$')] = score_open_player

    while(True):
        s = inf.readline().strip()
        if(s == ''):
            exit(0)
        for reg, func in mp.items():
            if(reg.match(s) != None):
                func(s)
                # print(*list(map(str, matches)), file=stderr)
                # stderr.write(str(reg) + '\n')
                break
        # print(str(matches[0]))


if __name__ == '__main__':
    main()

outf.close()
inf.close()
