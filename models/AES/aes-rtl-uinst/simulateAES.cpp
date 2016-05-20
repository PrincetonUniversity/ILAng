#include "simulateAES.hpp"
#include <sstream>
#include <cassert>
#include <iomanip>

VsimXramAes_top* top = NULL;

std::string cmdStr = "cmd";
std::string cmdaddrStr = "cmdaddr";
std::string cmddataStr = "cmddata";
std::string aes_stateStr = "aes_state";
std::string aes_addrStr = "aes_addr";
std::string aes_lenStr = "aes_len";
std::string aes_keyselStr = "aes_keysel";
std::string aes_ctrStr = "aes_ctr";
std::string aes_key0Str = "aes_key0";
std::string aes_key1Str = "aes_key1";
std::string data_outStr = "data_out";
std::string byte_cntStr = "byte_cnt";
std::string oped_byte_cntStr = "oped_byte_cnt";
std::string blk_cntStr = "blk_cnt";
std::string rd_dataStr = "rd_data";
std::string enc_dataStr = "enc_data";
std::string xramStr = "xram";

// Global inputs, for execution.
INT stb = 0;                // 1    1 * 8
INT cmd = 0;                // 1    1 * 8
INT cmdaddr = 0;            // 16   1 * 16
INT cmddata = 0;            // 8    1 * 8
// Global states, for comparison.
INT aes_state[1];           // 3    1 * 8
INT aes_addr[2];            // 16   2 * 8
INT aes_len[2];             // 16   2 * 8
INT aes_keysel[1];          // 1    1 * 8
INT aes_ctr[16];            // 128  16 * 8
INT aes_key0[16];           // 128  16 * 8
INT aes_key1[16];           // 128  16 * 8
INT data_out[1];            // 8    1 * 8
INT oped_byte_cnt[1];       // 16   1 * 16
INT byte_cnt[1];            // 16   1 * 16
INT blk_cnt[1];             // 16   1 * 16
INT rd_data[4];             // 128  4 * 32
INT enc_data[4];            // 128  4 * 32
// xram
INT defVal;

void assignXramInt();
std::ostream& dumpMemDataBuf(std::ostream& out);
std::ostream& dumpMemDataBufNext(std::ostream& out);
std::ostream& dumpEncDataNext(std::ostream& out);
std::ostream& dumpXram(std::ostream& out);
std::ostream& dumpState(std::ostream& out);

int main(int argc, char* argv[]) 
{
    std::string mode = argv[1];
    std::string inFile = argv[2];
    std::string outFile = argv[3];
    bool isMicro = (mode == "micro");
    top = new VsimXramAes_top();

    init();
    assignFromFile(inFile);
    assert(!hasChangedMicro() || stb == 0 || isRead());
   
    assignXramInt();
    do {
        execute();

        dumpState(std::cout);
        std::cout << "xram_addr=" << std::hex << top->v__DOT__xram_addr << std::endl;
        std::cout << "xram_stb=" << (int) top->v__DOT__xram_stb << std::endl;
        std::cout << "xram_data_in=" << std::hex << (int) top->v__DOT__xram_data_in << std::endl;
        std::cout << "xram_ack=" << (int) top->v__DOT__xram_ack << std::endl;
        std::cout << "mem_data_buf="; dumpMemDataBuf(std::cout) << std::endl;
        std::cout << "mem_data_buf_next="; dumpMemDataBufNext(std::cout) << std::endl;
        std::cout << "enc_data_buf_next="; dumpEncDataNext(std::cout) << std::endl;
        std::cout << std::dec;
        std::cout << "xram: " << std::endl; dumpXram(std::cout);

    } while (isMicro ? !hasChangedMicro() : 
                       !hasChangedMacro());

    //std::cout << "mem_data_buf="; dumpMemDataBuf(std::cout) << std::endl;
    //std::cout << "mem_data_buf_next="; dumpMemDataBufNext(std::cout) << std::endl;
    writeToFile(outFile);

    return 0;
}

