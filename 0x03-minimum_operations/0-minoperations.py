#!/usr/bin/python3
"""
0. Minimum Operations
"""

def minOperations(n):
    if n <= 1:
        return 0
    accrued = 1 # characters in the text file start always in 1
    clipBoard = 0 # number of copied characters
    operations = dijkstra(n, accrued, clipBoard, "CopyPaste")
    if operations == None:
        return 0
    return operations

def dijkstra(n, acrued, clipBoard, action):
    copySide = 0
    pasteSide = 0

    if acrued == n:
        return 0
    elif acrued > n:
        return 100 # still looking for another way

    if action == "CopyPaste":
        clipBoard = acrued
        acrued += clipBoard
        copySide = 2 + dijkstra(n, acrued, clipBoard, "CopyPaste")
        pasteSide = 2 + dijkstra(n, acrued, clipBoard, "Paste")
    elif action == "Paste":
        acrued += clipBoard
        copySide = 1 + dijkstra(n, acrued, clipBoard, "CopyPaste")
        pasteSide = 1 + dijkstra(n, acrued, clipBoard, "Paste")

    if copySide < pasteSide:
        return copySide
    else:
        return pasteSide

