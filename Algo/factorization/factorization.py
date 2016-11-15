primes = []
lp = []
border = 0


def init(N: int):
    '''
    Initializing function; argument is a border
    of least prime(lp) array calculation
    '''

    global primes
    global lp
    global border

    border = N
    from factorization.prime_gen import generate
    primes, lp = generate(N)


def factorize(x: int):
    'Yields primes in factorizaion of x (in non-decreasing order)'

    assert (x >= 0), 'Input int must be non-negative!'
    assert not(x != 0 and border == 0), 'Not initialized!'

    while(x != 1):
        yield lp[x]
        x //= lp[x]


def factorize_compact(x: int):
    '''
    Yields primes in factorizaion of x (in non-decreasing order) in compact way
    like (a[i], b[j]) where x = sum(i = 0..k, a[i] ** b[j])
    '''

    assert (x >= 0), 'Input int must be non-negative!'
    assert not(x != 0 and border == 0), 'Not initialized!'

    seq_sz = 0
    l = lp[x]

    while(x != 1):
        if(lp[x] == l):
            seq_sz += 1
        else:
            yield (l, seq_sz)
            l = lp[x]
            seq_sz = 1

        x //= lp[x]

    yield (l, seq_sz)
