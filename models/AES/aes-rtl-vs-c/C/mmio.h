
#define PLACEHOLDER(n,name)  uint8_t name[(n)]

struct mmio
{
    PLACEHOLDER(1,start); 
    PLACEHOLDER(1,state); 
    uint16_t PlainTextPointer;
    uint16_t EncryptLength;
    PLACEHOLDER(10,empty);
    uint32_t  EncryptKey[4];
    uint32_t  EncryptCtr[4];
};

uint32_t * bufAddr;

void ToFunctionArg(struct mmio *m, struct AES_parameter *p, uint8_t * buffer)
{
    p->PlainTextPointer = (uint32_t *) & (buffer[m->PlainTextPointer]);
    bufAddr = (uint32_t *)  buffer;
    p->EncryptLength = m->EncryptLength;
    memory_move(m->EncryptKey,p->EncryptKey,4);
    memory_move(m->EncryptCtr,p->EncryptCtr,4);
}
void ToMemoryMap(struct AES_parameter *p, struct mmio *m)
{
    m->EncryptLength = p->EncryptLength;
    memory_move(p->EncryptKey,m->EncryptKey,4); // p -> m
    memory_move(p->EncryptCtr,m->EncryptCtr,4); // p -> m

}
void loadFromMem(uint32_t *memAddr, uint32_t dest[]) // len = 4
{
	dest[0] = *( bufAddr + (memAddr - bufAddr + 0)%16384 );
	dest[1] = *( bufAddr + (memAddr - bufAddr + 1)%16384 );
	dest[2] = *( bufAddr + (memAddr - bufAddr + 2)%16384 );
	dest[3] = *( bufAddr + (memAddr - bufAddr + 3)%16384 );
}
void storeToMem(uint32_t *memAddr, uint32_t src[])
{
	*( bufAddr + (memAddr - bufAddr + 0)%16384 ) = src[0];
	*( bufAddr + (memAddr - bufAddr + 1)%16384 ) = src[1];
	*( bufAddr + (memAddr - bufAddr + 2)%16384 ) = src[2];
	*( bufAddr + (memAddr - bufAddr + 3)%16384 ) = src[3];
}
void memory_move(uint32_t src[], uint32_t dest[], int len) /*Basically a memory copy operation*/
{
    int i;
    for(i=0;i<len;i++)
        dest[i] = src[i];
}
