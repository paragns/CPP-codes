/*
The fact that it can be any path, and the fact that there are negative numbers, those things complicate this. Otherwise it would be a simple recursion.
But there is still a recursion here.
Given a subtree that is just one level, like so:

 A
B C   

Then you have the 6 possibilities of A * B * C, or A * B, or A * C, or A, or B, or C.

Given a larger tree like so:
  A
 X Y
 
where X and Y are trees in their own right, then consider that you have the similar 6 possible combinations:

1) A
2) A * (any potential product from X that includes the root node of X) * (any potential product from Y that includes the root node of Y)
3) A * (any potential product from X that includes the root node of X)
4) A * (any potential product from Y that includes the root node of Y)
5) Any potential product from X
6) Any potential product from Y
Any single one of those products can end up being the largest.

So now you can write a recursive function that incorporates those 6 possibilities, and call the function starting from the root node. In the function you will calculate all 6 of those products (calling your function recursively) and if any of those products are bigger than the global max, you have a new global max.
*/
