#!/usr/bin/env python3.10
import csv
import math
import sys
import os


def getFileContent(filename):
    with open(filename, 'r') as f:
        return [elem.replace('\n', '') for elem in f.readlines()]


def compute(n, x, y, m):
    def coefficientBinomial(n, k):
        return math.factorial(n) / (math.factorial(k) * math.factorial(n - k))

    def bezier(n, coords, k):
        return math.pow(coords / n, k) * math.pow(1 - (coords / n), n - k)

    pollution = 0

    for i in range(n):
        for j in range(n):
            pollution += coefficientBinomial(n - 1, i) * coefficientBinomial(
                n - 1, j) * bezier(n - 1, x, i) * bezier(n - 1, y, j) * m[i][j]
    return pollution


def process(argc, argv):
    n = int(argv[1])
    filename = argv[2]
    x = float(argv[3])
    y = float(argv[4])
    file_content = []
    tmp = getFileContent(filename)

    for line in tmp:
        elems = line.split(';')
        file_content.append([int(elem) for elem in elems])
    m = [[0 for _ in range(n)] for _ in range(n)]
    for coords in file_content:
        m[coords[0]][coords[1]] = coords[2]
    print('{:.2f}'.format(compute(n, x, y, m)))
    return 0
