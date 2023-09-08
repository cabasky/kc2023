
void create(int size, int type);
void remake(unsigned int index, int new_size, int type);
void delete(unsigned int index);

void add(unsigned int value);
void sub(unsigned int value);

void and(unsigned int value);

void  or(unsigned int value);

void  xor(unsigned int value);
void swap();
void end();

void KCTF() {
    remake(14,112,1);
create(70,1);
create(70,1);
delete(0);
delete(0);
}
