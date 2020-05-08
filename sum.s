.intel_syntax noprefix

push rbp
mov rbp, rsp
movss DWORD PTR [rbp-4], xmm0
movss DWORD PTR [rbp-8], xmm1
movss xmm0, DWORD PTR [rbp-4]
addss xmm0, DWORD PTR [rbp-8]
pop rbp
ret
