from sys import exit
import queue

inputf = open('input.txt', 'r')
outputf = open('output.txt', 'w')

def readil():
    return list(map(int, inputf.readline().strip().split()))

a = [inputf.readline().strip() for i in range(10)]
f = [[0 for j in range(10)] for i in range(10)]
mp = []

dx = (-1, 0, 1, 0)
dy = (0, 1, 0, -1)


def check(x, y):
    return (x < 10 and y < 10 and x >= 0 and y >= 0)


def bfs(cord, id):
    q = queue.Queue(maxsize=50)
    q.put_nowait(cord)
    mp.append(set())
    mp[-1].add(cord)
    while(not q.empty()):
        x, y = q.get_nowait()
        f[x][y] = id
        for it in range(4):
            nx, ny = x + dx[it], y + dy[it]
            if(not check(nx, ny) or f[nx][ny] != 0 or a[nx][ny] != '#'):
                continue
            f[nx][ny] = id
            mp[-1].add((nx, ny))

            q.put_nowait((nx, ny))

def main():
    m = readil()[0]
    ships_c = 0
    for i in range(10):
        for j in range(10):
            if(a[i][j] == '#' and f[i][j] == 0):
                ships_c += 1
                bfs((i, j), ships_c)
    for _ in range(m):
        x, y = inputf.readline().strip().split()
        x = int(x) - 1
        # stderr.write(str((x, y)))
        if(ord(y) > ord('j')):
            y = ord(y) - ord('a') - 1
        else:
            y = ord(y) - ord('a')
        if(a[x][y] == '.'):
            outputf.write('MISS\n')
            continue
        mp[f[x][y] - 1].discard((x, y))
        a[x] = a[x][:y] + '.' + a[x][y + 1:]
        if(len(mp[f[x][y] - 1])):
            outputf.write('HIT\n')
        else:
            gg = True
            for rec in mp:
                if(len(rec)):
                    gg = False
                    break

            if(gg):
                outputf.write('GAME OVER')
                exit(0)
            outputf.write('DEAD\n')

if __name__ == '__main__':
    main()

inputf.close()
outputf.close()
