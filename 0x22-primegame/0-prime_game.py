#!/usr/bin/python3


def isWinner(x, nums):
    number = 0
    for round in range(x):
        number ^= nums[round % len(nums)]

    return "Ben" if number > 0 else "Maria"
