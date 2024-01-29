#!/usr/bin/python3
"""function that measures island perimeter defined"""


def island_perimeter(grid):
    """Perimiter of an island returned"""
    width = len(grid[0])
    height = len(grid)
    edgs = 0
    size = 0

    for a in range(height):
        for b in range(width):
            if grid[a][b] == 1:
                size += 1
                if (b > 0 and grid[a][b - 1] == 1):
                    edgs += 1
                if (a > 0 and grid[a - 1][b] == 1):
                    edgs += 1
    return size * 4 - edgs * 2
