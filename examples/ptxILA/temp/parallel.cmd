#!/bin/bash 
# parallel job using 16 processors. and runs for 4 hours (max) 
#SBATCH -N 1 # node count 
#SBATCH --ntasks-per-node=4 
#SBATCH -t 4:00:00 
# sends mail when process begins, and 
# when it ends. Make sure you define your email 
#SBATCH --ntasks-per-socket=2 
#SBATCH --gres=gpu:4
# Load openmpi environment 
module load cudatoolkit 

./a.out

