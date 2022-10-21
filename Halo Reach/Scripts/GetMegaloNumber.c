
uint GetMegaloNumber(short param_1)

{
    byte bVar1;
    short sVar2;
    undefined4 uVar3;
    uint uVar4;
    int iVar5;
    undefined8 uVar6;
    longlong* plVar7;
    longlong lVar8;
    undefined6 in_register_0000000a;
    short* psVar9;
    uint uVar10;
    uint uVar11;
    ulonglong uVar12;
    longlong in_GS_OFFSET;

    psVar9 = (short*)CONCAT62(in_register_0000000a, param_1);
    uVar10 = 0;
    uVar11 = 0;
    switch (*(undefined*)(psVar9 + 1)) {
    case 0:
        uVar11 = (uint)*psVar9;
        break;
    case 1:
        uVar4 = ExplicitPlayerType((byte*)psVar9);
        uVar11 = uVar10;
        if (uVar4 != 0xffffffff) {
            uVar11 = (uint) * (short*)(*(longlong*)
                (*(longlong*)
                    (*(longlong*)(in_GS_OFFSET + 0x58) +
                        (ulonglong)GametypeIndex * 8) + 0x20) + 0x2ec +
                ((ulonglong)(uVar4 & 0xffff) * 0x70 +
                    (ulonglong) * (byte*)((longlong)psVar9 + 1)) * 2);
        }
        break;
    case 2:
        iVar5 = FUN_18023ef28(psVar9);
        lVar8 = FUN_18017ec70(iVar5, 0);
        if (lVar8 == 0) {
            uVar11 = uVar10;
            if (iVar5 != -1) {
                sVar2 = Return_GametypeLocation();
                uVar11 = GetMegaloNumber(sVar2 + (*(byte*)((longlong)psVar9 + 1) + 0x4c08) * 3);
            }
        }
        else {
            uVar11 = (int)*(short*)(lVar8 + 0x4e + (ulonglong) * (byte*)((longlong)psVar9 + 1) * 2);
        }
        break;
    case 3:
        iVar5 = MegaloGetDirectTeam((char*)psVar9);
        uVar11 = uVar10;
        if (iVar5 != -1) {
            uVar11 = (int)*(short*)(*(longlong*)
                (*(longlong*)
                    (*(longlong*)(in_GS_OFFSET + 0x58) +
                        (ulonglong)GametypeIndex * 8) + 0x20) + 0x10f4 +
                ((ulonglong) * (byte*)((longlong)psVar9 + 1) +
                    (longlong)iVar5 * 0x24) * 2);
        }
        break;
    case 4:
        uVar11 = (int)*(short*)(*(longlong*)
            (*(longlong*)
                (*(longlong*)(in_GS_OFFSET + 0x58) + (ulonglong)GametypeIndex * 8
                    ) + 0x20) + 0x1ec + (ulonglong) * (byte*)((longlong)psVar9 + 1) * 2
            );
        break;
    case 5:
        uVar12 = (ulonglong) * (byte*)((longlong)psVar9 + 1);
        uVar6 = Return_GametypeLocation();
        uVar11 = FUN_1800cd060(uVar6, uVar12 & 0xffffffff);
        break;
    case 6:
        uVar3 = FUN_18023ef28(psVar9);
        lVar8 = FUN_180477540(uVar3);
        uVar11 = uVar10;
        if (lVar8 != 0) {
            uVar11 = (int)*(char*)(lVar8 + 0x1a);
        }
        break;
    case 7:
        iVar5 = MegaloGetDirectTeam((char*)psVar9);
        iVar5 = FUN_180039efc(iVar5);
        uVar11 = uVar10;
        if (iVar5 != -1) {
            uVar11 = FUN_180068c80(iVar5);
        }
        break;
    case 8:
        iVar5 = ExplicitPlayerType((byte*)psVar9);
        uVar11 = uVar10;
        if (iVar5 != -1) {
            uVar11 = FUN_180068880(iVar5);
        }
        break;
    case 9:
        uVar4 = ExplicitPlayerType((byte*)psVar9);
        uVar11 = uVar10;
        if (uVar4 != 0xffffffff) {
            uVar11 = *(uint*)(*(longlong*)
                (*(longlong*)
                    (*(longlong*)
                        (*(longlong*)(in_GS_OFFSET + 0x58) + (ulonglong)GametypeIndex * 8)
                        + 0x18) + 0x50) + 0x47c + (ulonglong)(uVar4 & 0xffff) * 0x558);
        }
        break;
    case 10:
        iVar5 = ExplicitPlayerType((byte*)psVar9);
        uVar11 = uVar10;
        if (iVar5 != -1) {
            uVar11 = FUN_180068974(iVar5, &DAT_182789990, 0);
        }
        break;
    case 0xb:
        uVar11 = ExplicitPlayerType((byte*)psVar9);
        if (uVar11 == 0xffffffff) {
            return 0;
        }
        bVar1 = *(byte*)((longlong)psVar9 + 1);
        uVar11 = uVar11 & 0xffff;
        iVar5 = -1;
        goto LAB_1801c96b4;
    case 0xc:
        iVar5 = MegaloGetDirectTeam((char*)psVar9);
        iVar5 = FUN_180039efc(iVar5);
        if (iVar5 == -1) {
            return 0;
        }
        bVar1 = *(byte*)((longlong)psVar9 + 1);
        uVar11 = 0xffffffff;
    LAB_1801c96b4:
        uVar11 = FUN_1800ea27c(uVar11, iVar5, bVar1 + 0xf);
        break;
    case 0xd:
        uVar11 = FUN_180069f90();
        break;
    case 0xe:
    case 0xf:
        plVar7 = (longlong*)Return_GametypeLocation();
        bVar1 = (**(code**)(*plVar7 + 0x58))(plVar7);
        goto LAB_1801c96fe;
    case 0x10:
        plVar7 = (longlong*)Return_GametypeLocation();
        uVar11 = (**(code**)(*plVar7 + 0x48))(plVar7);
        break;
    case 0x11:
        plVar7 = (longlong*)Return_GametypeLocation();
        bVar1 = (**(code**)(*plVar7 + 0x40))(plVar7);
    LAB_1801c96fe:
        uVar11 = (uint)bVar1;
        break;
    case 0x12:
        lVar8 = Return_GametypeLocation();
        uVar11 = (uint) * (byte*)(lVar8 + 0x2b8);
        goto LAB_1801c9735;
    case 0x13:
        lVar8 = Return_GametypeLocation();
        uVar11 = (uint) * (byte*)(lVar8 + 0x2ba) * 0x3c;
        break;
    case 0x14:
        lVar8 = Return_GametypeLocation();
        uVar11 = (uint) * (byte*)(lVar8 + 699);
        break;
    case 0x15:
        lVar8 = Return_GametypeLocation();
        uVar11 = (uint)(*(byte*)(lVar8 + 0x2b8) >> 3);
        goto LAB_1801c9735;
    case 0x16:
        lVar8 = Return_GametypeLocation();
        uVar11 = (uint) * (byte*)(lVar8 + 0x2b9);
        break;
    case 0x17:
        lVar8 = Return_GametypeLocation();
        uVar11 = (int)*(short*)(lVar8 + 700);
        break;
    case 0x18:
        lVar8 = Return_GametypeLocation();
        uVar11 = (int)*(short*)(lVar8 + 0x2be);
        break;
    case 0x19:
        lVar8 = Return_GametypeLocation();
        uVar11 = (uint) * (byte*)(lVar8 + 0x2c1);
        break;
    case 0x1a:
        lVar8 = Return_GametypeLocation();
        uVar11 = (uint) * (byte*)(lVar8 + 0x2c2);
        break;
    case 0x1b:
        lVar8 = Return_GametypeLocation();
        uVar11 = (uint) * (byte*)(lVar8 + 0x2c3);
        break;
    case 0x1c:
        lVar8 = Return_GametypeLocation();
        uVar11 = (uint) * (byte*)(lVar8 + 0x2c4);
        break;
    case 0x1d:
        lVar8 = Return_GametypeLocation();
        uVar11 = (uint) * (byte*)(lVar8 + 0x2c5);
        break;
    case 0x1e:
        lVar8 = Return_GametypeLocation();
        uVar11 = (uint) * (byte*)(lVar8 + 0x2c6);
        break;
    case 0x1f:
        lVar8 = Return_GametypeLocation();
        uVar11 = (uint) * (byte*)(lVar8 + 0x2c7);
        break;
    case 0x20:
        lVar8 = Return_GametypeLocation();
        uVar11 = (uint) * (byte*)(lVar8 + 0x2c8);
        break;
    case 0x21:
        lVar8 = Return_GametypeLocation();
        uVar11 = (uint) * (byte*)(lVar8 + 0x2f8);
        goto LAB_1801c9735;
    case 0x22:
        lVar8 = Return_GametypeLocation();
        uVar11 = (uint)(*(ushort*)(lVar8 + 0x2f8) >> 1);
        goto LAB_1801c984e;
    case 0x23:
        lVar8 = Return_GametypeLocation();
        uVar11 = (uint)(*(ushort*)(lVar8 + 0x2f8) >> 2);
        goto LAB_1801c984e;
    case 0x24:
        lVar8 = Return_GametypeLocation();
        uVar11 = (uint)(*(ushort*)(lVar8 + 0x2f8) >> 3);
        goto LAB_1801c984e;
    case 0x25:
        lVar8 = Return_GametypeLocation();
        uVar11 = (uint)(*(ushort*)(lVar8 + 0x2f8) >> 4);
    LAB_1801c984e:
        uVar11 = uVar11 & 1;
        break;
    case 0x26:
        lVar8 = Return_GametypeLocation();
        uVar11 = (uint) * (byte*)(lVar8 + 0x2fc);
        goto LAB_1801c9735;
    case 0x27:
        lVar8 = Return_GametypeLocation();
        uVar11 = (uint)(*(byte*)(lVar8 + 0x2fc) >> 5);
    LAB_1801c9735:
        uVar11 = uVar11 & 1;
        break;
    case 0x28:
        lVar8 = Return_GametypeLocation();
        uVar11 = (uint) * (byte*)(lVar8 + 0x3b4);
        break;
    case 0x29:
        lVar8 = Return_GametypeLocation();
        uVar11 = (uint) * (byte*)(lVar8 + 0x3b5);
        break;
    case 0x2a:
        lVar8 = Return_GametypeLocation();
        uVar11 = (uint) * (byte*)(lVar8 + 0x3b6);
        break;
    case 0x2b:
        uVar11 = (uint) * (byte*)(*(longlong*)
            (*(longlong*)
                (*(longlong*)(in_GS_OFFSET + 0x58) + (ulonglong)GametypeIndex * 8
                    ) + 0x20) + 400);
    }
    return uVar11;
}

