
void FUN_1405cde70(byte* Trigger, longlong MegaloTable)

{
    byte bVar1;
    ushort ConditionCount;
    bool bVar3;
    char cVar4;
    bool ConditionResult;
    uint CurrentOrGroup;
    undefined4* puVar6;
    longlong Condition;
    int ConditionInsert;
    int ConditionIndex;
    uint PrevOrGroup;
    int iVar10;
    undefined auStack136[32];
    undefined local_68[32];
    ulonglong local_48;

    local_48 = DAT_14222db28 ^ (ulonglong)auStack136;
    ConditionIndex = 0;
    FUN_1407a4640(local_68, (longlong)(Trigger + (-8 - MegaloTable)) / 0xc);
    FUN_1407a4670();
    if ((DAT_142009b84 == 0) && (Trigger->ActionCount == 5)) {
        bVar1 = Trigger->ForgeLabel;
        if (0x10 < *(uint*)(MegaloTable + 0x80e4)) {
            ReportError(&PTR_s_valid()_1417bcfa0);
        }
        if (((char)bVar1 < 0) || (*(int*)(MegaloTable + 0x80e4) <= (int)(char)bVar1)) {
            ReportError(&PTR_s_valid(index)_1417bcf40);
        }
        puVar6 = (undefined4*)FUN_140734990();
        cVar4 = FUN_1407a40c0(MegaloTable + 0x80ec + (longlong)(char)bVar1 * 0x10, *puVar6);
        if (cVar4 == 0) goto Trigger_SkipToEnd;
    }
    iVar10 = 0;
    if (Trigger->ActionCount != 0) {
        do {
            ConditionCount = Trigger->ConditionCount;
            PrevOrGroup = 0xffffffff;
            bVar3 = true;
            if (ConditionIndex < ConditionCount) {
                do {
                    if ((ConditionIndex < 0) || (ConditionCount <= ConditionIndex)) 
                    {
                        ReportError(&PTR_s_VALID_INDEX(condition_index,_con_1417bceb8);
                    }
                    ConditionInsert = Trigger->ConditionStart + ConditionIndex;
                    if (512 < MegaloTable->ConditionCount) 
                    {
                        ReportError(&PTR_s_valid()_1417bcfd0);
                    }
                    if ((ConditionInsert < 0) || (MegaloTable->ConditionCount <= ConditionInsert)) {
                        ReportError(&PTR_s_valid(index)_1417bcf70);
                    }
                    if (iVar10 < (MegaloTable->Conditions[ConditionInsert].ExecBefore))
                        break;
                    if ((ConditionIndex < 0) || (Trigger->ConditionCount <= ConditionIndex)) 
                    {
                        ReportError(&PTR_s_VALID_INDEX(condition_index,_con_1417bceb8);
                    }
                    ConditionInsert = Trigger->ConditionStart + ConditionIndex;
                    if (512 < MegaloTable->ConditionCount) 
                    {
                        ReportError(&PTR_s_valid()_1417bcfd0);
                    }
                    if ((ConditionInsert < 0) || (MegaloTable->ConditionCount <= ConditionInsert)) 
                    {
                        ReportError(&PTR_s_valid(index)_1417bcf70);
                    }
                    Condition = MegaloTable->Conditions[ConditionInsert];
                    CurrentOrGroup = (Condition->OrGroup);
                    if (CurrentOrGroup != PrevOrGroup) 
                    {
                        if (!bVar3) goto Trigger_SkipToEnd;
                        bVar3 = false;
                        PrevOrGroup = CurrentOrGroup;
                    }
                    Evaluate_Condition(Condition);
                    ConditionResult = ConditionCount = Trigger->ConditionCount;
                    if (ConditionResult)
                    {
                        bVar3 = true;
                    }
                    ConditionIndex = ConditionIndex + 1;
                } while (ConditionIndex < ConditionCount);
                if (!bVar3) break;
            }
            if ((iVar10 < 0) || ((int)(uint) * (ushort*)(Trigger + 10) <= iVar10)) {
                ReportError(&PTR_s_VALID_INDEX(action_index, _action_1417bcf00);
            }
            ConditionInsert = (uint) * (ushort*)(Trigger + 8) + iVar10;
            if (0x400 < *(uint*)(MegaloTable + 0x2f10)) {
                ReportError(&PTR_s_valid()_1417bcfb8);
            }
            if ((ConditionInsert < 0) || (*(int*)(MegaloTable + 0x2f10) <= ConditionInsert)) {
                ReportError(&PTR_s_valid(index)_1417bcf58);
            }
            HandleAction(MegaloTable + ((longlong)ConditionInsert * 5 + 0xbc6) * 4);
            iVar10 = iVar10 + 1;
        } while (iVar10 < (int)(uint) * (ushort*)(Trigger + 10));
    }
Trigger_SkipToEnd:
    FUN_140edc990(local_48 ^ (ulonglong)auStack136);
    return;
}

