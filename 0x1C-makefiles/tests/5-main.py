#!/usr/bin/python3
"""
5-main test
"""
island_perimeter = __import__('5-island_perimeter').island_perimeter

if __name__ == "__main__":
    grid = [
        [1, 1, 1, 1, 1, 1],
        [0, 1, 0, 0, 0, 0],
        [0, 1, 0, 0, 0, 0],
        [0, 1, 1, 1, 2, 2],
        [0, 0, 0, 0, 0, 0]
     ]
print(island_perimeter(grid))