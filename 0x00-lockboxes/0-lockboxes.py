#!/usr/bin/python3
"""
Write a method that determines if all the boxes can be opened
"""


def canUnlockAll(boxes):
    keys = [0]
    open_box = [0]
    add_key = [0]
    while add_key:
        add_key = False
        for key in boxes:
            if boxes.index(key) in keys:
                if boxes.index(key) not in open_box:
                    open_box.append(boxes.index(key))
                for num in key:
                    if num not in keys:
                        keys.append(num)
                        add_key = True
    if len(open_box) == len(boxes):
        return True
    return False
