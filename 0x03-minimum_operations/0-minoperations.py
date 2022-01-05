#!/usr/bin/python3
"""
0. Minimum Operations
"""

def minOperations(n):
    if n <= 1:
        return 0
    accrued = 1 # characters in the text file start always in 1
    clipBoard = 0 # number of copied characters
    operations = 0
    operations = minimumSpanning(n, accrued, clipBoard, "CopyPaste", operations)
    return operations

def minimumSpanning(n, accrued, clipBoard, action, operations):
    """Will search the shorter way """

    if accrued == n:
        return operations
    elif accrued > n:
        return 0

    if action == "CopyPaste":
        clipBoard = accrued
        accrued += clipBoard
        operations += 2
    elif action == "Paste":
        accrued += clipBoard
        operations += 1

    copySide = minimumSpanning(n, accrued, clipBoard, "CopyPaste", operations)
    pasteSide = minimumSpanning(n, accrued, clipBoard, "Paste", operations)

    if (copySide != 0 and pasteSide != 0 and copySide <= pasteSide) or copySide != 0 and pasteSide == 0:
        return copySide
    elif (copySide != 0 and pasteSide != 0 and pasteSide <= copySide) or copySide == 0 and pasteSide != 0:
        return pasteSide
    else:
        return 0
