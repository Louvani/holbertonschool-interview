#!/usr/bin/python3
'''0. Rain module'''

from traceback import walk_stack


def rain(walls):
    '''calculate how many square units of
    water will be retained after it rains.'''
    units = 0
    wallsLen = len(walls)
    for index in range(1, wallsLen - 1):
        left = walls[index]
        for j in range(index):
            left = max(left, walls[j])

        right = walls[index]
        for j in range(index + 1, wallsLen):
            right = max(right, walls[j])

        units = units + min(left, right) - walls[index]
    return units
