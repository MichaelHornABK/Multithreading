#include <iostream>
#include <thread>

bool DidQuit = false;
int ThreadVar = 0;
int ThreadVar2 = 0;

void HelloWorldThread()
{
    while (!DidQuit)
    {
        ThreadVar++;
        if (ThreadVar > 1000)
        {
            ThreadVar = 0;
        }
    }
}

void NumberThread2()
{
    while (!DidQuit)
    {
        ThreadVar2++;
        if (ThreadVar2 > 1000)
        {
            ThreadVar2 = 0;
        }
    }
}

int main()
{
    std::cout << "Hello World!\n";
    char userInput;
    std::thread Hello(HelloWorldThread);
    std::thread NumberThread(NumberThread2);

    
    while (!DidQuit)
    {
        std::cout << "Enter any key to stop counter" << std::endl;
        std::cout << "q to quit" << std::endl;
        std::cin >> userInput;
        DidQuit = (userInput == 'q');
        std::cout << "ThreadVar: " << ThreadVar << std::endl;
        std::cout << "ThreadVar2: " << ThreadVar2 << std::endl;
    }
    Hello.join();
    NumberThread.join();
    
    return 0;
}