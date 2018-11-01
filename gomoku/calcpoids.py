#!/usr/bin/env python3

def myscore(consec, open, turn, board):
    if (open == 0 and consec < 5):
        return 0
    elif consec == 4:
        if open == 1:
            if turn == 1:
                return 100000000
            else:
                return 50
        elif open == 2:
            if turn == 1:
                return 100000000
            else:
                return 500000
    elif consec == 3:
        if open == 1:
            if turn == 1:
                return 7
            else:
                return 5
        elif open == 2:
            if turn == 1:
                return 10000
            else:
                return 50
    elif consec == 2:
        if open == 1:
                return 2
        elif open == 2:
                return 5
    elif consec == 1:
        if open == 1:
                return 0.5
        elif open == 2:
                return 1
    else:
        return 200000000

def calcPoids(board):
    score = 0
    consec = 0
    open = 0
    turn = 1
    for i in range(len(board)):
        for a in range(len(board[i])):
            if (board[i][a] == '1'):
                consec += 1
            elif (board[i][a] == 0 and consec > 0):
                open += 1
                score += myscore(consec, open, turn, board)
                consec = 0
                open = 1
            elif (board[i][a] == '0'):
                open = 1
            elif (consec > 0):
                score += myscore(consec, open, turn, board)
                consec = 0
                open = 0
            else:
                open = 0
        if (consec > 0):
            score += myscore(consec, open, turn, board)
            consec = 0
            open = 0
    consec = 0
    open = 0

    for i in range(len(board[0])):
        for a in range(len(board)):
            if (board[a][i] == '1'):
                consec += 1
            elif (board[a][i] == 0 and consec > 0):
                open += 1
                score += myscore(consec, open, turn, board)
                consec = 0
                open = 1
            elif (board[a][i] == '0'):
                open = 1
            elif (consec > 0):
                score += myscore(consec, open, turn, board)
                consec = 0
                open = 0
            else:
                open = 0
        if (consec > 0):
            score += myscore(consec, open, turn, board)
            consec = 0
            open = 0
    consec = 0
    open = 0
    for k in range(0,len(board) * 2):
        for j in range(0, k + 1):
            i = k - j
            if i < len(board) and j < len(board):
                if (board[i][j] == '1'):
                   consec += 1
                elif (board[i][j] == 0 and consec > 0):
                    open += 1
                    score += myscore(consec, open, turn, board)
                    consec = 0
                    open = 1
                elif (board[i][j] == '0'):
                    open = 1
                elif (consec > 0):
                    score += myscore(consec, open, turn, board)
                    consec = 0
                    open = 0
                else:
                    open = 0
        if (consec > 0):
            score += myscore(consec, open, turn, board)
            consec = 0
            open = 0

    rboard = list(zip(*board[::-1]))
    for k in range(0,len(rboard) * 2):
        for j in range(0, k + 1):
            i = k - j
            if i < len(rboard) and j < len(rboard):
                if (rboard[i][j] == '1'):
                    consec += 1
                elif (rboard[i][j] == 0 and consec > 0):
                    open += 1
                    score += myscore(consec, open, turn, board)
                    consec = 0
                    open = 1
                elif (rboard[i][j] == '0'):
                    open = 1
                elif (consec > 0):
                    score += myscore(consec, open, turn, board)
                    consec = 0
                    open = 0
                else:
                    open = 0
        if (consec > 0):
            score += myscore(consec, open, turn, board)
            consec = 0
            open = 0
    print(score)
