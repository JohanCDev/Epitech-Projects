#!/usr/bin/env python3.10
import math
import sys
import os


def process(argc, argv):
    vector = [0.0, 0.0, 0.0, 0.0, 0.0]
    radius = []
    args = {
        "r0": float(argv[1]),
        "r5": float(argv[2]),
        "r10": float(argv[3]),
        "r15": float(argv[4]),
        "r20": float(argv[5]),
        "n": int(argv[6]),
    }

    def compute_vector():
        a = 6 * (args["r0"] - 2 * args["r5"] + args["r10"]) / 50
        b = 6 * (args["r5"] - 2 * args["r10"] + args["r15"]) / 50
        c = 6 * (args["r10"] - 2 * args["r15"] + args["r20"]) / 50

        vector[2] = round((b - (a + c) / 4) * 4 / 7, 1)
        vector[1] = round(a / 2 - 0.25 * vector[2], 1)
        vector[3] = round(c / 2 - 0.25 * vector[2], 1)

        for i in range(len(vector)):
            if vector[i] == 0.0:
                vector[i] = abs(vector[i])

    def compute_radius():
        static_abscissa = [0, 5, 10, 15, 20]
        ordinate = []
        for arg_index in range(1, argc):
            if argv[arg_index] is not args['n']:
                ordinate.append(float(argv[arg_index]))

        for index in range(args["n"]):
            A = 20 / (args['n'] - 1) * index
            result = int((A - 0.01) / 5) + 1
            value = (- vector[result - 1] / 30 * pow(A - static_abscissa[result], 3)
                        + vector[result] / 30 * pow(A - static_abscissa[result - 1], 3)
                        - (ordinate[result - 1] / 5 - 5 / 6 * vector[result - 1])
                        * (A - static_abscissa[result])
                        + (ordinate[result] / 5 - 5 / 6 * vector[result])
                        * (A - static_abscissa[result - 1]))
            radius.append(value)

    compute_vector()
    compute_radius()
    print(f'vector result: {vector}')
    for index in range(args["n"]):
        abscissa = 20 / (args["n"] - 1) * index
        print(f'abscissa: %.1f cm\tradius: %.1f cm' %
              (abscissa, radius[index]))
    return 0