void assignState()
{
    top->v__DOT__aes_top1__DOT__aes_reg_state_next = aes_state[0];
}

void assignAddr()
{
    top->v__DOT__aes_top1__DOT__aes_reg_opaddr_i__DOT__reg0_next = aes_addr[0];
    top->v__DOT__aes_top1__DOT__aes_reg_opaddr_i__DOT__reg1_next = aes_addr[1];
}

void assignLen()
{
    top->v__DOT__aes_top1__DOT__aes_reg_oplen_i__DOT__reg0_next = aes_len[0];
    top->v__DOT__aes_top1__DOT__aes_reg_oplen_i__DOT__reg1_next = aes_len[1];
}

void assignKeySel()
{
    top->v__DOT__aes_top1__DOT__aes_reg_keysel_next = aes_keysel[0];
}

void assignCTR()
{
    top->v__DOT__aes_top1__DOT__aes_reg_ctr_i__DOT__reg0_next = aes_ctr[0];
    top->v__DOT__aes_top1__DOT__aes_reg_ctr_i__DOT__reg1_next = aes_ctr[1];
    top->v__DOT__aes_top1__DOT__aes_reg_ctr_i__DOT__reg2_next = aes_ctr[2];
    top->v__DOT__aes_top1__DOT__aes_reg_ctr_i__DOT__reg3_next = aes_ctr[3];
    top->v__DOT__aes_top1__DOT__aes_reg_ctr_i__DOT__reg4_next = aes_ctr[4];
    top->v__DOT__aes_top1__DOT__aes_reg_ctr_i__DOT__reg5_next = aes_ctr[5];
    top->v__DOT__aes_top1__DOT__aes_reg_ctr_i__DOT__reg6_next = aes_ctr[6];
    top->v__DOT__aes_top1__DOT__aes_reg_ctr_i__DOT__reg7_next = aes_ctr[7];
    top->v__DOT__aes_top1__DOT__aes_reg_ctr_i__DOT__reg8_next = aes_ctr[8];
    top->v__DOT__aes_top1__DOT__aes_reg_ctr_i__DOT__reg9_next = aes_ctr[9];
    top->v__DOT__aes_top1__DOT__aes_reg_ctr_i__DOT__reg10_next = aes_ctr[10];
    top->v__DOT__aes_top1__DOT__aes_reg_ctr_i__DOT__reg11_next = aes_ctr[11];
    top->v__DOT__aes_top1__DOT__aes_reg_ctr_i__DOT__reg12_next = aes_ctr[12];
    top->v__DOT__aes_top1__DOT__aes_reg_ctr_i__DOT__reg13_next = aes_ctr[13];
    top->v__DOT__aes_top1__DOT__aes_reg_ctr_i__DOT__reg14_next = aes_ctr[14];
    top->v__DOT__aes_top1__DOT__aes_reg_ctr_i__DOT__reg15_next = aes_ctr[15];
}

void assignKEY0()
{
    top->v__DOT__aes_top1__DOT__aes_reg_key0_i__DOT__reg0_next = aes_key0[0];
    top->v__DOT__aes_top1__DOT__aes_reg_key0_i__DOT__reg1_next = aes_key0[1];
    top->v__DOT__aes_top1__DOT__aes_reg_key0_i__DOT__reg2_next = aes_key0[2];
    top->v__DOT__aes_top1__DOT__aes_reg_key0_i__DOT__reg3_next = aes_key0[3];
    top->v__DOT__aes_top1__DOT__aes_reg_key0_i__DOT__reg4_next = aes_key0[4];
    top->v__DOT__aes_top1__DOT__aes_reg_key0_i__DOT__reg5_next = aes_key0[5];
    top->v__DOT__aes_top1__DOT__aes_reg_key0_i__DOT__reg6_next = aes_key0[6];
    top->v__DOT__aes_top1__DOT__aes_reg_key0_i__DOT__reg7_next = aes_key0[7];
    top->v__DOT__aes_top1__DOT__aes_reg_key0_i__DOT__reg8_next = aes_key0[8];
    top->v__DOT__aes_top1__DOT__aes_reg_key0_i__DOT__reg9_next = aes_key0[9];
    top->v__DOT__aes_top1__DOT__aes_reg_key0_i__DOT__reg10_next = aes_key0[10];
    top->v__DOT__aes_top1__DOT__aes_reg_key0_i__DOT__reg11_next = aes_key0[11];
    top->v__DOT__aes_top1__DOT__aes_reg_key0_i__DOT__reg12_next = aes_key0[12];
    top->v__DOT__aes_top1__DOT__aes_reg_key0_i__DOT__reg13_next = aes_key0[13];
    top->v__DOT__aes_top1__DOT__aes_reg_key0_i__DOT__reg14_next = aes_key0[14];
    top->v__DOT__aes_top1__DOT__aes_reg_key0_i__DOT__reg15_next = aes_key0[15];
}

