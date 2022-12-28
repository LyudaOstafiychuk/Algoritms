import pprint 

from math import log2 

def create_grid(no_of_players): 
    if not log2(no_of_players).is_integer() or no_of_players == 1:
        print("Wrong number of players for this algorythm:", no_of_players
        return

    if no_of_players == 2:
        print("Got to the base case: 2 persons, returning...")
        return [[2],[1]]

    prev_grid = create_grid(no_of_players//2)
    new_grid = [[0] * (no_of_players - 1) for _ in range(no_of_players)]

    for i, row in enumerate(prev_grid):
        for j, el in enumerate(row):
            new_grid[i][j] = el
            new_grid[i + no_of_players//2][j] = el + no_of_players//2

    high_oponents = [x for x in range(no_of_players // 2 + 1, no_of_players + 1)]
    low_oponents  = [x for x in range(1, no_of_players//2 + 1)]
    for col in range(no_of_players // 2):
        for row in range(no_of_players // 2):
            new_grid[row][col + no_of_players//2 - 1] = high_oponents[row]
            new_grid[row + no_of_players // 2][col + no_of_players//2 - 1] = low_oponents[row]
            
        high_oponents.append(high_oponents.pop(0))
        low_oponents.insert(0, low_oponents.pop())

    print("Done with {} players, currnet grid:".format(no_of_players))
    pprint.pp(new_grid)
    print("Returning...")

    return new_grid





pprint.pp(create_grid(8))
