import itertools
import sys
import matplotlib.pyplot as plt
import matplotlib
import numpy as np
from scipy.stats.mstats import gmean


from plot import read8051

def main():
    matplotlib.rcParams.update({'font.size': 16})
    fig = plt.figure(figsize=(8,4))
    ax = fig.add_subplot(111)
    plot8051(ax)
    plt.tight_layout()
    plt.savefig('images/8051times.pdf')

    plt.show()

if __name__ == '__main__':
    main()


