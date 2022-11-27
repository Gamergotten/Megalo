

enum VarType {
    number = 0,
    player = 1,
    object = 2,
    team = 3,
    timer = 4
};
enum ComparisonType {
    lessthan = 0,
    greaterthan = 1,
    equal = 2,
    lessthanequal = 3,
    greaterthanequal = 4,
    notequal = 5
};

bool Evaluate_IF(Condition* Condition)
{
    int var2;
    int var1;
    switch (Condition->param_slots[3]) { // offset of the 1st var's type
    case VarType.timer:
        var1 = GetMegaloTimer_butweird(); // looks like i didn't get this function right, params are missing
        goto numbertimercomparison; // note: in the original code, 2nd var defaults to number if it is not a timer
    case VarType.number:
        var1 = GetMegaloNumber((short)Condition);
    numbertimercomparison:
        if (Condition->param_slots[7] == VarType.number) // offset of the 2nd var's type
            var2 = GetMegaloNumber((short)Condition + 4);
        else var2 = GetMegaloTimer_butweird(); // note: if 2nd var is not a number, then defaults to a timer variable
        switch (Condition->param_slots[8]) { // offset of the comparison type
        case ComparisonType.lessthan:
            return (var1 < var2);
        case ComparisonType.greaterthan:
            return (var2 < var1);
        case ComparisonType.equal:
            return (var1 == var2);
        case ComparisonType.lessthanequal:
            return (var1 <= var2);
        case ComparisonType.greaterthanequal:
            return (var2 <= var1);
        case ComparisonType.notequal:
            return (var1 != var2);
        }
        break; // not possible to reach this but i put it anyway for maintaining the same behaviour as original
    case VarType.player:
        var1 = GetMegaloPlayer((longlong)(Condition->param_slots + 4));
        var2 = GetMegaloPlayer((longlong)Condition);
        goto non_number_comparison;
    case VarType.object:
        var1 = GetMegaloObject((longlong)(Condition->param_slots + 4));
        var2 = GetMegaloObject((longlong)Condition);
        goto non_number_comparison;
    case VarType.team:
        var1 = GetMegaloTeam((longlong)(Condition->param_slots + 4));
        var2 = GetMegaloTeam((longlong)Condition);
        goto non_number_comparison;
    }
    return false; // incase of no case
non_number_comparison:
    if (Condition->param_slots[8] == ComparisonType.equal) // offset of the comparison type
        return var2 == var1;
    return var2 != var1;
}

