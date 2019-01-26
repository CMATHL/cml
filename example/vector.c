#include <stdio.h>
#include <cml/vector.h>
#include <scic/vector.h>

int
main(int argc, const char *argv[])
{
        vector_t vector;
        int x, y;

        /* Choose initial capacity */
        /* Specify the size of the elements you want to store once */
        vector_setup(&vector, 10, sizeof(int));

        x = 6, y = 9;
        vector_push_back(&vector, &x);
        vector_insert(&vector, 1, &y);

        printf("Min element: %d\n", *((int *) cml_vector_min(&vector, &cml_sort_int_cmp)));
        printf("Max element: %d\n", *((int *) cml_vector_max(&vector, &cml_sort_int_cmp)));
        
        vector_clear(&vector);
        vector_destroy(&vector);
}
