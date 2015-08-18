import sys, imp
from os.path import isdir, dirname, join, exists
from os import listdir

module_dir = join(dirname(__file__), 'modules')

modules_main = [join(module_dir, dir, 'main.py') for dir in listdir(module_dir) if isdir(join(module_dir, dir)) and exists(join(module_dir, dir, 'main.py'))]

modules = list()
for mainfile in modules_main:
    modules.append(getattr(imp.load_source('module' + str(len(modules)), mainfile), 'Module')())

if len(sys.argv) == 1 or sys.argv[1] in ['-h', '--help']:
    if len(sys.argv) <= 2:
        print('Using:\npython3 cfhelpher.py __MODULENAME__\nwhere __MODULENAME__ is the name of module you need\n')
        print('Available modules:')
        for module in modules:
            print(module.name + " - " + module.description)
        print('\nUse python3 cfhelpher.py -h(--help) __MODULENAME__ to get help of module')
    else:
        module_name = sys.argv[2]
        for module in modules:
            if module.name == module_name:
                print(module.description, '\n', module.help, sep='')
    sys.exit()

module_name = sys.argv[1]
for module in modules:
    if module.name == module_name:
        module.execute(sys.argv[2:])
        sys.exit(0)

print('invalid module \'{0}\'\nuse -h(--help) to see available modules'.format(module_name))
