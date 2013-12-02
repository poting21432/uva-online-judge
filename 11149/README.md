UVa 11149
==============================
Power of Matrix
------------------------------
http://uva.onlinejudge.org/external/111/11149.html

剛開始出現了莫名其妙的 CE

> Compilation error for submission 12770786
> code.o: In function `operator+(Matrix const&, Matrix const&)':
> code.cpp:(.text+0x2c): relocation truncated to fit: R_X86_64_PC32 against symbol `n' defined in .bss section in code.o
> code.o: In function `operator*(Matrix const&, Matrix const&)':
> code.cpp:(.text+0xe1): relocation truncated to fit: R_X86_64_PC32 against symbol `n' defined in .bss section in code.o
> code.o: In function `matrixPower(Matrix const&, int const&)':
> code.cpp:(.text+0x1ba): relocation truncated to fit: R_X86_64_32S against symbol `computed' defined in .bss section in code.o
> code.cpp:(.text+0x27d): relocation truncated to fit: R_X86_64_32S against symbol `computed' defined in .bss section in code.o
> code.o: In function `test()':
> code.cpp:(.text+0x38d): relocation truncated to fit: R_X86_64_PC32 against symbol `n' defined in .bss section in code.o
> code.cpp:(.text+0x41e): relocation truncated to fit: R_X86_64_PC32 against symbol `n' defined in .bss section in code.o
> code.cpp:(.text+0x44b): relocation truncated to fit: R_X86_64_PC32 against symbol `n' defined in .bss section in code.o
> code.cpp:(.text+0x470): relocation truncated to fit: R_X86_64_PC32 against symbol `n' defined in .bss section in code.o
> code.cpp:(.text+0x495): relocation truncated to fit: R_X86_64_PC32 against symbol `n' defined in .bss section in code.o
> code.cpp:(.text+0x4cc): relocation truncated to fit: R_X86_64_PC32 against symbol `n' defined in .bss section in code.o
> code.cpp:(.text+0x4f3): additional relocation overflows omitted from the output
> collect2: error: ld returned 1 exit status

把全域 n 改成 struct member n 但 CE Again

> Compilation error for submission 12770833
> code.o: In function `matrixPower(Matrix const&, int const&)':
> code.cpp:(.text+0x1ba): relocation truncated to fit: R_X86_64_32S against symbol `computed' defined in .bss section in code.o
> code.cpp:(.text+0x295): relocation truncated to fit: R_X86_64_32S against symbol `computed' defined in .bss section in code.o
> code.o: In function `main':
> code.cpp:(.text.startup+0x11a): relocation truncated to fit: R_X86_64_32 against symbol `computed' defined in .bss section in code.o
> collect2: error: ld returned 1 exit status

把原本的 bool computed[] 換成 vector<boo> computed 還是一樣：

> code.o: In function `matrixPower(Matrix const&, int const&)':
> code.cpp:(.text+0x1bd): relocation truncated to fit: R_X86_64_PC32 against symbol `computed' defined in .bss section in code.o
> code.cpp:(.text+0x29a): relocation truncated to fit: R_X86_64_PC32 against symbol `computed' defined in .bss section in code.o
> code.o: In function `main':
> code.cpp:(.text.startup+0x115): relocation truncated to fit: R_X86_64_PC32 against symbol `computed' defined in .bss section in code.o
> code.cpp:(.text.startup+0x11f): relocation truncated to fit: R_X86_64_PC32 against symbol `computed' defined in .bss section in code.o
> code.o: In function `_GLOBAL__sub_I_computed':
> code.cpp:(.text.startup+0x389): relocation truncated to fit: R_X86_64_PC32 against symbol `computed' defined in .bss section in code.o
> code.cpp:(.text.startup+0x393): relocation truncated to fit: R_X86_64_PC32 against symbol `computed' defined in .bss section in code.o
> code.cpp:(.text.startup+0x39e): relocation truncated to fit: R_X86_64_PC32 against symbol `computed' defined in .bss section in code.o
> code.cpp:(.text.startup+0x3a8): relocation truncated to fit: R_X86_64_PC32 against symbol `computed' defined in .bss section in code.o
> code.cpp:(.text.startup+0x3b3): relocation truncated to fit: R_X86_64_PC32 against symbol `computed' defined in .bss section in code.o
> code.cpp:(.text.startup+0x3d1): relocation truncated to fit: R_X86_64_PC32 against symbol `computed' defined in .bss section in code.o
> code.cpp:(.text.startup+0x3d7): additional relocation overflows omitted from the output
> collect2: error: ld returned 1 exit status

