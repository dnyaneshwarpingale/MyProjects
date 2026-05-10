/* 
int main(void)
{
    int n1; 
    int n2; 
    int sum; 

    n1 = 100; 
    n2 = 200; 
    sum = n1 + n2; 
}

OPERATOR:   THE ENTITY WHICH TRIGGERS AN OPERATION 
OPERAND:    ENTITY/ENTITIES ON WHICH OPERATION TRIGGERED BY THE 
            OPERATOR IS APPLIED. 

In programming language, the operator is always denoted by a 
SYMBOL. 

SYMBOL      NAME 
DATA MOVEMENT OPERATOR 
=           ASSIGNMENT OPERATOR 

ARITHMETIC OPERATORS 
+           ADDITION OPERATOR 
-           SUBTRACTION OPERATOR 
-           NEGATION OPERATION 
*           MULTIPLICATION OPERATOR 
/           DIVISION OPERATOR 
%           MODULUS OPERATOR 
<<          SHIFT ARITHMETIC LEFT OPERATOR 
>>          SHIFT ARITHMETIC RIGHT OPERATOR 
++          PRE-INCREMENT 
++          POST-INCREMENT 
--          PRE-DECREMENT 
--          POST-DECREMENT 

COMPARISON OPERATORS 
==          EQUALITY OPERATOR 
!=          UNEQUALITY OPERATOR 
>           GREATER THAN OPERATOR 
>=          GREATER THAN OR EQUAL TO OPERATOR 
<           LESS THAN OPERATOR
<=          LESS THAN OR EQUAL TO OPERATOR 

LOGIC OPERATORS 
&&          LOGICAL AND OPERATOR 
||          LOGICAL OR OPERATOR 
!           LOGICAL NOT OPERATOR 

BITWISE OPERATORS 
&           BITWISE AND OPERATOR 
|           BITWISE OR OPERATOR 
^           BITWISE XOR OPERATOR 
~           BITWISE NOT OPERATOR 

INDIRECTION OPERATORS 
*           DEREFERENCE OPERATOR 
[]          SUBSCRIPT OPERATOR 
.           DOT OPERATOR 
->          ARROW OPERATOR 
()          CALL OPERATOR 
////////////////////////////////////////////////////////////

Every operator demands specific number of operands to operator on. 
This number is called as 'an ary' of the operator. 

For example: 
addition operator requires two operands to operate on. 
Therefore, it is called as a 'binary' operator 
bi -> two 
ary -> number of operands required. 
////////////////////////////////////////////////////////////
Let n be an integer variable. 
-n
'-' is a NEGATION OPERATOR 
It requires one operand. 
UNO -> ONE 
ARY -> Number of required operands 
UNARY 
////////////////////////////////////////////////////////////
a - b; 
  This '-' is a binary operator. 
  Therefore, compiler knows it to be a SUBTRACTION OPERATOR 
////////////////////////////////////////////////////////////
-n 
This '-' is a unary operator. 
Therefor,e compiler knowns it to be a NEGATION OPERATOR 
////////////////////////////////////////////////////////////
There are two ways in which unary operator and its operand 
can be written. 
a) Operator first and then operand 
b) Operand first and then operator 

e.g. 
NEGATIION: 
int n = 10; 
int m; 
int main(void)
{
    m = -n; 
}

Here negation operator appers first and then operand 'n'
(a number to be negated appears)

Such unary operators are known as UNARY PREFIX operator. 

int main(void)
{
    puts("Hello"); 
}

() -> call operator 
puts function is an operand. 

operand first and then operator. 
Such unary operators are known as UNARY POSTFIX operators. 
////////////////////////////////////////////////////////////
Binary operators: 
Let + be a binary operator and let m and n be the operands. 

m + n   operator between the operands (infix)
+ m n   operator first and then operands (prefix)
m n +   operands first and then operator (postfix)

ALL BINARY OPERATOS IN C are INFIX. 

OPERAND_1   OPERATOR    OPERAND_2 
////////////////////////////////////////////////////////////

a) ARY OF OPERATOR: How many number of operands does an operator 
require? ans: one (unary), two(binary)

b) SEQUENCE OF WRITING OPERATOR AND OPERAND: 
    for unary operator 
        a) prefix unary (operator first and then operand)
        b) postfix unary (operand first and then operator)

    for binary operator
        infix -> operand_1 operator operand_2 

c) PRECEDENCE 

d) ASSOCIATIVITY 
////////////////////////////////////////////////////////////

EXPRESSION: 
    Defintion: 
    A VALID COMBINATION OF OPERATORS AND OPERANDS WHERE 
    VALIDITY IS DETERMINED AS FOLLOWS: 
        1) SYNTACTIC VALIDITY : BASED ON ARY, AND SEQUENCE OF 
        OPERATOR AND OPERANDS 
        2) SEMANTIC VALIDITY: BASED ON RELATIVE PRECEDENCE 
        AND ASSOCIATIVITY. 

CONDITION: 
    ANY RIGHT HAND SIDE EXPRESSION WHICH EVALUATES TO 
    TRUE OR FALSE IS KNOWN AS A CONDITION. 


*/