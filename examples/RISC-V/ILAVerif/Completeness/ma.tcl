analyze -sva testMem.v
elaborate -top testMem

jasper_model_mpram -init my_mpram
jasper_model_mpram -justify my_mpram
jasper_model_mpram -justify my_mpram
jasper_model_mpram -justify my_mpram
jasper_model_mpram -justify my_mpram
jasper_model_mpram -justify my_mpram

clock clk
reset rst


elaborate -clear
jasper_model_mpram -clear

