#!/usr/bin/env python3.10
import sys
import bubble_sort
import insertion_sort
import selection_sort
import quicksort
import merge_sort
import os
import re
import matplotlib.pyplot as plt


def create_plot(selection_comps, insertion_comps, bubble_comps, quick_comps, merge_comps):
    plt.bar("selection", selection_comps)
    plt.bar("insertion", insertion_comps)
    plt.bar("bubble", bubble_comps)
    plt.bar("quick", quick_comps)
    plt.bar("merge", merge_comps)
    plt.xlabel("Type of sort")
    plt.ylabel("Number of swap checks")
    plt.show()


def check_file_validity(numbers_array):
    for i in numbers_array:
        try:
            j = int(i)
        except ValueError:
            try:
                j = float(i)
            except ValueError:
                print("Value", i, "is not valid", file=sys.stderr)
                return 84
    return 0


def process(argc, argv):
    try:
        f = open(argv[1])
    except FileNotFoundError:
        print("File doesn't exists", file=sys.stderr)
        return 84
    if os.path.getsize(argv[1]) == 0:
        print("File is empty", file=sys.stderr)
        f.close()
        return 84
    numbers_array = f.readline()
    numbers_array = re.sub('[a-zA-Z]', ' ', numbers_array)
    numbers_array = numbers_array.split()
    if check_file_validity(numbers_array) == 84:
        return 84
    sys.setrecursionlimit(100000)
    for i in range(len(numbers_array)):
        numbers_array[i] = float(numbers_array[i])
    selection_comps = selection_sort.sort(numbers_array)
    insertion_comps = insertion_sort.sort(numbers_array)
    bubble_comps = bubble_sort.sort(numbers_array)
    arr, quick_comps = quicksort.sort(numbers_array)
    merge_comps = merge_sort.sort(numbers_array)
    print(len(numbers_array), "element", end='')
    print("s" if len(numbers_array) > 1 else "")
    print("Selection sort:", selection_comps, "comparisons")
    print("Insertion sort:", insertion_comps,
          "comparisons")
    print("Bubble sort:", bubble_comps, "comparisons")
    print("Quicksort:", quick_comps, "comparisons")
    print("Merge sort:", merge_comps, "comparisons")
    f.close()
    create_plot(selection_comps, insertion_comps, bubble_comps, quick_comps, merge_comps)
    return 0
