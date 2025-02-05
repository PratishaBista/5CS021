// #include <pthread.h>
// #include <stdio.h>

// void *func1(void *arg)
// {
//     for (int i = 0; i < 4; i++)
//     {
//         // Sleep(100);
//         printf("This is function 1:%d\n", i);
//     }
// }
// void *func2(void *args)
// {
//     for (int i = 0; i < 5; i++)
//     {
//         // Sleep(100);
//         printf("This is function 2:%d\n", i);
//     }
// }

// int main()
// {
//     pthread_t thread1, thread2;

//     pthread_create(&thread1, NULL, func1, NULL);
//     pthread_create(&thread2, NULL, func2, NULL);
//     pthread_join(thread1, NULL);
//     pthread_join(thread2, NULL);
//     // func2();
//     return 0;
// }

#include <pthread.h>
#include <stdio.h>

void *func1(void *arg)
{
    for (int i = 0; i < 4; i++)
    {
        // Sleep(100);  // Uncomment if you need to slow down output
        printf("This is function 1: %d\n", i);
    }
    return NULL; 
}

void *func2(void *args)
{
    for (int i = 0; i < 5; i++)
    {
        // Sleep(100); // Uncomment if needed
        printf("This is function 2: %d\n", i);
    }
    return NULL; 
}

int main()
{
    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, func1, NULL);
    
    pthread_create(&thread2, NULL, func2, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    
    return 0;
}



// #include <pthread.h>
// #include <stdio.h>

// void* test_function(void* arg) {
//     printf("pthread is working!\n");
//     return NULL;
// }

// int main() {
//     pthread_t thread;
//     pthread_create(&thread, NULL, test_function, NULL);
//     pthread_join(thread, NULL);
//     return 0;
// }
