#!/usr/bin/env python3
import sys
import random


def myscore(consec, open, turn, board):
    if (consec == 5):
        return 9999999999
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

def computeBoard(board, player,turn):
    score = 0
    consec = 0
    open = 0
    for i in range(len(board)):
        for a in range(len(board[i])):
            if (board[i][a] == player):
                consec += 1
            elif (board[i][a] == 0 and consec > 0):
                open += 1
                score += myscore(consec, open, turn, board)
                consec = 0
                open = 1
            elif (board[i][a] == 0):
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
            if (board[a][i] == player):
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
                if (board[i][j] == player):
                   consec += 1
                elif (board[i][j] == 0 and consec > 0):
                    open += 1
                    score += myscore(consec, open, turn, board)
                    consec = 0
                    open = 1
                elif (board[i][j] == 0):
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
                if (rboard[i][j] == player):
                    consec += 1
                elif (rboard[i][j] == 0 and consec > 0):
                    open += 1
                    score += myscore(consec, open, turn, board)
                    consec = 0
                    open = 1
                elif (rboard[i][j] == 0):
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
    return (score)

def calcPoids(board, turn):
    if turn == 1:
        calcmax = computeBoard(board, 1, 0)
        calcmin = computeBoard(board, 2, 1)
    if turn == 2:
        calcmax = computeBoard(board, 1, 1)
        calcmin = computeBoard(board, 2, 0)
    minmax = calcmax - calcmin
    return minmax

def generateLine(size):
    line = [0] * size
    return (line)

def generateBoard(size):
    y = 0
    x = 0
    board = []

    while (y != size):
        board.append(generateLine(size))
        y = y + 1
    return (board)

def placePiece(board, x, y, player):
    board[y][x] = player
    return (board)

def printBoard(board):
    #print(board, sep="\n")
    return

def getMsg():
    lol =  sys.stdin.readline().strip()
    return lol

def aiMove(board):
    x = 0
    y = 0
    while (board[y][x] != 0):
        x = random.randint(0, 19)
        y = random.randint(0, 19)
    move = [x, y]
    return (move)

def createMove(move):
    val = [move[0],move[1], move[2]]
    return (val)

def createList(length):
    i = 0
    move = [0,0,-10000000000]
    info = []
    while (i != length):
        info.append(createMove(move))
        i = i + 1
    return (info)

def createEnList(length):
    i = 0
    move = [0,0,10000000000]
    info = []
    while (i != length):
        info.append(createMove(move))
        i = i + 1
    return (info)

def getMyMove(board, length, user):
    y = user[2]
    move = [0, 0, 0]
    size = len(board)
    info = createList(length)
    while (y != user[3]):
        x = user[0]
        while (x != user[1]):
            if (board[y][x] == 0):
                pos = length
                board[y][x] = 1
                move[2] = calcPoids(board, 1)
                board[y][x] = 0
                if (move[2] > info[pos - 1][2] ):
                    move[0] = y
                    move[1] = x
                    while (move[2] > info[pos - 1][2] and pos != 0):
                        pos = pos - 1
                    info.insert(pos, createMove(move))
                    test = info[length]
                    info.remove(test)
            x = x + 1
        y = y + 1
    return info

def getEnMove(board, length, user):
    y = user[2]
    move = [0, 0, 0]
    size = len(board)
    info = createEnList(length)
    while (y != user[3]):
        x = user[0]
        while (x != user[1]):
            if (board[y][x] == 0):
                pos = length
                board[y][x] = 2
                move[2] = calcPoids(board, 2)
                board[y][x] = 0
                if (move[2] < info[pos - 1][2]):
                    move[0] = y
                    move[1] = x
                    while (move[2] < info[pos - 1][2] and pos != 0):
                        pos = pos - 1
                    info.insert(pos, createMove(move))
                    test = info[length]
                    info.remove(test)
            x = x + 1
        y = y + 1
    return info

def bestAi(board, nbMove, turn, size):
    info = []
    move = [0,0,0]
    best = [0,0,0]
    place = [0,0,0]
    if (turn == 1):
        info = getMyMove(board, nbMove, size)
    else:
         info = getEnMove(board, nbMove, size)
    if (nbMove == 1):
        return info[0]
    else:
        i = 0
        if (turn == 1):
            while (i != nbMove):
                board[info[i][0]][info[i][1]] = 1
                place = bestAi(board, nbMove, 2, size)
                board[info[i][0]][info[i][1]] = 0
                if (best[2] < place[2] or i == 0):
                    best = createMove(place)
                    best[0] = info[i][0]
                    best[1] = info[i][1]
                i = i + 1
        else:
            while (i != nbMove):
                board[info[i][0]][info[i][1]] = 2
                place = bestAi(board, nbMove - 1, 1, size)
                board[info[i][0]][info[i][1]] = 0
                if (best[2] > place[2] or i == 0):
                    best = createMove(place)
                    best[0] = info[i][0]
                    best[1] = info[i][1]
                i = i + 1
    #if (best[2] < 10000):
     #   info = getEnMove(board, nbMove, size)
      #  best = info[0]
    return best

