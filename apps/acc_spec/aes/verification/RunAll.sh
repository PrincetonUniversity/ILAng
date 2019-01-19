#!/bin/bash
#source ~/cosaEnv/bin/activate
curdir=`pwd`
COSA="CoSA"
SOLVER=btor

for subd in WRITE_ADDRESS GET_STATUS READ_ADDRESS READ_COUNTER READ_KEY READ_LENGTH START_ENCRYPT  WRITE_COUNTER WRITE_KEY WRITE_LENGTH; do
    echo "------------------------------------------------"
    echo "Start checking instruction:" $subd
    cd "$subd"
    $COSA --problem problem.txt --solver-name=$SOLVER --vcd
    cd "$curdir"
    echo "Finish:" $subd
    echo "------------------------------------------------"
    echo
done

echo 'Now on sub-ILA:AES_BLOCK'
for subd in LOAD STORE OPERATE; do
    echo "------------------------------------------------"
    echo "Start checking sub-instruction:" $subd
    cd "$subd"
    $COSA --problem problem.txt --solver-name=$SOLVER --vcd
    cd "$curdir"
    echo "Finish:" $subd
    echo "------------------------------------------------"
    echo
done

echo 'Now on sub-ILA:AES_128_Rnd'
for subd in FirstRound IntermediateRound FinalRound; do
    echo "------------------------------------------------"
    echo "Start checking sub-instruction:" $subd
    cd "$subd"
    $COSA --problem problem.txt --solver-name=$SOLVER --vcd
    cd "$curdir"
    echo "Finish:" $subd
    echo "------------------------------------------------"
    echo
done


echo 'Done.'
