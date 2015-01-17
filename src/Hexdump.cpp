# include "Hexdump.hpp"
# include <stdio.h>
# include <ctype.h>
# include "Colors.hpp"
 void hexdump(void *mem, size_t len, int mark_at)
 {
        unsigned int i, j;
        for(i = 0; i < len + ((len % HEXDUMP_COLS) ? (HEXDUMP_COLS - len % HEXDUMP_COLS) : 0); i++)
        {
                /* print offset */
                if(i % HEXDUMP_COLS == 0)
                        printf(BOLDWHITE "0x%06x: " RESET, i);
 
                /* print hex data */
                if(i < len)
                {
                        if(i == mark_at || i-1 == mark_at)
                               printf(BOLDRED "%02x " RESET, 0xFF & ((char*)mem)[i]); 
                        else
                                printf("%02x ", 0xFF & ((char*)mem)[i]);
                }
                else /* end of block, just aligning for ASCII dump */
                        printf("   ");
                
                /* print ASCII dump */
                if(i % HEXDUMP_COLS == (HEXDUMP_COLS - 1))
                {
                        for(j = i - (HEXDUMP_COLS - 1); j <= i; j++)
                                if(j >= len) /* end of block, not really printing */
                                        putchar(' ');
                                else if(isprint(((char*)mem)[j])) /* printable char */
                                        putchar(0xFF & ((char*)mem)[j]);        
                                else /* other char */
                                        putchar('.');

                        putchar('\n');
                }
        }
}