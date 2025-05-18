add x2, x0, x1
sll x1, x2, x2
ori x2, x1, 15
lb x3, 0(x1)
sb x3, 0(x2)
bne x1, x2, label