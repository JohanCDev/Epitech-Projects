#!/usr/bin/env python3
import os
import sys
import process
import csv


def print_helper():
    print("USAGE")
    print("\t./309pollution n file x y\n")
    print("DESCRIPTION")
    print("\tn\tnumber of points on the grid axis")
    print("\tfile\tcsv file containing the data points x;y;p")
    print("\tx\tabscissa of the point whose pollution level we want to know")
    print("\ty\ordinate of the point whose pollution level we want to know")
    return 1


def check_file(filename, n):
    if os.path.getsize(filename) == 0:
        return -1
    with open(filename, "r") as file:
        csvreader = csv.reader(file, delimiter=";")
        for row in csvreader:
            if len(row) != 3:
                return -1
            try:
                x = int(row[0])
                y = int(row[1])
                p = int(row[2])
                if x < 0 or y < 0:
                    return -1
                if x > n - 1 or y > n - 1:
                    return -1
                if p < 0 or p > 100:
                    return -1
            except ValueError:
                return -1
    return 0


def check_values(argv):
    try:
        n = int(argv[1])
        x = float(argv[3])
        y = float(argv[4])
        if n <= 0 or x < 0 or y < 0:
            return -1
        if x > n - 1 or y > n - 1:
            return -1
        if not os.path.isfile(argv[2]):
            return -1
    except ValueError:
        return -1
    return check_file(argv[2], n)


def check_args(argc, argv):
    if argc == 2 and argv[1] == "-h":
        return print_helper()
    if argc != 5:
        return -1
    return check_values(argv)


def main(argc, argv):
    args_return = check_args(argc, argv)
    if args_return == -1:
        return 84
    elif args_return == 1:
        return 0
    else:
        return process.process(argc, argv)
