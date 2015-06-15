import sys
import os

if(len(sys.argv) != 2):
    print("Wrong input.\nTry cfhelper -h\nto know how to use it")
    sys.exit()

if(sys.argv[1] == '-h'):
    print('Using:\ncfhelper __MODULENAME__\nwhere __MODULENAME__ is the name of module you need')
    sys.exit()

mpath = os.path.dirname(__file__) + '/' + sys.argv[1] + '/main.py'

if(not os.path.isfile(mpath)):
    print('Such module doesn\'t exist')
    sys.exit()

os.system('python3 {}'.format(mpath))