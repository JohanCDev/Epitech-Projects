#!/usr/bin/env python3
import os
import sys
import process


def print_helper():
    print("USAGE")
    print("\t./308reedpipes r0 r5 r10 r15 r20 n\n")
    print("DESCRIPTION")
    print("\tr0\tradius (in cm) of pipe at the 0cm abscissa")
    print("\tr5\tradius (in cm) of pipe at the 5cm abscissa")
    print("\tr10\tradius (in cm) of pipe at the 10cm abscissa")
    print("\tr15\tradius (in cm) of pipe at the 15cm abscissa")
    print("\tr20\tradius (in cm) of pipe at the 20cm abscissa")
    print("\tn\tnumber of points needed to display the radius")
    return 1


def check_values(argv):
    for i in range(1, 6):
        try:
            if int(argv[i]) <= 0:
                print(f'{argv[i]}: Invalid argument, must be positive', file=sys.stderr)
                return -1
        except (ValueError):
            try:
                if float(argv[i]) < 0:
                    print(f'{argv[i]}: Invalid argument, must be positive', file=sys.stderr)
                    return -1
            except (ValueError):
                print(f'{argv[i]}: Invalid argument', file=sys.stderr)
                return -1
    try:
        if int(argv[6]) <= 0:
            print(f'{argv[6]}: Invalid argument, must be positive', file=sys.stderr)
            return -1
    except ValueError:
        print(
            f'{argv[6]}: Invalid argument, needs to be an integer', file=sys.stderr)
        return -1
    return 0


def check_args(argc, argv):
    if argc == 2 and argv[1] == "-h":
        return print_helper()
    if argc != 7:
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
