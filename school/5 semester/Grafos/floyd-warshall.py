def warshall(W):
    n = len(W)
    
    D = []
    
    D.append([row[:] for row in W])
    
    for k in range(1, n + 1):
        D.append([[0 for o in range(n)] for p in range(n)])
        
        for i in range(n):
            for j in range(n):
                D[k][i][j] = min(
                    D[k-1][i][j], 
                    D[k-1][i][k-1] + D[k-1][k-1][j]
                )
    
    return D[n]


if __name__ == "__main__":
    # casos de teste

    INF = float('inf')

    tests = [
        {
            "input" : [
                [0, 2, INF],
                [INF, 0, 3],
                [INF, INF, 0]
            ],
            "output": [
                [0, 2, 5],
                [INF, 0, 3],
                [INF, INF, 0]
            ]
        },
        {
            "input" : [
                [0, 3, 8, INF],
                [INF, 0, INF, 1],
                [INF, 4, 0, INF],
                [2, INF, 5, 0]
            ],
            "output": [
                [0, 3, 8, 4],
                [3, 0, 6, 1],
                [7, 4, 0, 5],
                [2, 5, 5, 0]
            ]
        },
        {
            "input" : [
                [0, 2, INF, INF, INF],
                [INF, 0, 3, INF, INF],
                [INF, INF, 0, 1, INF],
                [INF, INF, INF, 0, 4],
                [INF, INF, INF, INF, 0]
            ],
            "output": [
                [0, 2, 5, 6, 10],
                [INF, 0, 3, 4, 8],
                [INF, INF, 0, 1, 5],
                [INF, INF, INF, 0, 4],
                [INF, INF, INF, INF, 0]
            ]
        }
    ]

    for test in tests:
        inp = test["input"]
        out = test["output"]
        
        result = warshall(inp)


        if result == out:
            print("Funcionou!")
        else:
            print("Erro!")