void assignKEY1()
{
    top->v__DOT__aes_top1__DOT__aes_reg_key1_i__DOT__reg0_next = aes_key1[0];
    top->v__DOT__aes_top1__DOT__aes_reg_key1_i__DOT__reg1_next = aes_key1[1];
    top->v__DOT__aes_top1__DOT__aes_reg_key1_i__DOT__reg2_next = aes_key1[2];
    top->v__DOT__aes_top1__DOT__aes_reg_key1_i__DOT__reg3_next = aes_key1[3];
    top->v__DOT__aes_top1__DOT__aes_reg_key1_i__DOT__reg4_next = aes_key1[4];
    top->v__DOT__aes_top1__DOT__aes_reg_key1_i__DOT__reg5_next = aes_key1[5];
    top->v__DOT__aes_top1__DOT__aes_reg_key1_i__DOT__reg6_next = aes_key1[6];
    top->v__DOT__aes_top1__DOT__aes_reg_key1_i__DOT__reg7_next = aes_key1[7];
    top->v__DOT__aes_top1__DOT__aes_reg_key1_i__DOT__reg8_next = aes_key1[8];
    top->v__DOT__aes_top1__DOT__aes_reg_key1_i__DOT__reg9_next = aes_key1[9];
    top->v__DOT__aes_top1__DOT__aes_reg_key1_i__DOT__reg10_next = aes_key1[10];
    top->v__DOT__aes_top1__DOT__aes_reg_key1_i__DOT__reg11_next = aes_key1[11];
    top->v__DOT__aes_top1__DOT__aes_reg_key1_i__DOT__reg12_next = aes_key1[12];
    top->v__DOT__aes_top1__DOT__aes_reg_key1_i__DOT__reg13_next = aes_key1[13];
    top->v__DOT__aes_top1__DOT__aes_reg_key1_i__DOT__reg14_next = aes_key1[14];
    top->v__DOT__aes_top1__DOT__aes_reg_key1_i__DOT__reg15_next = aes_key1[15];
}

void assignDataOut()
{
    top->data_out = data_out[0];
}

void assignByteCnt()
{
    top->v__DOT__aes_top1__DOT__byte_counter_next = byte_cnt[0];
    top->v__DOT__aes_top1__DOT__byte_counter_next = byte_cnt[0];
}

void assignOpedByteCnt()
{
    top->v__DOT__aes_top1__DOT__operated_bytes_count = oped_byte_cnt[0];
    top->v__DOT__aes_top1__DOT__operated_bytes_count_next = oped_byte_cnt[0];
}

void assignBlkCnt()
{
    top->v__DOT__aes_top1__DOT__block_counter = blk_cnt[0];
    top->v__DOT__aes_top1__DOT__block_counter_next = blk_cnt[0];
}

void assignXramInt()
{
    top->v__DOT__xram_addr = (blk_cnt[0] + byte_cnt[0] + aes_addr[0] + aes_addr[1]*256);
    top->v__DOT__xram_stb = (aes_state[0] == 1 || aes_state[0] == 3);
}

