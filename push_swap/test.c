#include "push_swap.h"
void sort_assign (t_num **stack_a)
{
    insertionSort(stack_a, "num");
    assign_ordered_i(stack_a);
    insertionSort(stack_a, "input");
}

void check_sort(t_num **stack_a)
{
    write(1, "sortcheck\n", 10);
    printf("unsorted\n");
    print_list(stack_a, "num");
    print_list(stack_a, "input");
    print_list(stack_a, "sorted");

    insertionSort(stack_a, "num");
    assign_ordered_i(stack_a);

    printf("Sorted\n");
    print_list(stack_a, "num");
    print_list(stack_a, "input");
    print_list(stack_a, "sorted");

    printf("Sorted oroginal order with indices\n");
    insertionSort(stack_a, "input");

    print_list(stack_a, "num");
    print_list(stack_a, "input");
    print_list(stack_a, "sorted");
    printf("end sortcheck");
}

void check_swap(t_num **stack_a)
{
    write(1, "\nswapcheck\n", 11);
    print_list(stack_a, "num");
    write(1, "swap\n", 5);
    // swap(stack_a, 'a');
    print_list(stack_a, "num");
    printf("first %d, previous %d, next %d\n",(*stack_a) ->num, (*stack_a)-> prev ->num,  (*stack_a)-> next ->num);
    write(1, "swap\n", 5);
    // swap(stack_a, 'a');
    print_list(stack_a, "num");
    printf("first %d, previous %d, next %d\n",(*stack_a) ->num, (*stack_a)-> prev ->num,  (*stack_a)-> next ->num);
}

void check_push(t_num **stack_a, t_num **stack_b)
{
    write(1, "\npushcheck\n", 11);
    write(1, "stack_a: ", 9);
    print_list(stack_a, "num");
    write(1, "stack_b: ", 9);
    print_list(stack_b, "num");
    write(1, "\npush\n", 6);
    // push(stack_a, stack_b, 'b');
    write(1, "stack_a: ", 9);
    print_list(stack_a, "num");
    write(1, "stack_b: ", 9);
    print_list(stack_b, "num");
    printf("a first %d, previous %d, next %d\n", (*stack_a) ->num, (*stack_a) ->prev ->num, (*stack_a) ->next ->num);
    printf("b first %d, previous %d, next %d\n", (*stack_b) ->num, (*stack_b) ->prev ->num, (*stack_b) ->next ->num);
    write(1, "\npushback\n", 10);
    // push(stack_b, stack_a, 'a');
    printf("a first %d, previous %d, next %d\n", (*stack_a) ->num, (*stack_a) ->prev ->num, (*stack_a) ->next ->num);
    write(1, "stack_a: \n", 10);
    print_list(stack_a, "num");
    print_list(stack_a, "input");
    print_list(stack_a, "sorted");
    write(1, "stack_b: \n", 10);
    print_list(stack_b, "num");
}

void check_rotate(t_num **stack_a)
{
      write(1, "\nrotatecheck\n", 13);
    print_list(stack_a, "num");
    printf("%d\n", (*stack_a) ->num);
    printf("%d\n", (*stack_a) -> prev ->num);
    // rotate(stack_a, 0, 'a');
    print_list(stack_a, "num");
    printf("%d\n", (*stack_a) ->num);
    printf("%d\n", (*stack_a) -> prev ->num);
    // rotate(stack_a, 1, 'a');
    print_list(stack_a, "num");
    printf("%d\n", (*stack_a) ->num);
    printf("%d\n", (*stack_a) -> prev ->num);    
}