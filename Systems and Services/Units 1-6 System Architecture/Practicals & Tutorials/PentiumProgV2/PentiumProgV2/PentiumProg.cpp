// PentiumProg.cpp
// Example Assembly language program for Systems & Services
// A Armitage, Sept 2011, V2.0

int main(int argc, char* argv[])
{
	signed int Var1 = 11, Var2 = 18, Result = 0;

_asm
{
	mov eax, 0x0			//1: registers
	mov al,  0x11
	mov ah,  0x22
	mov ax,  0x3333
	mov eax, 0x1234abcd
	nop
	nop
	mov eax, 0x90			//2: arithmetic
	mov ebx, 0x10100088
	add eax, ebx
	mov ecx, 0x20000000
	sub ecx, eax
	nop	
	nop
	mov eax, Var1			//3: variables in memory
	mov ebx, Var2
	sub eax, ebx
	mov Result, eax
	nop
	nop
	mov eax, 0x90000000		//4: flags
	mov ebx, 0xa0000000
	add eax, ebx
	sub eax, 0x30000000
	nop
	nop
	mov al, 0x11			//5a: decisions
	mov bl, 0x11
	sub al, bl
	jz _EQ
	mov cl, 0x00
	nop
_EQ:mov cl, 0xff
	nop
	mov al, 0x11			//5b: decisions
	mov bl, 0x22
	sub al, bl
	jz _EQ
	mov cl, 0xaa
	nop
	nop
	mov eax, 0x0			//6: looping
	mov ecx,  0x04
_AA:add eax, 0x03
	loop _AA

}
	return 0;
}