
undefined4 GetMegaloObject(longlong param_1)

{
    char cVar1;
    int iVar2;
    undefined4 uVar3;
    uint uVar4;
    undefined4 uVar5;
    longlong lVar6;
    longlong in_GS_OFFSET;

    cVar1 = *(char*)(param_1 + 2);
    uVar3 = 0xffffffff;
    if (cVar1 == '\0') {
        uVar3 = FUN_18023ef28();
    }
    else if (cVar1 == '\x01') {
        uVar4 = ExplicitPlayerType((byte*)param_1);
        if (uVar4 != 0xffffffff) {
            uVar3 = *(undefined4*)
                (*(longlong*)
                    (*(longlong*)
                        (*(longlong*)(in_GS_OFFSET + 0x58) + (ulonglong)GametypeIndex * 8) + 0x20) +
                    0x2d8 + ((ulonglong)(uVar4 & 0xffff) * 0x38 + (ulonglong) * (byte*)(param_1 + 1))
                    * 4);
        }
    }
    else if (cVar1 == '\x02') {
        uVar5 = FUN_18023ef28();
        lVar6 = FUN_18017ec70(uVar5, 0);
        if (lVar6 != 0) {
            uVar3 = *(undefined4*)(lVar6 + 0x3c + (ulonglong) * (byte*)(param_1 + 1) * 4);
        }
    }
    else if (cVar1 == '\x03') {
        iVar2 = MegaloGetDirectTeam((char*)param_1);
        if (iVar2 != -1) {
            uVar3 = *(undefined4*)
                (*(longlong*)
                    (*(longlong*)
                        (*(longlong*)(in_GS_OFFSET + 0x58) + (ulonglong)GametypeIndex * 8) + 0x20) +
                    0x10d8 + ((ulonglong) * (byte*)(param_1 + 1) + (longlong)iVar2 * 0x12) * 4);
        }
    }
    else {
        if (cVar1 == '\x04') {
            uVar3 = ExplicitPlayerType((byte*)param_1);
        }
        else {
            if (cVar1 == '\x05') {
                uVar4 = ExplicitPlayerType((byte*)param_1);
                if (uVar4 == 0xffffffff) {
                    return 0xffffffff;
                }
                iVar2 = (int)*(char*)(*(longlong*)
                    (*(longlong*)
                        (*(longlong*)(in_GS_OFFSET + 0x58) +
                            (ulonglong)GametypeIndex * 8) + 0x20) +
                    (ulonglong)(uVar4 & 0xffff) * 0xe0 + 0x30c +
                    (ulonglong) * (byte*)(param_1 + 1));
            }
            else if (cVar1 == '\x06') {
                uVar3 = FUN_18023ef28();
                lVar6 = FUN_18017ec70(uVar3, 0);
                if (lVar6 == 0) {
                    return 0xffffffff;
                }
                iVar2 = (int)*(char*)((ulonglong) * (byte*)(param_1 + 1) + 0x70 + lVar6);
            }
            else {
                if (cVar1 != '\a') {
                    return 0xffffffff;
                }
                iVar2 = MegaloGetDirectTeam((char*)param_1);
                if (iVar2 == -1) {
                    return 0xffffffff;
                }
                iVar2 = (int)*(char*)(*(longlong*)
                    (*(longlong*)
                        (*(longlong*)(in_GS_OFFSET + 0x58) +
                            (ulonglong)GametypeIndex * 8) + 0x20) + (longlong)iVar2 * 0x48
                    + 0x1114 + (ulonglong) * (byte*)(param_1 + 1));
            }
            uVar3 = FUN_180043f4c(iVar2);
        }
        uVar3 = FUN_1801cc420(uVar3);
    }
    return uVar3;
}

undefined4 FUN_18023ef28(char* param_1)
{
    char cVar1;
    undefined4 uVar2;
    longlong in_GS_OFFSET;

    cVar1 = *param_1;
    uVar2 = 0xffffffff;
    if (cVar1 != '\0') {
        if ((byte)(cVar1 - 1U) < 0x10) {
            uVar2 = *(undefined4*)
                (*(longlong*)
                    (*(longlong*)
                        (*(longlong*)(in_GS_OFFSET + 0x58) + (ulonglong)GametypeIndex * 8) + 0x20) +
                    0x1a0 + (longlong)cVar1 * 4);
        }
        else if (cVar1 == '\x11') {
            uVar2 = *(undefined4*)
                (*(longlong*)
                    (*(longlong*)
                        (*(longlong*)(in_GS_OFFSET + 0x58) + (ulonglong)GametypeIndex * 8) + 0x20) +
                    0x168);
        }
        else if (cVar1 == '\x12') {
            uVar2 = *(undefined4*)
                (*(longlong*)
                    (*(longlong*)
                        (*(longlong*)(in_GS_OFFSET + 0x58) + (ulonglong)GametypeIndex * 8) + 0x20) +
                    0x180);
        }
        else if (cVar1 == '\x13') {
            uVar2 = *(undefined4*)
                (*(longlong*)
                    (*(longlong*)
                        (*(longlong*)(in_GS_OFFSET + 0x58) + (ulonglong)GametypeIndex * 8) + 0x20) +
                    0x184);
        }
        else {
            uVar2 = 0xffffffff;
            if (cVar1 == '\x14') {
                uVar2 = *(undefined4*)
                    (*(longlong*)
                        (*(longlong*)
                            (*(longlong*)(in_GS_OFFSET + 0x58) + (ulonglong)GametypeIndex * 8) + 0x20)
                        + 0x188);
            }
        }
    }
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

undefined4 FUN_1801cc420(uint param_1)

{
    longlong lVar1;
    undefined4 uVar2;
    longlong lVar3;
    longlong in_GS_OFFSET;

    uVar2 = 0xffffffff;
    if (param_1 != 0xffffffff) {
        lVar3 = (ulonglong)(param_1 & 0xffff) * 0x558;
        lVar1 = *(longlong*)
            (*(longlong*)
                (*(longlong*)(*(longlong*)(in_GS_OFFSET + 0x58) + (ulonglong)GametypeIndex * 8) +
                    0x18) + 0x50);
        uVar2 = 0xffffffff;
        if (*(int*)(lVar1 + 0x28 + lVar3) != -1) {
            uVar2 = *(undefined4*)(lVar1 + 0x28 + lVar3);
        }
    }
    return uVar2;
}