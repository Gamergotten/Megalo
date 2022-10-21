
ulonglong GetMegaloTimer_butweird(void)

{
    uint* puVar1;
    ulonglong uVar2;
    int iVar3;
    longlong in_GS_OFFSET;

    puVar1 = (uint*)FUN_1801cb92c();
    uVar2 = 0;
    if (puVar1 != (uint*)0x0) {
        iVar3 = (int)*(short*)(*(longlong*)
            (*(longlong*)
                (*(longlong*)(in_GS_OFFSET + 0x58) + (ulonglong)GametypeIndex * 8)
                + 0xa8) + 6);
        uVar2 = (longlong)(int)(iVar3 + -1 + (*puVar1 & 0xffffff) / 0x14) / (longlong)iVar3 &
            0xffffffff;
    }
    return uVar2;
}

