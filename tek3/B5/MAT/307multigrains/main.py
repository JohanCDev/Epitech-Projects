#!/usr/bin/env python3
import os
import sys
import process


def print_helper():
    print("USAGE")
    print("\t./307multigrains n1 n2 n3 n4 po pw pc pb ps\n")
    print("DESCRIPTION")
    print("\tn1\tnumber of tons of fertilizer F1")
    print("\tn2\tnumber of tons of fertilizer F2")
    print("\tn3\tnumber of tons of fertilizer F3")
    print("\tn4\tnumber of tons of fertilizer F4")
    print("\tpo\tprice of one unit of oat")
    print("\tpw\tprice of one unit of wheat")
    print("\tpc\tprice of one unit of corn")
    print("\tpb\tprice of one unit of barley")
    print("\tps\tprice of one unit of soy")
    return 1


def check_args(argc, argv):
    if argc == 2 and argv[1] == "-h":
        return print_helper()
    if argc != 10:
        print('Invalid number of arguments')
        return -1
    for x in range(1, argc):
        try:
            value = int(argv[x])
            if value < 0:
                raise ValueError
        except ValueError:
            print(f'Invalid argument at position {x}')
            return -1
    return 0


def main(argc, argv):
    args_return = check_args(argc, argv)
    if args_return == -1:
        return 84
    elif args_return == 1:
        return 0
    else:
        return process.process(argc, argv)
