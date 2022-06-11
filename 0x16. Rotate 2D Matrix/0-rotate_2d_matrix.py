#!/usr/bin/python3
"""
rotate a matrix 90 degrees clockwise.
"""


def rotate_2d_matrix(matrix):
    """
    rotate a matrix 90 degrees clockwise.
    """
    n = len(matrix)

    def rotate_matrix(i, j, s):
        if s < 4:
            rotate_matrix(j, n - 1 - i, s + 1)
            matrix[i][j] = matrix[n - 1 - j][i]
            if s == 0:
                matrix[i][j] = v

    for i in range(n // 2):
        for j in range(i, n - 1 - i):
            v = matrix[n - 1 - j][i]
            rotate_matrix(i, j, 0)
