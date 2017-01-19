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
 

/* substitue four bytes in a word */
/* in --1d--> out */

module S4 (clk, in, out);
    input clk;
    input [31:0] in;
    output [31:0] out;
    
    S
        S_0 (clk, in[31:24], out[31:24]),
        S_1 (clk, in[23:16], out[23:16]),
        S_2 (clk, in[15:8],  out[15:8] ),
        S_3 (clk, in[7:0],   out[7:0]  );
endmodule
