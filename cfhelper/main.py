import sys
import os

if(sys.argv[1] == '-h'):
    print('Using:\ncfhelper __MODULENAME__\nwhere __MODULENAME__ is the name of module you need')
    sys.exit()

mpath = os.path.dirname(__file__) + '/' + sys.argv[1] + '/main.py'

if(not os.path.isfile(mpath)):
    print('Such module doesn\'t exist')
    sys.exit()

query = 'python3 {}'.format(mpath)
for i in range(2, len(sys.argv)):
    query += ' ' + sys.argv[i]

os.system(query)
