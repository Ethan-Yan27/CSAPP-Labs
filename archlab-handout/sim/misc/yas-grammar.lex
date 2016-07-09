/* Grammar for Y86 Assembler */
 #include "yas.h"
 unsigned int atoh(const char *);

Instr         rrmovl|cmovle|cmovl|cmove|cmovne|cmovge|cmovg|rmmovl|mrmovl|irmovl|addl|subl|andl|xorl|jmp|jle|jl|je|jne|jge|jg|call|ret|pushl|popl|"."byte|"."word|"."long|"."pos|"."align|halt|nop|iaddl|leave
Letter        [a-zA-Z]
Digit         [0-9]
Ident         {Letter}({Letter}|{Digit}|_)*
Hex           [0-9a-fA-F]
Blank         [ \t]
Newline       [\n\r]
Return        [\r]
Char          [^\n\r]
Reg           %eax|%ecx|%edx|%ebx|%esi|%edi|%esp|%ebp

%x ERR COM
%%

^{Char}*{Return}*{Newline}      { save_line(yytext); REJECT;} /* Snarf input line */
#{Char}*{Return}*{Newline}      {finish_line(); lineno++;}
"//"{Char}*{Return}*{Newline}     {finish_line(); lineno++;}
"/*"{Char}*{Return}*{Newline}   {finish_line(); lineno++;}
{Blank}*{Return}*{Newline}      {finish_line(); lineno++;}


{Blank}+          ;
"$"+              ;
{Instr}           add_instr(yytext);
{Reg}             add_reg(yytext);
[-]?{Digit}+      add_num(atoi(yytext));
"0"[xX]{Hex}+     add_num(atoh(yytext));
[():,]            add_punct(*yytext);
{Ident}           add_ident(yytext);
{Char}            {; BEGIN ERR;}
<ERR>{Char}*{Newline} {fail("Invalid line"); lineno++; BEGIN 0;}
%%

unsigned int atoh(const char *s)
{
    return(strtoul(s, NULL, 16));
}
