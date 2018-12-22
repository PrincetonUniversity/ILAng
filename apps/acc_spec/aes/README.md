ILA vs Verilog Verification
==================================================================================


Overview
-------------------
This example contains a manually constructed Verilog Module.
The AES module works in Counter Mode, the counter is incremented for each block. For the sake of
simplicity, the module only provides AES encryption function. This AES accelerator is assumed to 
be connected through memory-mapped IO, it is assigned to the following address space. Encryption
happens in-place, in other words, the plaintext in the memory will be overwritten by ciphertext
after encryption.


| Memory Address | Content   | Comment                          |
|----------------|-----------|----------------------------------|
| 0xff00         | AES_START | Write 1 to start encryption      |
| 0xff01         | AES_STATE | Read-only, 0: Idle, >0: Busy     |
| 0xff02         | AES_ADDR  | Memory address for the plaintext |
| 0xff10         | AES_KEY   | Key for encryption               |
| 0xff20         | AES_CTR   | Initial value of the counter     |


