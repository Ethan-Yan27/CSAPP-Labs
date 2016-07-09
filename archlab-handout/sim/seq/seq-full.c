char simname[] = "Y86 Processor: seq-full.hcl";
#include <stdio.h>
#include "isa.h"
#include "sim.h"
int sim_main(int argc, char *argv[]);
int gen_pc(){return 0;}
int main(int argc, char *argv[])
  {plusmode=0;return sim_main(argc,argv);}
int gen_icode()
{
    return ((imem_error) ? (I_NOP) : (imem_icode));
}

int gen_ifun()
{
    return ((imem_error) ? (F_NONE) : (imem_ifun));
}

int gen_instr_valid()
{
    return ((icode) == (I_NOP) || (icode) == (I_HALT) || (icode) == 
      (I_RRMOVL) || (icode) == (I_IRMOVL) || (icode) == (I_RMMOVL) || 
      (icode) == (I_MRMOVL) || (icode) == (I_ALU) || (icode) == (I_JMP) || 
      (icode) == (I_CALL) || (icode) == (I_RET) || (icode) == (I_PUSHL) || 
      (icode) == (I_POPL) || (icode) == (I_IADDL) || (icode) == (I_LEAVE));
}

int gen_need_regids()
{
    return ((icode) == (I_RRMOVL) || (icode) == (I_ALU) || (icode) == 
      (I_PUSHL) || (icode) == (I_POPL) || (icode) == (I_IRMOVL) || (icode)
       == (I_RMMOVL) || (icode) == (I_MRMOVL) || (icode) == (I_IADDL));
}

int gen_need_valC()
{
    return ((icode) == (I_IRMOVL) || (icode) == (I_RMMOVL) || (icode) == 
      (I_MRMOVL) || (icode) == (I_JMP) || (icode) == (I_CALL) || (icode)
       == (I_IADDL));
}

int gen_srcA()
{
    return (((icode) == (I_RRMOVL) || (icode) == (I_RMMOVL) || (icode) == 
        (I_ALU) || (icode) == (I_PUSHL)) ? (ra) : ((icode) == (I_POPL) || 
        (icode) == (I_RET)) ? (REG_ESP) : ((icode) == (I_LEAVE)) ? 
      (REG_EBP) : (REG_NONE));
}

int gen_srcB()
{
    return (((icode) == (I_ALU) || (icode) == (I_RMMOVL) || (icode) == 
        (I_MRMOVL) || (icode) == (I_IADDL)) ? (rb) : ((icode) == (I_PUSHL)
         || (icode) == (I_POPL) || (icode) == (I_CALL) || (icode) == 
        (I_RET) || (icode) == (I_LEAVE)) ? (REG_ESP) : (REG_NONE));
}

int gen_dstE()
{
    return ((((icode) == (I_RRMOVL)) & (cond)) ? (rb) : ((icode) == 
        (I_IRMOVL) || (icode) == (I_ALU) || (icode) == (I_IADDL)) ? (rb) : 
      ((icode) == (I_PUSHL) || (icode) == (I_POPL) || (icode) == (I_CALL)
         || (icode) == (I_RET) || (icode) == (I_LEAVE)) ? (REG_ESP) : 
      (REG_NONE));
}

int gen_dstM()
{
    return (((icode) == (I_MRMOVL) || (icode) == (I_POPL)) ? (ra) : (
        (icode) == (I_LEAVE)) ? (REG_EBP) : (REG_NONE));
}

int gen_aluA()
{
    return (((icode) == (I_RRMOVL) || (icode) == (I_ALU)) ? (vala) : (
        (icode) == (I_IRMOVL) || (icode) == (I_RMMOVL) || (icode) == 
        (I_MRMOVL) || (icode) == (I_IADDL)) ? (valc) : ((icode) == (I_CALL)
         || (icode) == (I_PUSHL)) ? -4 : ((icode) == (I_RET) || (icode) == 
        (I_POPL) || (icode) == (I_LEAVE)) ? 4 : 0);
}

int gen_aluB()
{
    return (((icode) == (I_RMMOVL) || (icode) == (I_MRMOVL) || (icode) == 
        (I_ALU) || (icode) == (I_CALL) || (icode) == (I_PUSHL) || (icode)
         == (I_RET) || (icode) == (I_POPL) || (icode) == (I_IADDL)) ? 
      (valb) : ((icode) == (I_RRMOVL) || (icode) == (I_IRMOVL)) ? 0 : (
        (icode) == (I_LEAVE)) ? (vala) : 0);
}

int gen_alufun()
{
    return (((icode) == (I_ALU)) ? (ifun) : (A_ADD));
}

int gen_set_cc()
{
    return ((icode) == (I_ALU) || (icode) == (I_IADDL));
}

int gen_mem_read()
{
    return ((icode) == (I_MRMOVL) || (icode) == (I_POPL) || (icode) == 
      (I_RET) || (icode) == (I_LEAVE));
}

int gen_mem_write()
{
    return ((icode) == (I_RMMOVL) || (icode) == (I_PUSHL) || (icode) == 
      (I_CALL));
}

int gen_mem_addr()
{
    return (((icode) == (I_RMMOVL) || (icode) == (I_PUSHL) || (icode) == 
        (I_CALL) || (icode) == (I_MRMOVL)) ? (vale) : ((icode) == (I_POPL)
         || (icode) == (I_RET) || (icode) == (I_LEAVE)) ? (vala) : 0);
}

int gen_mem_data()
{
    return (((icode) == (I_RMMOVL) || (icode) == (I_PUSHL)) ? (vala) : (
        (icode) == (I_CALL)) ? (valp) : 0);
}

int gen_Stat()
{
    return (((imem_error) | (dmem_error)) ? (STAT_ADR) : !(instr_valid) ? 
      (STAT_INS) : ((icode) == (I_HALT)) ? (STAT_HLT) : (STAT_AOK));
}

int gen_new_pc()
{
    return (((icode) == (I_CALL)) ? (valc) : (((icode) == (I_JMP)) & (cond)
        ) ? (valc) : ((icode) == (I_RET)) ? (valm) : (valp));
}

