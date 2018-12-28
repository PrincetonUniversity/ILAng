/*
 * Copyright 2012, Homer Hsing <homer.hsing@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

 
// aes_128 : state , key --20d--> out
module aes_128(clk, state, key, out);
    input          clk;
    input  [127:0] state, key;
    output [127:0] out;
    reg    [127:0] s0, k0;
    wire   [127:0] s1, s2, s3, s4, s5, s6, s7, s8, s9,
                   k1, k2, k3, k4, k5, k6, k7, k8, k9,
                   k0b, k1b, k2b, k3b, k4b, k5b, k6b, k7b, k8b, k9b;

    always @ (posedge clk)
      begin
        s0 <= state ^ key;
        k0 <= key;
      end
	/* verilator lint_off UNUSED */
	wire[127:0] nouse;
	/* verilator lint_on UNUSED */
    /* verilator lint_off PINNOCONNECT */
    expand_key_128    a1 (clk, k0, k1, k0b, 8'h1);  // k0 -> k1 : 2d,  k0-> k0b : 1d
    expand_key_128    a2 (clk, k1, k2, k1b, 8'h2);
    expand_key_128    a3 (clk, k2, k3, k2b, 8'h4);
    expand_key_128    a4 (clk, k3, k4, k3b, 8'h8);
    expand_key_128    a5 (clk, k4, k5, k4b, 8'h10);
    expand_key_128    a6 (clk, k5, k6, k5b, 8'h20);
    expand_key_128    a7 (clk, k6, k7, k6b, 8'h40);
    expand_key_128    a8 (clk, k7, k8, k7b, 8'h80);
    expand_key_128    a9 (clk, k8, k9, k8b, 8'h1b); // k0 -> k9 : 18d , k0->k8b : 17d
    expand_key_128   a10 (clk, k9, nouse, k9b, 8'h36); // k0 -> k9b : 19d
    /* verilator lint_on PINNOCONNECT */

    
    one_round    r1 (clk, s0, k0b, s1); // 1d
    one_round    r2 (clk, s1, k1b, s2);
    one_round    r3 (clk, s2, k2b, s3);
    one_round    r4 (clk, s3, k3b, s4);
    one_round    r5 (clk, s4, k4b, s5);
    one_round    r6 (clk, s5, k5b, s6);
    one_round    r7 (clk, s6, k6b, s7);
    one_round    r8 (clk, s7, k7b, s8);
    one_round    r9 (clk, s8, k8b, s9);

    final_round  rf (clk, s9, k9b, out);
endmodule


