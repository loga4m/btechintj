/*

    Core idea:
        the taller is the minimum of left and right is,
        the great is the area.

    Note the idea implies we use minimum of two to get
    the area (otherwise, container overlow).
        
    We use two pointers to track. As we move from left to
    right and right to left, the possibility of that
    max area is there decreases, as the width of container
    does.

    In every change, we move the smaller pointer.
    Reason:
        If height[i] is smaller and if we move the larger,
        then we get only smaller area regardless of the
        new height. This is because the width decreases.
        If the new height is smaller, we get even smaller area.

        Therfore, we move smaller one.

    What if they're equal?
    In that case, we don't care. Either can move.
    Reason:
        Given height[i] == height[j],
        the area will be height[i] * (j - i), j > i.
        Then, two cases:
            1) There exists only one taller. In this case,
               since we take height[i] for area calculation
               (as it is smaller), we get smaller area
               (width decreased). In the next iteration,
               height[i] will be moved, and since there are
               more taller ones, we get only smaller area.

            2) There exists multiple taller heights. In this,
               in the next iterations, height[i] will be moved
               based on previous rules and we catch up two taller
               ones. If we are lucky, we can find max area here.
        Therefore, we don't care which one moves.
        We could move one or both.
        Question arises: wouldn't moving both simultaneously
                         break correctness?
        Again, two cases:
            1) There are taller ones. Then, even if we move both,
               we catch up with taller ones.
               There is no profit keeping one and moving another.
               Reason: if at least two taller exists, we anyway 
               catch up to them. Otherwise, we always get smaller area.
            2) No taller ones. Then, we always get smaller area.
        
        But moving one gave faster results, since it requires
        only two conditional statements rather than three.
*/


int min(int a, int b);
int max(int a, int b);

int maxArea(int* height, int heightSize) {
    int maxA = 0;
    int i = 0;
    int j = heightSize - 1;

    while (i < j) {
        int left = height[i];
        int right = height[j];
        int area = min(left, right) * (j - i);

        if (left < right) i++;
        else j--;
        maxA = max(maxA, area);
    }
    return maxA;
}

int min(int a, int b) {
    return (a < b) ? a:b;
}

int max(int a, int b) {
    return (a > b) ? a:b;
}

/*
Time complexity:
    loop --  O(n) 
        (extreme case where the tallest is on 
         another end and all others are smaller than it)
    others -- O(1)
    Overall: O(n)

Space complexity:
    Primitive type variables are used -- O(1)
    Overall: O(1)
*/