def getPion(board):
    h = 0
    l = 0
    move = [-1,-1]
    while (h != len(board)):
        l = 0
        while (l != len(board)):
            if (board[h][l] == 2):
                move[0] = h
                move[1] = l
            l = l + 1
        h = h + 1
    return move

def getStart(board):
    x = len(board)/2
    move = getPion(board)
    if (move[0] != -1):
        if move[1] + 1 < len(board) and board[move[0]][move[1] + 1] == 0:
            move[1] = move[1] + 1
        elif move[1] - 1 > - 1 and board[move[0]][move[1] - 1] == 0:
            move[1] = move[1] - 1
        elif move[0] + 1 < len(board) and board[move[0] + 1][move[1]] == 0:
            move[0] = move[0] + 1
        elif move[0] - 1 > - 1 and board[move[0] - 1][move[1]] == 0:
            move[0] = move[0] - 1
        else:
            move = aiMove(board)
    else:
        move[0] = x
        move[1] = x
    return move

def getSize(board):
    move = [-1,-1,-1,-1]
    x = 0
    y = 0
    while (y != len(board)):
        x = 0
        while (x != len(board)):
            if (board[y][x] != 0):
                if (x < move[0] or move[0] == -1):
                    move[0] = x
                if (x > move[1] or move[1] == -1):
                    move[1] = x
                if (y < move[2] or move[2] == -1):
                    move[2] = y
                if (y > move[3] or move[3] == -1):
                    move[3] = y
            x = x + 1
        y = y + 1
    return move

def resizeMove(move, board):
    move[0] = move[0] - 4
    move[1] = move[1] + 4
    move[2] = move[2] - 4
    move[3] = move[3] + 4
    if (move[0] < 0):
        move[0] = 0
    if (move[1] >= len(board)):
        move[1] = len(board) - 1
    if (move[2] < 0):
        move[2] = 0
    if (move[3] >= len(board)):
        move[3] = len(board) - 1
    return move

def optiAi(board):
    size = getSize(board)
    size = resizeMove(size, board)
    return size

gameTurn = 0

def gestionMsg(board, msg):
    global gameTurn
    list = msg.split(" ")
    if (list[0] == "START" or list[0] == "RESTART"):
        gameTurn = 0
        board = generateBoard(int(list[1]))
        print("OK")
    elif (list[0]== "TURN"):
        move = list[1].split(",")
        board = placePiece(board, int(move[0]), int(move[1]), 2)
        if (gameTurn == 0):
            move = getStart(board)
        else:
            size = optiAi(board)
            move = bestAi(board, 2, 1, size)
        a = move[0]
        move[0] = move[1]
        move[1] = a
        board = placePiece(board, int(move[0]), int(move[1]), 1)
        ret = str(str(move[0]) + "," + str(move[1]))
        print(ret)
        gameTurn = 1
    elif (msg == "BEGIN"):
        gameTurn = 1
        x = int(len(board)/2)
        move = [x, x]
        board = placePiece(board, int(move[0]), int(move[1]), 1)
        ret = str(str(move[0]) + "," + str(move[1]))
        print(ret)
    elif (msg == "BOARD"):
        a = 0
        while (a == 0):
            msg = getMsg()
            if (msg == "DONE"):
                a = 1
            else:
                move = msg.split(",")
                board = placePiece(board, int(move[0]), int(move[1]), int(move[2]))
        move = aiMove(board)
        board = placePiece(board, int(move[0]), int(move[1]), 1)
        ret = str(str(move[0]) + "," + str(move[1]))
        print(ret)
    elif (msg == "INFO"):
        #afficher l'info
        return
    elif(msg == "END"):
        sys.exit(0)
    elif (msg == "ABOUT"):
        print("name=\"WOW\", version=\"1.0\", author=\"Jacques/MONO/REMY\", country=\"FR\"")
    elif (msg == "BOARD"):
        printBoard(board)
    sys.stdout.flush()
    return (board)

def main():
    board = generateBoard(20)
    while(1):
        msg = getMsg()
        board = gestionMsg(board, msg)

if __name__ == '__main__':
    main()
