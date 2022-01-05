#!/usr/bin/python3
"""
0. Minimum opt
"""


def minOperations(n):
    if not isinstance(n, int) or n <= 1:
        return 0
    accrued = 1  # characters in the text file start always in 1
    count = 0
    while (accrued < n):
        rest = n - accrued

        if (rest % accrued == 0):
            clipBoard = accrued
            accrued += clipBoard
            count += 2
        else:
            accrued += clipBoard
            count = count + 1

    return (count)


def minimumSpanning(n, accrued, clipBoard, action, opt):
    """
    will go through the options to find the shortest
    The proble is that consume to much space, seem to be an infinite recursion
    """

    if accrued == n:
        return opt
    elif accrued > n:
        return 0

    if action == "CopyPaste":
        clipBoard = accrued
        accrued += clipBoard
        opt += 2
    elif action == "Paste":
        accrued += clipBoard
        opt += 1

    copy = minimumSpanning(n, accrued, clipBoard, "CopyPaste", opt)
    paste = minimumSpanning(n, accrued, clipBoard, "Paste", opt)

    if (copy != 0 and paste != 0 and copy <= paste) or (
         copy != 0 and paste == 0):
        return copy
    elif (copy != 0 and paste != 0 and paste <= copy) or (
         copy == 0 and paste != 0):
        return paste
    else:
        return 0
