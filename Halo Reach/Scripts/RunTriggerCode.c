
void RunTriggerCode(Trigger* trigger, longlong MegaloCodeTable)

{
    char Condition_result;
    uint or_group;
    longlong CondtableIndex;
    Condition* Condition_Address;
    int ConditionIndex;
    int ActionIndex;
    bool Group_Still_Valid;
    uint current_or_group;

    ConditionIndex = 0;
    ActionIndex = 0;
    if (trigger->ActionsCount != 0) {
        do {
            current_or_group = 0xffffffff;
            Group_Still_Valid = true;
            if (ConditionIndex < (int)(uint)trigger->ConditionsCount) {
                do {
                    CondtableIndex = (longlong)(int)((uint)trigger->ConditionsStart + ConditionIndex);
                    if (ActionIndex < (int)(uint) * (byte*)(MegaloCodeTable + 0xf1f + CondtableIndex * 0x10)) break;
                    Condition_Address = (Condition*)((CondtableIndex + 0xf1) * 0x10 + MegaloCodeTable);
                    or_group = (uint)Condition_Address->or_group;
                    if (or_group != current_or_group) {
                        if (!Group_Still_Valid) {
                            return;
                        }
                        Group_Still_Valid = false;
                        current_or_group = or_group;
                    }
                    Condition_result = Evaluate_Condition(Condition_Address);
                    if (Condition_result != 0) {
                        Group_Still_Valid = true;
                    }
                    ConditionIndex = ConditionIndex + 1;
                } while (ConditionIndex < (int)(uint)trigger->ConditionsCount);
                if (!Group_Still_Valid) {
                    return;
                }
            }
            Evaluate_Action((Action*)(MegaloCodeTable +((longlong)(int)((uint)trigger->ActionsStart + ActionIndex) * 5 + 0xbc6) *4));
            ActionIndex = ActionIndex + 1;
        } while (ActionIndex < (int)(uint)trigger->ActionsCount);
    }
    return;
}

