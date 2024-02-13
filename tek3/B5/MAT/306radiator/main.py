#!/usr/bin/env python3
import os
import sys
import process


def print_helper():
    print("USAGE")
    print("\t./306radiator n ir jr [i j]\n")
    print("DESCRIPTION")
    print("\tn\tsize of the room")
    print("\t(ir, jr)\tcoordinates of the radiator")
    print("\t(i, j)\tcoordinates of a point in the room")
    return 1


def check_args(argc, argv):
    size = -1
    ir = -1
    jr = -1
    i = -1
    j = -1
    if argc == 2 and argv[1] == "-h":
        return print_helper()
    if not (argc == 4 or argc == 6):
        print("Bad arguments number, try with -h", file=sys.stderr)
        return -1
    try:
        size = int(argv[1])
        if size < 1:
            print("Room size can't be inferior or equal to 0", file=sys.stderr)
            return -1
    except ValueError:
        print("Argument", argv[1], "is not a number", file=sys.stderr)
        return -1
    for k in range(2, argc):
        try:
            if int(argv[k]) < 0 or int(argv[k]) > size:
                print("Argument", argv[k], "is invalid", file=sys.stderr)
                return -1
            if k == 2:
                ir = int(argv[k])
            if k == 3:
                jr = int(argv[k])
            if k == 4:
                i = int(argv[k])
            if k == 5:
                j = int(argv[k])
        except ValueError:
            print("Argument", argv[i], "is not a number", file=sys.stderr)
            return -1
    if (ir * size + jr) > size**2:
        print("Invalid position", file=sys.stderr)
        return -1
    if ir == 0 or ir == size - 1 or jr == 0 or jr == size - 1:
        print("Radiator is on a wall", file=sys.stderr)
        return -1
    if argc:
        if (size * i + j) > size**2:
            print("Radiator is off the wall", file=sys.stderr)
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
