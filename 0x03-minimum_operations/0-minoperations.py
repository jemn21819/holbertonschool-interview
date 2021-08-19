#!/usr/bin/python3
"""
Given a number n, write a method that calculates the fewest number of
operations needed to result in exactly n H characters in the file.
"""


def minOperations(n):
    """"""
    if n < 2:
        return 0
    op_num = 0
    h = 1
    cp_all = 0
    while h != n:
        if n % h == 0:
            cp_all = h
            h = h + cp_all
            op_num = op_num + 2
        else:
            h = h + cp_all
            op_num = op_num + 1
    return op_num
