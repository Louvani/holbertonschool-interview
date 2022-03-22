#!/usr/bin/python3
""" 0. N queens """

from sys import exit, argv


def input(args):
    """ validate input arguments """
    if (len(args) == 2):
        try:
            num = int(args[1])
        except Exception:
            print("N must be a number")
            exit(1)
        if num < 4:
            print("N must be at least 4")
            exit(1)
        return num
    else:
        print("Usage: nqueens N")
        exit(1)


def print_board(board):
    """ print_board """
    new_list = []
    for idx, row in enumerate(board):
        value = []
        for idx2, col in enumerate(row):
            if col == 1:
                value.append(idx)
                value.append(idx2)
        new_list.append(value)

    print(new_list)


def isSafe(board, row, col, number):
    """ check if the cell is under attack by any other queen or not."""

    for i in range(col):
        if board[row][i] == 1:
            return False

    for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False

    for i, j in zip(range(row, number, 1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False

    return True


def N_queen(board, col, number):
    """Show of the all the posibilites to solve the problem"""

    if (col == number):
        print_board(board)
        return True
    res = False
    for i in range(number):

        if (isSafe(board, i, col, number)):

            board[i][col] = 1

            res = N_queen(board, col + 1, number) or res

            board[i][col] = 0

    return res


def solve(number):
    """ Find all the posibilities if exists"""
    board = [[0 for i in range(number)]for i in range(number)]

    if not N_queen(board, 0, number):
        return False

    return True


if __name__ == "__main__":
    """ Top-level code environment"""

    number = input(argv)
    solve(number)