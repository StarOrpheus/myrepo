class SimpleIO:
    __slots__ = (
        '__LOCAL__',
        'local_ifname',
        'local_ofname',
        'nonlocal_ifname',
        'nonlocal_ofname',
        'ifile',
        'ofile',
        'reader'
    )

    def __init__(self, *args, **argv):
        import sys
        self.__LOCAL__ = True if ('LOCAL' in sys.argv) else False
        self.local_ifname = "input.txt"
        self.local_ofname = "output.txt"
        self.nonlocal_ifname = "input.txt"
        self.nonlocal_ofname = "output.txt"

        self.ifile = -1
        self.ofile = -1

        if 'local' in argv.keys():
            self.__LOCAL__ = argv['local']

        if ('open' in argv.keys()) and (argv['open']):
            from sys import stdin, stdout
            ifname = self.local_ifname if self.__LOCAL__ else self.nonlocal_ifname
            ofname = self.local_ofname if self.__LOCAL__ else self.nonlocal_ofname
            self.ifile = stdin if ifname == '' else open(ifname, 'r')
            self.ofile = stdout if ofname == '' else open(ofname, 'w')
            self.reader = self.__new_reader__()

            self.test()

    def __new_reader__(self, ):
        buf = ''
        while(True):
            inp = self.ifile.read(1024).strip()
            if len(inp) == 0:
                if len(buf):
                    yield buf
                break
            for c in inp:
                if c in ' \t\v\n':
                    if(len(buf) > 0):
                        yield buf
                    buf = ''
                    continue
                buf += c

    def reset_local(self, ifname: str, ofname: str):
        from sys import stdin, stdout
        self.local_ifname = ifname
        self.local_ofname = ofname
        if self.__LOCAL__:
            self.ifile = stdin if ifname == '' else open(ifname, 'r')
            self.reader = self.__new_reader__()
            self.ofile = stdout if ofname == '' else open(ofname, 'w')
        return self

    def reset_nonlocal(self, ifname: str, ofname: str):
        from sys import stdin, stdout
        self.nonlocal_ifname = ifname
        self.nonlocal_ofname = ofname
        if not self.__LOCAL__:
            self.ifile = stdin if ifname == '' else open(ifname, 'r')
            self.reader = self.__new_reader__()
            self.ofile = stdout if ofname == '' else open(ofname, 'w')
        return self

    def print(self, *args, sep=' ', end='\n'):
        if(len(args) == 1):
            # print(self.ofile)
            self.ofile.write(str(args[0]) + end)
            self.ofile.flush()
            return

        self.ofile.write(str(args[0]))
        for x in args:
            self.ofile.write(sep + str(x))
        self.ofile.write(end)
        self.ofile.flush()

    def next_token(self, ):
        return self.reader.__next__()

    def __exit__(self, ):
        self.ifile.close()
        self.ofile.close()
        pass
