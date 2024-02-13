#!/usr/bin/env python3.10
import math
from numpy.linalg import inv
import numpy as np


def print_matrix(matrix: list[list[int]]):
    for y in range(len(matrix)):
        for x in range(len(matrix)):
            end_of_line = ''
            if x + 1 < len(matrix):
                end_of_line = '\t'
            print(str(matrix[y][x]), end=end_of_line)
        print()


def process(argc, argv):
    size: int = int(argv[1])
    option_one: bool = None
    ir: int = 0
    jr = 0
    i = 0
    j = 0
    if argc == 4:
        option_one = True
        jr = int(argv[2])
        ir = int(argv[3])
    else:
        option_one = False
        jr = int(argv[2])
        ir = int(argv[3])
        j = int(argv[4])
        i = int(argv[5])
    f_matrix: list[int] = np.zeros(size**2, int)
    f_matrix[size * ir + jr] = -300
    a_matrix = np.identity(size**2, dtype=int)
    for k in range(size):
        for l in range(size):
            if k >= 1 and k < size - 1 and l >= 1 and l < size - 1:
                a_matrix[k * size + l][k * size + l] = -16
                a_matrix[k * size + l][k * size + l - 1] = 4
                a_matrix[k * size + l][k * size + l + 1] = 4
                a_matrix[k * size + l][k * size + l - size] = 4
                a_matrix[k * size + l][k * size + l + size] = 4
    a_inv = inv(a_matrix)
    if option_one:
        print_matrix(a_matrix)
        x_matrix = np.matmul(a_inv, f_matrix)
        print()
        for elem in x_matrix:
            tmp = round(round(elem, 2) * 100)
            if tmp % 10 == 5:
                tmp += 1
            tmp /= 100
            if tmp > -0.04 and tmp < 0.01:
                tmp = abs(tmp)
            elem = tmp
            print('%.1f' % elem)
    if not option_one:
        list_a = []
        x_matrix = np.matmul(a_inv, f_matrix)
        for elem in x_matrix:
            tmp = round(round(elem, 2) * 100)
            if tmp % 10 == 5:
                tmp += 1
            tmp /= 100
            if tmp > -0.04 and tmp < 0.01:
                tmp = abs(tmp)
            elem = tmp
            list_a.append(elem)
        print('%.1f' % list_a[i * size + j])
    return 0
