mov reg ax reg bx
mov reg bx data byte 0xFF
mov reg bx 0x00000005
sum reg ax reg bx
dump
pop reg dx
inc reg ax
inc data byte 0xA0
mov reg cx dword word 00 0F