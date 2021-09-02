#!/usr/bin/python3
"""
reads stdin line by line and computes metrics
"""
import sys

status_code = ['200', '301', '400', '401', '403', '404', '405', '500']
num = [0, 0, 0, 0, 0, 0, 0, 0]
f_size = 0
count = 0
try:
    for line in sys.stdin:
        linesp = line.split(" ")
        if len(linesp) > 2:
            size = linesp[-1]
            scode = linesp[-2]
            if scode in status_code:
                i = status_code.index(scode)
                num[i] += 1
            f_size += int(size)
            count += 1
        if count == 10:
            print("File size: {}".format(f_size))
            for i in range(8):
                if num[i] != 0:
                    print("{}: {}".format(status_code[i], num[i]))
            count = 0
except Exception:
    pass
finally:
    print("File size: {}".format(f_size))
    for i in range(8):
        if num[i] != 0:
            print("{}: {}".format(status_code[i], num[i]))
