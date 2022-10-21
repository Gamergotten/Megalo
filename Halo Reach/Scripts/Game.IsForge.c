
ulonglong Game.IsForge(void)

{
    int iVar1;
    longlong lVar2;
    ulonglong uVar3;
    longlong lVar4;
    ulonglong uVar5;
    longlong in_GS_OFFSET;

    lVar2 = *(longlong*)(*(longlong*)(in_GS_OFFSET + 0x58) + (ulonglong)GametypeIndex * 8);
    iVar1 = *(int*)(*(longlong*)(lVar2 + 0x20) + 0x841c);
    uVar3 = (ulonglong)(iVar1 - 1U);
    if (iVar1 - 1U < 4) {
        lVar4 = *(longlong*)(&DAT_180a274b8 + (longlong)iVar1 * 8);
        uVar3 = (longlong)iVar1;
    }
    else {
        lVar4 = 0;
    }
    if ((lVar4 != 0) && (uVar3 = *(ulonglong*)(lVar2 + 0x50), *(int*)(uVar3 + 0x10) == 3)) {
        uVar3 = FUN_18006fe5c();
        uVar5 = 1;
        if ((short)uVar3 == 1) goto LAB_180060c6d;
    }
    uVar5 = 0;
LAB_180060c6d:
    return uVar3 & 0xffffffffffffff00 | uVar5;
}


undefined2 FUN_18006fe5c(void)

{
    undefined2* puVar1;
    int iVar2;
    longlong lVar3;
    undefined2 uVar4;
    longlong in_GS_OFFSET;

    lVar3 = *(longlong*)
        (*(longlong*)(*(longlong*)(in_GS_OFFSET + 0x58) + (ulonglong)GametypeIndex * 8) + 0x50
            );
    iVar2 = *(int*)(lVar3 + 0x10);
    uVar4 = 0;
    if (((iVar2 != 1) && (uVar4 = 0, iVar2 - 1U < 3)) &&
        (puVar1 = (undefined2*)(lVar3 + 0x38), puVar1 != (undefined2*)0x0)) {
        uVar4 = *puVar1;
    }
    return uVar4;
}
