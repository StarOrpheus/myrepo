from sys import stdin, stdout, stderr, exit

class Matrix:
    def print(m, fout = stderr):
        for i in m:
            for j in i:
                fout.write(str(j) + ' ')
            fout.write('\n')

    def createMatrix(n, m, defval = 0):
        return [[defval for i in range(m)] for j in range(n)]

    def createOneMatrix(n):
        m = [[0 for j in range(n)] for i in range(n)]
        for i in range(n):
            m[i][i] = 1
        return m

    def mult(a, b, *args):
        assert len(a[0]) == len(b), 'Lol, sizes must be like N x M and M x Z'

        if(len(args) == 0):
            res = Matrix.createMatrix(len(a), len(b[0]))

            for i in range(len(a)):
                for j in range(len(b[0])):
                    for z in range(len(a[0])):
                        res[i][j] = (res[i][j] + a[i][z] * b[z][j])
        elif(len(args) == 1):
            res = Matrix.createMatrix(len(a), len(b[0]))

            for i in range(len(a)):
                for j in range(len(b[0])):
                    for z in range(len(a[0])):
                        res[i][j] = (res[i][j] + a[i][z] * b[z][j] % args[0]) % args[0]

        return res

    def binpow(a, p: int, *args):
        assert len(a) == len(a[0]), 'meme'
        if(len(args) == 0):
            res = Matrix.createOneMatrix(len(a))
            while(p > 0):
                if((p & 1) == 1):
                    res = Matrix.mult(res, a)
                a = Matrix.mult(a, a)
                p >>= 1
            return res
        elif(len(args) == 1):
            res = Matrix.createOneMatrix(len(a))
            while(p > 0):
                if((p & 1) == 1):
                    res = Matrix.mult(res, a, args[0])
                a = Matrix.mult(a, a, args[0])
                p >>= 1
            return res

def Fibonacci(*args):
    "To find n-th Fibonacci number. Use Fibonacci(n[, modulo])"
    assert (len(args) > 0 and len(args) < 3), 'wrong params conut, use (number[, mod])'

    if(len(args) == 1):
        m1 = [[1, 1], [1, 0]]
        n = args[0]
        return Matrix.mult(Matrix.binpow(m1, n-1), [[1], [1]])[0][0]
    mod = args[1]
    m1 = [[1, 1], [1, 0]]
    n = args[0]
    return Matrix.mult(Matrix.binpow(m1, n-1, mod), [[1], [1]], mod)[0][0]
