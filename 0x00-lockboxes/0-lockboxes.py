#!/usr/bin/python3
"""
Write a method that determines if all the boxes can be opened
"""


def canUnlockAll(boxes):
    keys = [0]
    for num in keys:
        for key in boxes[num]:
            if key not in keys:
                if key < len(boxes):
                    keys.append(key)
    if len(keys) == len(boxes):
        return True
    return False
