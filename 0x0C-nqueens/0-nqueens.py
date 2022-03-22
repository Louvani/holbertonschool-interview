#!/usr/bin/python3
""" 0. N queens """

from sys import exit, argv


if __name__ == "__main__":

    if len(argv) != 2:
        print("Usage: nqueens N")
        exit(1)

    queens = argv[1]

    try:
        queens = int(queens)
    except ValueError:
        print("N must be a number")
        exit(1)

    if queens < 4:
        print("N must be at least 4")
        exit(1)

    result = []

    def nqueens(row, queens, result):
        """ method docs """
        if (row == queens):
            print(result)
        else:
            for col in range(queens):
                pos = [row, col]
                if validposition(result, pos):
                    result.append(pos)
                    nqueens(row + 1, queens, result)
                    result.remove(pos)

    def validposition(result, position):
        """ validate the psoition """
        for queen in result:
            if queen[1] == position[1] or \
                (queen[0] - queen[1]) == (position[0] - position[1]) or \
                    (queen[0] + queen[1]) == (position[0] + position[1]):
                return False
        return True

    nqueens(0, queens, result)