bool hasChangedAddr()
{
    if (
    top->v__DOT__aes_top1__DOT__aes_reg_opaddr_i__DOT__reg0_next != aes_addr[0]||
    top->v__DOT__aes_top1__DOT__aes_reg_opaddr_i__DOT__reg1_next != aes_addr[1])
        return true;
    else 
        return false;
}

bool hasChangedLen()
{
    if (
    top->v__DOT__aes_top1__DOT__aes_reg_oplen_i__DOT__reg0_next != aes_len[0] ||
    top->v__DOT__aes_top1__DOT__aes_reg_oplen_i__DOT__reg1_next != aes_len[1])
        return true;
    else 
        return false;
}

bool hasChangedCTR()
{
    if (
    top->v__DOT__aes_top1__DOT__aes_reg_ctr_i__DOT__reg0_next != aes_ctr[0] ||
    top->v__DOT__aes_top1__DOT__aes_reg_ctr_i__DOT__reg1_next != aes_ctr[1] ||
    top->v__DOT__aes_top1__DOT__aes_reg_ctr_i__DOT__reg2_next != aes_ctr[2] ||
    top->v__DOT__aes_top1__DOT__aes_reg_ctr_i__DOT__reg3_next != aes_ctr[3] ||
    top->v__DOT__aes_top1__DOT__aes_reg_ctr_i__DOT__reg4_next != aes_ctr[4] ||
    top->v__DOT__aes_top1__DOT__aes_reg_ctr_i__DOT__reg5_next != aes_ctr[5] ||
    top->v__DOT__aes_top1__DOT__aes_reg_ctr_i__DOT__reg6_next != aes_ctr[6] ||
    top->v__DOT__aes_top1__DOT__aes_reg_ctr_i__DOT__reg7_next != aes_ctr[7] ||
    top->v__DOT__aes_top1__DOT__aes_reg_ctr_i__DOT__reg8_next != aes_ctr[8] ||
    top->v__DOT__aes_top1__DOT__aes_reg_ctr_i__DOT__reg9_next != aes_ctr[9] ||
    top->v__DOT__aes_top1__DOT__aes_reg_ctr_i__DOT__reg10_next != aes_ctr[10] ||
    top->v__DOT__aes_top1__DOT__aes_reg_ctr_i__DOT__reg11_next != aes_ctr[11] ||
    top->v__DOT__aes_top1__DOT__aes_reg_ctr_i__DOT__reg12_next != aes_ctr[12] ||
    top->v__DOT__aes_top1__DOT__aes_reg_ctr_i__DOT__reg13_next != aes_ctr[13] ||
    top->v__DOT__aes_top1__DOT__aes_reg_ctr_i__DOT__reg14_next != aes_ctr[14] ||
    top->v__DOT__aes_top1__DOT__aes_reg_ctr_i__DOT__reg15_next != aes_ctr[15]) {
        return true;
    } else {
        return false;
    }
}

