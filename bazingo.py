import numpy as np

def make_board():
    b_numbers = np.arange(1, 16)
    i_numbers = np.arange(16, 31)
    n_numbers = np.arange(31, 46)
    g_numbers = np.arange(46, 51)
    o_numbers = np.arange(51, 76)

    bb = np.random.choice(b_numbers, 5, replace=False)
    ii = np.random.choice(i_numbers, 5, replace=False)
    nn = np.random.choice(n_numbers, 5, replace=False)
    gg = np.random.choice(g_numbers, 5, replace=False)
    oo = np.random.choice(o_numbers, 5, replace=False)

    board = np.array([bb, ii, nn, gg, oo])

if __name__ == "__main__":
    all_numbers = np.arange(1, 76)
    board = make_board()
    print(board.transpose())