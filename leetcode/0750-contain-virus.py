class Solution:
    def containVirus(self, grid: List[List[int]]) -> int:
        current_set_number = 1
        grid_set = [[0 for i in range(len(grid[0]))] for j in range(len(grid))]
        set_grid = {}
        threaten = {}

        def getAdjacentCellsSet(row, col) -> List[int]:
            answer = []
            if row != 0 and grid_set[row-1][col] != 0 and grid_set[row-1][col] not in answer:
                answer.append(grid_set[row-1][col])
            if col != 0 and grid_set[row][col-1] != 0 and grid_set[row][col-1] not in answer:
                answer.append(grid_set[row][col-1])
            if row != len(grid)-1 and grid_set[row+1][col] != 0 and grid_set[row+1][col] not in answer:
                answer.append(grid_set[row+1][col])
            if col != len(grid[0])-1 and grid_set[row][col+1] != 0 and grid_set[row][col+1] not in answer:
                answer.append(grid_set[row][col+1])
            if -1 in answer:
                answer.remove(-1)
            if grid_set[row][col] in answer:
                answer.remove(grid_set[row][col])
            return answer

        # Merge all regions to the first one.
        def merge(regions: List[int]):
            merge_to = regions[0]
            for i in range(1, len(regions)):
                for x, y in set_grid[regions[i]]:
                    grid_set[x][y] = merge_to
                set_grid[merge_to] += set_grid[regions[i]]
                del set_grid[regions[i]]
                if regions[i] in threaten:
                    del threaten[regions[i]]

        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1:
                    adjacent_sets = getAdjacentCellsSet(i, j)
                    set_number = 0
                    if len(adjacent_sets) == 0:
                        set_number = current_set_number
                        current_set_number += 1
                    elif len(adjacent_sets) == 1:
                        set_number = adjacent_sets[0]
                    else:  # Merge
                        merge(adjacent_sets)
                        set_number = adjacent_sets[0]
                    grid_set[i][j] = set_number
                    if set_number not in set_grid:
                        set_grid[set_number] = []
                    set_grid[set_number].append((i, j))

        def adjacentThreatened(x, y):
            answer = []
            if x != 0 and grid_set[x-1][y] == 0:
                answer.append((x-1, y))
            if y != 0 and grid_set[x][y-1] == 0:
                answer.append((x, y-1))
            if x != len(grid_set)-1 and grid_set[x+1][y] == 0:
                answer.append((x+1, y))
            if y != len(grid_set[0])-1 and grid_set[x][y+1] == 0:
                answer.append((x, y+1))
            return answer

        def threatenCells():
            for i in set_grid:
                if i == 0 or i == -1:
                    continue
                threatened = set()
                for x, y in set_grid[i]:
                    threatened = threatened.union(adjacentThreatened(x, y))
                threaten[i] = len(threatened)

        def contain(set_number):
            wall = 0
            for x, y in set_grid[set_number]:
                grid_set[x][y] = -1
                if x != 0 and grid_set[x-1][y] == 0:
                    wall += 1
                if y != 0 and grid_set[x][y-1] == 0:
                    wall += 1
                if x != len(grid_set)-1 and grid_set[x+1][y] == 0:
                    wall += 1
                if y != len(grid_set[0])-1 and grid_set[x][y+1] == 0:
                    wall += 1
            del set_grid[set_number]
            del threaten[set_number]
            return wall

        def spread():
            to_spread = deque()
            for _, v in set_grid.items():
                to_spread.extend(v)
            while len(to_spread) > 0:
                x, y = to_spread.popleft()
                current_set = grid_set[x][y]
                if x != 0 and grid_set[x-1][y] == 0:
                    grid_set[x-1][y] = current_set
                    set_grid[current_set].append((x-1, y))
                    adj = getAdjacentCellsSet(x-1, y)
                    merge([current_set]+adj)
                if y != 0 and grid_set[x][y-1] == 0:
                    grid_set[x][y-1] = current_set
                    set_grid[current_set].append((x, y-1))
                    adj = getAdjacentCellsSet(x, y-1)
                    merge([current_set]+adj)
                if x != len(grid_set)-1 and grid_set[x+1][y] == 0:
                    grid_set[x+1][y] = current_set
                    set_grid[current_set].append((x+1, y))
                    adj = getAdjacentCellsSet(x+1, y)
                    merge([current_set]+adj)
                if y != len(grid_set[0])-1 and grid_set[x][y+1] == 0:
                    grid_set[x][y+1] = current_set
                    set_grid[current_set].append((x, y+1))
                    adj = getAdjacentCellsSet(x, y+1)
                    merge([current_set]+adj)

        answer = 0
        threatenCells()
        # print(grid_set)
        # print(answer)
        while len(threaten) != 0:
            # print(threaten)
            largest_infected = sorted(
                threaten.items(), key=lambda x: x[1], reverse=True)[0]
            answer += contain(largest_infected[0])
            spread()
            # print(grid_set)
            # print(answer)
            threatenCells()
        return answer