bool hasChangedKEY0()
{
    if (
    top->v__DOT__aes_top1__DOT__aes_reg_key0_i__DOT__reg0_next != aes_key0[0] ||
    top->v__DOT__aes_top1__DOT__aes_reg_key0_i__DOT__reg1_next != aes_key0[1] ||
    top->v__DOT__aes_top1__DOT__aes_reg_key0_i__DOT__reg2_next != aes_key0[2] ||
    top->v__DOT__aes_top1__DOT__aes_reg_key0_i__DOT__reg3_next != aes_key0[3] ||
    top->v__DOT__aes_top1__DOT__aes_reg_key0_i__DOT__reg4_next != aes_key0[4] ||
    top->v__DOT__aes_top1__DOT__aes_reg_key0_i__DOT__reg5_next != aes_key0[5] ||
    top->v__DOT__aes_top1__DOT__aes_reg_key0_i__DOT__reg6_next != aes_key0[6] ||
    top->v__DOT__aes_top1__DOT__aes_reg_key0_i__DOT__reg7_next != aes_key0[7] ||
    top->v__DOT__aes_top1__DOT__aes_reg_key0_i__DOT__reg8_next != aes_key0[8] ||
    top->v__DOT__aes_top1__DOT__aes_reg_key0_i__DOT__reg9_next != aes_key0[9] ||
    top->v__DOT__aes_top1__DOT__aes_reg_key0_i__DOT__reg10_next != aes_key0[10]||
    top->v__DOT__aes_top1__DOT__aes_reg_key0_i__DOT__reg11_next != aes_key0[11]||
    top->v__DOT__aes_top1__DOT__aes_reg_key0_i__DOT__reg12_next != aes_key0[12]||
    top->v__DOT__aes_top1__DOT__aes_reg_key0_i__DOT__reg13_next != aes_key0[13]||
    top->v__DOT__aes_top1__DOT__aes_reg_key0_i__DOT__reg14_next != aes_key0[14]||
    top->v__DOT__aes_top1__DOT__aes_reg_key0_i__DOT__reg15_next != aes_key0[15]){
        return true;
    } else {
        return false;
    }
}

bool hasChangedKEY1()
{
    if (
    top->v__DOT__aes_top1__DOT__aes_reg_key0_i__DOT__reg0_next != aes_key0[0] ||
    top->v__DOT__aes_top1__DOT__aes_reg_key0_i__DOT__reg1_next != aes_key0[1] ||
    top->v__DOT__aes_top1__DOT__aes_reg_key0_i__DOT__reg2_next != aes_key0[2] ||
    top->v__DOT__aes_top1__DOT__aes_reg_key0_i__DOT__reg3_next != aes_key0[3] ||
    top->v__DOT__aes_top1__DOT__aes_reg_key0_i__DOT__reg4_next != aes_key0[4] ||
    top->v__DOT__aes_top1__DOT__aes_reg_key0_i__DOT__reg5_next != aes_key0[5] ||
    top->v__DOT__aes_top1__DOT__aes_reg_key0_i__DOT__reg6_next != aes_key0[6] ||
    top->v__DOT__aes_top1__DOT__aes_reg_key0_i__DOT__reg7_next != aes_key0[7] ||
    top->v__DOT__aes_top1__DOT__aes_reg_key0_i__DOT__reg8_next != aes_key0[8] ||
    top->v__DOT__aes_top1__DOT__aes_reg_key0_i__DOT__reg9_next != aes_key0[9] ||
    top->v__DOT__aes_top1__DOT__aes_reg_key0_i__DOT__reg10_next != aes_key0[10]||
    top->v__DOT__aes_top1__DOT__aes_reg_key0_i__DOT__reg11_next != aes_key0[11]||
    top->v__DOT__aes_top1__DOT__aes_reg_key0_i__DOT__reg12_next != aes_key0[12]||
    top->v__DOT__aes_top1__DOT__aes_reg_key0_i__DOT__reg13_next != aes_key0[13]||
    top->v__DOT__aes_top1__DOT__aes_reg_key0_i__DOT__reg14_next != aes_key0[14]||
    top->v__DOT__aes_top1__DOT__aes_reg_key0_i__DOT__reg15_next != aes_key0[15]){
        return true;
    } else {
        return false;
    }
}

bool hasChangedRD()
{
    for (int i=0; i<4; i++) {
        if (rd_data[i] != top->v__DOT__aes_top1__DOT__mem_data_buf_next[i]) 
            return true;
    }
    return false;
}

std::ostream& dumpState(std::ostream& out)
{
    out << "aes_state=" << std::hex << (int) top->v__DOT__aes_top1__DOT__aes_reg_state<< std::endl;
    out << "aes_state_next=" << std::hex << (int) top->v__DOT__aes_top1__DOT__aes_reg_state_next<< std::endl;
    return out;
}

