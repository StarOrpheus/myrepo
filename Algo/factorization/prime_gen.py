def generate(N: int):
    lp = [0 for i in range(N+1)]
    pr = []

    for i in range(2, N+1):
        if(lp[i] == 0):
            pr.append(i)
            lp[i] = i

        j = 0
        while(j < len(pr) and pr[j] <= lp[i] and i*pr[j] <= N):
            lp[i*pr[j]] = pr[j]
            j += 1

    return pr, lp
