#include "simulateAES.hpp"
#include <sstream>
#include <cassert>

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
std::string rd_dataStr = "rd_data";
std::string enc_dataStr = "enc_data";
std::string xramStr = "xram";

// Global inputs, for execution.
INT cmd = 0;
INT cmdaddr = 0;
INT cmddata = 0;
// Global states, for comparison.
INT aes_state;
INT aes_addr;
INT aes_len;
INT aes_keysel;
INT aes_ctr[16];
INT aes_key0[16];
INT aes_key1[16];
INT data_out;
INT byte_cnt;
INT rd_data[4];
INT enc_data[4];
// xram

int main(int argc, char* argv[]) 
{
    top = new VsimXramAes_top();

    init();
    assignFromFile("assign.ip");
    assert(!hasChanged());
   
    do {
        execute();
    } while (!hasChanged());

    writeToFile("res.op");

    return 0;
}

INT hex2int(const std::string& str)
{
    stringstream ss;
    INT res;
    ss << std::hex <<str;
    ss >> res;
    return res;
}

void hex2array(const std::string& str, INT* res, int bn)
{
    assert(str.size() == 16);
    unsigned num = str.size() / bn;

    for (unsigned i = 0; i < num; i++) {
        std::string sub = str.substr(str.size()-bn-(i*bn), bn);
        res[i] = hex2int(sub);
    }
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

bool hasChangedENC()
{
    for (int i=0; i<4; i++) {
        if (enc_data[i] != top->v__DOT__aes_top1__DOT__encrypted_data_buf_next[i])
            return true;
    }
    return false;
}

void init()
{
    for (int i=0; i<20; i++) {
        if (i % 10 == 0) {
            top->clk = 1;
            top->rst = 1;
            top->stb = 1;
        } else if (i % 10 == 5) {
            top->clk = 0;
            top->rst = 1;
            top->stb = 1;
        }
        top->eval();
    }
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
            cmd = hex2int(buff);
        } else if (buff == cmdaddrStr) {
            in >> buff;
            cmdaddr = hex2int(buff);
        } else if (buff == cmddataStr) {
            in >> buff;
            cmddata = hex2int(buff);
        } else if (buff == aes_stateStr) {
            in >> buff;
            aes_state = top->aes_state = hex2int(buff);
        } else if (buff == aes_addrStr) {
            in >> buff;
            aes_addr = top->aes_addr = hex2int(buff);
        } else if (buff == aes_lenStr) {
            in >> buff;
            aes_len = top->aes_len = hex2int(buff);
        } else if (buff == aes_keyselStr) {
            in >> buff;
            aes_keysel = 
                top->v__DOT__aes_top1__DOT__aes_reg_keysel = hex2int(buff);
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
            data_out = top->data_out << hex2int(buff);
        } else if (buff == byte_cntStr) {
            in >> buff;
            byte_cnt = 
                top->v__DOT__aes_top1__DOT__byte_counter = hex2int(buff);
        } else if (buff == rd_dataStr) {
            in >> buff;
            hex2array(buff, rd_data, 4);
            hex2array(buff, top->v__DOT__aes_top1__DOT__mem_data_buf_next, 4);
        } else if (buff == enc_dataStr) {
            in >> buff;
            hex2array(buff, enc_data, 4);
            hex2array(buff, top->v__DOT__aes_top1__DOT__encrypted_data_buf_next, 4);
        } else if (buff == xramStr) {
            in >> buff;
            // TODO
        } else {
            std::cerr << "Unknown state \"" << buff << "\"\n";
        }
        in >> buff;
    }

    in.close();
}

bool hasChanged()
{
    if (aes_state  != top->aes_state  || 
        aes_addr   != top->aes_addr   ||
        aes_len    != top->aes_len    ||
        aes_keysel != top->v__DOT__aes_top1__DOT__aes_reg_keysel ||
        byte_cnt   != top->v__DOT__aes_top1__DOT__byte_counter) { 
        return true;
    } else {
        if (hasChangedCTR()  || 
            hasChangedKEY0() || 
            hasChangedKEY1() ||
            hasChangedRD()   ||
            hasChangedENC()) {
            return true;
        } else {
            return false;
        }
    }
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

    out << ".AES_OP_START\n" << hex;
    
    out << aes_stateStr << " " << (INT)top->aes_state << "\n";
    out << aes_lenStr << " " << (INT)top->aes_len << "\n";
    out << aes_keyselStr << " " 
        << (INT)top->v__DOT__aes_top1__DOT__aes_reg_keysel << "\n";
    out << aes_ctrStr << " " << hex 
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
        << (INT)top->v__DOT__aes_top1__DOT__byte_counter << "\n";
    out << rd_dataStr << " " 
        << top->v__DOT__aes_top1__DOT__mem_data_buf[3]
        << top->v__DOT__aes_top1__DOT__mem_data_buf[2]
        << top->v__DOT__aes_top1__DOT__mem_data_buf[1]
        << top->v__DOT__aes_top1__DOT__mem_data_buf[0] << "\n";
    out << enc_dataStr << " "
        << top->v__DOT__aes_top1__DOT__encrypted_data_buf[3]
        << top->v__DOT__aes_top1__DOT__encrypted_data_buf[2]
        << top->v__DOT__aes_top1__DOT__encrypted_data_buf[1]
        << top->v__DOT__aes_top1__DOT__encrypted_data_buf[0] << "\n";
    // TODO
    out << xramStr << " " << "0x0" << "\n";

    out << ".AES_OP_END\n";
    out.close();
}