std::ostream& dumpMemDataBuf(std::ostream& out)
{
    for (int i=3; i>=0; i--) {
        out << std::hex << std::setw(8) << std::setfill('0') << top->v__DOT__aes_top1__DOT__mem_data_buf[i];
    }
    return out;
}

std::ostream& dumpMemDataBufNext(std::ostream& out)
{
    for (int i=3; i>=0; i--) {
        out << std::hex << std::setw(8) << std::setfill('0') << top->v__DOT__aes_top1__DOT__mem_data_buf_next[i];
    }
    return out;
}

std::ostream& dumpEncDataNext(std::ostream& out)
{
    for (int i=3; i>=0; i--) {
        out << std::hex << std::setw(8) << std::setfill('0') << top->v__DOT__aes_top1__DOT__encrypted_data_buf_next[i];
    }
    return out;
}

std::ostream& dumpXram(std::ostream& out) {
    for (unsigned i = 0; i < 65536; i++) {
        if (top->v__DOT__oc8051_xram1__DOT__buff[i] != defVal) {
            out << std::hex << i << " " 
                << std::hex << (INT)top->v__DOT__oc8051_xram1__DOT__buff[i] << "\n";
        }
    }
    out << "default: " << (INT)defVal << "\n";
    return out;
}
bool hasChangedENC()
{
    for (int i=0; i<4; i++) {
        if (enc_data[i] != top->v__DOT__aes_top1__DOT__encrypted_data_buf_next[i])
            return true;
    }
    return false;
}

bool isRead()
{
    if (cmd == 0) //&& top->v__DOT__aes_top1__DOT__aes_reg_state_next == 0)
        return true;
    else 
        return false;
}

void init()
{
    for (int i=0; i<20; i++) {
        if (i % 10 == 0) {
            top->clk = 1;
            top->rst = 1;
            top->stb = stb;
        } else if (i % 10 == 5) {
            top->clk = 0;
            top->rst = 1;
            top->stb = stb;
        }
        top->eval();
    }
    top->v__DOT__xram_ack = 0;
}

void assignFromFile(const std::string& fileName)
{
    ifstream in(fileName.c_str());
    if (!in.is_open()) {
        std::cerr << "File " << fileName << " not open.\n";
        return;
    }
    
    std::string buff;
    in >> buff;
    if (buff != ".AES_IP_START") {
        std::cerr << "Assignment file should start from .AES_IP_START\n";
    }

    in >> buff;
    while (buff != ".AES_IP_END") {
        if (buff == cmdStr) {
            in >> buff;
            INT tmp = hex2int(buff);
            if (tmp == 2) {
                stb = 1;
                cmd = 1;
            } else { 
                stb = 1;
                cmd = 0;
            } 
        } else if (buff == cmdaddrStr) {
            in >> buff;
            cmdaddr = hex2int(buff);
        } else if (buff == cmddataStr) {
            in >> buff;
            cmddata = hex2int(buff);
        } else if (buff == aes_stateStr) {
            in >> buff;
            hex2array(buff, aes_state, 2);
            assignState();
        } else if (buff == aes_addrStr) {
            in >> buff;
            hex2array(buff, aes_addr, 2);
            assignAddr();
        } else if (buff == aes_lenStr) {
            in >> buff;
            hex2array(buff, aes_len, 2);
            assignLen();
        } else if (buff == aes_keyselStr) {
            in >> buff;
            hex2array(buff, aes_keysel, 2);
            assignKeySel();
        } else if (buff == aes_ctrStr) {
            in >> buff;
            hex2array(buff, aes_ctr, 2);
            assignCTR();
        } else if (buff == aes_key0Str) {
            in >> buff;
            hex2array(buff, aes_key0, 2);
            assignKEY0();
        } else if (buff == aes_key1Str) {
            in >> buff;
            hex2array(buff, aes_key1, 2);
            assignKEY1();
        } else if (buff == data_outStr) {
            in >> buff;
            hex2array(buff, data_out, 2);
            assignDataOut();
        } else if (buff == byte_cntStr) {
            in >> buff;
            hex2array(buff, byte_cnt, 4);
            assignByteCnt();
        } else if (buff == oped_byte_cntStr) {
            in >> buff;
            hex2array(buff, oped_byte_cnt, 4);
            assignOpedByteCnt();
        } else if (buff == blk_cntStr) {
            in >> buff;
            hex2array(buff, blk_cnt, 4);
            assignBlkCnt();
        } else if (buff == rd_dataStr) {
            in >> buff;
            hex2array(buff, top->v__DOT__aes_top1__DOT__mem_data_buf_next, 8);
            hex2array(buff, rd_data, 8);
        } else if (buff == enc_dataStr) {
            in >> buff;
            hex2array(buff, enc_data, 8);
            hex2array(buff, top->v__DOT__aes_top1__DOT__encrypted_data_buf_next, 8);
        } else if (buff == xramStr) {
            std::map<INT, INT> mem;
            char head = nextChar(in);
            assert(head == '[');
            in >> buff;
            while (buff != "default:") {
                INT addr = memSplitA(buff);
                INT data = memSplitD(buff);
                mem[addr] = data;
                in >> buff;
            }
            in >> buff;
            defVal = memSplitD(buff);
            for (unsigned i = 0; i < 65536; i++) {
                top->v__DOT__oc8051_xram1__DOT__buff[i] = defVal;
            }
            for (std::map<INT, INT>::iterator it = mem.begin(); 
                 it != mem.end(); it++) {
                top->v__DOT__oc8051_xram1__DOT__buff[it->first] = it->second;
            }
        } else {
            std::cerr << "Unknown state \"" << buff << "\"\n";
        }
        in >> buff;
    }

    assignXramInt();


    in.close();
}

