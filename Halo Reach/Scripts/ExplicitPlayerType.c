
undefined4 ExplicitPlayerType(byte* param_1)

{
    byte bVar1;
    undefined4 uVar2;
    int iVar3;
    longlong in_GS_OFFSET;

    bVar1 = *param_1;
    if (bVar1 == 0) {
        return 0xffffffff;
    }
    if ((byte)(bVar1 - 0x11) < 8) {
        iVar3 = (int)*(char*)(*(longlong*)
            (*(longlong*)
                (*(longlong*)(in_GS_OFFSET + 0x58) + (ulonglong)GametypeIndex * 8)
                + 0x20) + 0x213 + (longlong)(char)bVar1);
    }
    else {
        if (bVar1 == 0x19) {
            return *(undefined4*)
                (*(longlong*)
                    (*(longlong*)(*(longlong*)(in_GS_OFFSET + 0x58) + (ulonglong)GametypeIndex * 8)
                        + 0x20) + 0x16c);
        }
        if (bVar1 == 0x1a) {
            return *(undefined4*)
                (*(longlong*)
                    (*(longlong*)(*(longlong*)(in_GS_OFFSET + 0x58) + (ulonglong)GametypeIndex * 8)
                        + 0x20) + 0x178);
        }
        if (bVar1 == 0x1b) {
            return *(undefined4*)
                (*(longlong*)
                    (*(longlong*)(*(longlong*)(in_GS_OFFSET + 0x58) + (ulonglong)GametypeIndex * 8)
                        + 0x20) + 0x17c);
        }
        if (bVar1 == 0x1c) {
            return *(undefined4*)
                (*(longlong*)
                    (*(longlong*)(*(longlong*)(in_GS_OFFSET + 0x58) + (ulonglong)GametypeIndex * 8)
                        + 0x20) + 0x18c);
        }
        if (0x10 < bVar1) {
            return 0xffffffff;
        }
        iVar3 = (char)bVar1 + -1;
    }
    uVar2 = FUN_180043f4c(iVar3);
    return uVar2;
}


uint FUN_180043f4c(uint param_1)

{
    longlong lVar1;
    uint uVar2;
    longlong in_GS_OFFSET;

    lVar1 = *(longlong*)
        (*(longlong*)(*(longlong*)(in_GS_OFFSET + 0x58) + (ulonglong)GametypeIndex * 8) + 0x18
            );
    uVar2 = 0xffffffff;
    if (param_1 != 0xffffffff) {
        uVar2 = (int)*(short*)(*(longlong*)(lVar1 + 0x20) * (longlong)(int)param_1 +
            *(longlong*)(lVar1 + 0x50)) << 0x10 | param_1;
    }
    return uVar2;
}
