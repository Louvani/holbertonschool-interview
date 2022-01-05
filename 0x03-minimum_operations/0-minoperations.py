#!/usr/bin/python3
"""
0. Minimum opt
"""


def minOperations(n):
    if n <= 1:
        return 0
    accrued = 1  # characters in the text file start always in 1
    clip = 0  # number of copied characters
    opt = 0
    opt = minimumSpanning(n, accrued, clip, "CopyPaste", opt)
    return opt


def minimumSpanning(n, accrued, clipBoard, action, opt):
    """Will search the shorter way """

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
