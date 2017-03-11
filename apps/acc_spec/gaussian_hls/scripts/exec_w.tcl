# Assumptions for proving write instruction 
# Execute: start and stop models
#
# start
assume -name {start model} -env \
{ counter <= 2 |-> ( \
    hls_complete == 0 & \
    ila_complete == 0 \
)} -type {temporary} -update_db;

# stop
assume -name {exec ila - continue} -env \
{ (counter > 1) |-> ( \
    ( \
    ((ila_U.in_stream_full == 0) & (ila_U.arg_1_TREADY == 0)) | \
    ((ila_U.slice_stream_full == 0) & (ila_U.in_stream_empty == 0)) | \
    ((ila_U.stencil_stream_full == 0) & (ila_U.slice_stream_empty == 0)) | \
    ((ila_U.arg_0_TVALID == 0) & (ila_U.stencil_stream_empty == 0)) 
    ) \
    |=> \
    (ila_complete == 0) \
)} -type {temporary} -update_db;
# 
assume -name {exec ila - break} -env \
{ (counter > 1) |-> ( \
    ~( \
    ((ila_U.in_stream_full == 0) & (ila_U.arg_1_TREADY == 0)) | \
    ((ila_U.slice_stream_full == 0) & (ila_U.in_stream_empty == 0)) | \
    ((ila_U.stencil_stream_full == 0) & (ila_U.slice_stream_empty == 0)) | \
    ((ila_U.arg_0_TVALID == 0) & (ila_U.stencil_stream_empty == 0)) 
    ) \
    |=> \
    (ila_complete == 1) \
)} -type {temporary} -update_db;
# 
assume -name {exec ila} -env \
{ (counter > 1) |-> ( \
    ( \
    ((ila_U.in_stream_full == 0) & (ila_U.arg_1_TREADY == 0)) | \
    ((ila_U.slice_stream_full == 0) & (ila_U.in_stream_empty == 0)) | \
    ((ila_U.stencil_stream_full == 0) & (ila_U.slice_stream_empty == 0)) | \
    ((ila_U.arg_0_TVALID == 0) & (ila_U.stencil_stream_empty == 0)) 
    ) \
    |=> ila_exec == 0\
)} -type {temporary} -update_db;
#
#assume -name {exec ila - continue} -env \
{ (counter > 1) |-> ( \
    (ila_exec == 1) |=> (ila_complete == 0) \
)} -type {temporary} -update_db;
#
#assume -name {exec ila - break} -env \
{ (counter > 1) |-> ( \
    (ila_exec == 0) |=> (ila_complete == 1) \
)} -type {temporary} -update_db;

assume -env \
{ (counter == 0) |=> ( \
    ( \
    ((ila_U.in_stream_full == 0) & (ila_U.arg_1_TREADY == 0)) | \
    ((ila_U.slice_stream_full == 0) & (ila_U.in_stream_empty == 0)) | \
    ((ila_U.stencil_stream_full == 0) & (ila_U.slice_stream_empty == 0)) | \
    ((ila_U.arg_0_TVALID == 0) & (ila_U.stencil_stream_empty == 0)) 
    ) \
)} -type {temporary} -update_db;
