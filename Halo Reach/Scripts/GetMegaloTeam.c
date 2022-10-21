
int GetMegaloTeam(longlong param_1)

{
    char cVar1;
    int iVar2;
    int iVar3;
    int iVar4;
    uint uVar5;
    longlong lVar6;
    longlong* plVar7;
    longlong in_GS_OFFSET;

    cVar1 = *(char*)(param_1 + 2);
    iVar4 = -1;
    plVar7 = (longlong*)0;
    if (cVar1 == 0) {
        iVar3 = MegaloGetDirectTeam((char*)param_1);
    }
    else {
        iVar3 = iVar4;
        if (cVar1 == 1) {
            uVar5 = ExplicitPlayerType((byte*)param_1);
            if (uVar5 != 0xffffffff) {
                iVar3 = (int)*(char*)(*(longlong*)
                    (*(longlong*)
                        (*(longlong*)(in_GS_OFFSET + 0x58) +
                            (ulonglong)GametypeIndex * 8) + 0x20) +
                    (ulonglong)(uVar5 & 0xffff) * 0xe0 + 0x2e8 +
                    (ulonglong) * (byte*)(param_1 + 1));
            }
        }
        else if (cVar1 == 2) {
            iVar4 = FUN_18023ef28();
            lVar6 = FUN_18017ec70(iVar4, 0);
            if (lVar6 == 0) {
                if (iVar4 != -1) {
                    lVar6 = Return_GametypeLocation();
                    iVar3 = (int)*(char*)(lVar6 + 0xe44c + (ulonglong) * (byte*)(param_1 + 1));
                }
            }
            else {
                iVar3 = (int)*(char*)((ulonglong) * (byte*)(param_1 + 1) + 0x4c + lVar6);
            }
        }
        else if (cVar1 == '\x03') {
            iVar4 = MegaloGetDirectTeam((char*)param_1);
            if (iVar4 != -1) {
                iVar3 = (int)*(char*)(*(longlong*)
                    (*(longlong*)
                        (*(longlong*)(in_GS_OFFSET + 0x58) +
                            (ulonglong)GametypeIndex * 8) + 0x20) + (longlong)iVar4 * 0x48
                    + 0x10f0 + (ulonglong) * (byte*)(param_1 + 1));
            }
        }
        else if (cVar1 == '\x04') {
            iVar4 = ExplicitPlayerType((byte*)param_1);
            if (iVar4 != -1) {
                iVar3 = *(int*)(*(longlong*)
                    (*(longlong*)
                        (*(longlong*)(in_GS_OFFSET + 0x58) + (ulonglong)GametypeIndex * 8)
                        + 0x20) + 0x841c);
                if (iVar3 - 1U < 4) {
                    plVar7 = *(longlong**)(&DAT_180a274b8 + (longlong)iVar3 * 8);
                }
                iVar3 = (**(code**)(*plVar7 + 400))(plVar7, iVar4);
            }
        }
        else {
            iVar3 = -1;
            if ((cVar1 == '\x05') && (iVar2 = FUN_18023ef28(), iVar3 = iVar4, iVar2 != -1)) {
                iVar3 = FUN_1801cc4bc(iVar2);
            }
        }
    }
    return iVar3;
}


int FUN_1801cc4bc(uint param_1)

{
    longlong lVar1;
    int iVar2;
    longlong lVar3;
    longlong* plVar4;
    ulonglong uVar5;
    longlong in_GS_OFFSET;

    iVar2 = -1;
    if (param_1 != 0xffffffff) {
        lVar3 = *(longlong*)(*(longlong*)(in_GS_OFFSET + 0x58) + (ulonglong)GametypeIndex * 8);
        uVar5 = (ulonglong)param_1 & 0xffff;
        lVar1 = *(longlong*)(*(longlong*)(lVar3 + 8) + 0x50);
        if (((1 << (*(byte*)(lVar1 + 4 + uVar5 * 0x18) & 0x1f) & 0x1003U) != 0) &&
            (*(int*)(*(longlong*)(lVar1 + 0x10 + uVar5 * 0x18) + 0x1cc) != -1)) {
            iVar2 = *(int*)(*(longlong*)(lVar3 + 0x20) + 0x841c);
            if (iVar2 - 1U < 4) {
                plVar4 = *(longlong**)(&DAT_180a274b8 + (longlong)iVar2 * 8);
            }
            else {
                plVar4 = (longlong*)0x0;
            }
            iVar2 = (**(code**)(*plVar4 + 400))();
            return iVar2;
        }
    }
    lVar3 = FUN_180477540((ulonglong)param_1);
    if (lVar3 != 0) {
        iVar2 = (int)*(char*)(lVar3 + 0x19);
    }
    return iVar2;
}


longlong FUN_180477540(int param_1)

{
    longlong lVar1;
    longlong lVar2;

    lVar1 = GetObjectAddress_WithTypeFilter(param_1, 0xffffffff);
    lVar2 = 0;
    if ((lVar1 != 0) && (*(short*)(lVar1 + 0x196) != -1)) {
        lVar2 = *(short*)(lVar1 + 0x196) + lVar1;
    }
    return lVar2;
}


ulonglong GetObjectAddress_WithTypeFilter(int object, uint TypeFilter)

{
    ObjectWrapper* object_wrapper;
    ulonglong OutAddress;
    longlong in_GS_OFFSET;

    OutAddress = 0;
    object_wrapper =
        GetObjectAddressFromObjectTable
        (*(Arrayof**)
            (*(longlong*)
                (*(longlong*)(in_GS_OFFSET + 0x58) + (ulonglong)GametypeIndex * 8) + 8),
            (GameObject)object);
    // if object_wrapper != null and idk how to explain this next condition
    // you just have to read it and figure it out
    if ((object_wrapper != (ObjectWrapper*)0x0) &&
        ((TypeFilter >> (*(byte*)&object_wrapper->type & 0b00011111) & 1) != 0)) {
        OutAddress = object_wrapper->object_data;
    }
    return OutAddress;
}

