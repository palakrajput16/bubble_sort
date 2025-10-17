# bubble_sort
A simple algorithm to sort numbers, using C, which was done as a part of my assignment in Computer Organisation.

Level 1: Understanding Sorting in My Mind


When I first came across this question , I wondered: "What is it to sort numbers?"


At the most basic level, sorting is about creating order. But what exactly is the order? It's being able to compare - to be able to say absolutely that one number is larger than, smaller than, or equal to another. This comparison relation is what allows numbers to be sortable, as opposed to arbitrary objects which have no ordering inherent in them.


The problem statement is: "place a finite set of given positive integers into ascending order." But is the above description specific enough for a computer? 


Let me consider what my mind really does when I sort numbers.


When I glance at numbers such as: 5, 4, 3, 2, 1,  it’s easy for me to sort them; however, to be able to write the code, I need to break down how my mind works to sort this.


How My Mind Sorts Numbers:


* I read through the numbers
* I compare neighboring pairs
* I see when something's out of order (5 > 4, so they're incorrect)
* I switch them in my head
* I do it again and again
* I keep going until everything is settled


The Key Insight: Pairwise Comparisons


The key insight is that I don't need to consider the whole sequence as a whole. I only need to:*
* Examine two neighboring numbers
* Determine if they're in the correct order
* Correct them if they're not
* Proceed to the next pair


This reduces the daunting task of "sorting everything" to the easy task of "correcting one pair at a time."


Level 2: Making the Process Explicit to Implement on a Machine
My thought process must become explicit steps that can be carried out by a machine. Let me lay out exactly what is done.


The Bubble Sort Process:
* Begin at the start of the list
* Compare the first number and the second number
* If first is greater than second, swap them
* Go on to the next pair (second and third numbers)
* Repeat the comparing and swapping for all nearby pairs
* When you get to the end, you've done one "pass"


Key insight: One pass later, the largest number has "bubbled up" to the end
Begin a new pass, but don't look at the last position (it's now correct)
Keep passing until you make a complete pass with no swaps


Why This Works: The Bubble Effect
I observed that in every pass, the biggest unsorted number always winds up in its rightful place - it "bubbles up" to the top as air bubbles in water do. 
This translates to:
After 1 pass: biggest number is in place
After 2 passes: biggest and next-biggest are in place
After n-1 passes: everything's in place


Converting to Machine Logic
To make this clear to a machine, I must be even more specific:
Variables required:
* Array to store the numbers
* Loop counters to keep track of position
* Temporary variable to swap
* Control flow required:
* Outer loop: governs number of passes
* Inner loop: iterates through pairs in each pass
* Conditional: determines if swap


The structure of the algorithm:


FOR pass = 0 to n-2:
    FOR position = 0 to n-2-pass:
        IF array[position] > array[position+1]:
exchange them




Level 3: Mapping to C Programming Language


Selecting Data Structures
In C, I must store the numbers somewhere. The natural choice is an array:

int inp_nums[MAXNUMS];
int out_nums[MAXNUMS];
  

I am using two arrays because I wish to leave the original input intact for display, sort a working copy instead.


Coding the Comparison Logic
The core of bubble sort is comparison and swap:
  
 if (out_nums[j] > out_nums[j + 1]) {
                temp = out_nums[j];
                out_nums[j] = out_nums[j + 1];
                out_nums[j + 1] = temp;
            }


This takes precisely what I explained above - that easy mental question of "is the first greater than the second?" followed by swapping their places.




Creating the Loop Structure
The nested loops execute the concept of "passes" that I've identified:
Outer loop (i = 0 to n-2): 
* Determines the number of passes we take
* We only need up to n-1 passes for n numbers
* Each pass puts one more number in its correct position


Inner loop (j = 0 to n-i-2):
* Walks through all adjacent pairs in current pass, similar to my mind scan process
* The n-i-1 bound captures my insight that after i passes, the last i positions are sorted
* We compare j and j+1, so we only go up to n-i-2 in order not to go out of bounds


The Complete Implementation
  
void bubble_sort(int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (out_nums[j] > out_nums[j + 1]) {
                temp = out_nums[j];
                out_nums[j] = out_nums[j + 1];
                out_nums[j + 1] = temp;
            }
        }
    }
}


Input/Output Handling


The assignment requires specific formatting:
* Read numbers as command line arguments using argv[]
* Display input with "INP: " prefix
* Display sorted output with "BUB: " prefix
// Reading input
  
for (i = 0; i < num_nums; i++) {
        inp_nums[i] = atoi(argv[i + 1]);
        out_nums[i] = inp_nums[i];
        printf("%d ", inp_nums[i]);
    }


Verifying the Translation


Glancing back at my code, I can see how naturally my original thought process mapped into C. All of the programming constructs do exactly the purpose I had identified while doing the mental analysis, ensuring that this is not just any implementation of bubble sort - it's exactly my understanding solidified.




Reflection
This exercise showed me that programming is actually about making our intuitive steps explicit and systematic. My brain was already doing bubble sort - I just needed to:
* Recognize what I was actually doing in my head
* Break it down into discrete, repeatable steps
* Map those steps to programming constructs (loops, conditionals, variables)




TEST CASES - Inputs and Expected Output


1. INP: 5 4 3 2 1
BUB: 1 2 3 4 5


2. INP: 1 2 3 4 5
BUB: 1 2 3 4 5


3. INP: 128 989 123 456 789
BUB: 123 456 989 789 128


4. INP: 32 456 -456 -32 -23 10 -10 -23
BUB: -456 -32 -23 -23 -10 10 32 456


5. INP: 10 20 15 20 5 21
BUB: 5 10 15 20 20 21


