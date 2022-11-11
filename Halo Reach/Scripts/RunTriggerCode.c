
void RunTriggerCode(Trigger* trigger, longlong MegaloCodeTable)

{
    bool Condition_result;
    uint or_group;
    longlong CondtableIndex;
    Condition* Condition_Address;
    int ConditionIndex;
    int ActionIndex;
    bool Group_Still_Valid;
    uint current_or_group;

    ConditionIndex = 0;
    // if this trigger has actions to run, then proceed
    if (trigger->ActionsCount != 0) 
    {
        for (int ActionIndex = 0; ActionIndex < trigger->ActionsCount; ActionIndex++)
        {
            // condtions with the same or group, but spread out across several offsets are treated as AND's, interestingly
            current_or_group = 0xffffffff;
            Group_Still_Valid = true;
            // if there are still conditions left to be evaluated, then
            while (ConditionIndex < trigger->ConditionsCount)  // in this snippet, this loop would not be entered if the condition is not true, incase thats not how it works normally
            {
                // find the pointer to the actual condition
                CondtableIndex = trigger->ConditionsStart + ConditionIndex;
                Condition_Address = (Condition*)((CondtableIndex + 0xf1) * 0x10 + MegaloCodeTable);

                // if the current condition is ahead of the current action, then skip processing condtions, potentially exploitable for higher functioanlity
                // IE. store conditions in the incorrect order, so conditions are not evaluated in a logical manner
                if (ActionIndex < Condition_Address->ExecBefore))) break;

                // if or groups do not match, then this is an AND, invalidate current or group
                // or group is first -1, so this is always evaluated on the first iteration
                or_group = Condition_Address->or_group;
                if (or_group != current_or_group) 
                {
                    // if the last condition was false, or last or group of conditions were false, then obviosly we shouldn't have reached this condition, end execution
                    if (!Group_Still_Valid) return;

                    Group_Still_Valid = false;
                    current_or_group = or_group;
                }
                if (Evaluate_Condition(Condition_Address))
                    Group_Still_Valid = true;

                ConditionIndex++;
            }
            if (!Group_Still_Valid) return;

            // if the conditions passed, then this action is free to run
            Evaluate_Action((Action*)(MegaloCodeTable +((longlong)(int)((uint)trigger->ActionsStart + ActionIndex) * 5 + 0xbc6) *4));
        } 
    }
    return;
}

