#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h> // for open
#include <unistd.h> // for close

#define BUF_SIZE 8

typedef struct {
    char head;
    char tail;
    char data[BUF_SIZE];
    char count;
}cb_t;

void Init (cb_t *c_buf)
{
    
    memset(c_buf->data, 0,BUF_SIZE);
    c_buf->head = 0;
    c_buf->tail = 0;
    c_buf->count = 0;
    return;
}

int cb_is_empty (cb_t *c_buf)
{
   if (c_buf->head == c_buf->tail)
   {
       return 1;
   }
    return 0;
  
}

int cb_is_full (cb_t *c_buf)
{
    if ((BUF_SIZE == ((c_buf->head+1)-c_buf->tail)) || (1 == c_buf->tail-c_buf->head ))
    {
        return 1;
    }
    return 0;
     
}

void cb_write (cb_t *c_buf, char idata)
{
    if (cb_is_full(c_buf))
    {
        
        printf("Buf is full, please clean the buffer to write.\n");
        //printf("%c \n", idata);
        //cb_read(c_buf, idata);
    }
    else
    {
        c_buf->data[c_buf->head]=idata;
        ++c_buf->head;
        return;
    }
    
}

char cb_read (cb_t *c_buf)
{
    if (cb_is_empty(c_buf))
    {
        printf("Buf is empty, please write something to read.\n");
        //cb_write(c_buf, str[c_buf->count]);
        //cb_write(c_buf);
    }
    else
    {
        char odata = '\0';
        odata = c_buf->data[c_buf->tail];
        ++c_buf->tail;
        printf("readout: %c\n", odata);
        //return odata;
    }
}


int main()
{
    cb_t cb;
    
    char readout = '\0';
    char str[10]="abc123456";
    Init(&cb);
    for (cb.count;cb.count<10;cb.count++)
    {
        //printf ("str: %c\n", str[cb.count]);
        cb_write(&cb, str[cb.count]);
    }
    for (int a=0;a<BUF_SIZE;a++)
    {
        cb_read(&cb);
        
    }
    

    return 0;
}