bool hasChangedMicro()
{
    if ( //stb == 0 ||
        //isRead() ||
        top->v__DOT__xram_ack ||
        aes_state[0] == 2)
        /*
        aes_state[0]  != top->v__DOT__aes_top1__DOT__aes_reg_state_next ||
        aes_keysel[0] != top->v__DOT__aes_top1__DOT__aes_reg_keysel_next || 
        byte_cnt[0]   != top->v__DOT__aes_top1__DOT__byte_counter_next ||
        blk_cnt[0]    != top->v__DOT__aes_top1__DOT__block_counter_next ||
        oped_byte_cnt[0] != 
            top->v__DOT__aes_top1__DOT__operated_bytes_count_next ||
        hasChangedAddr() ||
        hasChangedLen()  ||
        hasChangedCTR()  || 
        hasChangedKEY0() || 
        hasChangedKEY1() ||
        hasChangedRD()   ||
        hasChangedENC()) {*/
    {
        return true;
    } else {
        return false;
    }
}

bool hasChangedMacro()
{
    return true;
}

void execute()
{
    for (int i=0; i<10; i++) {
        if (i % 10 == 0) {
            top->clk = 1;
        } else if (i % 10 == 5) {
            top->clk = 0;
        }
        top->rst = 0;
        top->stb = 1;
        top->cmd = cmd;
        top->cmdaddr = cmdaddr;
        top->cmddata = cmddata;
        top->eval();
    }
}

