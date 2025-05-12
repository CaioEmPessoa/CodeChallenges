def calcular_custo_minimo(R, L, cortes):
    # Adiciona 0 e L para considerar os limites da tora
    cortes = [0] + sorted(cortes) + [L]
    N = len(cortes)

    # Criando a tabela DP
    dp = [[0] * N for _ in range(N)]

    # Preenchendo a tabela DP
    for tamanho in range(2, N):  # tamanhos da sub-tora
        for i in range(N - tamanho):  # índice do início
            j = i + tamanho  # índice do fim
            dp[i][j] = float('inf')
            for k in range(i + 1, j):  # posição do corte
                custo = dp[i][k] + dp[k][j] + (cortes[j] - cortes[i]) * R
                dp[i][j] = min(dp[i][j], custo)

    # O custo mínimo está na posição dp[0][N-1]
    return dp[0][N-1]