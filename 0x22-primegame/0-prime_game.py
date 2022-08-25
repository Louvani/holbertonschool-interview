#!/usr/bin/python3
"""
Module to finde the winer in the prime game
"""


def isWinner(x, nums):
    """
        Function to finde the winer in the prime game
    """
    number = 0
    for round in range(x):
        number ^= nums[round % len(nums)]

    return "Ben" if number > 0 else "Maria"