void writeToFile(const std::string& fileName)
{
    ofstream out(fileName.c_str());
    if (!out.is_open()) {
        std::cerr << "File " << fileName << " not open.\n";
        return;
    }
    INT temp = 0;

    out << ".AES_OP_START\n" << hex;
    
    out << aes_stateStr << " " 
        << (INT)top->v__DOT__aes_top1__DOT__aes_reg_state_next << "\n";

    temp = top->v__DOT__aes_top1__DOT__aes_reg_oplen_i__DOT__reg1_next;
    temp = temp << 8;
    temp = temp + top->v__DOT__aes_top1__DOT__aes_reg_oplen_i__DOT__reg0_next;
    out << aes_lenStr << " " << temp << "\n";

    temp = top->v__DOT__aes_top1__DOT__aes_reg_opaddr_i__DOT__reg1_next;
    temp = temp << 8;
    temp = temp + top->v__DOT__aes_top1__DOT__aes_reg_opaddr_i__DOT__reg0_next;
    out << aes_addrStr << " " << temp << "\n";

    out << aes_keyselStr << " " 
        << (INT)top->v__DOT__aes_top1__DOT__aes_reg_keysel_next << "\n";

    //FIXME 
    out << aes_ctrStr << " "
        << top->aes_ctr[3] << top->aes_ctr[2]
        << top->aes_ctr[1] << top->aes_ctr[0] << "\n";
    out << aes_key0Str << " " 
        << top->aes_key0[3] << top->aes_key0[2]
        << top->aes_key0[1] << top->aes_key0[0] << "\n";
    out << aes_key1Str << " " 
        << top->aes_key1[3] << top->aes_key1[2]
        << top->aes_key1[1] << top->aes_key1[0] << "\n";
    out << data_outStr << " " 
        << (INT)top->data_out << "\n";
    out << byte_cntStr << " " 
        << (INT)top->v__DOT__aes_top1__DOT__byte_counter_next << "\n";
    out << blk_cntStr << " "
        << (INT)top->v__DOT__aes_top1__DOT__block_counter_next << "\n";
    out << oped_byte_cntStr << " "
        << (INT)top->v__DOT__aes_top1__DOT__operated_bytes_count_next << "\n";
    out << rd_dataStr << " " 
        << std::setw(8) << std::setfill('0')
        << top->v__DOT__aes_top1__DOT__mem_data_buf_next[3]
        << std::setw(8) << std::setfill('0')
        << top->v__DOT__aes_top1__DOT__mem_data_buf_next[2]
        << std::setw(8) << std::setfill('0')
        << top->v__DOT__aes_top1__DOT__mem_data_buf_next[1]
        << std::setw(8) << std::setfill('0')
        << top->v__DOT__aes_top1__DOT__mem_data_buf_next[0] << "\n";
    out << enc_dataStr << " "
        << top->v__DOT__aes_top1__DOT__encrypted_data_buf_next[3]
        << top->v__DOT__aes_top1__DOT__encrypted_data_buf_next[2]
        << top->v__DOT__aes_top1__DOT__encrypted_data_buf_next[1]
        << top->v__DOT__aes_top1__DOT__encrypted_data_buf_next[0] << "\n";
    out << xramStr << "\n"; 
    for (unsigned i = 0; i < 65536; i++) {
        if (top->v__DOT__oc8051_xram1__DOT__buff[i] != defVal) {
            out << i << " " 
                << (INT)top->v__DOT__oc8051_xram1__DOT__buff[i] << "\n";
        }
    }
    out << "default: " << (INT)defVal << "\n";

    out << ".AES_OP_END\n";
    out.close();
}

INT hex2int(const std::string& str)
{
    stringstream ss;
    int64_t res;
    ss << std::hex << str;
    ss >> res;
    return (INT) res;
}

void hex2array(const std::string& str, INT* res, int bn)
{
    assert(str.size() % 2 == 0);
    unsigned num = str.size() / bn;

    for (unsigned i = 0; i < num; i++) {
        std::string sub = str.substr(str.size()-bn-(i*bn), bn);
        res[i] = hex2int(sub);
    }
}

char nextChar(std::istream& in) 
{
    char buf = '\0'; // init.
    while (!in.eof()) {
        buf = in.get();
        if (buf != ' ' && buf != '\n') return buf;
    }
    return buf;
}

INT memSplitA(const std::string& buff)
{
    unsigned pos = buff.find_first_of(':');
    return hex2int(buff.substr(0, pos+1));
}

INT memSplitD(const std::string& buff)
{
    unsigned semiPos = buff.find_first_of(':', 0);
    unsigned start = (semiPos == std::string::npos) ? 0 : semiPos+1;
    unsigned len = buff.size() - start;
    return hex2int(buff.substr(start, len));
}
