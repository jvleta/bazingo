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
    return board.transpose()
    

if __name__ == "__main__":
    import matplotlib.pyplot as plt
    all_numbers = np.arange(1, 76)
    board = make_board()
    
    nsims = 100000
    counts = np.zeros(nsims)
    
    for isim in range(nsims):
        matches = np.zeros((5,5), bool)
        ball_numbers = np.arange(1, 76)
        np.random.shuffle(ball_numbers)
        for index, number in enumerate(ball_numbers):
            is_number_on_board = False
            result = np.where(board == number)
            is_number_on_board = result[0].size > 0 and result[1].size > 0
            
            if (is_number_on_board):
                i = result[0][0]
                j = result[1][0]
                matches[i,j] = True
            
            if (matches[0,:].all() == True or 
               matches[1,:].all() == True or
               matches[2,:].all() == True or
               matches[3,:].all() == True or
               matches[4,:].all() == True or
               matches[:,0].all() == True or
               matches[:,1].all() == True or
               matches[:,2].all() == True or
               matches[:,3].all() == True or
               matches[:,4].all() == True or
               (matches[0,0] == True and matches[1,1] == True and matches[2,2] == True and matches[3,3] == True and matches[4,4]) or
               (matches[0,4] == True and matches[1,3] == True and matches[2,2] == True and matches[3,1] == True and matches[4,0])):
                counts[isim] = index + 1
                print("BINGO", index + 1)
                break
    np.savetxt("counts.txt", counts)
    plt.hist(counts)
    plt.show()