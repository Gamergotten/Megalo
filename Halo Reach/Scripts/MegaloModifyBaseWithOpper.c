
// 

enum operator_types
{
   addition = 0,
   subtraction = 1,
   mulitplication = 2,
   division = 3,
   set = 4,
   modulo = 5,
   AND = 6,
   OR = 7,
   XOR = 8,
   NOT = 9,
}

int MegaloModifyBaseWithOpper(int Base,int opperand,int operator)
{
   int Output;
   switch (operator)
   {
      case operator_types.addition:
         Output = Base + opperand;
         break;
      case operator_types.subtraction:
         Output = Base - opperand;
         break;
      case operator_types.mulitplication:
         Output = Base * opperand;
         break;
      case operator_types.division:
         Output = 0;
         if (opperand != 0) {
            Output = Base / opperand;
         }
         break;
      case operator_types.set:
         Output = opperand;
         break;
      case operator_types.modulo:
         Output = 0;
         if (opperand != 0) {
            Output = Base % opperand;
         }
         break;
      case operator_types.AND:
         Output = Base & opperand;
         break;
      case operator_types.OR:
         Output = Base | opperand;
         break;
      case operator_types.XOR:
         Output = Base ^ opperand;
         break;
      case operator_types.NOT:
         Output = ~opperand;
         break;
   }
   return Output;
}