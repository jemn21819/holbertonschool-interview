#!/usr/bin/python3


import sys


def diagonals(results, N):
    # fill diagonals
    diagonals = []
    for i in results:
        # up-left
        it_row = i[0]
        it_col = i[1]
        while it_col >= 0 and it_col < N and it_row >= 0 and it_row < N:
            if [it_row, it_col] not in diagonals:
                diagonals.append([it_row, it_col])
            it_row -= 1
            it_col -= 1

        # up-right
        it_row = i[0]
        it_col = i[1]
        while it_col >= 0 and it_col < N and it_row >= 0 and it_row < N:
            if [it_row, it_col] not in diagonals:
                diagonals.append([it_row, it_col])
            it_row -= 1
            it_col += 1

        # up-right
        it_row = i[0]
        it_col = i[1]
        while it_col >= 0 and it_col < N and it_row >= 0 and it_row < N:
            if [it_row, it_col] not in diagonals:
                diagonals.append([it_row, it_col])
            it_row += 1
            it_col -= 1

        # down-right
        it_row = i[0]
        it_col = i[1]
        while it_col >= 0 and it_col < N and it_row >= 0 and it_row < N:
            if [it_row, it_col] not in diagonals:
                diagonals.append([it_row, it_col])
            it_row += 1
            it_col += 1

    return diagonals


def isSafe(row, col, results, N):
    """
    know if safe a position
    """
    # validate columns
    for _row in range(N):
        if [_row, col] in results:
            return False

    return not [row, col] in diagonals(results, N)


def chess(N):
    """
    iterate the positions
    """
    result = []
    row = 0
    col = 0

    while row < N:
        while col < N:
            if isSafe(row, col, result, N):
                result.append([row, col])
                break
            col += 1

        # if a new position not exists in results
        if len(result) != (row + 1):
            row -= 1
            if row < 0:
                break
            col = result[row][1] + 1
            del result[row]
            continue
        elif len(result) == N:
            print(result)
            col += 1
            del result[row]
            continue
        row += 1
        col = 0


def start():
    """
    N queens
    """
    args = sys.argv
    if len(args) < 2:
        print("Usage: nqueens N")
        sys.exit(1)
    try:
        int(args[1])
    except BaseException:
        print("N must be a number")
        sys.exit(1)
    if int(args[1]) < 4:
        print("N must be at least 4")
        sys.exit(1)
    N = int(args[1])
    chess(N)


if __name__ == "__main__":
    start()
