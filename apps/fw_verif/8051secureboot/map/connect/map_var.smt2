; variables for interface
(declare-var entryMem (Array Int Int))
(declare-var exitMem (Array Int Int))
(declare-var mmio_input_addr Int)
(declare-var mmio_input_data Int)
(declare-var returnVal Int)

; variables for shared variables
(declare-var XRAM (Array Int Int))
(declare-var XRAM_0 (Array Int Int))
(declare-var XRAM_1 (Array Int Int))
(declare-var cmd Int)
(declare-var cmddata Int)
(declare-var cmdaddr Int)
(declare-var dataout Int)
(declare-var dataout_0 Int)
(declare-var dataout_1 Int)

; variables for sha interface 
(declare-var addr_sha_state Int)
(declare-var addr_sha_rdaddr Int)
(declare-var addr_sha_wraddr Int)
(declare-var addr_sha_len Int)
(declare-var addr_sha_bytes Int)
(declare-var sha_mem_state (Array Int Int))
(declare-var sha_mem_len (Array Int Int))
(declare-var sha_mem_rdaddr (Array Int Int))
(declare-var sha_mem_wraddr (Array Int Int))
(declare-var sha_mem_bytes (Array Int Int))

; variables for rsa interface
(declare-var addr_rsa_state Int)
(declare-var addr_rsa_addr Int)
(declare-var addr_rsa_byte Int)
(declare-var rsa_mem_state (Array Int Int))
(declare-var rsa_mem_addr (Array Int Int))
(declare-var rsa_mem_byte (Array Int Int))
