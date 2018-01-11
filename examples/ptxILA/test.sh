#! /bin/bash

python data_race/direct_nd/ptx_tokenizer_bra.py
python data_race/direct_nd/ptx_ld_set.py
python data_race/direct_nd/ptx_pred_map_generator.py
python data_race/direct_nd/ptxILAdirect_nd_lockstep_warp.py
python data_race/direct_nd/ptx_ld_set.py
python data_race/direct_nd/ptxILAdirect_nd_detail_new2.py
python ptxILA.py
python ptxTwoThreadsILA.py
