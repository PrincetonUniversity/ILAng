#!/bin/bash
source ~/cosaEnv/bin/activate
curdir=`pwd`
COSA="/home/hongce/CoSA/CoSA.py"
SOLVER=z3

for subd in GET_STATUS READ_ADDRESS READ_COUNTER READ_KEY READ_LENGTH START_ENCRYPT WRITE_ADDRESS WRITE_COUNTER WRITE_KEY WRITE_LENGTH; do
    echo "Checking Instruction:" $subd
    cd "$subd"
    $COSA --problem problem.txt --solver-name=$SOLVER --vcd
    cd "$curdir"
    echo "Finish:" $subd
    echo
done

echo 'Done.'
