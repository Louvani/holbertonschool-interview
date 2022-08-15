#!/usr/bin/python3
"""
A module to resolve the problem of the pascal triangle
"""


def pascal_triangle(n):
    """Return a list of lists contain the pascal triangle"""
    if n <= 0:
        return []

    list_pascal = []

    for i in range(n):
        list_pascal.append([])
        list_pascal[i].append(1)
        for j in range(1, i):
            list_pascal[i].append(
                list_pascal[i - 1][j - 1] + list_pascal[i - 1][j])
        if i != 0:
            list_pascal[i].append(1)

    return list_pascal
